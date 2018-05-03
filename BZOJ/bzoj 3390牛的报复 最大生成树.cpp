#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,tot,ans,fa[1001];
struct edge{int x,y,v;}a[20001];
bool cmp(edge a,edge b)
{return a.v>b.v;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	   scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int p=find(a[i].x),q=find(a[i].y);
		if(p!=q)
		{
		    fa[p]=q;tot++;ans+=a[i].v;
		    if(tot==n-1){printf("%d",ans);return 0;}
		}
	}
	printf("-1");
	return 0;
}

