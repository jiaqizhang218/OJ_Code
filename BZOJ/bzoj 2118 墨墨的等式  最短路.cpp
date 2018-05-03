#include<bits/stdc++.h>
typedef long long LL;
#define pa pair<LL,int>
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
int n , cnt , a[15] , last[500005];
LL dis[500005];
LL L , R , ans;
bool vis[500005];
struct Edge{
	int to,next,v;
}e[5000005];
priority_queue <pa,vector<pa>,greater<pa> > q;
inline void insert(int u,int v,int w)
{
	e[++cnt] = (Edge){v,last[u],w}; last[u] = cnt;
}
void dijkstra()
{
	for(int i = 0 ; i < a[1] ; i++) dis[i] = 1LL * 1e60 ;  dis[0] = 0;
	q.push(make_pair(0,0));
	while(!q.empty())
	{
		int now = q.top().second;	q.pop();
		if(vis[now]) 	continue; vis[now] = true;
		for(int i = last[now] ; i ; i = e[i].next)
			if(dis[now] + e[i].v < dis[e[i].to])
			{
				dis[e[i].to] = dis[now] + e[i].v;
				q.push(make_pair(dis[e[i].to],e[i].to));
			 } 
	}
}
int main()
{
	n = read() , L = read() , R = read();
	for(int i = 1 ; i <= n ; i ++)	a[i] = read();
	sort(a+1,a+1+n);
	for(int i = 0 ; i < a[1] ; i++)
		for(int j = 2 ; j <= n ; j++)
			insert(i,(a[j]+i)%a[1],a[j]);
	dijkstra();
	for(int i = 0 ; i < a[1] ; i++)
		if(dis[i] <= R)
		{
			LL l=max(0LL,(L-dis[i])/a[1]);
			if(l*a[1]+dis[i]<L)l++;
			LL r=(R-dis[i])/a[1];
			if(r*a[1]+dis[i]>R)r--;
			ans+=r-l+1;
		}
	cout<<ans;
}


