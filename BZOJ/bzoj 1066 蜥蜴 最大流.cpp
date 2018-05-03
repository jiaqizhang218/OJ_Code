#include<bits/stdc++.h>
typedef long long LL;
#define T 801
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
struct data{
	int to,next,v;
}e[500001];
int r,c,d,cnt=1,ans,mp[21][21],mark[21][21],q[802],h[802],head[802];
inline void ins(int u,int v,int w)
{
	e[++cnt].to = v , e[cnt].next = head[u] , head[u] = cnt , e[cnt].v = w;
}
inline void insert(int u,int v,int w)
{
	ins(u,v,w),ins(v,u,0);
}
inline bool jud(int x1,int y1,int x2,int y2)
{
	return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) <= (d*d) && mp[x1][y1] && mp[x2][y2]); 
}
inline void build()
{
	for(int x1 = 1 ; x1 <= r ; x1++)
		for(int y1 = 1 ; y1 <= r ; y1++)
			for(int x2 = x1-d ; x2 <= x1+d ; x2++)
				for(int y2 = y1-d ; y2 <= y1+d ; y2++)
	if(jud(x1,y1,x2,y2)&&(x1!=x2||y1!=y2))	insert(mark[x1][y1]+400,mark[x2][y2],INF);
	for(int i = 1 ; i <= r ; i++)
		for(int j = 1 ; j <= c ; j++)
			if(mp[i][j])	insert(mark[i][j],mark[i][j]+400,mp[i][j]);
}
inline bool bfs()
{
	memset(h,-1,sizeof h);
	int t = 0 , w = 1, now;q[0] = h[0] = 0;
	while(t <= w)
	{
		now = q[t++];
		for(int i = head[now] ; i ;  i = e[i].next)
		{
			if(e[i].v && h[e[i].to] < 0)
			{
				h[e[i].to] = h[now] + 1;
				q[w++] = e[i].to;
			}
		}
	}
	return h[T] != -1;
}
inline int dfs(int x,int f)
{
	if(x == T)	return f;
	int used = 0 , w;
	for(int i = head[x] ; i ; i = e[i].next)
	{
		if(e[i].v && h[e[i].to] == h[x] + 1)
				{
					w = f - used ; 
					w = dfs(e[i].to,min(w,e[i].v));
					e[i].v -= w;
					e[i^1].v += w;
					used += w;
					if(used == f)	return f;
				}
	}
	if(!used) h[x] = -1;
	return used;
}
inline void dinic()
{
	while(bfs())	ans -= dfs(0,INF);
}
int main()
{
	r = read() , c = read() , d = read();
	char ch[21];
	for(int i = 1 ; i <= r ; i++)
	{
		scanf("%s",ch+1);
		for(int j = 1 ; j <= c ; j++)
			mp[i][j] = ch[j] - '0';
	}
	int tot = 0;
	for(int i = 1 ; i <= r ; i++)
		for(int j = 1 ; j <= c ; j++)
			mark[i][j] = ++tot;
	for(int i = 1 ; i <= r ; i++)
	{
		scanf("%s",ch+1);
		for(int j = 1 ; j <= c ; j++)
			if(ch[j] == 'L')
				insert(0,mark[i][j],1),ans++;
	}
	for(int i = 1 ; i <= d ; i++)
		for(int j = d + 1 ; j <= r ; j++)
		{
			insert(mark[j][i]+400,T,INF);
			insert(mark[j][c-i+1]+400,T,INF);
		}
	for(int i = 1 ; i <= d ; i++)
		for(int j = 1 ; j <= c ; j++)
		{
			insert(mark[i][j]+400,T,INF);
			insert(mark[r-i+1][j]+400,T,INF);
		}
	build();
	dinic();
	cout<<ans;
}

