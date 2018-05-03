#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const double eps = 1e-5;
const int N = 1000;
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,cnt,scc,ind,top;
int v[N],w[N];
int sv[N],sw[N];
int dfn[N],low[N],belong[N];
int q[N],f[N][N],in[N];
struct Edge{
	int to,next;
}e[N],ed[N]; int last[N],last2[N];
bool inq[N];
inline void insert(int u,int v)
{
	e[++cnt].to = v , e[cnt].next = last[u] , last[u] = cnt;
}
inline void insert2(int u,int v)
{
	in[v] = 1;
	ed[++cnt].to = v, ed[cnt].next = last2[u] , last2[u] = cnt;
}
inline void tarjan(int x)
{
	int now = 0;
	low[x] = dfn[x] = ++ind;
	q[++top] = x , inq[x] = 1;
	for(int i = last[x] ; i ; i = e[i].next)
		if(!dfn[e[i].to]) 
			{
				tarjan(e[i].to);
				low[x] = min (low[x],low[e[i].to]);
			}
		else if (inq[e[i].to])
			low[x] = min(low[x],dfn[e[i].to]);
	if(low[x] == dfn[x])
	{
		scc++;
		while(now != x)
		{
			now = q[top--];
			inq[now] = false;
			belong[now] = scc;
			sv[scc] += v[now] , sw[scc] += w[now];
		}
	}
}
inline void rebuild()
{
	cnt = 0;
	for(int x = 1 ; x <= n ; x++)
		for(int i = last[x] ; i ; i = e[i].next)
			if(belong[x] != belong[e[i].to])
				insert2(belong[x],belong[e[i].to]);
}
inline void dp(int x)
{
	for(int i=last2[x];i;i=ed[i].next)
	{
		dp(ed[i].to);
		for(int j=m-sw[x];j>=0;j--)
		{
			for(int k=0;k<=j;k++)
				f[x][j]=max(f[x][j],f[x][k]+f[ed[i].to][j-k]);		
		}
	}
	for(int j=m;j>=0;j--)
	{
		if(j>=sw[x])f[x][j]=f[x][j-sw[x]]+sv[x];
		else f[x][j]=0;
	}
}
int main()
{
	n = read() , m = read();
	for(int i = 1 ; i <= n ; i++) w[i] = read();
	for(int j = 1 ; j <= n ; j++) v[j] = read();
	for(int i = 1 ; i <= n ; i++) if(int x = read()) insert(x,i);
	for(int i = 1 ; i <= n ; i++)
		if(!dfn[i]) tarjan(i);
	rebuild();
	for(int i = 1 ; i <= scc ; i++)
		if(!in[i])
			insert2(scc+1,i);
	dp(scc+1);
	printf("%d",f[scc+1][m]);
	return 0;	
}
