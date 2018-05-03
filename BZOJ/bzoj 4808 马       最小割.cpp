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
#define num(A,B)	((A)*m-m+B)
#define ok(A,B)		(A>=1&&A<=n&&B>=1&&B<=m&&!mp[A][B])
int n,m,cnt,tot,ans;
int dx[]={-1,-1,1,1,-2,-2,2,2},dy[]={2,-2,2,-2,1,-1,1,-1};
int d[40010],next[500050],val[500050],head[40010],to[500010],mp[210][210];
queue<int>q;
inline void add(int a,int b,int c)
{
	to[cnt]=b;val[cnt]=c,next[cnt]=head[a],head[a]=cnt++;
	to[cnt]=a,val[cnt]=0,next[cnt]=head[b],head[b]=cnt++;
}
inline int dfs(int x,int mf)
{
	if(x==n*m+1)	return mf;
	int i,k,temp=mf;
	for(i=head[x];i!=-1;i=next[i])
	{
		if(d[to[i]]==d[x]+1&&val[i])
		{
			k=dfs(to[i],min(mf,val[i]));
			if(!k)	d[to[i]]=0;
			val[i]-=k,val[i^1]+=k,temp-=k;
			if(!temp)	break;
		}
	 } 
	 return mf-temp;
}
inline int bfs()
{
	memset(d,0,sizeof d);
	while(!q.empty())
		q.pop();
	int i,u;
	d[0]=1,q.push(0);
	while(!q.empty())
	{
		u=q.front(),q.pop();
		for(i=head[u];i!=-1;i=next[i])
		{
			if(val[i]&&!d[to[i]])
			{
				d[to[i]]=d[u]+1;
				if(to[i]==n*m+1)	return true;
				q.push(to[i]);
			}
		}
	}
	return false;
}
int main()
{
	n=read(),m=read();
	int i,j,k,a;
	memset(head,-1,sizeof head);
	for(i=1;i<=n;i++)	for(j=1;j<=m;j++)	mp[i][j]=read();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[i][j])	continue;
			tot++;
			if((i^j)&1)
			{
				add(0,num(i,j),1);
				for(k=0;k<8;k++)
					if(ok(i+dx[k],j+dy[k]))
						add(num(i,j),num(i+dx[k],j+dy[k]),1<<30);
			}
			else 
				add(num(i,j),n*m+1,1);
		}
	}
	while(bfs())	ans+=dfs(0,1<<30);
	printf("%d",tot-ans);
	return 0;
}
