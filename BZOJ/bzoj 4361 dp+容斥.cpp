#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc() //*/	
template <typename T>
inline void rd(T &x) {
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int Mod = 1e9 + 7 , MXN = 2005;
struct node { int a,id; } p[MXN];
int n , ans , k , a[MXN] , h[MXN] , f[MXN][MXN] , fac[MXN] , g[MXN] , t[MXN];
inline bool cmp (node a,node b) {return a.a < b.a;}
inline void add(int &x,int y) {x += y; if(x>=Mod) x-=Mod;}
inline void Add(int x,int y) {
	for(;x<=k;x+=x&-x) add(t[x],y);
}
inline int Ask(int x) {
	int ret=0;
	for(;x;x-=x&-x) add(ret,t[x]);
	return ret;
}
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(n); rep(i,1,n) rd(p[i].a),p[i].id=i;
	sort(p+1,p+n+1,cmp); k=0;p[0].a=-2e9;
	rep(i,1,n) {
		if(p[i].a!=p[i-1].a) ++k; h[p[i].id]=k;
		f[1][i]=1;
	}
	fac[0]=fac[1]=1; rep(i,2,n) fac[i]=1LL*fac[i-1]*i%Mod;
	rep(i,2,n) {
		rep(j,1,k) t[j]=0;
		rep(j,1,n) {
			f[i][j] = Ask( h[j] );
			Add( h[j] , f[i-1][j] );
		}
	}
	rep(i,1,n) rep(j,1,n) add(g[i],f[i][j]);
	ans = 0;
	rep(i,1,n) {
		add(ans , 1LL * g[i] * fac[n-i] % Mod);
		if(i < n) ans = (ans - 1LL * g[i+1] * fac[n-i-1] % Mod * (i+1) % Mod + Mod) % Mod;
	}
	printf("%d",ans);
	return 0;
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
