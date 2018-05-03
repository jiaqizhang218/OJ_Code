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
const int MXN = 80;
int n,mod,num[MXN];
struct mtx{
	int p[MXN][MXN];
	inline void init() {
		rep(i,1,n) rep(j,1,n) rd(p[i][j]);
	}
}a,b,c,hsh[MXN<<1];
inline mtx tms(mtx x,mtx y) {
	mtx z;
	rep(i,1,n) rep(j,1,n) { 
		z.p[i][j]=0;
		rep(k,1,n) (z.p[i][j]+=x.p[i][k]*y.p[k][j])%=mod;
	}
	return z;
}
inline mtx mul(mtx x,mtx y) {
	mtx z; int i,j;
	rep(i,1,n) rep(j,1,n) {
		z.p[i][j]=0;
		z.p[i][1]=(z.p[i][1]+x.p[i][j]*y.p[j][1])%mod;
	}
	return z;
}
inline mtx qpow(mtx x,int y) {
	mtx z=x;
	for(;y;y>>=1,x=tms(x,x)) if(y&1) z=tms(x,z);
	return z;
}
inline bool ok(mtx x,mtx z) {
	rep(i,1,n) if(x.p[i][1]!=z.p[i][1]) return 0;
	return 1;
}
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(n),rd(mod); int m=(int)sqrt(mod)+1;
	srand(19260817); a.init(); b.init();
	rep(i,1,n) c.p[i][1]=num[i]=rand()%mod;
	rep(i,0,m-1) hsh[i]=mul(b,c),c=mul(a,c);
	a=qpow(a,m-1);
	rep(i,1,n) c.p[i][1]=num[i];
	rep(i,1,m) {
		c=mul(a,c);
		per(j,m-1,0) 
			if(ok(c,hsh[j])) {
				return printf("%d\n",i*m-j),0;
			}
		}
	return 0;
#ifdef iloi
	debug("\nMy Time: %.4lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

