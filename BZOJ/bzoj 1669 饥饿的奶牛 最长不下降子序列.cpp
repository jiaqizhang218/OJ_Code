#include<bits/stdc++.h>
#define ll long long
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std;
const int maxn = 5000+5;
int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x * f;
}
int n,a[maxn],dp[maxn],ans;
int main()
{
	n = read();
	for(int i = 1 ; i <= n ; i++)
	{
		a[i] = read();
		for(int j = 0 ; j < i ; j++)
		{
			if(a[i] > a[j]) dp[i] = max(dp[i],dp[j]+1);
			ans = max(ans,dp[i]);
		}
	}
	printf("%d",ans);
	return 0; 
}

