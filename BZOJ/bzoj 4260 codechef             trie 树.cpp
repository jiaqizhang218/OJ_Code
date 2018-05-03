#include<cstdio>  
#include<cstring>  
#include<cstdlib>  
#include<cmath>  
#include<iostream>  
#include<algorithm>  
#define maxn 400010  
  
using namespace std;  
  
int ch[maxn*32][2];  
int n,m,a[maxn],tot;  
int lmax[maxn],rmax[maxn];  
  
void build(int x)  
{  
    int now=1;  
    for (int i=31;i>=0;i--)  
    {  
        bool w;  
        if (x&(1<<(i-1))) w=1; else w=0;  
        if (!ch[now][w]) ch[now][w]=++tot;  
        now=ch[now][w];   
    }  
}  
  
int cal(int x)  
{  
    int ans=0,now=1;  
    for (int i=31;i>=0;i--)  
    {  
        bool w;  
        if (x&(1<<(i-1))) w=1; else w=0;  
        if (ch[now][!w]) ans+=(1<<(i-1)),now=ch[now][!w];  
        else now=ch[now][w];  
    }  
    return ans;  
}  
  
int main()  
{  
    scanf("%d",&n);  
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);  
    int now=0;tot=1;  
    build(0);  
    for (int i=1;i<=n;i++)  
    {  
        now^=a[i];  
        build(now);  
        lmax[i]=cal(now);  
    }  
    for (int i=1;i<=n;i++) lmax[i]=max(lmax[i-1],lmax[i]);  
    memset(ch,0,sizeof(ch));  
    now=0;tot=1;  
    build(0);  
    for (int i=n;i>=1;i--)  
    {  
        now^=a[i];  
        build(now);  
        rmax[i]=cal(now);  
    }  
    for (int i=n;i>=1;i--) rmax[i]=max(rmax[i+1],rmax[i]);  
    int ans=0;  
    for (int i=1;i<n;i++) ans=max(ans,lmax[i]+rmax[i+1]);  
    printf("%d\n",ans);  
    return 0;  
} 
