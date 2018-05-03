#include<cstdio>  
#include<cmath>  
using namespace std;  
inline int max(int a,int b){return a>b?a:b;}  
int pre[10000005],f[50005],n,l;  
char c;  
inline void read(int &a)  
{  
    a=0;do c=getchar();while(c<'0'||c>'9');  
    while(c<='9'&&c>='0')a=(a<<3)+(a<<1)+c-'0',c=getchar();  
}  
int main()  
{  
    int n,l;  
    read(n),read(l);  
    int ans=0;  
    for(int i=1;i<=n;i++)   
    {  
        int x;  
        read(x);  
        for(int j=1;j<=sqrt(x);j++)  
           if(x%j==0)  
              {  
                if(j>=l)  
                   f[i]=max(f[i],f[pre[j]]+1),pre[j]=i;  
                int k=x/j;  
                if(k>=l&&k!=j)  
                    f[i]=max(f[i],f[pre[k]]+1),pre[k]=i;  
              }  
        ans=max(ans,f[i]);  
    }  
 	printf ("%d\n",ans);  
}
