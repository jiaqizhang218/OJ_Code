#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int maxn=500010;
struct data {
    int num,x;
    friend bool operator < (const data &x,const data &y) {
        return x.x<y.x;
    }
};
struct edge {int to,next;}e[maxn<<1];
struct E {int u,v;}ee[maxn];
int dis[maxn],head[maxn],dfn[maxn],low[maxn],st[maxn],vis[maxn],pos[maxn],a[maxn],w[maxn],ll[maxn];
int n,m,top,sum,cnt,S,ind,p;
 
void link(int u,int v) {
    e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;
}
void Tarjan(int x) {
    dfn[x]=low[x]=++ind;
    vis[x]=1;
    st[++top]=x;
    for (int i=head[x];i;i=e[i].next) {
        if (!vis[e[i].to]) {
            Tarjan(e[i].to);
            low[x]=min(low[x],low[e[i].to]);
        }
        else if (!pos[e[i].to])
            low[x]=min(low[x],dfn[e[i].to]);
    }
    if (dfn[x]==low[x]) {
        sum++;
        int j;
        do {
            j=st[top--];
            pos[j]=sum;w[sum]+=a[j];
        }while (st[top+1]!=x);
    }
}
void SPFA() {
    queue<int> q;
    for (int i=1;i<=sum;i++) dis[i]=-INF;
    q.push(S);dis[S]=w[S];
    while (q.size()) {
        int x=q.front();q.pop();
        vis[x]=0;
        for (int i=head[x];i;i=e[i].next)
            if (dis[e[i].to]<dis[x]+w[e[i].to]) {
                dis[e[i].to]=dis[x]+w[e[i].to];
                if (!vis[e[i].to]) q.push(e[i].to);
            }
    }
}
int main() {
    n=read(),m=read();
    for (int i=1;i<=m;i++) {
    	ee[i].u=read(),ee[i].v=read();
        link(ee[i].u,ee[i].v);
    }
    for (int i=1;i<=n;i++) a[i]=read();
    S=read(),p=read();
    Tarjan(S);S=pos[S];
    for (int x,i=1;i<=p;i++) {
        x=read();
        ll[pos[x]]=1;
    }
    for (int i=1;i<=n;i++) vis[i]=head[i]=0;
    for (int i=1;i<=m;i++)
        if (pos[ee[i].u]!=pos[ee[i].v]) link(pos[ee[i].u],pos[ee[i].v]);
	SPFA();
    int ans=0;
    for (int i=1;i<=sum;i++) if (ll[i]) ans=max(ans,dis[i]);
    printf("%d",ans);
    return 0;
}
