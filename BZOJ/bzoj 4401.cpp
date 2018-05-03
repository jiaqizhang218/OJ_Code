#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#define N 1000006
#define M 2000006
 
using namespace std;
inline int read(){
    int ret=0;char ch=getchar();
    while (ch<'0' || ch>'9') ch=getchar();
    while ('0'<=ch && ch<='9'){
        ret=ret*10-48+ch;
        ch=getchar();
    }
    return ret;
}
 
struct edge{
    int adj,next;
    edge(){}
    edge(int _adj,int _next):adj(_adj),next(_next){}
} e[M];
int n,g[N],m;
void AddEdge(int u,int v){
    e[++m]=edge(v,g[u]);g[u]=m;
    e[++m]=edge(u,g[v]);g[v]=m;
}
 
int cnt[N], size[N];
bool vis[N];
void dfs(int u){
    vis[u]=1;size[u]=1;
    for (int i=g[u];i;i=e[i].next){
        int v=e[i].adj;
        if (vis[v]) continue;
        dfs(v);
        size[u]+=size[v];
    }
    ++cnt[size[u]];
}
 
int main(){
    n=read();
    memset(g,0,sizeof(g));m=1;
    for (int i=1;i<n;++i) AddEdge(read(),read());
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
    dfs(1);
    int ans=0;
    for (int i=1;i<=n;++i){
        for (int j=2;i*j<=n;++j)
            cnt[i]+=cnt[i*j];
        if (i*cnt[i]==n) ++ans;
    }
    printf("%d\n",ans);
    return 0;
}
