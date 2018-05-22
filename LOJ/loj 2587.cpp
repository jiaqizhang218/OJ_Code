#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rpg1(i,x) for(register int i=g1.fir[x];i;i=g1.e[i].nxt)
#define rpg2(i,x) for(register int i=g2.fir[x];i;i=g2.e[i].nxt)
#define fi first
#define se second
#define pb push_back
#define bin(i) (1<<i)
#define cls(x,y) memset(x,y,sizeof x)
typedef pair<int,int> pa;
typedef long long LL;
typedef unsigned long long ull;
const int INF = 0x7fffffff;
template <typename T> inline void rd(T &x) {
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
template <typename T> inline bool chmax(T &a,const T &b) {
    return a<b?a=b,true:false;
}
template <typename T> inline bool chmin(T &a,const T &b) {
    return a>b?a=b,true:false;
}
const int MXN = 1e5 + 5;
LL ans;
int vis[MXN<<1],val[MXN<<1],n,m,sz,low[MXN],dfn[MXN],dfs_clock,stk[MXN],top,siz,size[MXN<<1];
struct graph {
    int fir[MXN<<1],edge_cnt;
    graph(){cls(fir,0),edge_cnt=1;}
    struct edge {
        int to,nxt;
    }e[MXN<<2];
    inline void AE(int u,int v) {
        e[++edge_cnt].to=v;e[edge_cnt].nxt=fir[u];fir[u]=edge_cnt;
    }
}g1,g2;
inline void tarjan(int x,int fro) {
    dfn[x]=low[x]=++dfs_clock;
    rpg1(i,x) {
        if(i==(fro^1)) continue;
        if(!dfn[g1.e[i].to]) {
            stk[++top]=i;
            tarjan(g1.e[i].to,i);
            chmin(low[x],low[g1.e[i].to]);
            if(low[g1.e[i].to]>=dfn[x]) {
                ++sz; int v=0;
                while(v!=i) {
                    v=stk[top--]; ++val[sz+n];
                    g2.AE(sz+n,g1.e[v].to); g2.AE(g1.e[v].to,sz+n);
                }g2.AE(sz+n,x);g2.AE(x,sz+n); ++val[sz+n];
            }
        } else chmin(low[x],dfn[g1.e[i].to]);
    }
}
inline void dfs1(int x,int fro) {
    siz+=(x<=n);
    rpg2(i,x) if(g2.e[i].to!=fro) dfs1(g2.e[i].to,x);
}
inline void dfs(int x,int fro) {
    vis[x]=1;
    rpg2(i,x) {
        if(g2.e[i].to!=fro) dfs(g2.e[i].to,x),size[x]+=size[g2.e[i].to];
    }
    rpg2(i,x) {
        if(g2.e[i].to!=fro) 
            ans+=1LL*val[x]*size[g2.e[i].to]*(siz-size[g2.e[i].to]);
    }
    ans+=1LL*val[x]*(siz-size[x])*size[x];
    if(x<=n) ans-=(siz-1);
}
int main() {
#ifdef iloi
    freopen("test.txt","r",stdin);
#endif
    rd(n),rd(m);
    rep(i,1,m) {
        int x,y; rd(x),rd(y);
        g1.AE(x,y),g1.AE(y,x);
    }
    rep(i,1,n) val[i]=-1,size[i]=1;
    rep(i,1,n) if(!dfn[i]) tarjan(i,0);
    rep(i,1,sz+n) if(!vis[i]) siz=0,dfs1(i,0),dfs(i,0);
    cout<<ans<<endl;
}
