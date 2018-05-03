#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
int t,p;
int get_phi(int x)
{
    int res=x;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            res=res/i*(i-1);
            while(x%i==0)x/=i;
        }
    }
    if(x!=1)res=res/x*(x-1);
    return res;
}
LL pow(LL a,LL n,LL mod)
{
    LL res=1;
    while(n)
    {
        if(n&1)res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res;
}
int solve(int p)
{
    if(p==1)return 0;
    int phi=get_phi(p);
    return pow(2,solve(phi)+phi,p);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&p);
        printf("%d\n",solve(p));
    }
    return 0;
}
