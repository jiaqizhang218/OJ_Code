#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<cmath>  
#include<algorithm>  
#define ll long long  
#define maxn 10005  
using namespace std;  
int n,m,ans;  
int f[maxn],t[maxn],x[maxn],y[maxn];  
inline int read()  
{  
    int x=0,f=1;char ch=getchar();  
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}  
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  
    return x*f;  
}  
int main()  
{  
    n=read();m=read();  
    for(int i = 1 ; i <= m ; i++) f[i]=1;  
    for(int i = 1 ; i <= m ; i++) 
    {  
        t[i]=read();x[i]=read();y[i]=read();  
        for(int j = 1 ; j < i ; j++) if (abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])  
            f[i]=max(f[i],f[j]+1); 
		ans=max(ans,f[i]);   
    }   
    printf("%d\n",ans);  
}  
