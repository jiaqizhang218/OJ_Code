#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 5;
int n,size[maxn],deep[maxn];
int cnt,to[maxn<<1],nxt[maxn<<1],head[maxn];
long long f[maxn],ans;
int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x * f;
}
int ansx;
void addedge(int u,int v)
{
	to[++cnt] = v; nxt[cnt] = head[u] ; head[u] = cnt;
	to[++cnt] = u; nxt[cnt] = head[v] ; head[v] = cnt;
}
void dfs(int x,int fa)
{
	size[x] = 1;
	for(int i = head[x] ; i ; i = nxt[i])
	{
		if(to[i] != fa)
		{
			dfs(to[i],x);
			deep[to[i]] = deep[x] + 1;
			size[x] += size[to[i]];
		}
	}
}
void treedp(int x,int fa)
{
	for(int i = head[x] ; i ; i = nxt[i])
	{
		if(to[i] != fa)
		{
			f[to[i]] = (long long)f[x] - (long long)size[to[i]] + (long long)n - size[to[i]];
			if(ans < f[to[i]])
			ans = f[to[i]],ansx=to[i];
			if(ans == f[to[i]] && ansx > to[i])
				ansx = to[i];
			treedp(to[i],x);
		}
	}
}
int main()
{
	n = read();
	for(int i = 1 ; i < n ; i++)
	{
		int u = read() , v = read();
		addedge(u,v);
	}
	deep[1] = 1;
	dfs(1,0);
	for(int i = 1 ; i <= n ; i++)
	f[1] += (long long)deep[i];
	ans = f[1], ansx = 1;
	treedp(1,0);
	printf("%d",ansx);
}
