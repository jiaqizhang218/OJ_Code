#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#define inf 1000000000
#define pa pair<int,int>
#define ll long long 
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,scc,cnt,ans,ind,top;
int last[100005],last2[100005],d[100005];
int low[100005],dfn[100005],q[100005],bl[100005],num[100005];
bool inq[100005],mark[100005];
struct edge{
    int to,next,v;
}e[300005],ed[300005];
void insert(int u,int v)
{
    e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}
void insert2(int u,int v)
{
    d[v]++;
    ed[++cnt].to=v;ed[cnt].next=last2[u];last2[u]=cnt;
}
void tarjan(int x)
{
    low[x]=dfn[x]=++ind;
    inq[x]=1;q[++top]=x;
    for(int i=last[x];i;i=e[i].next)
        if(!dfn[e[i].to])
        {
            tarjan(e[i].to);
            low[x]=min(low[x],low[e[i].to]);
        }
        else if(inq[e[i].to])
            low[x]=min(low[x],dfn[e[i].to]);
    if(low[x]==dfn[x])
    {
        int now=0;scc++;
        while(x!=now)
        {
            now=q[top--];
            bl[now]=scc;
            inq[now]=0;
            num[scc]++;
        } 
    }
}
void rebuild()
{
    cnt=0;
    for(int x=1;x<=n;x++)
    {
        for(int i=last[x];i;i=e[i].next)
            if(bl[x]!=bl[e[i].to]&&!mark[bl[e[i].to]])
                mark[bl[e[i].to]]=1,insert2(bl[x],bl[e[i].to]);
        for(int i=last[x];i;i=e[i].next)
            if(bl[x]!=bl[e[i].to])
                mark[bl[e[i].to]]=0;
    }
}
bool jud(int x)
{
    if(d[x]!=0||num[x]!=1)return 0;
    for(int i=last2[x];i;i=ed[i].next)
        if(d[ed[i].to]==1)return 0;
    return 1;
}
int main()
{
    n=read();m=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read();
        insert(u,v);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])tarjan(i);
    rebuild();
    for(int i=1;i<=scc;i++)
        if(!d[i])ans++;
    for(int i=1;i<=scc;i++)
        if(jud(i))
        {
            ans--;break;
        }
    printf("%.6lf",(double)(n-ans)/n);
    return 0;
}
