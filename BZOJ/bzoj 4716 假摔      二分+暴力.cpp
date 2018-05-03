#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n,m,xn,yn,K;
int s[1010][1010];
inline int rd()
{
    int ret=0,f=1;  char gc=getchar();
    while(gc<'0'||gc>'9') {if(gc=='-')    f=-f;   gc=getchar();}
    while(gc>='0'&&gc<='9')   ret=ret*10+gc-'0',gc=getchar();
    return ret*f;
}
inline int calc(int a,int b,int c,int d)
{
    return s[c][d]-s[a][d]-s[c][b]+s[a][b];
}
inline bool check(int x)
{
    register int i,j,a,b;
    int ret=K;
    for(i=xn;i<=n;i++)   for(j=yn;j<=m;j++)
    {
        for(a=i-xn;a>=0&&calc(a,j-yn,i,j)<x;a--)  for(b=j-yn;b>=0&&calc(a,b,i,j)<x;b--)
        {
            ret--;
            if(!ret)    return 1;
        }
    }
    return 0;
}
int main()
{
    n=rd(),m=rd(),xn=rd(),yn=rd(),K=rd();
    int i,j;
    for(i=1;i<=n;i++)    for(j=1;j<=m;j++)    s[i][j]=s[i-1][j]-s[i-1][j-1]+s[i][j-1]+rd();
    int l=0,r=s[n][m]+1,mid;
    while(l<r)
    {
        mid=(l+r)>>1;
        if(check(mid))  r=mid;
        else    l=mid+1;
    }
    printf("%d",r);
    return 0;
}
