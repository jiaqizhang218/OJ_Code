#include<bits/stdc++.h>
typedef long long LL;
const int N = 100005;
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
LL A,B,C,ans=1LL<<60;
int cnt[2][N],n,m;
int main()
{
	LL cost = 0 , dis = 0 , lef = 0;
	scanf("%lld%lld%lld",&A,&B,&C); n = read() ,m  = read();
	if(A > B) A = B;
	for(int i = 1 ; i <= n ; i++)	
	{
		int x = read() ;cnt[1][x]++; cost += N - x;
	}
	for(int i = 1 ; i <= m ; i++)
	{
		int x = read() ; cnt[2][x]++;lef += N - x;
	}
	for(int i = 2 ; i < N ; i++)
		cnt[1][i] += cnt[1][i-1] , cnt[2][i] += cnt[2][i-1];
	for(int i = N- 1 ; i ; i--)
	{
		dis += (cnt[2][N-1] - cnt[2][i]);
		lef -= cnt[2][i];
		cost -= cnt[1][i];
		if(C >= 10000000000000000LL && cost)	continue;
		ans += min(ans,min(dis,lef)*A+max(0LL,dis-lef)*B+cost*C);
	}
	printf("%d",ans);
}


