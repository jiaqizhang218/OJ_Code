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
const int N = 200005;
int n,k,x,y,z,sum,root,cnt;
int tot,point[N],nxt[N<<1],v[N<<1],c[N<<1];
int size[N],big[N],dis[N],deep[N],ans[N];
bool vis[N]; 
struct hp {
	int dis,deep;
}pt[N];
inline void AE(int x,int y,int z)
{
	nxt[++tot]=point[x],point[x]=tot,v[tot]=y,c[tot]=z;
	nxt[++tot]=point[y],point[y]=tot,v[tot]=x,c[tot]=z;
}
inline void getroot(int x,int fa)
{
	size[x]=1,big[x]=0;
	for(int i=point[x];i;i=nxt[i])
	{
		if(v[i]!=fa&&!vis[v[i]])
		{
			getroot(v[i],x);
			size[x]+=size[v[i]];
			big[x]=max(big[x],size[v[i]]);
		}
	
	}
	big[x]=max(big[x],sum-size[x]);
	if(big[x]<big[root]) root=x;
}
inline void getdeep(int x,int fa)
{
	pt[++cnt].dis=dis[x],pt[cnt].deep=deep[x];
	for(int i=point[x];i;i=nxt[i])
	{
		if(v[i]!=fa&&!vis[v[i]])
		{
			dis[v[i]]=dis[x]+c[i];
			deep[v[i]]=deep[x]+1;
			getdeep(v[i],x);
		}
	}
}
int cmp(hp a,hp b)
{
	return a.dis<b.dis;
}
inline void calc(int x,int nowdis,int nowdeep,int add)
{
	dis[x]=nowdis; deep[x]=nowdeep; cnt=0;
	getdeep(x,0);
	sort(pt+1,pt+cnt+1,cmp);
	for(int l=1,r=cnt;l<=r;l++)
	{
		while(l<r&&pt[l].dis+pt[r].dis>k)	r--;
		for(int i=r;pt[l].dis+pt[i].dis==k;i--)	ans[pt[l].deep+pt[i].deep]+=add;
	}
}
inline void dfs(int x)
{
	calc(x,0,0,1);
	vis[x]=true;
	for(int i=point[x];i;i=nxt[i])
	{
		if(!vis[v[i]])
		{
			calc(v[i],c[i],1,-1);
			sum=size[v[i]];	root=0;
			getroot(v[i],0);
			dfs(root);
		}
	}
}
int main()
{
	n=read(),k=read();
	for(int i=1;i<n;i++)
	{
		x=read()+1,y=read()+1,z=read();
		AE(x,y,z);
	}
	sum=n;root=0;big[0]=INF;
	getroot(1,0);
	dfs(root);
	for(int i=1;i<=n;i++)
	{
		if(ans[i])
		{
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}
