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
const int N = 5e5 + 7;
struct edge{
	int to,next;
}e[N<<1]; 
int head[N],cnt,n,k,size[N];
inline void AE(int x,int y)
{
	e[++cnt].next=head[x],head[x]=cnt,e[cnt].to=y;
}
double f[N];
inline void dfs(int x)
{
	size[x]++;
	bool flag=false;
	for(int i=head[x];i;i=e[i].next)
		dfs(e[i].to),size[x]+=size[e[i].to],flag=true;
	if(!flag) {f[x]=1;return;}
	for(int i=head[x];i;i=e[i].next)
	{
		int y=e[i].to;
		f[x]=max(f[x],min(f[y],(double)size[y]/(double)(size[x]-1)));
	}
}
int main()
{
	n=read(),k=read();
	for(int i=2;i<=n;i++)
		AE(read(),i);
	dfs(1);
	double ans=0;
	for(int i=1;i<=n;i++)
		if(size[i]>k&&ans<f[i])
			ans=f[i];
	printf("%.7lf",ans);
	return 0;
}
