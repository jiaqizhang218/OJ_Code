#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
const int inf = 0x7fffffff;
using namespace std;

bool tag[21],a[21][110],vis[21];
int head[21],to[1010],next[1010],len[1010],dis[21],q[21];
int f[110][110],dp[110];
int n,m,num,k,Day,cnt;

void addedge(int x,int y,int z)
{
	to[++num]=y;len[num]=z;next[num]=head[x];head[x]=num;   //前向星... 
}

void spfa()
{
	for (int i=2;i<=n;i++) dis[i]=inf;
	dis[1]=0;
	int l=0,r=1;
	q[1]=1;vis[1]=1;
	while (l!=r)
	{
		l++;if (l==21) l=0;
		int x=q[l];
		for (int p=head[x];p;p=next[p])
		  if (dis[x]+len[p]<dis[to[p]])
		  {
		  	dis[to[p]]=dis[x]+len[p];
		  	if (!vis[to[p]] && !tag[to[p]])
		  	{
		  		if (++r==21) r=0;
		  		q[r]=to[p]; vis[to[p]]=1;
		  	}
		  }
		vis[x]=0;
	}
}

int main()
{
	scanf("%d%d%d%d",&Day,&n,&k,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z);addedge(y,x,z);
	}
	
	scanf("%d",&cnt);
	for (int i=1;i<=cnt;i++)
	{
		int x,l,r;
		scanf("%d%d%d",&x,&l,&r);
		for (int j=l;j<=r;j++) a[x][j]=1;
	}
	
	for (int i=1;i<=Day;i++)
	{
		memset(tag,0,sizeof(tag));
		for (int j=i;j<=Day;j++)
		{
			for (int k=1;k<=n;k++) tag[k]|=a[k][j];  //若tag数组为1 则不能用 
			spfa();
			f[i][j]=dis[n];
		}
	}
	

	dp[0]=-k;
	for (int i=1;i<=Day;i++)
	{
		dp[i]=inf;
		for (int j=0;j<i;j++) if (f[j+1][i]!=inf) dp[i]=min(dp[i],dp[j]+f[j+1][i]*(i-j)+k);
	}
	printf("%d\n",dp[Day]);
	return 0;
}

