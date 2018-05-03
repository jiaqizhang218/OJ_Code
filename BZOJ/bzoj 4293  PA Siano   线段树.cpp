#include<bits/stdc++.h>
#define ll long long 
#define N 1000005
using namespace std;
int n,m;
ll ans,now,last,stdd;
int a[N];
int l[N<<2],r[N<<2];
ll s[N<<2],sum[N<<2],vl[N<<2],vr[N<<2];
struct node {bool a;ll b,c;} tag[N<<2];
inline ll read()
{
    ll a=0,f=1; char c=getchar();
    while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
    while (c>='0'&&c<='9') {a=a*10+c-'0'; c=getchar();}
    return a*f;
}
void build(int k,int x,int y)
{
    l[k]=x; r[k]=y; 
    if (l[k]==r[k]) {s[k]=a[l[k]]; return;}
    int mid=l[k]+r[k]>>1;
    build(k<<1,x,mid); build(k<<1|1,mid+1,y);
    s[k]=s[k<<1]+s[k<<1|1];
}
inline void add(int k,node p)
{
    if (p.a)
    {
        vl[k]+=p.b+p.c*a[l[k]];
        vr[k]+=p.b+p.c*a[r[k]];
        sum[k]+=p.b*(r[k]-l[k]+1)+p.c*s[k];
    }
    else
    {
        vl[k]=p.b+p.c*a[l[k]];
        vr[k]=p.b+p.c*a[r[k]];
        sum[k]=p.b*(r[k]-l[k]+1)+p.c*s[k];
    }
    tag[k].a&=p.a;
    tag[k].b=tag[k].b*p.a+p.b;
    tag[k].c=tag[k].c*p.a+p.c;
}
void find(int k)
{
    if (vr[k]<=stdd) return;
    if (vl[k]>stdd)
    {
        ans+=sum[k]-(r[k]-l[k]+1)*stdd;
        add(k,(node){0,stdd,0});
        return;
    }
    add(k<<1,tag[k]); add(k<<1|1,tag[k]);
    tag[k].a=1; tag[k].b=0; tag[k].c=0;
    int mid=l[k]+r[k]>>1;
    find(k<<1); find(k<<1|1);
    vl[k]=vl[k<<1]; vr[k]=vr[k<<1|1]; sum[k]=sum[k<<1]+sum[k<<1|1];
}
int main()
{
    n=read(); m=read();
    for (int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    build(1,1,n);
    for (int i=1;i<=m;i++)
    {
        now=read(),stdd=read();
        add(1,(node){1,0,now-last});
        ans=0;
        find(1);
        last=now;
        printf("%lld\n",ans);
    }
    return 0;
}
