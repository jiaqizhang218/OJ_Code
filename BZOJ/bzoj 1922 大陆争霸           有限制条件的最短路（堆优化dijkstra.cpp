#include<bits/stdc++.h>
typedef long long LL;
#define pa pair<int,int>
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int N = 3005;
int n,m,cnt,last[N],d1[N],d2[N],d[N];
int l[N],a[N][N];
bool vis[N];
struct edge{
	int to,next,v;
}e[70005];
inline void insert(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;e[cnt].v=w;
}
priority_queue<pa,vector<pa>,greater<pa> >q;
inline void dijkstra()
{
	memset(d1,127/3,sizeof(d1));
	q.push(make_pair(0,1));
	d1[1]=0;
	while(!q.empty())
	{
		int now=q.top().second;q.pop();
		if(vis[now])continue;vis[now]=1;
		int mx=max(d1[now],d2[now]);
	    for(int i=last[now];i;i=e[i].next)
			if(mx+e[i].v<d1[e[i].to])
			{
				d1[e[i].to]=mx+e[i].v;
				int tmp=max(d1[e[i].to],d2[e[i].to]);
				if(!d[e[i].to])q.push(make_pair(tmp,e[i].to));
			}
		for(int i=1;i<=l[now];i++)
		{
			int t=a[now][i];
			d[t]--;d2[t]=max(d2[t],mx);
			int tmp=max(d1[t],d2[t]);
			if(!d[t])q.push(make_pair(tmp,t));
		}
	}
	printf("%d\n",max(d1[n],d2[n]));
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		if(u!=v) insert(u,v,w);
	}
	for(int i=1;i<=n;i++)
	{
		d[i]=read();
		for(int j=1;j<=d[i];j++)
		{
			int u=read();
			a[u][++l[u]]=i;
		}
	}
	dijkstra();
	return 0;
}
