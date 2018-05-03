#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int maxn = 1005 , maxm = 10005;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
int L,n,m,dp[maxn][maxn];
struct _data{
	int l,r,w,c;
	bool operator < (const _data& rhs) const{
		return l < rhs.l;
	}
}track[maxm];
int main()
{
	L = read() , n = read() , m = read();
	for(register int i = 1 ; i <= n ; i++)
		track[i].l = read() , track[i].r = track[i].l + read(), track[i].w = read() , track[i].c = read();
	sort(track+1,track+1+n);
	memset(dp,-1,sizeof dp);
	dp[0][0] = 0;
	for(register int i = 1 ; i <= n ; i++)
		for(register int j = track[i].c ; j <= m ; j++)	if(~dp[track[i].l][j-track[i].c])
			dp[track[i].r][j] = max(dp[track[i].r][j],dp[track[i].l][j-track[i].c]+track[i].w);
	int ans = -1;
	for(register int i = 1 ; i <= m ; i++)
		ans = max(ans,dp[L][i]);
	cout<<ans;
	return 0;
}
