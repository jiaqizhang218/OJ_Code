#include<bits/stdc++.h>
typedef long long LL;
const int MAXN = 1000050;
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int n,l,r;
LL p[MAXN],x[MAXN],c[MAXN],f[MAXN];
LL b[MAXN],sum[MAXN];
int q[MAXN];
inline double slop(int k,int j)
{
	return double(f[j]-f[k]+b[j]-b[k])/double(sum[j]-sum[k]);
}
int main()
{
	n = read();
	for(int i = 1 ; i <= n ; i++)
		x[i] = read() , p[i] = read() , c[i] = read();
	for(int i = 1 ; i <= n ; i++)
		{
			sum[i] = sum[i-1] + p[i];
			b[i] = b[i-1] + p[i] * x[i];
		}
	for(int i = 1 ; i <= n ; i++)
		{
			while(l < r && slop(q[l],q[l+1]) < x[i]) l++;
			int t = q[l];
			f[i] = f[t] - b[i] + b[t] + (sum[i] - sum[t]) * x[i] + c[i];
			while(l < r && slop(q[r-1],q[r]) > slop(q[r],i)) r--;
			q[++r] = i; 
			}	
	printf("%lld",f[n]);
}
