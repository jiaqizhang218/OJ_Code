#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=100010;
int n,k,ans;
 
int v[maxn];
int f[maxn<<2];
inline int rd()
{
    int ret=0,f=1;  char gc=getchar();
    while(gc<'0'||gc>'9') {if(gc=='-')    f=-f;   gc=getchar();}
    while(gc>='0'&&gc<='9')   ret=ret*10+gc-'0',gc=getchar();
    return ret*f;
}
int main()
{
    n=rd(),k=rd();
    int i,j;
    for(i=1;i<=n;i++)    v[i]=rd();
    if(n-k>=16)
    {
        for(i=1<<16;i;i>>=1)
        {
            for(j=1;j<=n;j++)    if(v[j]&i)  break;
            if(j<=n) ans|=i;
        }
        printf("%d",ans);
        return 0;
    }
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for(i=1;i<=n;i++)
    {
        for(j=(1<<17)-1;~j;j--)
        {
            f[j|v[i]]=min(f[j|v[i]],f[j]+1);
        }
    }
    for(i=(1<<17)-1;~i;i--)
    {
        for(j=1<<16;j;j>>=1)    if(i&j) f[i^j]=min(f[i^j],f[i]);
    }
    for(i=1<<16;i;i>>=1)
    {
        if(f[ans|i]<=n-k)    ans|=i;
    }
    printf("%d",ans);
    return 0;
}
