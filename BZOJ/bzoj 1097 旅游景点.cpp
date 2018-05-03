#include<bits/stdc++.h>
using namespace std;
const int inf = 100000000;
const int maxn = 1e4 + 5;
int read(){
	int x = 0 ; char ch = getchar();
	while(ch<='9'&&ch>='0')
	{
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return x;
}
int n,m,K,cnt,ed;
int bin[22],a[22];
int dis[22][22],d[maxn<<1],last[maxn<<1];
int f[1046584][22];
bool vis[maxn<<1];
struct data{
	int to,nxt,v;
}e[maxn<<5];
void addedge(int u,int v,int w)
{
	e[++cnt].to = v ; e[cnt].nxt = last[u] ; last[u] = cnt ; e[cnt].v = w;
	e[++cnt].to = u ; e[cnt].nxt = last[v] ; last[v] = cnt ; e[cnt].v = w;
}
void dijkstra(int x)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	for(int i = 1 ; i <= n ; i++)	d[i] = inf;
	memset(vis,0,sizeof(vis));
	d[x] = 0; q.push(make_pair(0,x));
	while(!q.empty())
	{
		int now = q.top().second; q.pop();
		if(vis[now])	continue;
			vis[now] = true;
		for(int i = last[now] ; i ; i = e[i].nxt)		
			if(d[now] + e[i].v < d[e[i].to])
			{
				d[e[i].to] = d[now] + e[i].v;
				q.push(make_pair(d[e[i].to],e[i].to));
			}	  
	}
	for(int i = 1 ; i <= K + 1 ; i++)
		dis[x][i] = d[i];
	dis[x][0] = d[n];//x这个城市到每个城市的最短路 
}
void dp()
{
	for(int now = 0 ; now <= ed ; now++)	
		for(int x = 1 ; x <= K + 1; x++)		
			if(f[now][x] != -1)
			for(int i = 2 ; i <= K + 1; i++)
			{
				int to = (now | bin[i - 2]);
				if((now & a[i]) == a[i]) //即a[i]把 now 已经覆盖了 而不是 now把a[i]覆盖了				
					if(f[to][i] > f[now][x] + dis[x][i] || f[to][i] == -1)					
						f[to][i] = f[now][x] + dis[x][i];								  
			}
}


int main()
{
	bin[0] = 1;	for(int i = 1 ; i < 22 ; i++)	bin[i] = bin[i-1]<<1;
	n = read(); m = read(); K = read();	ed = bin[K] - 1; //ed就能表示所有状态
	for(int i = 1 ; i <= m ; i++)
	{
		int u = read() , v = read() , w = read();
		addedge(u,v,w);
	 } 
	 for(int i = 1 ; i <= K + 1 ; i++)
	 	dijkstra(i);
	int x = read();
	for(int i = 1 ;i <= x ;i++)
	{
		int u = read() , v = read();
		a[v] += bin[u-2];		// 2的 u-2次方？  什么意思啊？ 
	}
	memset(f,-1,sizeof(f));
	f[0][1] = 0;
	dp();
	int ans = inf;
	for(int i = 1 ; i <= K+1 ; i++)
		if(f[ed][i] != -1)	ans = min(ans,f[ed][i]+dis[i][0]);
	printf("%d",ans);
	return 0;
}
