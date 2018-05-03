#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int MAXN = 50000 + 50;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
bool vis[MAXN];
int a,b,c,d,k;
int mu[MAXN],prime[MAXN],PrimeSize,sum[MAXN];
inline void Init()
{
		mu[1] = 1;
		for(int i = 2 ; i < MAXN ; i++)
		{
			if(!vis[i])
			{
				prime[++PrimeSize] = i;
				mu[i] = -1; 
			}
			for(int j = 1 ; j <= PrimeSize && i * prime[j] <= MAXN ; j++)
			{
				vis[i * prime[j]] = 1;
				if(i % prime[j]) mu[i * prime[j]] = -mu[i];
				else
				{
					mu[i * prime[j]] = 0;
					break;
				}
			}
		}
	for(int i = 1 ; i <= MAXN ; i++)
		sum[i] = sum[i-1] + mu[i];
}
inline int cal(int n,int m,int k)
{
	int ans = 0;
	n /= k , m /= k;
	for(int i = 1 , last; i <= n && i <= m; i = last + 1)
	{
		last = min(n/(n/i),m/(m/i));
		ans += (sum[last] - sum[i-1]) * (n/i)*(m/i); 
	} 
	return ans;
}
int main()
{
	Init();
	for(int T = read();T;T--)
	{
		int a = read() - 1, b = read() , c = read() - 1, d = read() , k = read();
		printf("%lld",(LL)cal(b,d,k)-cal(b,c,k)-cal(a,d,k)+cal(a,c,k));
	}
	return 0; 
}
