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
struct data{
	int u,v,x,y,id;
}b[20];
int a[20][20],c[20],ans,n,m;
bool cmp(int x,int y)
{
	if(b[x].u==b[y].u)	return b[x].v<b[y].v;
	return b[x].u<b[y].u;
}
inline void dfs(int i,int j,int d)
{
	if(j>a[i][0])	i++,j=1,d=0;
	if(i>n) {
		int tmp=0;
		for(int k=1;k<=m;k++)
			if(!b[k].x)	tmp+=b[k].y;
		ans=max(ans,tmp);
		return;
	}
	dfs(i,j+1,d);
	if(d<b[a[i][j]].u&&b[a[i][j]].x) {
		b[a[i][j]].x--;
		dfs(i,j+1,b[a[i][j]].v);
		b[a[i][j]].x++;
	}
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) {
		a[i][0]=read();
		for(int j=1;j<=a[i][0];j++)	a[i][j]=read();
	}
	for(int i=1;i<=m;i++) b[i].u=read(),b[i].v=read(),b[i].x=read(),b[i].y=read();
	for(int i=1;i<=n;i++) sort(a[i]+1,a[i]+a[i][0]+1,cmp);
	dfs(1,1,0);
	printf("%d",ans);
	return 0;
}
