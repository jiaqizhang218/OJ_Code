#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
using namespace std;  
typedef long long LL;  
#define maxn 31000  
  
int l,r,q[maxn],t;  
LL sum[maxn],a[maxn],f[2][maxn];  
LL sqrr(LL x){return x*x;}  
double X(int j){return sum[j];}  
double Y(int j){return f[1-t][j]+sqrr(sum[j]);}  
double slop(int j1,int j2) {return (Y(j2)-Y(j1))/(X(j2)-X(j1));}  
int main()  
{  
    int n,m,i,k;LL sm;  
    sm=sum[0]=0;  
    scanf("%d%d",&n,&m);  
    for (i=1;i<=n;i++)  
    {  
        scanf("%lld",&a[i]);  
        sm+=a[i];a[i]*=m;  
        sum[i]=sum[i-1]+a[i];  
    }t=1;  
    memset(f,63,sizeof(f));f[0][0]=0;  
    for (i=1;i<=n;i++) f[0][i]=sqrr(sum[i]-sm);  
    for (k=1;k<=m;k++,t^=1)  
    {  
        l=r=1;q[l]=0;  
        memset(f[t],63,sizeof(f[t]));  
        for (i=1;i<=n;i++)  
        {  
            while (l<r && slop(q[l],q[l+1])<(sum[i]-sm)*2) l++;  
            int j=q[l];  
            f[t][i]=f[t^1][j]+sqrr(sum[i]-sum[j]-sm);  
            while (l<r && slop(q[r-1],q[r])>slop(q[r],i)) r--;  
            q[++r]=i;  
        } 
    }printf("%lld\n",f[1-t][n]/m);  
    return 0;  
} 
