#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int N = 500015;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int m,now,deep[N],point[N],next[N<<1],cnt,f[N],ff,fa[N][20],n,a[N],x,y;
LL ans;
struct ppp{
	int st,en;
}e[N<<1];
bool vis[N];
inline void add(int x,int y) {
	next[++cnt]=point[x];point[x]=cnt;e[cnt].en=y;
}
inline int findfa(int x) {
	return x==f[x]?x:f[x]=findfa(f[x]);
}
inline void dfs(int x) {
	for(int i=1;(1<<i)<=deep[x];i++) {
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	if(vis[x])	f[x]=fa[x][0];	else f[x]=x;
	for(int i=point[x];i;i=next[i]) {
		if(e[i].en!=fa[x][0]) {
			deep[e[i].en]=deep[x]+1;
			fa[e[i].en][0]=x;
			dfs(e[i].en);
		}
	} 
}
inline int lca(int x,int y) {
	if(deep[x]<deep[y])	swap(x,y);
	int t=deep[x]-deep[y];
	for(int i=0;i<=17;i++)	if((1<<i)&t)	x=fa[x][i];
	for(int i=17;i>=0;i--)	
		if(fa[x][i]!=fa[y][i])	x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
inline void up(int x) {
	if(deep[x]<deep[ff])	return;
	vis[x]=true; f[x]=fa[x][0];
	up(findfa(fa[x][0])); 
}
int main()
{
	n=read(),m=read(),now=read();
	memset(vis,1,sizeof vis);
	for(int i=1;i<n;i++)	{
		x=read(),y=read();
		add(x,y),add(y,x);
	}
	for(int i=1;i<=m;i++)	a[i]=read(),vis[a[i]]=0;
	dfs(1);
	deep[0]=-1;
	for(int i=1;i<=m;i++) {
		if(!vis[a[i]]) {
			ff=lca(a[i],now);
			ans+=(long long)(deep[a[i]]+deep[now]-2*deep[ff]);
			up(a[i]);
			up(now);
			now=a[i];
		}
	}
	cout<<ans;
}
