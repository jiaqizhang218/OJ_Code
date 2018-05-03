#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=55;
const int M=100005;
const int inf=0x3f3f3f3f;

int n,a[N],f[M],prime[M],tot,low[M];
bool not_prime[M];

void get_prime(int n)
{
    for (int i=2;i<=n;i++)
    {
        if (!not_prime[i]) prime[++tot]=i,low[i]=i;
        for (int j=1;j<=tot&&i*prime[j]<=n;j++)
        {
            not_prime[i*prime[j]]=1;
            low[i*prime[j]]=prime[j];
            if (i%prime[j]==0) break;
        }
    }
}

int main()
{
    scanf("%d",&n);
    int mx=0;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),mx=max(mx,a[i]);
    get_prime(mx);
    for (int i=1;i<=mx;i++) f[i]=inf;
    for (int i=mx;i>=1;i--)
    {
        int s=0;
        for (int j=1;j<=n;j++) s+=a[j]/i;
        f[i]=min(f[i],s);
        int x=i;
        while (x>1)
        {
            int y=i/low[x],s=0;
            for (int j=1;j<=n;j++) s+=a[j]%i/y;
            f[y]=min(f[y],f[i]+s);
            y=low[x];
            while (x%y==0) x/=y;
        }
    }
    printf("%d",f[1]);
    return 0;
}
