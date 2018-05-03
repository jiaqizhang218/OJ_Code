#include<bits/stdc++.h>
#define F(i,j,n) for(int i=j;i<=n;i++)  
#define D(i,j,n) for(int i=j;i>=n;i--)  
#define ll long long  
#define pa pair<int,int>  
#define maxn 70000  
#define maxm 700000  
#define inf 1000000000  
#define f(x,y,z) ((x-1)*n*n+(y-1)*n+z)  
using namespace std;  
struct edge_type  
{  
    int next,to,v;  
}e[maxm];  
int head[maxn],cur[maxn],dis[maxn];  
int n,m,s,t,ans=0,cnt=1;  
char ch;  
inline int read()  
{  
    int x=0,f=1;char ch=getchar();  
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}  
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  
    return x*f;  
}  
inline void add_edge(int x,int y,int v1,int v2)  
{  
    e[++cnt]=(edge_type){head[x],y,v1};head[x]=cnt;  
    e[++cnt]=(edge_type){head[y],x,v2};head[y]=cnt;  
}  
inline bool bfs()  
{  
    queue<int>q;  
    memset(dis,-1,sizeof(dis));  
    dis[s]=0;q.push(s);  
    while (!q.empty())  
    {  
        int tmp=q.front();q.pop();  
        if (tmp==t) return true;  
        for(int i=head[tmp];i;i=e[i].next) if (e[i].v&&dis[e[i].to]==-1)  
        {  
            dis[e[i].to]=dis[tmp]+1;  
            q.push(e[i].to);  
        }  
    }  
    return false;  
}  
inline int dfs(int x,int f)  
{  
    int tmp,sum=0;  
    if (x==t) return f;  
    for(int &i=cur[x];i;i=e[i].next)  
    {  
        int y=e[i].to;  
        if (e[i].v&&dis[y]==dis[x]+1)  
        {  
            tmp=dfs(y,min(f-sum,e[i].v));  
            e[i].v-=tmp;e[i^1].v+=tmp;sum+=tmp;  
            if (sum==f) return sum;  
        }  
    }  
    if (!sum) dis[x]=-1;  
    return sum;  
}  
inline void dinic()  
{  
    while (bfs())  
    {  
        F(i,1,t) cur[i]=head[i];  
        ans+=dfs(s,inf);  
    }  
}  
int main()  
{  
    n=read();  
    s=n*n*n+1;t=s+1;  
    F(i,1,n) F(j,1,n) F(k,1,n)  
    {  
        if (i!=n) add_edge(f(i,j,k),f(i+1,j,k),1,1);  
        if (j!=n) add_edge(f(i,j,k),f(i,j+1,k),1,1);  
        if (k!=n) add_edge(f(i,j,k),f(i,j,k+1),1,1);  
    }  
    F(i,1,n) F(j,1,n) F(k,1,n)  
    {  
        ch=getchar();while (ch!='P'&&ch!='N'&&ch!='?') ch=getchar();  
        if (ch=='P')  
        {  
            if ((i+j+k)%2) add_edge(s,f(i,j,k),inf,0);  
            else add_edge(f(i,j,k),t,inf,0);  
        }  
        else if (ch=='N')  
        {  
            if ((i+j+k)%2) add_edge(f(i,j,k),t,inf,0);  
            else add_edge(s,f(i,j,k),inf,0);  
        }  
    }  
    dinic();  
    printf("%d\n",3*n*n*(n-1)-ans);  
}  
