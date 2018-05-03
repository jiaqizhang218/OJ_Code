#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rpg(i,x) for(register int i=fir[x];i;i=e[i].nxt)
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define bin(i) (1<<i)
#define cls(x,y) memset(x,y,sizeof x)
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
const LL N = 2100,mod=1000000009;
LL a[N],b[N],n,m,k,f[N>>1][N>>1][12];
int main()
{
#ifdef	iloi
	freopen("test.txt","r",stdin);
#endif
	n=rd(),m=rd(),k=rd();
	rep(i,1,n) a[i]=rd();	rep(i,1,m) b[i]=rd();
	sort(a+1,a+1+n);sort(b+1,b+1+m);	f[0][0][0]=1;
	rep(i,0,n) 
		rep(j,0,m) 
			rep(t,0,k) {
				if(i+j==0)	continue;
				if(i==0) f[i][j][t]=f[i][j-1][t];
				else if(j==0) f[i][j][t]=f[i-1][j][t];
				else f[i][j][t]=f[i-1][j][t]+f[i][j-1][t]-f[i-1][j-1][t];
				f[i][j][t]=(f[i][j][t]%mod+mod)%mod;
				if(a[i]>b[j])	if(t!=0)	f[i][j][t]+=f[i-1][j-1][t-1];
				f[i][j][t]=(f[i][j][t]%mod+mod)%mod;
			}
	printf("%lld\n",f[n][m][k]);
	
	return 0;
}
