#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
int n, k, sta[17];
double dp[105][1<<17], sc[17];
//dp[i][j]表示前 i 次游戏，当前宝物状态是 j 能得到的期望分数
int main(){
    scanf("%d%d", &k,&n);
    for(int i = 1; i <= n; i++){
        scanf("%lf", &sc[i]);
        int x;
        while(scanf("%d", &x) && x) sta[i] = sta[i] | (1<<(x-1));
    }
    int mask = (1 << n) - 1;
    for(int i = k; i >= 1; i--){
        for(int j = 0; j <= mask; j++){
            for(int l = 1; l <= n; l++){
                if((j | sta[l]) == j) dp[i][j] += max(dp[i+1][j], dp[i+1][j|(1<<(l-1))] + sc[l]) / n;
                else dp[i][j] += dp[i+1][j] / n;
            }
        }
    }
    printf("%.6f\n", dp[1][0]);
    return 0;
}
