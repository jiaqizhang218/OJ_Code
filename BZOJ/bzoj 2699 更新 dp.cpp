#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define debug(x) cerr<<#x" = "<<x<<endl
#define rep(i,a,b) for(register long long i=(a);i<=(b);++i)
#define per(i,a,b) for(register long long i=(a);i>=(b);--i)
#define edeg(x) for(int i=fir[x];i;i=e[i].nxt)
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define bin(i) (1<<i)
#define cla(x) memset(x,0,sizeof x)
#define meminf(x) memset(x,127,sizeof x)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
const int oo = 0x3f3f3f3f;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
//#define  getchar() nc()
inline LL rd()
{
	LL x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int N = 155;
const LL mod =1000000007;
LL t,n,m,p,a[N],f[N][N<<1][N]; 
//f[i][j][k]表示前i个数,最大值为j,更新了k次的方案数 
int main()
{
#ifdef	iloi
	freopen("test.txt","r",stdin);
#endif
	rep(i,1,300)	f[1][i][0]=i;
	rep(i,2,150) {
		rep(k,0,150) {
			rep(j,1,300) {
				if(k)	f[i][j][k]=f[i-1][j-1][k-1];
				f[i][j][k]=(f[i][j][k]+1LL*j*(f[i-1][j][k]-f[i-1][j-1][k]+mod)%mod+f[i][j-1][k])%mod;
			}			
		}
	}
	for(t=rd();t;t--)
	{
		n=rd(),m=rd(),p=rd();
		printf("%d\n",f[n][m][p]);
	}
}
