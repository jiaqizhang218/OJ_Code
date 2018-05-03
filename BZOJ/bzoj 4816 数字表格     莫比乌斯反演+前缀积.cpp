#include<bits/stdc++.h>
typedef long long LL;
const int MAXN = 1000000 + 5;
const int MOD = 1000000007;
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int f[MAXN],fp[MAXN][3],u[MAXN],mu[MAXN],p[MAXN],pn;
int ff[MAXN],fs[MAXN],fr[MAXN];
inline int pw(int x,int y)
{
	int r = 1; y += (y < 0) ? MOD - 1 : 0;
	for(;y;y>>=1,x=1LL*x*x%MOD)
		if(y&1) r = 1LL * r * x % MOD;
	return r;
}
int main()
{
	int T = read() , n , m , i , j , ans;
	for(f[1]=mu[1]=1,i=2;i<=MAXN;++i)
    {
        if((f[i]=f[i-1]+f[i-2])>=MOD)f[i]-=MOD;
        if(!u[i])p[++pn]=i,mu[i]=-1;
        for(j=1;i*p[j]<=MAXN&&(u[i*p[j]]=1);++j)
            if(i%p[j])mu[i*p[j]]=-mu[i];else break;
    }
	for(i=1;i<=MAXN;++i)fp[i][0]=pw(f[i],-1),fp[i][1]=1,fp[i][2]=f[i];
    for(i=1;i<=MAXN;++i)ff[i]=1;
    for(i=1;i<=MAXN;++i)for(j=i;j<=MAXN;j+=i)ff[j]=1LL*ff[j]*fp[i][mu[j/i]+1]%MOD;
    for(fs[0]=i=1;i<=MAXN;++i)fs[i]=1LL*fs[i-1]*ff[i]%MOD;
    for(fr[i=MAXN]=pw(fs[MAXN],-1);i--;)fr[i]=1LL*fr[i+1]*ff[i+1]%MOD;
    while(T--)
    {
        n=read();m=read();ans=1;
        for(i=1;i<=n&&i<=m;i=j+1)
        {
            j=min(n/(n/i),m/(m/i));
            ans=1LL*ans*pw(1LL*fs[j]*fr[i-1]%MOD,1LL*(n/i)*(m/i)%(MOD-1))%MOD;
        }
        printf("%d\n",ans);
    }
}
