#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>
#include<queue>
using namespace std;
const int INF = 0x7fffffff;
const int maxn = 100000 + 5;
struct Edge{
	int u,v,w;
	bool operator <(const Edge& rhs)const {
		return w > rhs.w;
	}
};
priority_queue <Edge> q;
int ans=INF,n,m,c[maxn],f[maxn];
int findfather(int x)
{
	return x == f[x] ? x : f[x] = findfather(f[x]);
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; i++)
	scanf("%d",&c[i]),f[i]=i,ans=min(ans,c[i]);
	for(int i = 1 ; i <= m ; i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		q.push((Edge){x,y,(z<<1)+c[x]+c[y]});
	}
}
int main()
{
	init();
	int cnt = 0;
	while (true)
	{	
		Edge e = q.top(); q.pop();
		int u1 = findfather(e.u),v1 = findfather(e.v);
		if(u1 != v1)
		{
			f[u1] = v1;
			cnt++;
			ans += e.w;
		}
		if(cnt == n-1) break;
	}
	cout<<ans;
	return 0;
} 
