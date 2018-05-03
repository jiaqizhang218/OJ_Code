#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int N = 305;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int T,n,r;
double p[N],d[N],f[N][N],ans;
inline void clear()
{
	n = r = ans = 0;
	for(int i = 1 ; i < N ; i++)	p[i] = d[i] = 0;
	memset(f,0,sizeof f);
}
double fast_pow(double a,int p)
{
	double ans = 1;
	for(;p;p>>=1,a*=a)
		if(p & 1)
			ans *= a;
	return ans;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		clear();
		scanf("%d%d",&n,&r);
		for(int i = 1; i <= n; i++)	scanf("%lf%lf",&p[i],&d[i]);
		f[0][r] = 1;
		for(int i = 1 ; i <= n ; ++i)
			for(int j = 1; j <= r ; ++j)
				f[i][j] = f[i-1][j] * fast_pow(1-p[i-1],j) + f[i-1][j+1] * (1-fast_pow(1-p[i-1],j+1));
		for(int i = 1 ; i <= n ; ++i)
			for(int j = 1 ; j <= r ; ++j)
				ans += f[i][j] * (1-fast_pow(1-p[i],j)) * d[i];
		printf("%.10lf\n",ans);
	}
}

