#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int N = 15100;
struct edge{
	int x,y,f;
	bool operator <(const edge& rhs)const {
		return f<rhs.f;
	}
}edges[N<<1];
struct abcd{
	int to,f,next;
}table[N<<1];
int head[N],tot,n,m,k;
int fa[N][20],f_max[N][20],dpt[N];
int belong[N];
inline int get(int x)
{
	if(!belong[x]||belong[x]==x)
		return belong[x]=x;
	return belong[x]=get(belong[x]);
}
inline void add(int x,int y,int z)
{
	table[++tot].to=y;
	table[tot].f=z;
	table[tot].next=head[x];
	head[x]=tot;
}
inline void dfs(int x)
{
	int i;
	dpt[x]=dpt[fa[x][0]]+1;
	for(i=head[x];i;i=table[i].next)
	{
		if(table[i].to==fa[x][0])
			continue;
		fa[table[i].to][0]=x;
		f_max[table[i].to][0]=table[i].f;
		dfs(table[i].to);
	}
}
inline int Query(int x,int y)
{
	int j,re=0;
	if(dpt[x]<dpt[y])	swap(x,y);
	for(j=14;~j;j--)
		if(dpt[fa[x][j]]>=dpt[y])
			re=max(re,f_max[x][j]),x=fa[x][j];
	if(x==y)
		return re;
	for(j=14;~j;j--)
		if(fa[x][j]!=fa[y][j])
		{
			re=max(re,f_max[x][j]);
			re=max(re,f_max[y][j]);
			x=fa[x][j]; y=fa[y][j];
		}
	re=max(re,f_max[x][0]);
	re=max(re,f_max[y][0]);
	return re;
}
int main()
{
	int i,j,x,y;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
		edges[i].x=read(),edges[i].y=read(),edges[i].f=read();
	sort(edges+1,edges+1+m);
	for(i=1;i<=m;i++)
	{
		int fx=get(edges[i].x),fy=get(edges[i].y);
		if(fx!=fy)
		{
			belong[fx]=fy;
			add(edges[i].x,edges[i].y,edges[i].f);
			add(edges[i].y,edges[i].x,edges[i].f);
		}
	}
	dfs(1);
	for(j=1;j<=14;j++)
		for(i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1],f_max[i][j]=max(f_max[i][j-1],f_max[fa[i][j-1]][j-1]);
	for(i=1;i<=k;i++)
	{
		x=read(),y=read();
		printf("%d\n",Query(x,y));
	}
	return 0;
}
