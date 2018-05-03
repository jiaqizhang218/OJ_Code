#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std; 
const int mod = 10007;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
int t,n,m,fac[20000000];
inline void init()
{
	fac[0] = 1;
	for(int i = 1 ; i <= mod ; i++)
		fac[i] = fac[i-1]*i%mod;
}
inline int exp_mod(int a,int b,int p)
{
	int tmp = a % p , ans = 1;
	for(;b;b>>=1,tmp=tmp*tmp%p)
		if(b & 1) ans = ans * tmp % mod;
	return ans;
}
inline int C(int n,int m,int p)
{
	if(m > n) return 0;
	return fac[n] * exp_mod(fac[m] * fac[n-m],p-2,p) % p;
}
inline int Lucas(int n,int m,int p)
{
	if(m == 0)	return 1;
	return (C(n%p,m%p,p) * Lucas(n/p,m/p,p) % p) % p;
}
int main()
{
	init();
	t = read();
	while(t--)
	{
		n = read() , m = read();
		printf("%d\n",Lucas(n,m,mod));
	}
	return 0;
}


