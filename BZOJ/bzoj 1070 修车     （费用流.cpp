#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
#define T 1001
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int n , m , cnt = 1 , ans , t[61][10];
int d[1005] , q[1005] , from[1005] , head[1005];
bool inq[1005];
struct edge{
	int from,to,next,c,v;
}e[100010];
inline void ins(int u,int v,int w,int c)
{
	e[++cnt].to = v ; e[cnt].from = u ; e[cnt].next = head[u] ; head[u] = cnt; e[cnt].c = c ; e[cnt].v = w;
}
inline void insert(int u,int v,int w,int c)
{
	ins(u,v,w,c),ins(v,u,0,-c);
}
inline bool spfa()
{
	for(int i = 0 ; i <= T; i++)	d[i] = INF; 
	int t = 0 , w = 1;
	d[0] = q[0] = 0 ; inq[0] = 1;
	while(t!=w)
	{
		int now = q[t++]; if(t == T) t = 0;
		for(int i = head[now] ; i ; i = e[i].next)
			if(e[i].v && d[e[i].to] > d[now] + e[i].c)
			{
				d[e[i].to] = d[now] + e[i].c;
				from[e[i].to] = i;
				if(!inq[e[i].to])
				{
					inq[e[i].to] = 1;
					q[w++] = e[i].to;
					if(w == T) w = 0;
				}
			}
		inq[now] = 0;
	}
	return d[T] != INF;
}
inline void MCF()
{
	int x = INF;
	for(int i = from[T] ; i ; i = from[e[i].from])
		x = min(x,e[i].v);
	for(int i = from[T] ; i ; i = from[e[i].from])
		{
			e[i].v -= x;
			e[i^1].v += x;
			ans += e[i].c * x; 
		}
} 
int main()
{
	n = read() , m = read();
	for(int i = 1 ; i <= m ; i++)
		for(int j = 1 ; j <= n ; j++)
			t[i][j] = read();
	for(int i = 1 ; i <= n * m ; i++)
		insert(0,i,1,0);
	for(int i = n * m + 1; i <= n * m + m ; i++)
		insert(i,T,1,0);
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			for(int k = 1 ; k <= m ; k++)
				insert((i-1)*m+j,n*m+k,1,t[k][i] * j);
	while (spfa()) MCF();
	printf("%.2lf",(double)ans/m);
	return 0;
}
