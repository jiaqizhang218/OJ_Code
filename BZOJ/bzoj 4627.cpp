#include<stdio.h>
#include<iostream>
using namespace std;
const int N=100005;
#define ll long long
int n,tot,i,l,r,x,rt,ls[5000005],rs[5000005],t[5000005];
ll sum[N],Max,Min,ans;
inline void rd(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;	return; 
}
inline void update(ll l,ll r,ll x,int&p)
{
    if(!p) p=++tot;
    if(l==r)
    {
        t[p]++;
        return;
    }
    ll mid=(l+r)>>1;
    if(x<=mid) update(l,mid,x,ls[p]);else
    update(mid+1,r,x,rs[p]);
    t[p]=t[ls[p]]+t[rs[p]];
}
inline void solve(ll l,ll r,ll x,ll y,int p)
{
    if(x<=l&&r<=y)
    {
        ans+=t[p];
        return;
    }
    ll mid=(l+r)>>1;
    if(x<=mid&&ls[p]) solve(l,mid,x,y,ls[p]);
    if(y>mid&&rs[p]) solve(mid+1,r,x,y,rs[p]);
}
int main()
{
    rd(n),rd(l),rd(r);
    for(i=1;i<=n;i++)
    {
        rd(x);
        sum[i]=sum[i-1]+x;
        Max=max(Max,sum[i]);
        Min=min(Min,sum[i]);
    }
    update(Min,Max,0,rt);
    for(i=1;i<=n;i++)
    {
        solve(Min,Max,sum[i]-r,sum[i]-l,rt);
        update(Min,Max,sum[i],rt);
    }
    cout<<ans;
    return 0;
}
