#include<bits/stdc++.h>
#define ll long long
const int INF = 0x7fffffff;
const double eps = 1e-5;
const int maxn = 1e3 + 5;
using namespace std;
int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x * f;
}
int n,q;
int cnt,to[maxn<<1],nxt[maxn<<1],c[maxn<<1],head[maxn];
int deep[maxn],fa[maxn][18],dis[maxn],vis[maxn];
void add(int u,int v,int w)
{
	to[++cnt] = v ; nxt[cnt] = head[u] ; head[u] = cnt; c[cnt] = w;
	to[++cnt] = u ; nxt[cnt] = head[v] ; head[v] = cnt; c[cnt] = w;
}

void dfs(int x,int f)
{
	vis[x]=1;
	for(int i = 1; i <= 9; i++)
	{
		if(deep[x]<(1<<i)) break;
		fa[x][i] = fa[fa[x][i-1]][i-1];
	}
	for(int i = head[x]; i; i = nxt[i])
	{
		if(to[i] != f)
		{
			deep[to[i]] = deep[x]+1;
			dis[to[i]] = dis[x] + c[i];
			fa[to[i]][0]=x;
			dfs(to[i],x);
		}
	}
}
int LCA(int a,int b)
{
	if(deep[b] > deep[a]) swap(a,b);
	int t = deep[a] - deep[b];
	for(int i = 0 ; i <= 9 ; i++)
		if(t&(1<<i)) a = fa[a][i];
	for(int i = 0 ; i <= 9 ; i++)
	{
		while(fa[a][i]!=fa[b][i])
			a=fa[a][i],b=fa[b][i];	
	}
	if(a==b) return a;
	else return fa[a][0];
}
int main()
{
	n = read() , q = read();
	for(int i = 1 ; i < n ; i++)
	{
		int a = read() , b = read() , c = read();
		add(a,b,c);
	}
	dfs(1,0);
	for(int i = 1 ; i <= q ; i++)
	{
		int a = read(), b =read();
		printf("%d\n",dis[a]+dis[b]-(dis[LCA(a,b)]<<1));
	}
	return 0;
}

