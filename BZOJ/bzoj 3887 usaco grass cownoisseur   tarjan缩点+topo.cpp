#include<bits/stdc++.h>
using namespace std;
#define N 100005

int n,m,dfs_clock,scc,ans;
struct hp{int x,y;}e[N];
int dfn[N],low[N],sta[N],tmp,belong[N],size[N],dis[N],_dis[N];
int tot,point[N],nxt[N],v[N];
bool vis[N];
queue <int> q;

void add(int x,int y)
{
    ++tot; nxt[tot]=point[x]; point[x]=tot; v[tot]=y;
}
void tarjan(int x)
{
    dfn[x]=low[x]=++dfs_clock;vis[x]=true;sta[++tmp]=x;
    for (int i=point[x];i;i=nxt[i])
        if (!dfn[v[i]])
        {
            tarjan(v[i]);
            low[x]=min(low[x],low[v[i]]);
        }
        else if (vis[v[i]])
            low[x]=min(low[x],dfn[v[i]]);
    if (dfn[x]==low[x])
    {
        ++scc;int now=0;
        while (now!=x)
        {
            now=sta[tmp--];
            vis[now]=false;
            belong[now]=scc;
            size[scc]++;
        }
    }
}
void build()
{
    tot=0;memset(point,0,sizeof(point));
    for (int i=1;i<=m;++i)
        if (belong[e[i].x]!=belong[e[i].y])
            add(belong[e[i].x],belong[e[i].y]);
}
void rebuild()
{
    tot=0;memset(point,0,sizeof(point));
    for (int i=1;i<=m;++i)
        if (belong[e[i].x]!=belong[e[i].y])
            add(belong[e[i].y],belong[e[i].x]);
}
void spfa(int *dis)
{
    memset(vis,0,sizeof(vis));
    dis[belong[1]]=size[belong[1]];vis[belong[1]]=true;q.push(belong[1]);
    while (!q.empty())
    {
        int now=q.front();q.pop();
        vis[now]=false;
        for (int i=point[now];i;i=nxt[i])
            if (dis[v[i]]<dis[now]+size[v[i]])
            {
                dis[v[i]]=dis[now]+size[v[i]];
                if (!vis[v[i]])
                {
                    vis[v[i]]=true;
                    q.push(v[i]);
                }
            }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;++i)
    {
        scanf("%d%d",&e[i].x,&e[i].y);
        add(e[i].x,e[i].y);
    }

    for (int i=1;i<=n;++i)
        if (!dfn[i]) tarjan(i);
    build();
    spfa(dis);
    rebuild();
    spfa(_dis);
    ans=size[belong[1]];
    for (int i=1;i<=m;++i)
        if (belong[e[i].x]!=belong[e[i].y])
            if (_dis[belong[e[i].x]]&&dis[belong[e[i].y]])
                ans=max(ans,_dis[belong[e[i].x]]+dis[belong[e[i].y]]-size[belong[1]]);
    printf("%d\n",ans);
}
