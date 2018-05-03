#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 270000
using namespace std;
int n,ans,a[N],dp[N][70];
int main()
{
    cin>>n;
    for(int j,i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        dp[i][a[i]]=i;
        for(j=a[i]+1;j<=65;++j)
        {
            dp[i][j]=dp[dp[i][j-1]-1][j-1];
            if(!dp[i][j])break;
            ans=max(ans,j);
        }
    }
    cout<<ans;
    return 0;
}
