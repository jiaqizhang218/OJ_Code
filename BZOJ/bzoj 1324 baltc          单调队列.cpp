#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
const int N = 1001000;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
#define  getchar() nc()
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int id1[N],x1[N],l1,r1;  
int id2[N],x2[N],l2,r2;  
int n,m,p,s[N];  
int main()  
{  
    int i;  
    n=read(),m=read(),p=read(); 
    for(i=1;i<=n;i++)s[i]=read();  
    l1=l2=1,r1=r2=0;  
    int flag=1;  
    for(i=1;i<=n;i++)  
    {  
        while(l1<=r1&&i-id1[l1]>=m)l1++;  
        while(l2<=r2&&i-id2[l2]>=m)l2++;  
        while(l1<=r1&&s[i]>=x1[r1])r1--;  
        while(l2<=r2&&s[i]<=x2[r2])r2--;  
        id1[++r1]=id2[++r2]=i;  
        x1[r1]=x2[r2]=s[i];  
        if(i>=m)if(x1[l1]-x2[l2]<=p)  
            printf("%d\n",i-m+1),flag=0;  
    }  
    if(flag)puts("NONE");  
    return 0;  
} 
