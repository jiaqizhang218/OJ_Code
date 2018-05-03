#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rpg(i,x) for(register int i=fir[x];i;i=e[i].nxt)
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define bin(i) (1LL<<i)
#define cls(x,y) memset(x,y,sizeof x)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
const int oo = 0x3f3f3f3f;
/*
const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc() //*/
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 1e5 + 5 ;
int n,m,f,dfs_clock,a[MXN];
int tag[MXN],spe[MXN],up[MXN],vis[MXN];
int dep[MXN],fa[MXN],siz[MXN];
int son[MXN],top[MXN],Q;
struct Bitset {
	ull bit[666]; int Max;
	inline void clear() {
		rep(i,0,Max) bit[i]=0LL;
		Max=0;
	}
	inline void operator |= (const Bitset &rhs) {
		Max = max(Max,rhs.Max);
		rep(i,0,Max) bit[i]|=rhs.bit[i];
	}
	inline void operator |= (const int &rhs) {
		bit[rhs>>6] |= 1LL << (rhs&63);
		Max = max(Max,rhs>>6);
	}
	inline int num() {
		int ans=0;
		rep(i,0,Max) rep(j,0,63)	if(bit[i]&(bin(j))) ++ans;
		return ans;
	}
	inline int mex() {
		rep(i,0,Max) rep(j,0,63)	if(!(bit[i]&(bin(j)))) return (i<<6)+j;
	}
}ans;
Bitset Bit[333][333];
int fir[MXN],cnt;
struct edge{
	int to,nxt;
}e[MXN<<1];
inline void AE(int u,int v){e[++cnt].to=v;e[cnt].nxt=fir[u];fir[u]=cnt;}
inline void ins(int u,int v){AE(u,v),AE(v,u);}
inline void dfs1(int x,int f,int dp) {
	fa[x]=f; dep[x]=dp; siz[x]=1; son[x]=0;
	rpg(i,x) {
		int v = e[i].to;
		if(v==f) continue;
		dfs1(v,x,dp+1);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]]) son[x]=v;
	}
}
inline void dfs2(int x,int tp) {
	top[x]=tp;
	if(!son[x]) return;
	dfs2(son[x],tp);
	rpg(i,x) {
		int v=e[i].to;
		if(v==fa[x]||v==son[x])	continue;
		dfs2(v,v);
	}
}
inline int lca(int x,int y) {
	int t1=top[x],t2=top[y];
	while(t1!=t2) {
		if(dep[t1]<dep[t2]) swap(t1,t2),swap(x,y);
		x=fa[t1],t1=top[x];
	}
	return dep[x]<dep[y]?x:y;
}
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(n),rd(m),rd(f);	rep(i,1,n) rd(a[i]);
	for(register int x,y,i=1;i<n;++i) rd(x),rd(y),ins(x,y);
	srand(19260817); Q = (int)sqrt(n);
	dfs1(1,0,1); dfs2(1,1);
	rep(i,1,Q) {
		int h = rand() % n + 1;
		while(vis[h]) h = rand() % n + 1,dbg(h);
		vis[h]=1;
		tag[i]=h;
		spe[tag[i]]=i;
	}	//*/
//	dbg(n);
	rep(i,1,Q) {
		int x = tag[i];
		ans.clear();
		do {
			ans |= a[x];
			if(x != tag[i] && spe[x]) {
				Bit[i][spe[x]] |= ans;
				if(!up[tag[i]]) up[tag[i]]=x;
			}
			x=fa[x];
		}	while(x!=0);
	}
	int lastans=0;
	rep(i,1,m) {
		rd(cnt);
		ans.clear();
		for(register int j=1,x,y;j<=cnt;++j) {
			rd(x),rd(y);
			if(f) x^=lastans,y^=lastans;
			
			int z=lca(x,y); ans |= a[z];
			
			while(!spe[x] && x != z) ans |= a[x], x=fa[x];
			int now=x;
			while(dep[up[x]] > dep[z]) x=up[x];
			ans |= Bit[spe[now]][spe[x]];
			while(x!=z) ans |= a[x], x=fa[x];
			
			
			while(!spe[y]&&y != z) ans |= a[y], y=fa[y];
			now=y;
			while(dep[up[y]] > dep[z]) y=up[y];
			ans |= Bit[spe[now]][spe[y]];
			while(y!=z) ans |= a[y], y=fa[y];
		}
		int num=ans.num(),mex=ans.mex();
		lastans=num+mex;
		printf("%d %d\n",num,mex);
	}
}
