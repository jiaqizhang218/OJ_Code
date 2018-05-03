#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int M = 10000001;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
bool not_prime[M+100];
LL prime[M>>1],ans[M+100],fac[M+100],rev[M+100];
int n,m,p,T,tot;
inline void Linear_Shaker()
{
	LL i ,j;
	for(LL i = 2 ; i <= M ; i++)
	{
		if(!not_prime[i]) prime[++prime[0]] = i;
		for(LL j = 1 ; j <= prime[0] && prime[j] * i <= M ; j++)
		{
			not_prime[prime[j] * i] = true;
			if(i % prime[j] == 0)	break;
		}
	}
	fac[1] = 1;
	for(LL i = 2 ; i <= M ; i++)
		fac[i] = fac[i-1] * i % p;
	rev[1] = 1;
	for(LL i = 2 ; i <= M && i < p; i++)
		rev[i] = (p-p/i) * rev[p%i] % p;
	ans[1] = 1;
	for(LL i = 2 ; i <= M ; i++)
		if(!not_prime[i])
			ans[i] = ans[i-1] * (i-1) % p * rev[i%p] %p;
		else
			ans[i] = ans[i-1];
}
int main()
{
	T = read() , p = read();
	Linear_Shaker();
	while(T--)
	{
		n = read() , m = read();
		printf("%d\n",fac[n]*ans[m]%p);
	}
	return 0;
}
