#include<cstdio>  
#include<cstring>  
#include<cstdlib>  
#include<cmath>  
#include<algorithm>  
#include<iostream>  
#define maxn 510  
#define maxm 20010  
#define inf 1000000000  
  
using namespace std;  
  
struct yts  
{  
    int x,y;  
}e[2010];  
  
int head[maxn],to[maxm],c[maxm],next[maxm],q[maxn],d[maxn];  
int a[maxn];  
int num,n,m,s,t;  
long long ans1,ans2;  
  
void addedge(int x,int y,int z)  
{  
    num++;to[num]=y;c[num]=z;next[num]=head[x];head[x]=num;  
    num++;to[num]=x;c[num]=0;next[num]=head[y];head[y]=num;  
}  
  
void build(int k)  
{  
    num=1;  
    memset(head,0,sizeof head);  
    s=0;t=n+1;  
    for (int i=1;i<=n;i++)  
      if (a[i]>=0)  
      {  
        if (a[i]&(1<<k))  
        {  
            addedge(i,t,inf);addedge(s,i,1);  
        }  
        else addedge(s,i,inf);  
      }  
      else addedge(s,i,1);  
    for (int i=1;i<=m;i++) addedge(e[i].x,e[i].y,10000),addedge(e[i].y,e[i].x,10000);  
}  
  
inline bool bfs()  
{  
    memset(d,-1,sizeof d);  
    int l=0,r=1;  
    q[1]=s;d[s]=0;  
    while (l<r)  
    {  
        int x=q[++l];  
        for (int p=head[x];p;p=next[p])  
          if (c[p] && d[to[p]]==-1)  
          {  
            d[to[p]]=d[x]+1;  
            q[++r]=to[p];  
          }  
    }  
    if (d[t]==-1) return false;
	return true;  
}  
  
inline int find(int x,int low)  
{  
    if (x==t || low==0) return low;  
    int totflow=0;  
    for (int p=head[x];p;p=next[p])  
      if (c[p] && d[to[p]]==d[x]+1)  
      {  
        int a=find(to[p],min(c[p],low));  
        c[p]-=a;c[p^1]+=a;  
        low-=a;totflow+=a;  
        if (low==0) return totflow;  
      }  
    if (low) d[x]=-1;  
    return totflow;  
}  
  
int Dinic()  
{  
    int ans=0;  
    while (bfs()) ans+=find(s,inf);  
    return ans;  
}  
  
int main()  
{  
    scanf("%d%d",&n,&m);  
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);  
    for (int i=1;i<=m;i++) scanf("%d%d",&e[i].x,&e[i].y);  
    for (int k=0;k<=30;k++)  
    {  
        build(k);  
        int sum=Dinic();  
        int sum1=sum/10000,sum2=sum%10000;  
        ans1+=(long long)sum1*(long long)(1<<k);  
        ans2+=(long long)sum2*(long long)(1<<k);  
    }  
    printf("%lld\n%lld\n",ans1,ans2);  
    return 0;  
}  
