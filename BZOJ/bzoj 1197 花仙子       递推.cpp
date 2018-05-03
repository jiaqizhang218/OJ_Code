#include<cstdio>
long long dp[2][100];
int main()
{
        int n,m;
        long long *a=dp[0],*b=dp[1];
        scanf("%d%d",&m,&n);dp[0][0]=1;
        for(int i=1;i<=m;i++)a[i]=i*2;
        if(n==1){printf("%lld",a[m]);return 0;}
        for(int i=2;i<=n;i++)
        {
                b[0]=1;
                for(int j=1;j<=m;j++) b[j]=b[j-1]+a[j-1];
                long long *t=a;  a=b;  b=t;
        }
        printf("%lld\n",a[m]);
        return 0;
}
