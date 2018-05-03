#include<bits/stdc++.h>
using namespace std;
const int N = 18, inf = 1000000010;
int W, n;
int t[N], w[N], sumw[1 << N], sumt[1 << N], dp[1 << N];
int main()
{
    scanf("%d%d", &W, &n);
    for(int i = 0; i < n; ++i)
        scanf("%d%d", &t[i], &w[i]);
    for(int i = 0; i < (1 << n); ++i)
    {
        for(int j = 0; j < n; ++j) if(i & (1 << j))
        {
            sumw[i] += w[j];
            sumt[i] = max(sumt[i], t[j]);
        }
        if(sumw[i] <= W) dp[i] = sumt[i];
        else dp[i] = inf;
    }
    for(int i = 0; i < (1 << n); ++i) 
        for(int j = i; j; j = (j - 1) & i) 
            dp[i] = min(dp[i], dp[i ^ j] + dp[j]);
    printf("%d\n", dp[(1 << n) - 1]);
    return 0;
}
