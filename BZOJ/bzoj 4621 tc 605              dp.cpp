#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
//#define  getchar() nc()
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int P=1000000007;
int n,m,ans,sum;
int f[510][510],v[510];
int main()
{
    scanf("%d%d",&n,&m);
    int i,j,k,ls,rs;
    for(i=1;i<=n;i++)    scanf("%d",&v[i]);
    f[0][0]=1;
    for(i=1;i<=n;i++)
    {
        for(ls=i;ls>1&&v[ls-1]<v[i];ls--);
        for(rs=i;rs<n&&v[rs+1]<v[i];rs++);
        for(j=m;j>=0;j--)
        {
            f[i][j]=(f[i][j]+f[i-1][j])%P;
            if(j)
            {
                sum=0;
                for(k=ls;k<=rs;k++)  sum=(sum+f[k-1][j-1])%P,f[k][j]=(f[k][j]+sum)%P;
                f[i][j]=(f[i][j]-f[i-1][j-1]+P)%P;
            }
        }
    }
    for(i=0;i<=m;i++)    ans=(ans+f[n][i])%P;
    printf("%d",ans);
    return 0;
}
