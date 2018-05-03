#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int N = 50001;
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
//#define  getchar() nc()
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int n,m,l,r,c[N],b[N];
struct node{
	int l,r,num[2],fl[2],fr[2];
}a[N<<2];
inline void update(int k,int kkz)  
{  
    int l=a[k].l,r=a[k].r,ls=k<<1,rs=k<<1|1,mid=l+r>>1;  
    a[k].num[kkz]=max(max(a[ls].num[kkz],a[rs].num[kkz]),a[ls].fr[kkz]+a[rs].fl[kkz]);  
    a[k].fl[kkz]=a[ls].fl[kkz]+(a[ls].fl[kkz]==mid-l+1 ? a[rs].fl[kkz]:0);  
    a[k].fr[kkz]=a[rs].fr[kkz]+(a[rs].fr[kkz]==r-mid ? a[ls].fr[kkz]:0);  
}  
  
inline void build(int l,int r,int k,int kkz)  
{  
    a[k].l=l;a[k].r=r;  
    if(l==r)  
    {  
        a[k].num[kkz]=a[k].fl[kkz]=a[k].fr[kkz]=b[l]>=0 ? 1:0;return;  
    }  
    int mid=l+r>>1;  
    build(l,mid,k<<1,kkz);build(mid+1,r,k<<1|1,kkz);  
    update(k,kkz);  
}  
  
inline int cal(int k,int u,int v,int kkz)  
{  
    int l=a[k].l,r=a[k].r,mid=l+r>>1,now=0,ll=0,rr=0;  
    if(l>=u && r<=v) return a[k].num[kkz];  
    if(u<=mid)  
    {  
        now=max(now,cal(k<<1,u,v,kkz));  
        if(v>mid) ll=min(mid-u+1,a[k<<1].fr[kkz]);  
    }  
    if(v>mid)  
    {  
        now=max(now,cal(k<<1|1,u,v,kkz));  
        if(u<=mid) rr=min(v-mid,a[k<<1|1].fl[kkz]);  
    }  
    now=max(now,ll+rr);  
    return now;  
}  
  
int main()  
{  
    n=read();  
    for(int i=1;i<=n;i++) c[i]=read();  
    for(int i=1;i<=n;i++) b[i]=c[i]-c[i-1];  
    build(1,n,1,0);  
    for(int i=n;i;i--) b[i]=c[i]-c[i+1];  
    build(1,n,1,1);  
    m=read();  
    while(m--)  
    {  
        l=read();r=read();  
        if(l==r) puts("1");  
        else printf("%d\n",max(cal(1,l+1,r,0),cal(1,l,r-1,1))+1);  
    }  
    return 0;  
}  
