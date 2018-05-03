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
const int N=210;
int n,m;
double ans,f[N][2],g[N]; 
int main()
{
	n=read(),m=read();
	g[1]=1,f[0][1]=1;
	for(int i=2;i<=n;i++)	g[i]=g[i-1]*1.0/(double)m;

	for(int i=0;i<=n;i++) 	
		for(int j=i+1;j<=n;j++) {
			f[j][0]+=(j-i)*g[j-i]*(f[i][0]*(double)(m-2.0)/m+f[i][1]*(double)(m-1.0)/m);
			f[j][1]+=(j-i)*g[j-i]*f[i][0]*1.0/(double)m;
		}
	ans=g[n]*n;
	for(int i=1;i<n;i++) ans+=(double)i*(double)i*f[n-i][0]*g[i];
	printf("%.5lf",ans);
	return 0; 
}
