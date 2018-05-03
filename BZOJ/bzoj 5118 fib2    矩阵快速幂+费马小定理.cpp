#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rpg(i,x) for(register int i=fir[x];i;i=e[i].nxt)
#define uLL unsigned long long
#define fi first
#define se second
#define pb push_back
#define bin(i) (1<<i)
#define cls(x,y) memset(x,y,sizeof x)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
const int oo = 0x3f3f3f3f;
/*
const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc() //*/
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
#define Mod(x) ((x)>=mod?(x-mod):(x))
const int MXN = 500010;
const LL mod = 1125899839733759;
struct mtx{LL a[3][3];mtx(){cls(a,0);}}ans,base;
LL n,T;
inline LL mul(LL a, LL b, LL mod)
{
    LL ans=0; a%=mod;
    for(;b;b>>=1, a=Mod(a+a))
    if(b&1) ans=Mod(ans+a);
    return ans;
}
mtx operator*(mtx a, mtx b)
{
    mtx c;
    rep(i,0,1) rep(j,0,1) rep(k,0,1)    c.a[i][j]=Mod(c.a[i][j]+mul(a.a[i][k], b.a[k][j], mod));
    return c;
}
inline LL qpow(LL a, LL b, LL mod)
{
    LL ans=1;
    for(;b;b>>=1, a=mul(a, a, mod))
    if(b&1) ans=mul(ans, a, mod);
    return ans;
}
inline LL mtx_qpow(LL b)
{
    if(!b) return 0; 
    for(;b;b>>=1, base=base*base)
    if(b&1) ans=ans*base;
    return ans.a[1][0];
}
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	int T;rd(T);
	while(T--) {
		rd(n);	LL t = qpow(2,n,mod-1);
		base.a[0][0]=base.a[0][1]=base.a[1][0]=1; base.a[1][1]=0;
		ans.a[0][0]=ans.a[1][1]=1;	ans.a[1][0]=ans.a[0][1]=0;
		cout<<mtx_qpow(t)<<endl;
	}
}
