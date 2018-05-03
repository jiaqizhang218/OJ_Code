#include<bits/stdc++.h>
#define ll long long
const int INF = 0x7fffffff;
const double eps = 1e-5;
const int maxn = 500000 + 10;
using namespace std;
int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x * f;
}
void put(int x)
{
    int num = 0; char c[15];
    while(x) c[++num] = (x%10)+48, x /= 10;
    while(num) putchar(c[num--]);
}
int n,K,dp[2][maxn][2],a[maxn],ans;
int main()
{
	n = read() , K = read();
	for(int i = 1 ; i <= n ; ++i) a[i] = read(); 
	dp[1][1][a[1]] = 1 ; int cur = 1;
	for(int i = 2 ; i <= n ; ++i)
	{
		cur ^= 1;
		for(int j = 1; j <= (K<<1)-1 ; ++j)
			for(int k = 0 ; k < 2 ; ++k)
			{
				dp[cur][j][k] = max(dp[cur][j][k],dp[cur^1][j][k]+(a[i]==k));
				dp[cur][j][k] = max(dp[cur][j][k],dp[cur^1][j-1][k^1]+(a[i]==k));
				ans = max(ans,dp[cur][j][k]);
			}
	}
	put(ans);
	return 0;
}

