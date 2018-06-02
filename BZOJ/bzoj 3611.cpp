#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rpg1(i,x) for(register int i=g1.fir[x];i;i=g1.e[i].nxt)
#define rpg2(i,x) for(register int i=g2.fir[x];i;i=g2.e[i].nxt)
#define bin(i) (1<<i)
#define cls(x,y) memset(x,y,sizeof x)
typedef pair<int,int> pa;
typedef long long LL;
const LL INF = INT_MAX;
template <typename T>
inline void rd(T &x) {
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 1e6 + 5;
#define int long long
int a[MXN],n,m,dfn[MXN],dfs_clock,stk[MXN],size[MXN],sum[MXN],flag[MXN],mx[MXN],mn[MXN],top,fa[MXN][22],dep[MXN];
LL ans1,ans2,ans3;
struct graph {
	int fir[MXN],edge_cnt;
	struct edge {
		int to,nxt;
	}e[MXN<<1];
	inline void AE(int u,int v) {
		e[++edge_cnt].to=v;e[edge_cnt].nxt=fir[u];fir[u]=edge_cnt;
	}
	inline void Ins(int u,int v) {
		AE(u,v),AE(v,u);
	}
	inline void Ins(int u,int v,int dd) {
		if(u==v) return;
		AE(u,v);
	}
}g1,g2;
void dfs(int x,int fro) {
	dfn[x]=++dfs_clock;
	for(int i=1;bin(i)<=dep[x];++i) {
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	rpg1(i,x) {
		int v=g1.e[i].to;
		if(v==fro) continue;
		fa[v][0]=x; dep[v]=dep[x]+1;
		dfs(v,x);
	}
}
inline int getlca(int x,int y) {
	if(dep[x]>dep[y]) swap(x,y);
	for(int i=20;~i;--i) if(dep[fa[y][i]]>=dep[x]) y=fa[y][i];
	if(dep[x]>dep[y]) swap(x,y);
	for(int i=20;~i;--i) 
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return x!=y?fa[x][0]:x;
}
inline bool cmp(int a,int b) {
	return dfn[a]<dfn[b];
}
void dp(int x) {
	int mx1=0,mx2=0,mn1=INF,mn2=INF;size[x]=sum[x]=0;
	if(flag[x]) {
		size[x]++; sum[x]=dep[x]; mn1=0;
	}
	rpg2(i,x) {
		int v=g2.e[i].to;
		dp(v);
		size[x]+=size[v]; sum[x]+=sum[v];
		if(mx[v]+dep[v]-dep[x]>mx1) {
			mx2=mx1,mx1=mx[v]+dep[v]-dep[x];
		} else if(mx[v]+dep[v]-dep[x]>mx2) {
			mx2=mx[v]+dep[v]-dep[x];
		}
		if(mn[v]+dep[v]-dep[x]<mn1) {
			mn2=mn1,mn1=mn[v]+dep[v]-dep[x];
		} else if(mn[v]+dep[v]-dep[x]<mn2) {
			mn2=mn[v]+dep[v]-dep[x];
		}
	}
	rpg2(i,x) {
		int v=g2.e[i].to;
		ans1+=(LL)(size[x]-size[v])*(sum[v]-(LL)size[v]*dep[x]);
	}
	ans2=min(ans2,(LL)mn1+mn2);
	if(flag[x]||(!flag[x]&&mx2)) ans3=max(ans3,(LL)mx1+mx2);
	mx[x]=mx1,mn[x]=mn1;
	g2.fir[x]=0; 
}
inline void solve() {
	int k; rd(k);
	rep(i,1,k) rd(a[i]),flag[a[i]]=1;
	sort(a+1,a+k+1,cmp);
	stk[top=1]=1;
	rep(i,1,k) {
		int now=a[i],f=getlca(now,stk[top]);
		while(1) {
			if(dep[f]>=dep[stk[top-1]]) {
				g2.Ins(f,stk[top],1);top--;
				if(stk[top]!=f) stk[++top]=f;
				break;
			}
			g2.Ins(stk[top-1],stk[top],1),top--;
		}
		if(stk[top]!=now) stk[++top]=now;
	}
	while(top>1) {
		g2.Ins(stk[top-1],stk[top],1);top--;
	}
	ans1=ans3=0,ans2=INF;
	dp(1);
	rep(i,1,k) flag[a[i]]=0; g2.edge_cnt=0;
	printf("%lld %lld %lld\n",ans1,ans2,ans3);
}
main()
{
#ifdef iloi
	   freopen("test.in","r",stdin);
#endif
	rd(n);
	rep(i,2,n) {
		int x,y; rd(x),rd(y);
		g1.Ins(x,y);
	}
	dep[1]=1,dfs(1,0);
	rd(m);
	rep(owo,1,m) {
		solve();
	}
	return 0;
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
