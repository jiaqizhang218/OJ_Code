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
int t;
double f[101],g[101];
int main()
{
	t=read();
	while(t--)
	{
		int n=read();
		double p,q;
		scanf("%lf%lf",&p,&q);
		f[0]=0,g[0]=1;
		n=min(n,1000);
		for(int i=1;i<=n;i++)
		{
			if(f[i-1]>g[i-1])p=1-p,q=1-q;  
            g[i]=(q*f[i-1]+(1-q)*p*g[i-1])/(p+q-p*q);  
            f[i]=(p*g[i-1]+(1-p)*q*f[i-1])/(p+q-p*q);  
            if(f[i-1]>g[i-1])p=1-p,q=1-q;  
		}
		printf("%.6lf\n",f[n]);
	}
	return 0;
}
