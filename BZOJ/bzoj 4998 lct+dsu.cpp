#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
typedef pair<int,int> pa;
typedef long long LL;
template <typename T>
inline void rd(T &x){x = 0; int f = 1; char CH = getchar();while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}x=(f==1)?x:-x;  return;}
const int MXN = 200010;
int w[MXN],fa[MXN],bl[MXN],c[MXN][2],rev[MXN],con[MXN];
inline int findfa(int x) {return x==bl[x]?x:bl[x]=findfa(bl[x]);}
inline int getcon(int x) {return x==con[x]?x:con[x]=getcon(con[x]);}
inline void pushdown(int x) {
	if(rev[x]) {
		int l=c[x][0],r=c[x][1];
		rev[x]^=1; rev[l]^=1; rev[r]^=1;
		swap(c[l][0],c[l][1]); swap(c[r][0],c[r][1]);
	}
}
inline bool isrt(int x) {return x!=c[fa[x]][0]&&x!=c[fa[x]][1];}
inline void update(int x) {
	if(!isrt(x)) update(x);
	pushdown(x);
}
inline void rotate(int x) {
	int y=findfa(fa[x]),z=findfa(fa[y]),l=(c[y][1]==x),r=l^1;
	if(!isrt(y)) c[z][c[z][1]==y]=x;
	fa[x]=z; fa[y]=x; fa[c[x][r]]=y; c[y][l]=c[x][r]; c[x][r]=y;
}
inline void splay(int x) {
	update(x);
	for(int y=findfa(fa[x]),z=findfa(fa[y]);!isrt(x);rotate(x),y=findfa(fa[x]),z=findfa(fa[y]))
		if(c[y][0]==x^c[z][0]==y)	rotate(x); else rotate(y);
}
inline void access(int x) {
	for(int t=0;x;splay(x),c[x][1]=t,t=x,x=findfa(fa[x]));
}
inline void mkrt(int x) {
	 access(x),splay(x),swap(c[x][0],c[x][1]); rev[x]^=1;
}
inline void link(int x,int y) {
	mkrt(x); fa[x]=y; con[getcon(x)]=getcon(y);
}
inline void dfs(int x,int y) {
	if(!x) return;
	bl[x]=y; w[y]+=w[x];
	dfs(c[x][0],y); dfs(c[x][1],y);
}
inline int add(int x,int y) {
	x=findfa(x),y=findfa(y);
	if(x==y) return w[x];
	else if(getcon(x)!=getcon(y)) {
		link(x,y);
		return -1;
	}
	mkrt(x),access(y),splay(y);
	dfs(c[y][0],y);
	return w[y];
}
int n,m,p,i,x,y,t;
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(n),rd(m),rd(p);
	rep(i,1,n) bl[i]=con[i]=i;
	rep(i,1,m) rd(x),rd(y),add(x,y);
	rep(i,1,p) {
		rd(x),rd(y);
		t = add(x,y);
		if(~t) printf("%d\n",t);
		else puts("No");
	}
	return 0;
#ifdef iloi
	debug("\nMy Time: %.4lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

