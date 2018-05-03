#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
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
const int MXN = 1e5 + 5;
int n,m,q,p;
LL a[MXN];
map<LL,LL> f;
inline LL get_phi(LL x) {
	LL ans=x,z=x;
	if(f.count(x)) return f[x];
	for(register int i=2;i*i<=x;++i) {
		if(x%i==0) {
			ans-=ans/i;
			while(x%i==0) x/=i;
		}
	}
	if(x>1) ans-=ans/x;
	return f[z]=ans;
}
inline LL qpow(LL a, LL b, LL mod){
    LL ret = 1 , fl  = a >= mod;
    for (;b;b>>=1){
        if (b&1){ret = ret * a;if (ret>=mod)fl=1, ret%=mod;}
        a=a*a;if(a>=mod) a%=mod,fl=1;
    }
    return ret + fl * mod;
}
inline LL solve(int l,int r,LL mod) {
	const LL Mod = mod;
	if(l==r) return a[l];
	if(Mod==1) return 1;
	return qpow(a[l],solve(l+1,r,get_phi(mod)),mod); 
}
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(n),rd(p);
	rep(i,1,n) rd(a[i]);
	for(rd(q);q--;) {
		int l,r;
		rd(l),rd(r);
		printf("%lld\n",solve(l,r,p)%p);
	}
	return 0;
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
