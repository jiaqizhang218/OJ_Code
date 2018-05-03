#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn=100010;
double b[maxn];
int a[maxn],sb[maxn];
ll sa[maxn];
int n,k;
ll P,Q,g;
inline int rd()
{
    int ret=0,f=1;  char gc=getchar();
    while(gc<'0'||gc>'9') {if(gc=='-')    f=-f;   gc=getchar();}
    while(gc>='0'&&gc<='9')   ret=ret*10+(gc^'0'),gc=getchar();
    return ret*f;
}
ll gcd(ll a,ll b)
{
    return !b?a:gcd(b,a%b);
}
bool check(double mid)
{
    int i;
    for(i=1;i<=n;i++)    b[i]=b[i-1]+a[i]-mid,sb[i]=(b[i]<b[sb[i-1]])?i:sb[i-1];
    for(i=k;i<=n;i++)
    {
        if(b[i]-b[sb[i-k]]>0)
        {
            P=sa[i]-sa[sb[i-k]],Q=i-sb[i-k];
            return 1;
        }
    }
    return 0;
}
int main()
{
    n=rd(),k=rd();
    int i;
    for(i=1;i<=n;i++)    a[i]=rd(),sa[i]=sa[i-1]+a[i];
    double l=-1e8,r=1e8,mid;
    for(i=1;i<=100;i++)
    {
        mid=(l+r)/2;
        if(check(mid))  l=mid;
        else    r=mid;
    }
    g=gcd(P,Q);
    g=g>0?g:-g;
    if(g)   P/=g,Q/=g;
    printf("%lld/%lld",P,Q);
    return 0;
}
