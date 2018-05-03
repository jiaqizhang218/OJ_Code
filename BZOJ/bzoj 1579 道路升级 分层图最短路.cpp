#include<bits/stdc++.h>
#define ll long long
#define N 10005
#define M 100005
const int INF = 0x7fffffff;
const double eps = 1e-5;
const int maxn = 50000 + 5; 
using namespace std;
int n,m,K,cnt,k;
int to[M],head[N],next[M],w[M];
int dis[N][25],vis[N][25];

void Add(int u,int y,int z)
{
	to[++cnt] = y; next[cnt] = head[u];head[u] = cnt;w[cnt] =z;
	to[++cnt] = u; next[cnt] = head[y];head[y] = cnt;w[cnt] =z;
}
int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x * f;
}
void dijkstra()
{
	priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	memset(dis,127/3,sizeof(dis));
	dis[1][0] = 0;
	q.push(make_pair(0,1));
	while(!q.empty())
	{
		int now = q.top().second; q.pop();
		int z = now / (n + 1); now = now % (n + 1); // z是跳跃次数 now是所在点 太机智了 这样子来存压缩状态 
		if(vis[now][z]) continue;
		vis[now][z] = 1;
		for(int i = head[now] , y ; i ; i = next[i])
		{
			if(dis[y = to[i]][z] > dis[now][z] + w[i])
			{
				dis[y][z] = dis[now][z] + w[i];
				q.push(make_pair(dis[y][z],z*(n+1)+y));
			}
			if( z == k) continue; //跳跃次数用光了 
			if(dis[to[i]][z+1]>dis[now][z])
			{
				dis[to[i]][z+1]=dis[now][z];
				q.push(make_pair(dis[to[i]][z+1],(z+1)*(n+1)+y));
			}
		}
	}
}
int main()
{
	n = read(), m = read(), k = read();
	for(int i = 1 ; i <= m ; i++)
	{
		int x = read(),y = read(),z = read();
		Add(x,y,z);
	}
	dijkstra();
	printf("%d",dis[n][k]);
	return 0;
}

