#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define rep(i,a,b) for(register long long i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register long long i=(a),i##_st=(b);i>=i##_st;--i)
typedef long long LL;
const LL INF = 0x7fffffff;
template <typename T>
inline void rd(T &x)
{
    x = 0; LL f = 1; char CH = getchar();
    while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
    while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const LL MXN = 1e6 + 5 , Mod = 1e9 + 7;
LL inv[MXN+5],fac[MXN+5];
inline void init(){
	inv[0]=inv[1]=fac[0]=fac[1]=1; 
	rep(i,2,MXN)inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
	rep(i,2,MXN)fac[i]=fac[i-1]*i%Mod;
	rep(i,2,MXN)inv[i]=inv[i]*inv[i-1]%Mod;
}
inline LL C(LL n,LL m) {return fac[n]*inv[m]%Mod*inv[n-m]%Mod;}
inline LL qpow(LL n,LL m) {LL ret=1; for(;m;m>>=1,(n*=n)%=Mod)	if(m&1) (ret*=n)%=Mod;return ret%Mod;}
LL n,m;	LL ans,h[MXN],f[MXN],g[MXN];
int main()
{
	init();
	rd(n),rd(m);
	if(n<m) return puts("0"),0;
  	if(n==1 && m==1) return puts("0"),0;
  	if(n==2 && m==2) return puts("1"),0;
  	if(m==1) return puts("0"),0;
	rep(i,1,n)	h[i]=qpow(i,n-2);
	rep(i,1,n-m) {
		if((n-m-i)&1)	(ans-=1LL*C(n-m,i)*h[i])%=Mod;
		else (ans+=1LL*(C(n-m,i)*h[i]))%=Mod;
	}
	ans = C(n,m) * ans % Mod;
	cout<<(ans+Mod)%Mod;
}
