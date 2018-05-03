#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int MAXN = 1000005;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int n,l,r;
int a,b,c;
int x[MAXN];
LL sum[MAXN],f[MAXN];
int q[MAXN];
inline LL sqr(LL x)
{
	return x * x;
}
inline double slop(int k,int j)
{
	return  ((f[j]-f[k]+a*(sqr(sum[j])-sqr(sum[k]))+b*(sum[k]-sum[j])) / (2 * a * (sum[j] - sum[k])));
}
int main()
{
	n = read() , a = read() , b = read() , c = read();
	for(int i = 1 ; i <= n ; i++) x[i] = read() , sum[i] = sum[i-1] + x[i];
	for(int i = 1 ; i <= n ; i++)
	{
		while(l < r && slop(q[l],q[l+1]) < sum[i]) l++;
		f[i] = f[q[l]] + a * sqr(sum[i] - sum[q[l]]) + b * (sum[i] - sum[q[l]]) + c;
		while(l < r && slop(q[r-1],q[r]) > slop(q[r],i)) r--;
		q[++r] = i;
	}
	printf("%lld",f[n]);
	return 0;
}

