#include<bits/stdc++.h>
#define ll long long
const int INF = 0x7fffffff;
const double eps = 1e-5;
const int maxn = 300005; 
using namespace std;
int n,a[maxn],ans[maxn];
int cnt,head[maxn],next[maxn<<1],to[maxn<<1];
int sz,now,size[maxn],deep[maxn],fa[maxn],son[maxn],top[maxn],pid[maxn<<1],idp[maxn<<1];
int f[maxn<<2];
int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x * f;
}
void add(int u,int v)
{
	to[++cnt] = v ; next[cnt] = head[u]; head[u] = cnt;
	to[++cnt] = u ; next[cnt] = head[v]; head[v] = cnt;
}
inline void dfs1(int x,int f)
{
	size[x] = 1 ;
	for(int i = head[x] ; i ; i = next[i])
	{
		if(to[i] != f)
		{
			fa[to[i]] = x;
			deep[to[i]] = deep[x] + 1;
			dfs1(to[i],x);
			if(size[to[i]] > size[son[x]]) son[x] = to[i];
			size[x]+=size[to[i]];
		}
	}
}
inline void dfs2(int x,int chain)
{
	pid[x]=++now;idp[now]=x;top[x]=chain;
	if(son[x])	dfs2(son[x],chain);
	for(int i = head[x]; i; i = next[i])
	{
		if(to[i]!=fa[x]&&to[i]!=son[x])
			dfs2(to[i],to[i]);
	}
}
void lazy(int pos)
{
	f[pos<<1] += f[pos];
	f[pos<<1|1] += f[pos];
	f[pos] = 0;
}
inline void change(int pos,int l,int r,int x,int y)
{
	if(x <= l &&  r <= y)
	{
		f[pos]++; return;
	}
	if(f[pos]) lazy(pos);
	int mid = (l + r) >> 1;
	if(y <= mid)
		change(pos<<1,l,mid,x,y);
	else if(x > mid)
		change(pos<<1|1,mid+1,r,x,y);
	else
		change(pos<<1,l,mid,x,y),change(pos<<1|1,mid+1,r,x,y);
}
void ask(int pos,int l,int r)
{
	if(l == r)
	{
		ans[idp[l]] = f[pos]; return;
	}
	if(f[pos]) lazy(pos);
	int mid = (l + r) >> 1;
	ask(pos<<1,l,mid);
	ask(pos<<1|1,mid+1,r);
}
void work(int x,int y)
{
	int f1 = top[x], f2 = top[y];
	
	while(f1 != f2)
	{	
		if(deep[f1]<deep[f2])
			swap(x,y),swap(f1,f2);
		change(1,1,n,pid[f1],pid[x]);
		x = fa[f1];
		f1= top[x];
	}
	if(deep[x] > deep[y])
		swap(x,y);
	change(1,1,n,pid[x],pid[y]); 
}
int main()
{
	n = read();
	for(int i = 1 ; i <= n; i++)
		a[i] = read();
	for(int i = 1,x,y; i < n; i++)
		x = read() , y = read() , add(x,y);
	deep[1]=1;
	dfs1(1,0);
	dfs2(1,1);
	for(int i=2;i<=n;++i)  
        work(a[i],a[i-1]);  
    ask(1,1,n);  
    for(int i=1;i<=n;i++) 
        printf("%d\n",i==a[1]?ans[i]:ans[i]-1);  //除了第一个点其他每个点都有多算 
    return 0;
}
