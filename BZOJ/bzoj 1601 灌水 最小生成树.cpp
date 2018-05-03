#include<iostream>  
#include<algorithm>  
#include<cmath>  
#include<cstring>  
#include<cstdio>    
using namespace std;
const int maxn = 300 + 5;
const int INF = 0x7fffffff;
int ans,cnt,t,n,f[maxn];
struct Edge{
	int u,v,w;
	bool operator <(const Edge& rhs)const {
		return w < rhs.w;
	}
}e[100001];
void insert(int u,int v,int w)
{
	e[++cnt].u=u;e[cnt].v=v;e[cnt].w=w;
}
int findfa(int x)
{
	return x==f[x]?x:f[x]=findfa(f[x]);
}
void init ()
{
	cin>>n;
	for(int i = 1 ; i <= n ; i++)
	{
		f[i]=i;
		cin>>t;
		insert(0,i,t);
	}
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
		{
			cin>>t;
			if(i!=j) insert(i,j,t);
		}
	sort(e,e+cnt);
}
void kruskal()
{
	for(int i = 1 ; i <= cnt ; i++)
	{
		int u1 = findfa(e[i].u); int v1 = findfa(e[i].v); int w1 = e[i].w;
		if(u1!=v1)
		{
			f[u1] = v1;
			ans += w1; 
		}
	}
	
}
int main()
{
	ios::sync_with_stdio(false);
	init();
	kruskal();	
	printf("%d",ans);
	return 0;		
}
