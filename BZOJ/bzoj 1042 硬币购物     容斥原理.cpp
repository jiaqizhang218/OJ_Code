#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std;
inline LL read()
{
	LL x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
LL d[5] , c[5] , tot , s , ans ;
LL f[110000];
void dfs(int x,int k,int sum)
{
	if(sum<0)return;
	if(x==5)
	{
		if(k&1) ans-=f[sum];
		else ans+=f[sum];
		return;
	}
    dfs(x+1,k+1,sum-(d[x]+1)*c[x]);
	dfs(x+1,k,sum);
}
int main()
{
	for(int i=1;i<=4;i++)c[i]=read();
	tot=read();
	f[0]=1;
	for(int i=1;i<=4;i++)
		for(int j=c[i];j<=100000;j++)
			f[j]+=f[j-c[i]];
	for(int i=1;i<=tot;i++)
	{
		for(int k=1;k<=4;k++)d[k]=read();
		int x=read();
		ans=0;
		dfs(1,0,x);
		printf("%lld\n",ans);
	}
	return 0;
}