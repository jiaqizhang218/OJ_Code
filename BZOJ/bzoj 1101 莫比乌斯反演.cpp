#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std;
const int N = 50010;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
int a,b,d;
int tot,t,prime[N];
int miu[N],sum[N];
bool f[N];
void Euler()
{
	miu[1] = 1;
	for(int i = 2 ; i < N ; i++)
	{
		if(!f[i])
		{
			prime[++t] = i;
			miu[i] = -1;
		}
		for(int j = 1 ; j <= t && i * prime[j] < N; j ++)
		{
			f[i*prime[j]] = true;
			if(i%prime[j] == 0)
			{
				miu[i*prime[j]] = 0;
				break;
			}
			else miu[i*prime[j]] = -miu[i];
		}
	}
	for(int i = 1 ; i < N ; i++)
		sum[i] = sum[i-1] + miu[i];
}
int main()
{	
	Euler();
	scanf("%d",tot);
	for(int i = 1 ; i <= tot ; i++)
	{
		scanf("%d%d%d",&a,&b,&d);
		int a1 = a/b , b1 = b/d;
		int x = min(a1,b1);
		int pos,ans = 0;
		for(int i = 1 ; i <= x ; i=pos+1)
		{
			pos=min(a1/(a1/i),b1(b1/i));
			ans += (sum[pos]-sum[i-1]) * (a1/i) * (b1/i);
		}
		printf("%d\n",ans);
	}
	return 0;
}


