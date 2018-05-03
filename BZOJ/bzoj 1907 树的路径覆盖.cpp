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
int T,n,cnt;
int head[10005],v[10005];
bool mark[10005];
struct edge{
	int to,next;
}e[20005];
inline void insert(int u,int v)
{
	e[++cnt].to = v ; e[cnt].next = head[u] ; head[u] = cnt;
	e[++cnt].to = u ; e[cnt].next = head[v] ; head[v] = cnt;
}
inline void dfs(int x,int f)
{
	v[x] = 1;
	int tot = 0;
	for(int i = head[x] ; i ; i = e[i].next)
	{
		if(e[i].to == f) continue;
		dfs(e[i].to,x);
		v[x] += v[e[i].to];
		if(!mark[e[i].to]) tot++;
	}
	if(tot >= 2)	v[x] -= 2 , mark[x] = 1;
	else if (tot == 1) v[x]--;
}
inline void clear()
{
	cnt = 0;
	memset(head,0,sizeof head);
	memset(v,0,sizeof v);
	memset(mark,0,sizeof mark);
}
int main()
{
	T = read();
	while(T--)
	{
		clear();
		n = read();
		for(int i = 1; i < n ; i++)
			insert(read(),read());
		dfs(1,0);
		printf("%d\n",v[1]);
	}
	return 0;
}
