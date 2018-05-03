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
const int N = 100005;
int cnt,n,val[N],lim[N],last[N],a[N],a1,f[N],g[N];
struct edge{int to,next;}e[N*2];
inline void AE(int u,int v)
{
	e[++cnt].to=v; e[cnt].next=last[u]; last[u]=cnt;
	e[++cnt].to=u; e[cnt].next=last[v]; last[v]=cnt;
}
bool cmp(int a,int b)
{
	return f[a]>f[b];
}
inline void dfs(int x,int fa)
{
	f[x]=val[x];
	for(int i=last[x];i;i=e[i].next)
		if(e[i].to!=fa)	dfs(e[i].to,x);
	a1=0;
	for(int i=last[x];i;i=e[i].next)
		if(e[i].to!=fa)	a[++a1]=e[i].to;
	sort(a+1,a+a1+1,cmp);
	int p=0;
	while(p<min(lim[x]-1,a1)&&f[a[p+1]]>=0)	p++,f[x]+=f[a[p]],g[x]=g[a[p]];
	if(p<a1&&p>0&&f[a[p]]==f[a[p+1]]||f[a[p]]==0&&p>0)	g[x]=1;
}
int main()
{
	n=read();
	for(int i=2;i<=n;i++)	val[i]=read();
	for(int i=2;i<=n;i++)	lim[i]=read();
	for(int i=1;i<n;i++)	
	{
		int x=read(),y=read();
		AE(x,y);
	}
	lim[1]=n+1;
	dfs(1,0);
	cout<<f[1]<<endl;
	if(g[1])	cout<<"solution is not unique";
	else cout<<"solution is unique";
	return 0; 
}
