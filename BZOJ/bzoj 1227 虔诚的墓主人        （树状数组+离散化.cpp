#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib> 
#define N 100005
#define ll int
using namespace std;
ll lx,ly,n,k,cnt,b[N],c[N][11],num[N],hash[N],sum[N],tmp,ans;
struct data{
    ll x,y,l,r,u,d;
}a[N];
ll read(){
    ll x=0;
    char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar());
    for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;
    return x;
}
void add(ll x,ll t){
    for (;x<=cnt;x+=x&(-x)) b[x]+=t;
}
ll qry(ll x){
    ll t=0;
    for (;x;x-=x&(-x)) t+=b[x];
    return t;
}
ll find(ll x){
    ll l=1,r=cnt,mid;
    while (l<r){
        mid=(l+r)/2;
        if (hash[mid]<x) l=mid+1; else r=mid;
    }
    return l;
}
bool cmp(data a,data b){return a.y<b.y||(a.x<b.x&&a.y==b.y);}
int main(){
    lx=read();
    ly=read();
    n=read();
    for (ll i=1;i<=n;i++){
        num[i]=a[i].x=read();
        a[i].y=read();
    }
    sort(num+1,num+n+1);
    hash[cnt=1]=num[1];
    for (ll i=2;i<=n;i++) 
        if (num[i]!=num[i-1]) hash[++cnt]=num[i];	//离散化 
    sort(a+1,a+n+1,cmp);
    for (ll i=1;i<=n;i++) a[i].x=find(a[i].x);
    tmp=ans=0;
    //u d l r
    for (ll i=1;i<=n;i++){
        if (a[i].y==a[i-1].y) tmp++; else tmp=1;
        a[i].l=tmp;
        sum[a[i].x]++;
        a[i].u=sum[a[i].x];
    }
    tmp=0;
    for (ll i=n;i;i--){
        if (a[i].y==a[i+1].y) tmp++; else tmp=1;
        a[i].r=tmp;
        a[i].d=sum[a[i].x]-a[i].u;
    }
    c[0][0]=1; 
    k=read();  
    for (ll i=1;i<=n;i++){  
        c[i][0]=1;  
        for (ll j=1;j<=k&&j<=i;j++) c[i][j]=c[i-1][j]+c[i-1][j-1];  
    }  //组合数递推 
    
    for (ll i=1;i<=n;i++){  
        add(a[i].x,c[a[i].u][k]*c[a[i].d][k]-qry(a[i].x)+qry(a[i].x-1));  
        if (i>1&&a[i].y==a[i-1].y)  
            ans+=c[a[i-1].l][k]*c[a[i].r][k]*(qry(a[i].x-1)-qry(a[i-1].x));  
    }  
    printf("%d\n",ans&2147483647);  
    return 0; 
}
