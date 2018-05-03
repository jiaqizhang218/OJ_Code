#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
#define ll long long 
#define N 10000005 
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,sum[400005];
bool tag[400005];
void pushdown(int k,int l,int r)
{
    if (l==r) return;
    int mid=(l+r)>>1;tag[k]=0;
    tag[k<<1]^=1;tag[k<<1|1]^=1;
    sum[k<<1]=mid-l+1-sum[k<<1];
    sum[k<<1|1]=r-mid-sum[k<<1|1];
}
void modify(int k,int l,int r,int x,int y)
{
    if (l==x&&r==y){sum[k]=r-l+1-sum[k];tag[k]^=1;return;}
    if (tag[k]) pushdown(k,l,r);
    int mid=(l+r)>>1;
    if (y<=mid) modify(k<<1,l,mid,x,y);
    else if (x>mid) modify(k<<1|1,mid+1,r,x,y);
    else modify(k<<1,l,mid,x,mid),modify(k<<1|1,mid+1,r,mid+1,y);
    sum[k]=sum[k<<1]+sum[k<<1|1];
}
int query(int k,int l,int r,int x,int y)
{
    if (l==x&&r==y) return sum[k];
    if (tag[k]) pushdown(k,l,r);
    int mid=(l+r)>>1;
    if (y<=mid) return query(k<<1,l,mid,x,y);
    else if (x>mid) return query(k<<1|1,mid+1,r,x,y);
    else return query(k<<1,l,mid,x,mid)+query(k<<1|1,mid+1,r,mid+1,y);
}
int main()
{
    n=read();m=read();
    for (int i=1;i<=m;i++)
    {
        int opt=read(),l=read(),r=read();
        if (opt==0) modify(1,1,n,l,r);
        else printf("%d\n",query(1,1,n,l,r));
    }
    return 0;
}
