#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
const int N = 110;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int tree[N],l[N],r[N];
int a[N],nxt[N],p[N],val[N],tot;
int n,m,num[N];
int dis[N],f[N][60][N];
inline void add(int x,int y,int v)
{
	tot++; a[tot]=y; nxt[tot]=p[x]; p[x]=tot; val[tot]=v;
}
inline void dfs(int x,int fa)
{
	for(int i=p[x];i!=-1;i=nxt[i])
	{
		if(a[i]!=fa)
		{
			dis[a[i]]=dis[x]+val[i];
			dfs(a[i],x);
		}
	}
}
inline int dp(int i,int j,int k)
{
	if(f[i][j][k]!=-1)	return f[i][j][k];
	f[i][j][k]=INF;
	for(int h=0;h<=j;h++)
	{
		int ans=0;
		if(l[i])	ans+=dp(l[i],h,k);
		if(r[i])	ans+=dp(r[i],j-h,k);
		f[i][j][k]=min(f[i][j][k],ans+(dis[i]-dis[k])*num[i]);
		if(h<j)
		{
			ans=0;
			if(l[i])	ans+=dp(l[i],h,i);
			if(r[i])	ans+=dp(r[i],j-h-1,k);
			f[i][j][k]=min(f[i][j][k],ans); 
		}
	}
	return f[i][j][k];		
} 
int main()
{
	memset(p,-1,sizeof p);
	memset(nxt,-1,sizeof nxt);
	memset(tree,-1,sizeof tree);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		int y,z;
		num[i]=read(),y=read(),z=read();
		if(tree[y]==-1)	l[y]=i,tree[y]=i;
		else 	r[tree[y]]=i;tree[y]=i;
		add(y,i,z);
	}
	dfs(0,0);
	memset(f,-1,sizeof f);
	printf("%d\n",dp(0,m,0));
	return 0;
}
