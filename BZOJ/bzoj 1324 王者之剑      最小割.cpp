#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std;
int n,m,cnt=1,sum,S,T;
int head[10005],dis[10005],cur[10005],q[10005];
int next[1200005],lis[1200005],key[1200005];
int a[105][105];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
inline int read()
{
    int a=0,f=1; char c=getchar();
    while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
    while (c>='0'&&c<='9') {a=a*10+c-'0'; c=getchar();}
    return a*f;
}
inline void insert(int x,int y,int z)
{
    next[++cnt]=head[x];
    head[x]=cnt;
    lis[cnt]=y;
    key[cnt]=z;
}
inline int c(int i,int j)
{
    return (i-1)*m+j;
}
inline bool BFS()
{
    memset(dis,-1,sizeof(dis));
    dis[S]=1; q[1]=S; 
    int t=0,w=1,x;
    while (t<w)
    {
        x=q[++t];
        for (int i=head[x];i;i=next[i])
            if (key[i]&&dis[lis[i]]==-1)
                dis[lis[i]]=dis[x]+1,q[++w]=lis[i];
    }
    return dis[T]!=-1;
}
int find(int x,int flow)
{
    if (x==T) return flow;
    int w,used=0;
    for (int i=cur[x];i;i=next[i])
        if (key[i]&&dis[lis[i]]==dis[x]+1)
        {
            w=find(lis[i],min(flow-used,key[i]));
            key[i]-=w; key[i^1]+=w; used+=w;
            if (key[i]) cur[x]=i;
            if (used==flow) return flow;
        }
    if (!used) dis[x]=-1;
    return used;
}
inline int dinic()
{
    int tmp=0;
    while (BFS()) 
    {
        for (int i=S;i<=T;i++) cur[i]=head[i];
        tmp+=find(S,INF);
    }
    return tmp;
}
int main()
{
    n=read(); m=read(); T=n*m+1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            a[i][j]=read(),sum+=a[i][j];
    for (int i=1;i<=n;i++)
    {
        for (int j=1+(i%2==1);j<=m;j+=2)
        {
            insert(S,c(i,j),a[i][j]);
            insert(c(i,j),S,0);
            for (int k=0;k<4;k++)
            {
                int x=i+dx[k],y=j+dy[k];
                if (x<1||x>n||y<1||y>m) continue;
                insert(c(i,j),c(x,y),INF);
                insert(c(x,y),c(i,j),0);
            }
        }
        for (int j=1+(i%2==0);j<=m;j+=2)
        {
            insert(c(i,j),T,a[i][j]);
            insert(T,c(i,j),0);
        }
    }
    cout << sum-dinic();
    return 0;
}
