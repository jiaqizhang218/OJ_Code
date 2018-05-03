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
const int N = 1e5 + 5;
struct edge{
	int next,to;
	edge(int _n=0,int _t=0) : next(_n),to(_t) {}
}e[N];
int n,m;
int first[N],tot;
int deg[N],q[N];
int t[N],NOW,v[N];
int ans[N];
inline void add_edge(int x,int y)
{
	e[++tot] = edge(first[x],y),first[x]=tot;
	++deg[y];
}
#define p q[l]
#define y e[x].to
inline bool check_circle()
{
	static int i,l,r,x;
	for(r=0,i=1;i<=n;++i)	if(deg[i]==0)	q[++r]=i;
	for(l=1;l<=r;++l)	
		for(x=first[p];x;x=e[x].next)
			if(--deg[y]==0)	q[++r]=y;
	return r!=n; 
}
inline int bfs(int s)
{
	static int l,r,x;
	++NOW;
	q[l=r=1]=s;
	for(;l<=r;++l)
	{
		for(x=first[p];x;x=e[x].next)	
			if(!v[y])
				{
					++deg[y];
					if(t[y]!=NOW)
						q[++r]=y,t[y]=NOW;
				}
	}
}
priority_queue<int>h;
#undef p
inline void get(int s)
{
	static int p,x;
	while(!h.empty()) h.pop();
	h.push(s),v[s]=1;
	while(!h.empty())
	{
		p=h.top();	h.pop();
		ans[++ans[0]]=p;
		for(x=first[p];x;x=e[x].next)
			if(!v[y])
			{
				if(--deg[y]==0) h.push(y),v[y]=1;
			}
	}
}
#undef y
int main()
{
	int T,i,x,y;
	T=read();
	while(T--)
	{
		n=read(),m=read(),tot=NOW=0;
		memset(first,0,sizeof first);
		memset(v,0,sizeof v);
		memset(deg,0,sizeof deg);
		memset(t,0,sizeof t);
		for(i=1;i<=m;++i)
		{
			x=read(),y=read();
			add_edge(y,x);
		}
		if(check_circle())
		{
			puts("Impossible!");
			continue;
		}
		for(i=1;i<=n;i++)
		if(!v[i])
		{
			bfs(i);
			get(i);
			for(;ans[0];--ans[0])	printf("%d ",ans[ans[0]]);
		}
		puts("");
	}
	return 0;
}
