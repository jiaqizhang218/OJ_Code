#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
typedef long long LL;
const int INF = 1e9+6666;
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 100010;
int fa[MXN],tr[MXN][2],val[MXN];
int n,siz,rt,t1,t2;
namespace Splay {
	
	inline void rotate(int x,int &k) {
		int y=fa[x],z=fa[y],l,r;
		if(tr[y][0]==x) l=0;else l=1; r=l^1;
		if(k==y) k=x;
		else tr[z][tr[z][1]==y]=x;
		fa[x]=z; fa[y]=x; fa[tr[x][r]]=y;
		tr[y][l]=tr[x][r]; tr[x][r]=y;
	}
	inline void splay(int x,int &k) {
		for(int y=fa[x],z=fa[y];x!=k;rotate(x,k),y=fa[x],z=fa[y]) 
			if(y!=k) {if(tr[y][0]==x^tr[z][0]==y) rotate(x,k); else rotate(y,k);}
	}
	inline bool insert(int &k,int x,int f) {
		if(k==0) {k=++siz;val[k]=x,fa[k]=f,splay(k,rt);return 1;}
		if(val[k]==x) return 0;
		if(x<val[k]) return insert(tr[k][0],x,k);
		else return insert(tr[k][1],x,k);
	}
	inline void query_pre(int k) {
		if(tr[k][0]==0) return;
		k=tr[k][0];
		while(tr[k][1]) k=tr[k][1];
		t1=val[k];
	}
	inline void query_nxt(int k) {
		if(tr[k][1]==0) return;
		k=tr[k][1];
		while(tr[k][0]) k=tr[k][0];
		t2=val[k];
	}
}using namespace Splay;
	
int main()
{
	rd(n);	int ans=0;
	rep(i,1,n) {
		int x; rd(x);
		if(!insert(rt,x,0)) continue;
		t1=-INF,t2=INF;
		query_pre(rt); query_nxt(rt);
		dbg(min(x-t1,t2-x));
		if(i==1) ans+=x;
		else ans+=min(x-t1,t2-x);
	}
	printf("%d\n",ans);
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

