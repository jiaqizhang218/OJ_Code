#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,tim,top,scc,cnt;
int to[100005],q[100005],dfn[100005],low[100005];
int head[100005],hav[100005],belong[100005],ans[100005];
bool inq[100005];
struct data{int to,next;}e[100005];
void insert(int u,int v)
{e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;}
void tarjan(int x)
{
	int now=0;
	dfn[x]=low[x]=++tim;
	q[++top]=x;inq[x]=1;
	if(inq[to[x]])low[x]=min(low[x],dfn[to[x]]);
	else if(!dfn[to[x]]){tarjan(to[x]);low[x]=min(low[x],low[to[x]]);}
	if(low[x]==dfn[x])
	{
		scc++;
		while(now!=x)
		{
			now=q[top--];
			belong[now]=scc;
			hav[scc]++; 
			inq[now]=0;
		}
	}
}
void rebuild()
{
	for(int i=1;i<=n;i++)
    {
    	if(belong[i]!=belong[to[i]])
		    insert(belong[i],belong[to[i]]); 
    }
}
int solve(int x)
{
	if(ans[x])return ans[x];
	ans[x]=hav[x];
	if(hav[x]==1)
    ans[x]+=solve(e[head[x]].to);
    return ans[x];
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	    to[i]=read();
	for(int i=1;i<=n;i++)
	    if(!dfn[i])tarjan(i);
	rebuild();
	for(int i=1;i<=n;i++)
	    printf("%d\n",solve(belong[i]));
	return 0;
}
