#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
//#define  getchar() nc()
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int n,cnt,sum,rt,mxdeep;
bool vis[200005];
int t[200005],mx[100005],fa[100005],size[100005],deep[100005],dis[100005];
LL ans,g[200005][2],f[200005][2];
struct edge{int to,nex,v;}e[200005];int fir[100005];
inline void insert(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].nex=fir[u];fir[u]=cnt;e[cnt].v=w;
	e[++cnt].to=u;e[cnt].nex=fir[v];fir[v]=cnt;e[cnt].v=w;
}
inline void getroot(int x,int fa)
{
	size[x]=1;mx[x]=0;
	for(int i=fir[x];i;i=e[i].nex)
	{
		if(e[i].to!=fa&&!vis[e[i].to])
		{
			getroot(e[i].to,x);
			size[x]+=size[e[i].to];
			mx[x]=max(mx[x],size[e[i].to]);
		}
	}
	mx[x]=max(mx[x],sum-size[x]);
	if(mx[x]<mx[rt]) rt=x;
}
inline void dfs(int x,int fa)
{
	mxdeep=max(mxdeep,deep[x]);
	if(t[dis[x]])f[dis[x]][1]++;
	else f[dis[x]][0]++;
	t[dis[x]]++;
	for(int i=fir[x];i;i=e[i].nex)
	{
		if(e[i].to!=fa&&!vis[e[i].to])
		{
			deep[e[i].to]=deep[x]+1;
			dis[e[i].to]=dis[x]+e[i].v;
			dfs(e[i].to,x);
		}
	}
	t[dis[x]]--;
}
inline void calc(int x)
{
	int mx=0;
	vis[x]=1;	g[n][0]=1;
	for(int i=fir[x];i;i=e[i].nex)
	{
		if(!vis[e[i].to])
		{
			dis[e[i].to]=n+e[i].v;
			deep[e[i].to]=1;
			mxdeep=1;dfs(e[i].to,0);mx=max(mx,mxdeep);
			ans+=(g[n][0]-1)*f[n][0];
			for(int j=-mxdeep;j<=mxdeep;j++)
				ans+=g[n-j][1]*f[n+j][1]+g[n-j][0]*f[n+j][1]+g[n-j][1]*f[n+j][0];
			for(int j=n-mxdeep;j<=n+mxdeep;j++)
			{
				g[j][0]+=f[j][0];
				g[j][1]+=f[j][1];
				f[j][0]=f[j][1]=0;
			}
		}
	}
	for(int i=n-mx;i<=n+mx;i++)
		g[i][0]=g[i][1]=0;
	for(int i=fir[x];i;i=e[i].nex)
		if(!vis[e[i].to])
		{
			sum=size[e[i].to];
			rt=0;
			getroot(e[i].to,0);
			calc(rt);
		}
}

int main()
{
	n=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		if(!w)w=-1;
		insert(u,v,w);
	}
	sum=mx[0]=n;
	getroot(1,0);
	calc(rt);
	printf("%lld",ans);
	return 0;
}
