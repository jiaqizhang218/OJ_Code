#include<bits/stdc++.h>
using namespace std;
const int MXN = 250005;
#define rpg1(i,x) for(register int i=g1.fir[x];i;i=g1.e[i].nxt)
#define rpg2(i,x) for(register int i=g2.fir[x];i;i=g2.e[i].nxt)
typedef long long LL;
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define debug(...) fprintf(stderr,__VA_ARGS__)
struct graph {
    int fir[MXN],edge_cnt;
    struct edge {
        int to,nxt,w;
    }e[MXN<<1];
    graph(){edge_cnt=0;memset(fir,0,sizeof fir);}
    inline void AE(int u,int v,int w) {
        e[++edge_cnt].to=v;e[edge_cnt].nxt=fir[u];fir[u]=edge_cnt;e[edge_cnt].w=w;
    }
}g1;
struct gg {
    int fir[MXN],edge_cnt;
    struct edge {
        int to,nxt;
    }e[MXN<<1];
    inline void AE(int u,int v) {
        if(u==v) return;
        e[++edge_cnt].to=v;e[edge_cnt].nxt=fir[u];fir[u]=edge_cnt;
    }
}g2;
int b[MXN],q[MXN],n,k,a[MXN],m,siz[MXN],fa[MXN],dep[MXN],dfn[MXN],pos[MXN],dfs_clock,top[MXN];
LL mn[MXN],f[MXN];
inline void dfs1(int x) {
    siz[x]=1;
    rpg1(i,x) {
        int v=g1.e[i].to;
        if(v==fa[x]) continue;
        mn[v]=min(mn[x],(LL)g1.e[i].w), fa[v]=x; dep[v]=dep[x]+1;
        dfs1(v); siz[x]+=siz[v];
    }
}
inline void dfs2(int x,int chain) {
    dfn[x]=++dfs_clock; top[x]=chain; pos[dfs_clock]=x;
    int v=0,mx=0;
    rpg1(i,x) {
        if(g1.e[i].to!=fa[x]) 
            if(siz[g1.e[i].to]>mx) mx=siz[g1.e[i].to],v=g1.e[i].to;
    }
    if(v)
        dfs2(v,chain);
    rpg1(i,x) {
        if(g1.e[i].to!=fa[x]&&g1.e[i].to!=v) {
            dfs2(g1.e[i].to,g1.e[i].to);
        }
    }
}
inline int LCA(int x,int y) {
    while(top[x]!=top[y]) {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        x=fa[top[x]];
    }
    return dep[x]<dep[y]?x:y;
}
bool cmp(int x,int y) {
    return dfn[x] < dfn[y];
}
inline void dfs(int x) {
    f[x]=mn[x];
    LL s=0;
    rpg2(i,x) {
        dfs(g2.e[i].to);
        s+=f[g2.e[i].to];
    }
    if(s<f[x]&&s) f[x]=s;
    g2.fir[x]=0;
}
int main() {
#ifdef iloi
    freopen("test.in","r",stdin);
    freopen("233.out","w",stdout);
#endif
    scanf("%d",&n);
    for(int i=1,x,y,z;i<n;++i) {
        scanf("%d%d%d",&x,&y,&z);
        g1.AE(x,y,z),g1.AE(y,x,z);
    }
    mn[1]=LONG_LONG_MAX; dfs1(1),dfs2(1,1);
    scanf("%d",&m);
    for(int owo=1;owo<=m;++owo) {
        scanf("%d",&k);
        for(int i=1;i<=k;++i) scanf("%d",&a[i]);
        sort(a+1,a+1+k,cmp);
        int tot=1;b[tot]=a[1];
        for(int i=2;i<=k;++i) if(LCA(a[i],b[tot])!=b[tot]) b[++tot]=a[i];
        int tp=1; q[tp]=1;
        for(int i=1;i<=tot;++i) {
            int now=b[i],f=LCA(now,q[tp]);
            while(1) {
                if(dep[f]>=dep[q[tp-1]]) {
                    g2.AE(f,q[tp--]); break;
                }
                g2.AE(q[tp-1],q[tp]); tp--;
            }
            if(q[tp]!=f) q[++tp]=f;
            if(q[tp]!=now) q[++tp]=now;
        }
        while(tp>1) {
            g2.AE(q[tp-1],q[tp]);
            tp--;
        }
        dfs(1);
        printf("%lld\n",f[1]);
        g2.edge_cnt=0;
    }
#ifdef iloi
    debug("My time is %.3lfs",(double)clock()/CLOCKS_PER_SEC);
#endif
}
