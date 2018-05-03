#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=100005;

int n,last[N],size[N],son[N],cnt,val[N],a[N],ans[N],c[N];
struct edge{int to,next;}e[N];

int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

void addedge(int u,int v)
{
    e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}

void dfs(int x)
{
    size[x]=1;
    for (int i=last[x];i;i=e[i].next) dfs(e[i].to),size[x]+=size[e[i].to];
    for (int i=last[x];i;i=e[i].next) if (size[e[i].to]>size[son[x]]) son[x]=e[i].to;
}

void ins(int x,int y)
{
    while (x<=n) c[x]+=y,x+=x&(-x);
}

int find(int x)
{
    int ans=0;
    while (x) ans+=c[x],x-=x&(-x);
    return ans;
}

void work(int x,int y)
{
    ins(val[x],y);
    for (int i=last[x];i;i=e[i].next) work(e[i].to,y);
}

void solve(int x)
{
    for (int i=last[x];i;i=e[i].next) if (e[i].to!=son[x]) solve(e[i].to),work(e[i].to,-1);
    if (son[x]) solve(son[x]);
    ins(val[x],1);
    for (int i=last[x];i;i=e[i].next) if (e[i].to!=son[x]) work(e[i].to,1);
    ans[x]=find(n)-find(val[x]);
}

int main()
{
    n=read();
    for (int i=1;i<=n;i++) val[i]=read(),a[i]=val[i];
    sort(a+1,a+n+1);
    int a1=unique(a+1,a+n+1)-a-1;
    for (int i=1;i<=n;i++) val[i]=lower_bound(a+1,a+a1+1,val[i])-a;
    for (int i=2;i<=n;i++)
    {
        int x=read();
        addedge(x,i);
    }
    dfs(1);
    solve(1);
    for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}
