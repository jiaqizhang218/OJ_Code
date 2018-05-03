#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
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
/*const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc() //*/
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 155, p = 1234567891;
int T,k; LL inv[MXN<<1],s1[MXN],s2[MXN],g[MXN],f[MXN],a,d,n,m;
inline void init(int n) {
	inv[0]=inv[1]=1;
	rep(i,2,n) inv[i]=inv[p%i]*(p-p/i)%p;
	rep(i,2,n) inv[i]=inv[i]*inv[i-1]%p;
}
inline void Add(LL &a,LL b){a+=b;if(a>=p)a%=p;}
inline LL Lagrange(LL *a,int n,LL pos) {
	if(pos<=n) return a[pos];
	s1[0]=s2[n+1]=1;
	rep(i,1,n) s1[i]=s1[i-1]*(pos-i)%p;
	per(i,n,1) s2[i]=s2[i+1]*(pos-i)%p;
	LL ans=0;
	rep(i,1,n) Add(ans, a[i] * s1[i - 1] % p * s2[i + 1] % p * inv[i - 1] % p * inv[n - i] % p * ((n - i) & 1 ? -1 : 1));
	return ans;
}
inline LL qpow(LL x,LL y) {
	LL ans=1;
	for(;y;y>>=1,(x*=x)%=p) if(y&1) (ans*=x)%=p;
	return ans;
}
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(T);
	init(300);
	while(T--) {
		rd(k),rd(a),rd(n),rd(d);
		rep(i,1,k+3) g[i]=qpow(i,k);
		rep(i,2,k+3) Add(g[i],g[i-1]);
		rep(i,2,k+3) Add(g[i],g[i-1]);
		f[0]=Lagrange(g,k+3,a);
		rep(i,1,k+5) f[i]=Lagrange(g,k+3,(i*d+a)%p),Add(f[i],f[i-1]);
		printf("%lld\n",(Lagrange(f,k+5,n)+p)%p);
	}
	return 0;
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

