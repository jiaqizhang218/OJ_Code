#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int maxn = 1000005;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
LL n,m,p;
LL s[maxn],f[maxn],fac[maxn],inv[maxn]; 
inline void pre()
{
	fac[0] = 1;
	for(int i = 1 ; i <= n ; i++)
		fac[i] = fac[i-1] * i % p;
	inv[0] = inv[1] = 1;
	for(int i = 2 ; i <= n ; i++)
		inv[i] = (p/i+1)*inv[i-p%i] % p;
	for(int i = 2 ; i <= n ; i++)
		inv[i] = inv[i] * inv[i-1] % p;	
}
inline LL C(int n,int m)
{
	if(n < m)	return 0;
	if(n < p && m < p)	return fac[n] * inv[m] % p * inv[n-m] % p;
	return C(n/p,m/p)*C(n%p,m%p) % p;
}
int main()
{
	scanf("%lld%lld",&n,&p);
	pre();
	for(int i = n ; i>=1; i--)
	{
		s[i] = s[i<<1] + s[i<<1|1] + 1;
		f[i]=((i<<1)>n?1:f[i<<1])*((i<<1|1)>n?1:f[i<<1|1])%p*C(s[i]-1,s[i<<1])%p;
	}
	printf("%lld",f[1]);
}
