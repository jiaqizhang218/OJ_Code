#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rpg(i,x) for(register int i=fir[x];i;i=e[i].nxt)
#define ull unsigned long long
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff , MXN = 1e5 + 5;
template <typename T>
inline void rd(T &x) {
	    x = 0; int f = 1; char CH = getchar();
		while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
		while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
		x=(f==1)?x:-x;  return;
}
const double eps = 1e-6;

double a[MXN],b[MXN],ans;

int n;

bool cmp(double a,double b) {return a>b;}

inline double calc(int i,int j) {
	return (min(a[i],b[j])-(i+j));
}

int main() {
	//ios::sync_with_stdio(false); 
	cin>>n; rep(i,1,n) scanf("%lf%lf",&a[i],&b[i]);	sort(a+1,a+1+n,cmp),sort(b+1,b+1+n,cmp);
	rep(i,1,n) a[i] += a[i-1] , b[i] += b[i-1];
	rep(i,1,n) {
		int l = 0 ,r = n ,ls ,rs;
		while((r - l + 1) / 3 >= eps) {
			ls = l + (r - l + 1)/3 ,rs = r - (r - l + 1)/3;
			if(calc(i,ls) > calc(i,rs)) r = rs;
			else l = ls;
		}
		rep(j,l,r) ans = max(calc(i,j),ans);
	}
	printf("%.4lf\n",ans);
}
