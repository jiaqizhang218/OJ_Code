#include<bits/stdc++.h>
const int N = 110; 
#define p 30011
using namespace std;
struct matrix {int a[N][N];}a,b,c;
int a1[N][N],a2[N][N],f[N];
int n,m,L;
matrix operator *(matrix a,matrix b)
{
    matrix c;
    for(int i=1;i<=L;i++)
        for(int j=1;j<=L;j++)
        {
            c.a[i][j]=0;
            for(int k=1;k<=L;k++)
                (c.a[i][j]+=a.a[i][k]*b.a[k][j])%=p;
        }
    return c;
}
int main()
{
#ifdef iloi
	freopen("test.txt","r",stdin);
#endif
    scanf("%d%d",&n,&m);L=2*n;
    if(m==2)
    {
        printf("%d\n",n>2?0:1);
        return 0;
    }   
    for(int i=1;i<=n;i++)
    {
        a2[i][i]=a2[i+n][i+n]=a1[i][i]=a1[i+n][i+n]=1;
        a1[i+n][i]=a2[i][i+n]=1;
        if(i>1)a1[i+n-1][i]=a2[i-1][i+n]=1;
        if(i<n)a1[i+n+1][i]=a2[i+1][i+n]=1;
    }
    for(int i=1;i<=L;i++)
        for(int j=1;j<=L;j++)
            for(int k=1;k<=L;k++)
                (a.a[i][j]+=a1[i][k]*a2[k][j])%=p;
    c=a;
    for(int i=1;i<=L;i++)b.a[i][i]=1;
    for(int y=(m-1)/2-1;y;y>>=1,a=a*a)if(y&1)b=b*a;
    c=b*c;
    int x=2*n;if(m&1)x-=n;
    int ans=(c.a[1][x]+c.a[n+1][x]+c.a[n+2][x]-(ans=b.a[1][x]+b.a[n+1][x]+b.a[n+2][x]))%p;
    printf("%d\n",(ans+p)%p);
    return 0;
}
