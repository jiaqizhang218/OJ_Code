#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int N = 505;
const int S = 1;
#define T n
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
struct edge{
	int x,y,f,c;
}edges[124800];
int n,m,ans;
int mp[N][N];
namespace Max_flow{
	struct abcd{
		int to,next,f;
	}table[300000];
	int head[N] , tot = 1;
	int dpt[N];
	inline void Add(int x,int y,int z)
	{
		table[++tot].to = y;
		table[tot].next = head[x];
		head[x] = tot;
		table[tot].f = z;
	}
	inline void Link(int x,int y,int z)
	{
		Add(x,y,z);
		Add(y,x,0);
	}
	bool BFS()
	{
		static int q[N];
		int i , r = 0 , h = 0;
		memset(dpt,-1,sizeof dpt);
		dpt[S] = 1; q[++r] = S;
		while(r != h)
		{
			int x = q[++h];
			for(int i = head[x] ; i ; i = table[i].next)
				if(table[i].f && !~dpt[table[i].to])
				{
					dpt[table[i].to] = dpt[x] + 1;
					q[++r] = table[i].to;
					if(table[i].to == T) return true;
				}
		}
		return false;
	}
	int Dinic(int x,int flow)
	{
		int i , left = flow;
		if (x == T) return flow;
		for(int i = head[x] ; i ; i = table[i].next)
			if(table[i].f && dpt[table[i].to] == dpt[x] + 1)
			{
				int tmp = Dinic(table[i].to,min(left,table[i].f));
				left -= tmp;
				table[i].f -= tmp;
				table[i^1].f += tmp;
			 }
		if(left)	dpt[x] = -1;
		return flow - left; 
	}
}
void floyd()
{
	for(int k = 1 ; k <= n ; k++)
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= n ; j++)
				mp[i][j] = min(mp[i][j],mp[i][k]+mp[k][j]);
}
int main()
{
	using namespace Max_flow;
	n = read() , m = read();
	memset(mp,0x3f,sizeof mp);
	for(int i = 1 ; i <= n ; i++)
		mp[i][i] = 0;
	for(int i = 1 ; i <= m ; i++)
	{
		edges[i].x=read(),edges[i].y=read(),edges[i].f=read(),edges[i].c=read();
		mp[edges[i].x][edges[i].y] = mp[edges[i].y][edges[i].x] = edges[i].f;
	}
	floyd();
	cout<<mp[1][n]<<endl;
	for(int i = 1; i <= m ; i++)
	{
		int x = edges[i].x , y = edges[i].y , z = edges[i].f;
		if(mp[1][x] + mp[y][n] + z == mp[1][n])
			Link(x,y,edges[i].c);
		if(mp[1][y] + mp[x][n] + z == mp[1][n])
			Link(y,x,edges[i].c);
	}
	while(BFS())
		ans += Dinic(S,INF);
	cout<<ans;
	return 0;
}
