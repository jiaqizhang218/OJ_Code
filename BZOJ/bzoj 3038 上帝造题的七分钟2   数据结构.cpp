#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
ll a[100001];int n,m;
struct data{
       int l,r;ll sum;
       bool flag;
       }tr[400001];
void build(int k,int s,int t)
{
     tr[k].l=s;tr[k].r=t;
     
     if(s==t)
	 {
            tr[k].sum=a[s];
            if(a[s]==1||a[s]==0)tr[k].flag=1;
            return;
     }
     int mid=(s+t)>>1;
     build(k<<1,s,mid);
     build(k<<1|1,mid+1,t);  	// 两个方向建立 线段树 我第一次看见 毫无感觉.jpg  看来还是对线段树太不熟悉了
	 							// 我太弱了。 
     
     tr[k].sum=tr[k<<1].sum+tr[k<<1|1].sum;
     // flag 是干啥的啊QAQ 
     tr[k].flag=tr[k<<1].flag&tr[k<<1|1].flag;
}
void change(int k,int x,int y)
{
     if(tr[k].flag)return;
     int l=tr[k].l,r=tr[k].r;
     if(l==r){
              tr[k].sum=(ll)sqrt(tr[k].sum);
              if(tr[k].sum==1||tr[k].sum==0)tr[k].flag=1;
              return;
     }
     int mid=(l+r)>>1;
     if(mid>=y)change(k<<1,x,y);
     else if(mid<x)change(k<<1|1,x,y);
     else {
          change(k<<1,x,mid);
          change(k<<1|1,mid+1,y);
          }
    tr[k].sum=tr[k<<1].sum+tr[k<<1|1].sum;
    tr[k].flag=tr[k<<1].flag&tr[k<<1|1].flag;
}

ll ask(int k,int x,int y)
{
    int l=tr[k].l,r=tr[k].r;
    if(l==x&&r==y)return tr[k].sum;
    int mid=(l+r)>>1;
    if(mid>=y)return ask(k<<1,x,y);
    else if(mid<x)return ask(k<<1|1,x,y);
    else return ask(k<<1,x,mid)+ask(k<<1|1,mid+1,y); 
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    
    build(1,1,n);
    
    scanf("%d",&m);
    
    for(int i=1;i<=m;i++)
    {
            int k,x,y;
            scanf("%d%d%d",&k,&x,&y);
            if(x>y)swap(x,y);
            if(!k)change(1,x,y);
            else printf("%lld\n",ask(1,x,y));
            }
    return 0;
}
