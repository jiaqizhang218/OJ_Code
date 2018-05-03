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
const int N = 2000010;
int fa[N],X[N],Y[N],cnt;
inline int findfa(int x)
{
	return x==fa[x]?x:fa[x]=findfa(fa[x]);
}
inline void merge(int x,int y)
{
	x=findfa(x),y=findfa(y);
	fa[y]=x;
}
int main()
{
	int n=read(),m=read(),k=read();
	int i,j,x,y,ans=0;
	for(int i=1;i<=n;i++)	fa[i]=i;
	for(i=1;i<=m;i++)
	{
		x=read(),y=read();
		if(x>k&&y>k)	ans++,merge(x,y);
		else cnt++,X[cnt]=x,Y[cnt]=y;
	}
	for(i=1;i<=cnt;i++)
	{
		int xx=findfa(X[i]),yy=findfa(Y[i]);
		if(xx==yy)	continue;
		ans++;
		fa[yy]=xx;
	}
	cout<<m-ans;
	return 0;
}
