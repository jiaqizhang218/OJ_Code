#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAXN 1000+10
#define LL long long
#define MOD 7777777
using namespace std;
LL f[MAXN][MAXN][2],n;
int main()
{
    scanf("%lld",&n);
    f[1][0][0]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            f[i][j][1]=(f[i-1][j][1]+f[i-1][j-1][1]+f[i-1][j-1][0]*2)%MOD;
            f[i][j][0]=(f[i-1][j+1][1]*j+f[i-1][j+1][0]*(j+1))%MOD;
            f[i][j][0]=(f[i][j][0]+f[i-1][j][1]*(i-j-1)+f[i-1][j][0]*(i-j-2))%MOD;
        }
    }
    printf("%lld\n",f[n][0][0]);
    return 0;
}
