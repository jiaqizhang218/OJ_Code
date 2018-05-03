#include<bits/stdc++.h>
#define inf 2147483647  
#define LL long long  
using namespace std;  
int mid,n,f,v[20005];  
struct Point  
{  
    int x,y;  
}a[20005];  
void read(int &x)  
{  
    x=0;  
    char ch=getchar();  
    int fu=1;  
    for (;ch<'0'||ch>'9';ch=getchar())  
        if (ch=='-') fu=-1;  
    for (;ch>='0'&&ch<='9';ch=getchar())  
        x=x*10+ch-'0';  
    x*=fu;  
}  

void Get(int &h1,int &h2,int &s1,int &s2)  
{  
    h1=-inf,h2=inf,s1=inf,s2=-inf;  
    for (int i=1;i<=n;i++)  
        if (!v[i])  
        {  
            h1=max(h1,a[i].x);  
            h2=min(h2,a[i].x);  
            s1=min(s1,a[i].y);  
            s2=max(s2,a[i].y);  
        }  
}  //求最小覆盖矩形的
 
void Paint1(int x,int y)  
{  
    for (int i=1;i<=n;i++)  
        if (a[i].x<=x&&a[i].x>=x-mid&&a[i].y>=y&&a[i].y<=y+mid)  
            v[i]++;  //v[i]表示第i个点有么有被覆盖 
}  
void Paint2(int x,int y)  
{  
    for (int i=1;i<=n;i++)  
        if (a[i].x<=x&&a[i].x>=x-mid&&a[i].y>=y&&a[i].y<=y+mid)  
            v[i]--;   //这个就是回溯 
}  
void dfs(int now)  
{  
    if (f) return;  
    int h1,h2,s1,s2;  
    Get(h1,h2,s1,s2);  
    if (h1==-inf)  
	    {  
	        f=1;return;  
	    }  
    if (now==3)  
	    {  
	        if (max(h1-h2,s2-s1)<=mid) f=1;  
	        return;  
	    }  
    Paint1(h1,s1);  
    	dfs(now+1);  
    Paint2(h1,s1);  
    
    Paint1(h2+mid,s1);  
    	dfs(now+1);  
    Paint2(h2+mid,s1);
	  
    Paint1(h1,s2-mid);  
    	dfs(now+1);  
    Paint2(h1,s2-mid);  
    
    Paint1(h2+mid,s2-mid);  
    	dfs(now+1);  
    Paint2(h2+mid,s2-mid);  
}  
int main()  
{  
    read(n);  
    for (int i=1;i<=n;i++)  
        read(a[i].x),read(a[i].y);
	  
    int ans,L=0,R=1e9;  
    while (L<=R)  
    {  
        mid=(L+R)>>1;  
        f=0;  
        dfs(1);  
        if (f) ans=mid,R=mid-1;  
        else L=mid+1;  
        memset(v,0,sizeof(v));  
    }  
    printf("%d\n",ans);  
    return 0;  
}  
