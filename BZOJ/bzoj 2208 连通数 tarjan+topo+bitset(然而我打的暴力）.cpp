//这暴力都能ac，暴力踩标程不是浪得虚名QAQ 
#include<bits/stdc++.h>
#define ll long long
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std;
const int N = 2000 + 5; 
int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x * f;
}
struct Edge{
	int to,next;
}e[N*N];
int head[N],ans,T,cnt,vis[N];
char c[N];
void ins(int u,int v)
{
	e[++cnt].to = v; e[cnt].next = head[u]; head[u] = cnt;
}
void dfs(int u)
{
	vis[u] = T; ans++;
	for(int i = head[u];i;i=e[i].next)
	{
		int v = e[i].to;
		if(vis[v]==T) continue;
		vis[v] = T; dfs(v);
	}
}
int main()
{
	int n = read();
	for(int i = 1; i <= n ; i++)
	{
		scanf("%s",c+1);
		for(int j = 1 ; j <= n ; j++)
			if(c[j]-'0') ins(i,j);
	}
	for(int i = 1; i <= n ; ++i)
	{
		++T;
		dfs(i);
	}
	printf("%d",ans);
	return 0;
}

