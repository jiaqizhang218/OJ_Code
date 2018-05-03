#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
#define RG register
const int MAXN = 100011;
int n,m,ans,pos;
double val;
struct node{
    double maxl;
    int cnt;
}a[MAXN*4];

inline int getint()
{
    RG int w=0,q=0; RG char c=getchar();
    while((c<'0' || c>'9') && c!='-') c=getchar(); if(c=='-') q=1,c=getchar(); 
    while (c>='0' && c<='9') w=w*10+c-'0', c=getchar(); return q ? -w : w;
}

inline void build(int root,int l,int r){   
    if(l==r) return ; int mid=(l+r)>>1; int lc=root<<1,rc=root<<1|1;
    build(lc,l,mid); build(rc,mid+1,r);
}

inline int calc(int root,int l,int r,double height){
    if(l==r) return a[root].maxl>height;
    int mid=(l+r)>>1; int lc=root<<1,rc=lc+1;
    if(a[lc].maxl<=height) return calc(rc,mid+1,r,height);
    return calc(lc,l,mid,height)+a[root].cnt-a[lc].cnt;
}

inline void update(int root,int l,int r){
    if(l==r) { a[root].maxl=val; a[root].cnt=1; return ; }
    int mid=(l+r)>>1; int lc=root<<1,rc=root<<1|1;  if(pos<=mid) update(lc,l,mid);  else update(rc,mid+1,r);
    a[root].maxl=max(a[lc].maxl,a[rc].maxl);
    a[root].cnt=a[lc].cnt+calc(rc,mid+1,r,a[lc].maxl);
}

inline void work(){
    n=getint(); m=getint(); int x,y; build(1,1,n);
    while(m--) {
    x=getint(); y=getint(); pos=x; val=(double)y/x;
    update(1,1,n);
    printf("%d\n",a[1].cnt);
    }
}

int main()
{
    work();
    return 0;
}
