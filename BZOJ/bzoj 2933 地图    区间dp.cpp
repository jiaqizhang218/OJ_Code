#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
//#define  getchar() nc()
inline LL read()
{
	LL x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
//w[i][j]表示i到j划为一段的代价。。。
//f[i][j]表示前i个用j个颜色的mincost
const int N = 3000+10;
const int M = 20;
LL n,m,a[N],f[N][M],w[N][N]; 
int main()
{
	n=read(),m=read();
	for(LL i=1;i<=n;i++)	a[i]=read();
	sort(a+1,a+1+n);
	for(LL j=1;j<=n;j++)
	{
		for(LL i=j-1;i;i--)
			w[i][j]=w[i+1][j]+a[((i+1)+j)>>1]-a[i];
	}
	for(LL i=0;i<n+1;i++)	for(LL j=0;j<m+1;j++)	f[i][j]=INF;
	f[0][0]=0;
	for(LL i=1;i<=n;i++)
		for(LL j=1;j<=m;j++)
		{
			f[i][j]=INF;
			for(LL k=0;k<i;k++)
				f[i][j]=min(f[i][j],f[k][j-1]+w[k+1][i]);
		}
	cout<<f[n][m];
	return 0;
}

