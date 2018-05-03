#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define ll long long
#define inf 0x7ffffff
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int F,n,m,W,cnt;
int head[505],dis[505];
bool flag,mark[505];
struct data{int to,next,v;}e[100001];
inline void ins(int u,int v,int w)
{e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;e[cnt].v=w;}
inline void insert(int u,int v,int w)
{ins(u,v,w);ins(v,u,w);}
inline void spfa(int x)
{
     mark[x]=1;
     for(int i=head[x];i;i=e[i].next)
         if(e[i].v+dis[x]<dis[e[i].to])
         {
              if(mark[e[i].to]){flag=1;return;}
              else
              {
                   dis[e[i].to]=e[i].v+dis[x];
                   spfa(e[i].to);
              }
         }
     mark[x]=0;
}
bool jud()
{
     for(int i=1;i<=n;i++){dis[i]=inf;mark[i]=0;}
     flag=0;
     for(int i=1;i<=n;i++)
         {dis[i]=0;spfa(i);if(flag)return 1;}
     return 0;
}
int main()
{
    F=read();
    while(F--)
    {
        cnt=0;
        memset(head,0,sizeof(head));
        n=read(),m=read(),W=read();
        int u,v,w;
        for(int i=1;i<=m;i++)
            u=read(),v=read(),w=read(),insert(u,v,w);
        for(int i=1;i<=W;i++)
            u=read(),v=read(),w=read(),ins(u,v,-w);
        if(jud())printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
