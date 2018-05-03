#include<bits/stdc++.h> 
#define ll long long 
#define inf 1000000000
using namespace std;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,cnt;
int last[100005],out[100005];
double f[100005];
bool vis[100005];
struct edge{
	int to,next,v;
}e[200005];
void insert(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;e[cnt].v=w;
}
void dfs(int x)
{
	if(!vis[x])vis[x]=1;
	else return;
	for(int i=last[x];i;i=e[i].next)
	{
		dfs(e[i].to);
		f[x]+=e[i].v+f[e[i].to];
	}
	if(out[x])f[x]/=out[x];
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		insert(u,v,w);
		out[u]++;
	}
	dfs(1);
	printf("%.2lf",f[1]);
	return 0;
}
