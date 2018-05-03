#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int maxn = 2010;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
struct node
{
    LL x,y,c,next;
}a[maxn*2];LL len,first[maxn];
LL n,K,size[maxn],f[maxn][maxn],ls[maxn];
LL mymin(LL x,LL y){return (x<y)?x:y;}
LL mymax(LL x,LL y){return (x>y)?x:y;}
void ins(LL x,LL y,LL c)
{
    a[++len].x=x;a[len].y=y;
    a[len].c=c;a[len].next=first[x];first[x]=len;
}
void treedp(LL x,LL fa)
{
    LL i,j,k;size[x]=1;
    for (k=first[x];k!=-1;k=a[k].next)
    {
        LL y=a[k].y;
        if (y==fa) continue;
        treedp(y,x);
        for (i=0;i<=K;i++) ls[i]=0;
        LL sizx=mymin(K,size[x]);
        LL sizy=mymin(K,size[y]);
        for (i=0;i<=sizx;i++)
         for (j=0;j<=sizy;j++) if (i+j<=K)
         {
             LL tt=j*(K-j)+(size[y]-j)*(n-K-(size[y]-j));
             ls[i+j]=mymax(ls[i+j],f[x][i]+f[y][j]+tt*a[k].c);
         }
        for (i=0;i<=K;i++) f[x][i]=ls[i];
        size[x]+=size[y];
    }
}
int main()
{
    LL i,x,y,c;
    scanf("%lld%lld",&n,&K);
    len=0;memset(first,-1,sizeof(first));
    for (i=1;i<n;i++)
    {
        scanf("%lld%lld%lld",&x,&y,&c);
        ins(x,y,c);ins(y,x,c);
    }
    memset(f,0,sizeof(f));
    treedp(1,0);
    printf("%lld\n",f[1][K]);
    return 0;
}
