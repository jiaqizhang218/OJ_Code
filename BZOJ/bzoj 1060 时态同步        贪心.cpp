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
const int N = 500005;
LL f[N],ans;
int head[N],n,s,x,y,tot,z;
struct edge{
	int to,next;
	LL val;
}e[N<<1];
inline void ins(int u,int v,LL va)
{
	e[++tot].to=v;	e[tot].val=va; e[tot].next=head[u]; head[u]=tot;
}
inline void dfs(LL x,LL fa)
{
	for(int i=head[x];i;i=e[i].next)
	{
		if(e[i].to!=fa)
		{
			dfs(e[i].to,x);
			f[x]=max(f[x],f[e[i].to]+e[i].val);
		}
	}
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa)	ans+=f[x]-f[e[i].to]-e[i].val;
}
int main()
{
	n=read(),s=read();
	for(int i=1;i<n;i++)
	{
		x=read(),y=read(),z=read();
		ins(x,y,z); ins(y,x,z);
	}
	dfs(s,0);
	cout<<ans;
	return 0;
}
