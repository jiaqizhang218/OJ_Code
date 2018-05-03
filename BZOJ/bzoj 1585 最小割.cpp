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
    x=(f==1)?x:-x;  return;
}
using namespace std;
#define MAXL 1000000
#define MAX 100000
#define INF 1000000000
struct Line
{
    int v,next,w;
}e[MAXL];
int h[MAX],cnt;
int ans,S,T,n,m;
inline void Add(int u,int v,int w)
{
    e[cnt]=(Line){v,h[u],w};
    h[u]=cnt++;
    e[cnt]=(Line){u,h[v],0};
    h[v]=cnt++;
}
int level[MAX];
int cur[MAX];
bool BFS()
{
    memset(level,0,sizeof(level));
    level[S]=1;
    queue<int> Q;
    Q.push(S);
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        for(int i=h[u];i!=-1;i=e[i].next)
        {
            int v=e[i].v;
            if(e[i].w&&!level[v])
                level[v]=level[u]+1,Q.push(v);
        }
    }
    return level[T];
}
int DFS(int u,int flow)
{
    if(flow==0||u==T)return flow;
    int ret=0;
    for(int i=h[u];i!=-1;i=e[i].next)
    {
        int v=e[i].v;
        if(e[i].w&&level[v]==level[u]+1)
        {
            int dd=DFS(v,min(flow,e[i].w));
            flow-=dd;ret+=dd;
            e[i].w-=dd;e[i^1].w+=dd;
        }
    }
    return ret;
}
int Dinic()
{
    int ret=0;
    while(BFS())     ret+=DFS(S,INF);
    return ret;
}
int P,C,N;
bool vis[MAX];
int U[MAX],V[MAX],R[MAX];
int main()
{
    memset(h,-1,sizeof(h));
    rd(P);rd(C),rd(N);
    S=1;T=P+P+1;
    Add(1,1+P,INF);
    for(int i=1;i<=C;++i)
    {
        int u,v;rd(u),rd(v);
        Add(u+P,v,INF);Add(v+P,u,INF);
    }
    for(int xx,i=1;i<=N;++i)rd(xx),vis[xx]=true;;
    for(int i=2;i<=P;++i)
        if(!vis[i])
            Add(i,i+P,1);
        else Add(i,i+P,INF),Add(i+P,T,INF);
    printf("%d\n",Dinic());
    return 0;   
}
