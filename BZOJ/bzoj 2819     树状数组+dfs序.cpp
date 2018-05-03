#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='0')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int bin[20];
int n,m,cnt;
int t[500005];
int ind,l[500005],r[500005],val[500005];
int last[500005],deep[500005],fa[500005][20];
struct edge{
	int to,next;
}e[1000005];
void insert(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}
void modify(int x,int val)
{
	for(int i=x;i<=n;i+=i&-i)
		t[i]^=val;
}
int query(int x)
{
	int tmp=0;
	for(int i=x;i;i-=i&-i)
		tmp^=t[i];
	return tmp;
}
void dfs(int x)
{
	for(int i=1;i<=18;i++)
		if(deep[x]>=bin[i])
			fa[x][i]=fa[fa[x][i-1]][i-1];
		else break;
	l[x]=++ind;
	for(int i=last[x];i;i=e[i].next)
		if(e[i].to!=fa[x][0])
		{
			deep[e[i].to]=deep[x]+1;
			fa[e[i].to][0]=x;
			dfs(e[i].to);
		}
	r[x]=ind;
}
int lca(int x,int y)
{
	if(deep[x]<deep[y])swap(x,y);
	int t=deep[x]-deep[y];
	for(int i=0;i<=18;i++)
		if(bin[i]&t)x=fa[x][i];
	for(int i=18;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
int main()
{
	bin[0]=1;for(int i=1;i<20;i++)bin[i]=bin[i-1]<<1;
	n=read();
	for(int i=1;i<=n;i++)val[i]=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		insert(u,v);
	}
	dfs(1);
	for(int i=1;i<=n;i++)
		modify(l[i],val[i]),modify(r[i]+1,val[i]);
	m=read();
	while(m--)
	{
		char ch[2];
		scanf("%s",ch);
		int x=read(),y=read();
		if(ch[0]=='Q')
		{
			int t=lca(x,y);
			int res=query(l[x])^query(l[y])^val[t];
			if(res)puts("Yes");
			else puts("No");
		}
		else 
		{
			modify(l[x],val[x]);modify(r[x]+1,val[x]);
			val[x]=y;
			modify(l[x],y);modify(r[x]+1,y);
		}
	}
	return 0;
}
