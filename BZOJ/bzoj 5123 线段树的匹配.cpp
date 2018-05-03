#include<map>
#include<cstdio>
#include<cstring>

using namespace std;

typedef long long LL;

const int mod=998244353;

map<LL,LL>dp[2];
map<LL,LL>sum[2];

void dfs(LL len)
{
    if(len==1){dp[0][1]=0;sum[0][1]=1;dp[1][1]=1;sum[1][1]=1;return;}
    LL R=len>>1,L=len-R;
    if(dp[0].find(L)==dp[0].end()) dfs(L);
    if(dp[0].find(R)==dp[0].end()) dfs(R);
    dp[1][len]=1+dp[0][L]+dp[0][R],sum[1][len]=sum[0][L]*sum[0][R]%mod;
	dp[0][len]=dp[0][L]+dp[0][R],sum[0][len]=sum[1][len];
    if(dp[0][L]+dp[1][R]>dp[0][len])dp[0][len]=dp[0][L]+dp[1][R],sum[0][len]=sum[0][L]*sum[1][R]%mod;
    else if(dp[0][L]+dp[1][R]==dp[0][len])sum[0][len]=(sum[0][len]+sum[0][L]*sum[1][R])%mod;
    if(dp[1][L]+dp[0][R]>dp[0][len])dp[0][len]=dp[1][L]+dp[0][R],sum[0][len]=sum[1][L]*sum[0][R]%mod;
    else if(dp[1][L]+dp[0][R]==dp[0][len])sum[0][len]=(sum[0][len]+sum[1][L]*sum[0][R])%mod;
}

int main()
{
    LL n;scanf("%lld",&n);
    dfs(n);printf("%lld %lld",dp[0][n],sum[0][n]);
}
