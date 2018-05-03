#include<iostream>  
#include<cstdio>  
#define N 2000010  
using namespace std;  
long long s[N],h=1,t=1;  
long long a[N],f[N],g[N];  
int main()  
{  
    long long n,p,d;  
    scanf("%lld%lld%lld",&n,&p,&d);  
    long long i,j,x,y;  
    for(i=1;i<=n;i++)  
    {  
        scanf("%lld",&a[i]);  
        f[i]=f[i-1]+a[i];  
    }  
    for(i=0;i<=n;i++)  
    {  
        if(i+d>n) g[i]=f[n]-f[i];  
        else g[i]=f[i+d]-f[i];  
    }  
    long long ans=d,now=0;  
    s[1]=0;  
    for(i=d+1;i<=n;i++)  
    {  
        while(h<=t&&g[s[t]]<g[i-d]) t--;  
        t++;s[t]=i-d;  
        while(now<i-d&&f[now]+g[s[h]]<f[i]-p)  
        {  
            now++;  
            if(now>s[h]) h++;  
        }    
        ans=max(ans,i-now);  
    }  
    printf("%lld",ans);  
} 
