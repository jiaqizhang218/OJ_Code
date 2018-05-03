#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

int n,Sa,Sb,Sc,Sd,a[5000005],MOD;

int f(int x)
{
    return ((LL)Sa*x%MOD*x%MOD*x%MOD+(LL)Sb*x%MOD*x%MOD+(LL)Sc*x%MOD+(LL)Sd)%MOD;
}

bool check(int mid)
{
    int ls=a[1]-mid;
    for (int i=2;i<=n;i++)
        if (a[i]>=ls) ls=max(ls,a[i]-mid);
        else if (a[i]+mid<ls) return 0;
    return 1;
}

int main()
{
    scanf("%d%d%d%d%d%d%d",&n,&Sa,&Sb,&Sc,&Sd,&a[1],&MOD);
    for (int i=2;i<=n;i++) a[i]=(f(a[i-1])+f(a[i-2]))%MOD;
    int l=0,r=MOD-1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (check(mid)) r=mid-1;
        else l=mid+1;
    }
    printf("%d",r+1);
    return 0;
}
