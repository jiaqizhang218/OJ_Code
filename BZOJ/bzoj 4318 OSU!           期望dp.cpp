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
const int M = 100100;
int n;
double a[M],l[M],l2[M],f[M]; 
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&a[i]);
		l[i]=(l[i-1]+1)*a[i];
		l2[i]=(l2[i-1]+2*l[i-1]+1)*a[i];
		f[i]=f[i-1]+(3*l2[i-1]+3*l[i-1]+1)*a[i];
	}
	printf("%.1lf\n",f[n]);
	return 0;
}
