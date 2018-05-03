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
#define bin(i) (1<<i)
#define cls(x,y) memset(x,y,sizeof x)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
const int oo = 0x3f3f3f3f;
/*const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc() //*/
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 1011 , MXM = 1011010;
int n,m,tot,score[MXN];
struct edge{ int to,nxt,cap;} e[MXM];
int fir[MXN],cnt=1,vis[MXN],deg[MXN],s,t;
inline void AE(int u,int v,int w){e[++cnt].to=v;e[cnt].nxt=fir[u];fir[u]=cnt;e[cnt].cap=w;}
inline void ins(int u,int v,int w){AE(u,v,w),AE(v,u,0);}
vector<int> G[MXN];
inline void dfs(int x) {
	vis[x]=1;	rep(i,0,G[x].size()-1) if(!vis[G[x][i]]) dfs(G[x][i]);
}
inline void Toposort() {
	s=1;t=n*m;
	stack<int> st;
	rep(i,s,t) if(!deg[i]) st.push(i); else vis[i]=1;
	while(!st.empty()) {
		int now = st.top(); st.pop();
		vis[now]=0;
		rep(i,0,G[now].size()-1) {
			if(!(--deg[G[now][i]])) st.push(G[now][i]);
		}
	}
	rep(i,s,t) if(vis[i]) dfs(i);
}
namespace MaxFlow {
	int h[MXN],cur,S,T;
	inline int dfs(int x,int flow)
	{
		if(x==T)	return flow;
		int used=0,tmp;
		rpg(i,x){
			if(e[i].cap&&h[e[i].to]==h[x]+1)
			{
				tmp=flow-used;tmp=dfs(e[i].to,min(tmp,e[i].cap));
				e[i].cap-=tmp,e[i^1].cap+=tmp;
				used+=tmp;if(used==flow)	return flow;
			}
		}
		if(!used)	h[x]=-1;
		return used;
	}
	inline bool bfs()
	{
		static int q[MXN];
		memset(h,-1,sizeof h);
		int hd=1,tl=1,now;
		q[tl++]=S;h[S]=0;
		while(hd<tl)
		{
			now=q[hd++];
			rpg(i,now)
			{
				if(e[i].cap&&h[e[i].to]==-1)
				{
					h[e[i].to]=h[now]+1;
					q[tl++]=e[i].to;
				}
			}
		}
		return h[T]!=-1;
	}
	inline int dinic(){int res=0;while(bfs())res+=dfs(S,INF);return res;}
}using namespace MaxFlow;
int total;
inline void build() {
	S=0,T=n*m+1;
	rep(i,1,T-1) {
		if(!vis[i]) {
			if(score[i]>0) ins(i,T,score[i]); else ins(S,i,-score[i]);
			rep(j,0,G[i].size()-1) if(!vis[G[i][j]]) ins(i,G[i][j],INF);
			total+=score[i]>0?score[i]:0;
		}
	}
}
inline int pos(int x,int y) {return (x-1)*m+y;}
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(n),rd(m);
	rep(i,1,n) rep(j,1,m) {
		int now=pos(i,j),num;
		rd(score[now]); rd(num);
		for(register int x,y,z=1;z<=num;++z) rd(x),rd(y),++x,++y,G[now].pb(pos(x,y)),deg[pos(x,y)]++;
		if(j>1) G[now].pb(pos(i,j-1)),deg[pos(i,j-1)]++;
	}
//	assert(m>555555);
	Toposort();
//	assert(m>66666);
	build();
	int maxflow=dinic();
	printf("%d\n",total-maxflow);
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
