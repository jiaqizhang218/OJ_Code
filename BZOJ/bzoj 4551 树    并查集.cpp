#include<bits/stdc++.h>
const int N = 100010;
using namespace std;
struct yts { int x,t,ne;} e[N<<1];
struct QQ { int ty,x;} q[N];
int num,father[N],fa[N],v[N],c[N],ans[N];
char st[5];
void put(int x,int y)
{	e[++num].x=x; e[num].t=y;
	e[num].ne=v[x]; v[x]=num;
}
int find(int x) { return father[x]==x?x:father[x]=find(father[x]);}
void dfs(int x)
{
	if (c[x]) father[x]=x; else father[x]=fa[x];
	for (int i=v[x];i;i=e[i].ne)
	{
		int y=e[i].t;
		if (y!=fa[x]) { fa[y]=x; dfs(y);}
	}
}
	
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		put(x,y); put(y,x);
	}
	c[1]=1;
	for (int i=1;i<=m;i++)
	{
		scanf("%s%d",st,&q[i].x);
		if (st[0]=='C') c[q[i].x]++,q[i].ty=1;
	}
	dfs(1);
	for (int i=m;i;i--)
	{
		int x=q[i].x;
		if (q[i].ty)
		{
			c[x]--; if (c[x]==0) father[x]=fa[x];
		}
		else ans[i]=find(x);
	}
	for (int i=1;i<=m;i++)
	  if (ans[i]) printf("%d\n",ans[i]);
	return 0;
}
