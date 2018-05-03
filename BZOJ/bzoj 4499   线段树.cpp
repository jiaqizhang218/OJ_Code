#include <cstdio>
#include <cstring>
#include <iostream>
#define lson x<<1
#define rson x<<1|1
using namespace std;
typedef long long ll;
const ll P=1000000007;
const int N=200010;
int n,m;
ll B[N],K[N];
char str[5];
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
#define  getchar() nc()
struct node
{
    ll b,k;
    node() {}
    node(ll x,ll y) {b=x,k=y;}
    node operator + (const node &a) const {return node((b*a.k+a.b)%P,k*a.k%P);}
}s[N<<2];
void build(int l,int r,int x)
{
    if(l==r)
    {
        s[x]=node(B[l],K[l]);
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,lson),build(mid+1,r,rson);
    s[x]=s[lson]+s[rson];
}
void updata(int l,int r,int x,int a)
{
    if(l==r)
    {
        s[x]=node(B[l],K[l]);
        return ;
    }
    int mid=(l+r)>>1;
    if(a<=mid)   updata(l,mid,lson,a);
    else    updata(mid+1,r,rson,a);
    s[x]=s[lson]+s[rson];
}
node query(int l,int r,int x,int a,int b)
{
    if(a<=l&&r<=b)    return s[x];
    int mid=(l+r)>>1;
    if(b<=mid)   return query(l,mid,lson,a,b);
    if(a>mid)    return query(mid+1,r,rson,a,b);
    return query(l,mid,lson,a,b)+query(mid+1,r,rson,a,b);
}
inline char rc(){char c;while((c=getchar())!='M'&&c!='Q');return c;}
inline int rd()
{
    int ret=0,f=1;  char gc=getchar();
    while(gc<'0'||gc>'9') {if(gc=='-')    f=-f;   gc=getchar();}
    while(gc>='0'&&gc<='9')   ret=ret*10+gc-'0',gc=getchar();
    return ret*f;
}
int main()
{
    int i,a,b;
    ll x;
    n=rd(),m=rd();
    for(i=1;i<=n;i++)    K[i]=rd(),B[i]=rd();
    build(1,n,1);
    for(i=1;i<=m;i++)
    {
        str[0]=rc();
        if(str[0]=='M')
        {
            a=rd(),K[a]=rd(),B[a]=rd();
            updata(1,n,1,a);
        }
        else
        {
            a=rd(),b=rd(),x=rd();
            node tmp=query(1,n,1,a,b);
            printf("%lld\n",(x*tmp.k+tmp.b)%P);
        }
    }
    return 0;
}
