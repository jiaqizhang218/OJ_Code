#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int MAXN = 100010;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int next[MAXN],head[MAXN],point[MAXN],n,a,b,now,dp[MAXN];
map <pair<int,int>,int>s;
inline void add(int x,int y)
{
	next[++now] = head[x]; head[x] = now ; point[now] = y;
}
int main()
{
	n = read();
	for(int i = 1 ; i <= n ; i++)
	{
		a = read() , b = read();
		if(a + b >= n)	continue;
		b = n - b ; a++;
		if(!s[make_pair(a,b)])	add(b,a);
		s[make_pair(a,b)] = min(s[make_pair(a,b)]+1,b-a+1);
	}
	for(int i = 1; i <= n ; i++)
	{
		dp[i] = dp[i-1];
		for(int j = head[i] ; j ; j = next[j])
		{
			int u = point[j]-1;
			dp[i] = max(dp[i],dp[u] + s[make_pair(u+1,i)]);
		}
	}
	cout<<n-dp[n]<<endl;
	return 0;
}
