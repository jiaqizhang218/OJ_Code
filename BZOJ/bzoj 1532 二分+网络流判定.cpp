#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rpg(i,x) for(register int i=fir[x];i;i=e[i].nxt)
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define bin(i) (1<<i)
#define cls(x,y) memset(x,y,sizeof x)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
const int oo = 0x3f3f3f3f;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
//#define  getchar() nc()
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
    while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    return;
}
const int N = 10005;
namespace MaxFlow {
	int cnt=1,fir[N<<1],n,m,h[N<<1],q[N<<1],ans,S,T,x[N<<1],y[N<<1],cur[N<<1];
	struct edge{
		int to,nxt,val;
	}e[N*10];
	inline void AE(int u,int v,int w) 
	{
		e[++cnt].to=v;e[cnt].nxt=fir[u];fir[u]=cnt;e[cnt].val=w;
		e[++cnt].to=u;e[cnt].nxt=fir[v];fir[v]=cnt;e[cnt].val=0;
	}
	inline bool bfs()
	{
		int t=0,w=1;
		cls(h,-1);
		q[S]=0,h[S]=0;
		while(t!=w)
		{
			int now=q[t++];
			rpg(i,now) 
				if(e[i].val&&h[e[i].to]==-1) {
					q[w++]=e[i].to;
					h[e[i].to]=h[now]+1;
				}
		}
		return (h[T]==-1)?0:1;
	}
	inline int dfs(int x,int flow) 
	{
		if(x==T)	return flow;
		int w,used=0;
		for(int i=cur[x];i;i=e[i].nxt) {
			if(e[i].val&&h[e[i].to]==h[x]+1) {
				w=flow-used;
				w=dfs(e[i].to,min(w,e[i].val));
				e[i].val-=w; e[i^1].val+=w;
				if(e[i].val) cur[x]=i;
				used += w;	
				if(used==flow)	return flow;
			}
		}
		if(!used)h[x]=-1;
   	 	return used;
	}
	inline void dinic() {
		while(bfs()) {rep(i,0,T) cur[i]=fir[i];	ans+=dfs(S,INF);}
	}
	inline void build_graph(int v) {
		cnt=1; ans=0;
		cls(fir,0);
		rep(i,1,n) AE(i,T,v);
		rep(i,1,m) AE(S,i+n,1),AE(i+n,x[i],1),AE(i+n,y[i],1);
	}
}
using namespace MaxFlow;
int main()
{
	rd(n),rd(m),S=0,T=n+m+1;
	rep(i,1,m) rd(x[i]),rd(y[i]);
	int l=0,r=5000;
	while(l<=r) {
		int mid=(l+r)>>1;
		build_graph(mid);
		dinic();
		if(ans==m)	r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
