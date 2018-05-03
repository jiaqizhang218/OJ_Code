#include<bits/stdc++.h>
using namespace std;

#define LL long long
LL n,m;
#define maxn 5000011
const int mod=1e9+7;
int phi[maxn],sumphi[maxn],prime[maxn],lp; bool notprime[maxn];

void pre(int n)
{
    phi[1]=1; sumphi[1]=1;
    for (int i=2;i<=n;i++)
    {
        if (!notprime[i]) {prime[++lp]=i; phi[i]=i-1;}
        sumphi[i]=sumphi[i-1]+1ll*i*i%mod*phi[i]%mod;
        sumphi[i]-=sumphi[i]>=mod?mod:0;
        for (int tmp,j=1;j<=lp && 1ll*prime[j]*i<=n;j++)
        {
            notprime[tmp=prime[j]*i]=1;
            if (i%prime[j]) phi[tmp]=phi[i]*(prime[j]-1);
            else {phi[tmp]=phi[i]*prime[j]; break;}
        }
    }
}

struct Edge{LL to; int v,next;};
#define maxh 1000007
struct Hash
{
    int first[maxh],le; Edge edge[maxn];
    Hash() {le=2;}
    void insert(LL y,int v) {int x=y%maxh; Edge &e=edge[le]; e.to=y; e.v=v; e.next=first[x]; first[x]=le++;}
    int find(LL y) {int x=y%maxh; for (int i=first[x];i;i=edge[i].next) if (edge[i].to==y) return edge[i].v; return -1;}
}h;

int two=(mod+1)/2,six=(mod+1)/6;
int calc(LL n)
{
    if (n<=m) return sumphi[n];
    int tmp=h.find(n); if (tmp!=-1) return tmp;
    int ans=(n%mod)%mod*((n+1)%mod)%mod*(n%mod)%mod*((n+1)%mod)%mod*two%mod*two%mod;
    for (LL i=2,last;i<=n;i=last+1)
    {
        last=n/(n/i);
        ans-=((last%mod)%mod*((last+1)%mod)%mod*((last+last+1)%mod)%mod*six%mod
        -((i-1)%mod)%mod*(i%mod)%mod*((i+i-1)%mod)%mod*six%mod)*calc(n/i)%mod;
        ans+=ans<0?mod:0; ans-=ans>=mod?mod:0;
    }
    h.insert(n,ans);
    return ans;
}

int main()
{
    scanf("%lld",&n);
    m=pow(n,2.0/3); pre(m);
    int ans=0;
    for (LL i=1,last;i<=n;i=last+1)
    {
        last=n/(n/i);
        ans+=((last-i+1)%mod)*((last+i)%mod)%mod*two%mod*calc(n/i)%mod;
        ans-=ans>=mod?mod:0;
    }
    printf("%d\n",ans);
    return 0;
}
