#include<bits/stdc++.h>
#define MAXN 50005
using namespace std;
typedef long long LL; 
int n,m,P,c,a[MAXN],phi[MAXN],k;
struct Node
{
    int l,r,cnt;
    LL sum;
}t[MAXN*4];
inline int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
inline int get_phi(int x)
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
inline LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
void build(int idx,int l,int r)
{
    t[idx].l=l,t[idx].r=r,t[idx].cnt=0;
    if(l==r){t[idx].sum=a[l]%phi[0];return;}
    int mid=(l+r)>>1;
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    t[idx].sum=(t[idx<<1].sum+t[idx<<1|1].sum)%phi[0];
}
int query(int idx,int l,int r)
{
    if(l<=t[idx].l&&r>=t[idx].r)return t[idx].sum;
    int mid=(t[idx].l+t[idx].r)>>1;
    if(r<=mid)return query(idx<<1,l,r);
    else if(l>mid)return query(idx<<1|1,l,r);
    else return (query(idx<<1,l,r)+query(idx<<1|1,l,r))%phi[0];
}
inline LL pow(LL a,LL n,LL mod)
{
    LL res=1;
    while(n)
    {
        if(n&1)res=(res*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return res%mod;
}
inline LL modify(int cnt,LL num)
{
    LL res=num;
    if(res>=phi[cnt])res=res%phi[cnt]+phi[cnt];
    for(int i=cnt;i>0;i--)
    {
        res=pow(c,res,phi[i-1]);
        if(gcd(c,res)!=1)res+=phi[i-1];
    }
    return res%phi[0];
} 
void change(int idx,int l,int r)
{
    if(t[idx].cnt>=k)return;
    if(t[idx].l==t[idx].r)
    {
        t[idx].cnt++;
        t[idx].sum=modify(t[idx].cnt,a[t[idx].l]);
        return;
    }
    int mid=(t[idx].l+t[idx].r)>>1;
    if(r<=mid)change(idx<<1,l,r);
    else if(l>mid)change(idx<<1|1,l,r);
    else change(idx<<1,l,r),change(idx<<1|1,l,r);
    t[idx].sum=(t[idx<<1].sum+t[idx<<1|1].sum)%phi[0];
    t[idx].cnt=min(t[idx<<1].cnt,t[idx<<1|1].cnt);
}
int main()
{
    n=read(),m=read(),P=read(),c=read();
    for(int i=1;i<=n;i++)a[i]=read();
    k=0;phi[0]=P; 
    while(P!=1)
    {
        phi[++k]=get_phi(P);
        P=phi[k]; 
    }
    phi[++k]=1; 
    build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int opt=read(),l=read(),r=read();
        if(!opt)change(1,l,r);
        else printf("%d\n",query(1,l,r));
    }
    return 0;
}
