#include<iostream>  
#include<cstdio>  
#define N 200005  
#define ll long long  
#define eps 2e-5  
using namespace std;  
  
int n,m,L,R,q[2][N],head[2],tail[2],a[N];  
ll fenzi,fenmu; long double sum[N];  
bool ok(long double x){  
    int i; for (i=1; i<=n; i++) sum[i]=sum[i-1]+a[i]-x;  
    head[0]=head[1]=1; tail[0]=tail[1]=0;  
    for (i=L; i<=n; i++){  
        int j=i-L,k=i&1;  
        while (head[k]<=tail[k] && sum[j]<sum[q[k][tail[k]]]) tail[k]--;  
        q[k][++tail[k]]=j;  
        if (i-q[k][head[k]]>R) head[k]++;  
        if (sum[i]-sum[q[k][head[k]]]>0){  
            fenmu=i-q[k][head[k]]; return 1;  
        }  
    }  
    return 0;  
}  
ll gcd(ll aa,ll bb){ return (bb)?gcd(bb,aa%bb):aa; }  
int main(){  
    scanf("%d%d%d",&n,&L,&R); int i;  
    L+=L&1; R-=R&1; long double l=0,r=0;  
    for (i=1; i<=n; i++){  
        scanf("%d",&a[i]); a[i+n]=a[i];  
        if (a[i]>r) r=a[i];  
    }  
    n<<=1;  
    while (l+eps<r){  
        long double mid=(l+r)/2;  
        if (ok(mid)) l=mid; else r=mid;  
    }  
    long double ans=(l+r)/2; fenzi=(ll)(ans*fenmu+0.5);  
    ll tmp=gcd(fenzi,fenmu); fenzi/=tmp; fenmu/=tmp;  
    if (fenmu==1) printf("%lld\n",fenzi); else printf("%lld/%lld\n",fenzi,fenmu);  
    return 0;  
}
