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
const int MAXN = 10000005;
int n,m,p,q,i,j,x,k,y,f[MAXN],a[MAXN];
inline int find(int x)
{
	return f[x] == x ? x : f[x] = find(f[x]);
}
int main()
{
	n = read() , m = read() , p = read() , q = read();
	for(i=1;i<=n+1;i++)	f[i]=i;
	for(i=m;i>=1;i--)
	{
		x=(i*p%n+q)%n+1;
		y=(i*q%n+p)%n+1;
		if(x>y)	swap(x,y);
		for(j=find(x);j<=y;j=find(j))
		{
			a[j]=i,f[j]=j+1;k++;
			if(k==n)break;
		}
	 } 
	for(i=1;i<=n;i++)
		printf("%d\n",a[i]);
	return 0;
}
