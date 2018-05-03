#include<bits/stdc++.h>
#define debug(x) cerr<<#x" = "<<x<<endl
typedef long long LL;
const int M = 320000; 
#define S n+m+1
#define T S+1
const int INF = 0x7fffffff;
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
//#define  getchar() nc()
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int n,m,ans;
namespace Max_Flow{
	struct abcd {
		int to,f,nxt;
	}e[M];
	int fir[M],tot=1,dpt[M];
	void Add(int x,int y,int z) {
		e[++tot].to=y; e[tot].f=z; e[tot].nxt=fir[x];fir[x]=tot;
	}
	void Link(int x,int y,int z) {
		Add(x,y,z); Add(y,x,0);
	}
	bool Bfs()
	{
		static int q[M];
		int i,r=0,h=0;
		memset(dpt,-1,sizeof dpt);
		dpt[S]=1;q[++r]=S;
		while(r!=h)
		{
			int x=q[++h];
			for(i=fir[x];i;i=e[i].nxt)
			{
				if(e[i].f&&!~dpt[e[i].to])
				{
					dpt[e[i].to]=dpt[x]+1;
					q[++r]=e[i].to;
					if(e[i].to==T)	return true;
				}
			}
		}
		return false;
	}
	int Dinic(int x,int flow)
	{
		int i,left=flow;
		if(x==T) return flow;
		for(i=fir[x];i&&left;i=e[i].nxt)
			if(e[i].f&&dpt[e[i].to]==dpt[x]+1)
			{
				int tmp=Dinic(e[i].to,min(e[i].f,left));
				left-=tmp;
				e[i].f-=tmp; e[i^1].f+=tmp;
			}
			if(left)dpt[x]=-1;
			return flow-left;
	}
}
using namespace Max_Flow;
inline void build()
{
	n=read(),m=read();
	for(int i=1,z;i<=n;i++)Link(i+m,T,read());
	for(int i=1,x,y,z;i<=m;i++)
	{
		x=read(),y=read(),z=read();	ans+=z;
		Link(S,i,z);
		Link(i,x+m,INF);
		Link(i,y+m,INF);
	}
}
int main()
{
	build();
	while(Bfs()) ans-=Dinic(S,INF);
	return printf("%d",ans),0;
}

