#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int N = 50000;
using namespace std;
inline LL read()
{
	LL x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
int T;
LL ans,K;
int tot,mu[50005],pri[50005];
bool mark[50005];
inline void get_miu()
{
	mu[1] = 1;
	for(int i = 2 ; i <= N ; i++)
	{
		if(!mark[i]) pri[++tot] = i , mu[i] = -1;
		for(int j = 1 ; j <= tot && i * pri[j] <= N ; j++)
		{
			mark[i * pri[j]] = 1;
			if(i % pri[j] == 0) 	
			{
				mu[i*pri[j]] = 0; break;
			}
			else 
				mu[i*pri[j]] = -mu[i];
		}
	}
}
inline LL cal(int x)
{
	LL sum = 0;
	int t = sqrt(x);
	for(int i = 1; i <= t ; i++)
		sum += x/(i*i)*mu[i];
	return sum;
}
int main()
{
	get_miu();
	T = read();
	while(T--)
	{
		K = read();
		LL l = K , r = INF;
		while(l <= r)
		{
			LL mid = (l + r) >> 1;
			if(cal(mid) >= K)	ans = mid , r = mid - 1;
			else l = mid + 1; 
		}
		printf("%lld\n",ans);
	}
	return 0;
}
