#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define ll long long
#define inf 9000000000000000000
#define MAX 1000000000000000000LL
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
int l=1,r;
ll a[1000005],b[1000005];
int q[1000005];
ll tot,ans,f[1000005],sum[1000005];
double cal(int j,int k)
{
    return (double)(f[k]-f[j])/(double)(j-k);
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)b[i]=read();
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+b[i];
    for(int i=1;i<n;i++)
        tot+=b[i]*(n-i);
    tot+=a[n];
    q[++r]=n;
    for(int i=n-1;i;i--)
    {
        while(l<r&&cal(q[l],q[l+1])>sum[i])l++;
        int j=q[l];
        f[i]=f[j]+sum[i]*(j-i)-a[i];
        ans=max(ans,f[i]);
        while(l<r&&cal(q[r],i)>cal(q[r-1],q[r]))r--;
        q[++r]=i;
    }
    printf("%lld",tot-ans);
    return 0;
}
