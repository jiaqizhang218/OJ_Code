#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int N = 500005;
const double eps = 1e-5;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
struct Edge{
	int to,next;
}e[N<<2];
int n , m , cnt , dfs_clock, head[N];
int low[N], dfn[N], size[N] , last[N];
LL ans[N];
void tarjan(int x)
{
	int t = 0;
	size[x] = 1;
	dfn[x] = low[x] = ++dfs_clock;
	for(int i = head[x] ; i ; i = e[i].next)
		if(dfn[e[i].to])	low[x] = min(low[x],dfn[e[i].to]);
		else 
		{
			tarjan(e[i].to);
			size[x] += size[e[i].to];
			low[x] = min(low[x],low[e[i].to]);
			if(dfn[x] <= low[e[i].to])
			{
				ans[x] += (LL)t*size[e[i].to];
				t += size[e[i].to];
			}
		}
	ans[x] += (LL)t * (n-t-1);
}
inline void insert(int u,int v)
{
	e[++cnt].to = v ; e[cnt].next = head[u] ; head[u] = cnt;
	e[++cnt].to = u ; e[cnt].next = head[v] ; head[v] = cnt;
}

int main()
{
	n = read() , m = read();
	for(int i = 1 ; i <= m ; ++i)
		insert(read(),read());
	tarjan(1);
	for(int i = 1 ; i <= n ; i++)
		printf("%lld\n",(ans[i]+n-1)<<1);
	return 0;
}


