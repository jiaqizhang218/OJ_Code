#include<bits/stdc++.h>
#define inf 1000000000
#define pa pair<int,int>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,T,cnt,tot;
bool vis[10005];
int u[400005],v[400005],w[400005];
int last[10005],p[10005],dis[10005];
struct data{int to,next,v;}e[400005];
inline void insert(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;e[cnt].v=w;
}
inline void ins(int a,int b,int c)
{
	tot++;
	u[tot]=a;v[tot]=b;w[tot]=c;
}
void dijkstra()
{
	memset(vis,0,sizeof(vis));
	priority_queue<pa,vector<pa>,greater<pa> > q;
	for(int i=1;i<=T;i++)dis[i]=inf;
	dis[1]=0;q.push(make_pair(0,1));
	while(!q.empty())
	{
		int now=q.top().second;q.pop();
		if(vis[now])continue;vis[now]=1;
		for(int i=last[now];i;i=e[i].next)
			if(dis[now]+e[i].v<dis[e[i].to]&&!vis[e[i].to])
			{
				dis[e[i].to]=dis[now]+e[i].v;
				if(now==1)p[e[i].to]=e[i].to;
				else p[e[i].to]=p[now];
				q.push(make_pair(dis[e[i].to],e[i].to));
			}
	}
}
void rebuild()
{
	for(int x=1;x<=n;x++)
		for(int i=last[x];i;i=e[i].next)
		{
			if(e[i].to==1)
			{
				if(p[x]!=x)ins(1,T,dis[x]+e[i].v);
				else ins(x,T,e[i].v);
 			}
			if(x==1)
			{
				if(p[e[i].to]!=e[i].to)
					ins(1,e[i].to,e[i].v);
			}
			if(e[i].to!=1&&x!=1)
			{
				if(p[x]!=p[e[i].to])ins(1,e[i].to,dis[x]+e[i].v);
				else ins(x,e[i].to,e[i].v);
			}
		}
	cnt=0;
	memset(last,0,sizeof(last));
	for(int i=1;i<=tot;i++)
		insert(u[i],v[i],w[i]);
}
int main()
{
	n=read();m=read();T=n;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w1=read(),w2=read();
		insert(u,v,w1);
		insert(v,u,w2);
	}
	dijkstra();
	T++;
	rebuild();
	dijkstra();
	if(dis[T]==inf){puts("-1");return 0;}
	else printf("%d\n",dis[T]);
	return 0;
}
