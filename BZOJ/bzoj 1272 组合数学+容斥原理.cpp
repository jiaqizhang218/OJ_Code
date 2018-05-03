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
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
    while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    return;
}
const int N = 100005;
int n,t,Mod,m,b[N];
LL fac[N],inv[N],ans;
inline void init() 
{
	fac[0]=1;
	rep(i,1,Mod)	fac[i]=fac[i-1]*i%Mod;
	inv[1]=1;
	rep(i,2,Mod)	inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
	inv[0]=1;
	rep(i,1,Mod)	inv[i]=inv[i-1]*(LL)inv[i]%Mod;
}
inline LL C(int n,int m) 
{
	if(m>n)	return 0;
	return fac[n]*inv[n-m]%Mod*inv[m]%Mod;
}
inline LL lucas(int n,int m)
{
	if(m>n)	return 0;
	return m?C(n%Mod,m%Mod)*lucas(n/Mod,m/Mod)%Mod:1;
}
LL calc(int state)
{
	int now=m;
	rep(i,0,t-1)	if(state&bin(i))	now-=b[i+1]+1;
	if(now<0)	return 0;
	return lucas(now+n,now);
}
int main()
{
	rd(n),rd(t),rd(m),rd(Mod);
	init();
	rep(i,1,t)	rd(b[i]);
	rep(i,0,bin(t)-1) 
	{
		int opt=0;
		rep(j,0,t-1)	if(bin(j)&i)	opt++;
		if(opt&1)	(ans-=calc(i))%=Mod;
		else (ans+=calc(i))%=Mod;
	}
	ans=(ans+Mod)%Mod;
	printf("%lld\n",ans);
	return 0;
}
