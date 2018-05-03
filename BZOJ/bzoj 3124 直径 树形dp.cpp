#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 200005;

int n,x,y,l,r,pt; ll z,Max,Maxn;
int tot,head[N],nxt[N*2],to[N*2]; ll c[N*2];
int father[N],chain[N]; ll dis[N],ddis[N];
bool vis[N];

void addeage(int u,int v,ll z)
{
	to[++tot] = v ; nxt[tot] = head[u] ; head[u] = tot ; c[tot] = z;
	to[++tot] = u ; nxt[tot] = head[v] ; head[v] = tot ; c[tot] = z;
}

void dfs(int x,int fa,int s)
{
	if(!s)
	{
		if(dis[x] > Max)
		{
			Max = dis[x];
			pt = x;
		}
		father[x] = fa;
		for(int i = head[x] ; i ; i = nxt[i])
			if(to[i] != fa)
			{
				dis[to[i]] = dis[x] + c[i];
				dfs(to[i],x,0);
			}
		
	}
	else
	{
		vis [x] = true ;
		Maxn = max(Maxn , ddis[x]);
		for(int i = head[x] ; i ; i = nxt[i])
		{
			if(to[i] != fa && !vis[to[i]])
			{
				ddis[to[i]] = ddis[x] + c[i];
				dfs(to[i],x,1);
			}	
		}
	}
}

void Chain(int x)
{
	while (x)
	{
		vis[x] = true;
		chain[++chain[0]] = x;
		x = father [x];
	}
}

void init()
{
	scanf("%d",&n);
	for(int i = 1 ; i < n ; i++)
	scanf("%d%d%lld",&x,&y,&z),addeage(x,y,z);
}

int main()
{
	init();
	dfs(1,0,0);
	memset(dis,0,sizeof(dis)); Max = 0; dfs(pt,0,0);
	printf("%lld\n",Max);
	Chain(pt);
	r = chain[0] ; l = 1;
	for(int i = chain[0] ; i ; --i)
	{
		Maxn = 0 ; dfs(chain[i],0,1);
		if(!Maxn) continue;
		if(Maxn == dis[chain[i]]) r = i;
		if(Maxn == Max - dis[chain[i]]) {l = i ; break;}
	}
	printf("%d\n",r-l);	
}
