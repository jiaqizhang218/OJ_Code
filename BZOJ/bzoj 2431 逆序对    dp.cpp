#include<cstdio>
#define N 1005
#define P 10000
int f[N],sum[N],n,k;
int main(){
    scanf("%d%d",&n,&k);f[0]=1;
    for(int i=0;i<=k;i++) sum[i]=1;
    for(int i=2;i<=n;i++,f[0]=1){
        for(int j=1;j<=k;j++)
            if(j>=i) f[j]=((sum[j]-sum[j-i])%P+P)%P;
            else f[j]=sum[j]%P;
        for(int j=1;j<=k;j++) sum[j]=((sum[j-1]+f[j])%P+P)%P;
    }
    printf("%d\n",f[k]);
    return 0;
}
