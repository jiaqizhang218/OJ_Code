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
template <typename T> inline void rd(T &x) {
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int Mod = 998244353;
const int MXN = 2e5 + 5;
int n,k,fac[MXN],inv[MXN],a[MXN],b[MXN];
inline int C(int n,int m) {
	if(n<m) return 0;
	return 1LL*fac[n]*inv[m]%Mod*inv[n-m]%Mod;
}
int main() {
#ifdef iloi
	   freopen("test.in","r",stdin);
#endif
	rd(n),rd(k); rep(i,1,n) rd(a[i]),b[i]=a[i];
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	rep(i,2,MXN/2) fac[i]=1LL*fac[i-1]*i%Mod;
	rep(i,2,MXN/2) inv[i]=1LL*(Mod-Mod/i)*inv[Mod%i]%Mod;
	rep(i,2,MXN/2) inv[i]=1LL*inv[i-1]*inv[i]%Mod;	
	sort(a+1,a+1+n);
	rep(i,1,n) {
		int ans=0;
		if(b[i]==0) {
			printf("%d\n",C(n,k));
			continue;
		}
		int tot1,tot2;
		tot1=upper_bound(a+1,a+1+n,b[i]*2-1)-lower_bound(a+1,a+1+n,b[i]);
		tot2=upper_bound(a+1,a+1+n,b[i]-1)-lower_bound(a+1,a+1+n,(b[i]+1)/2)+1;
		ans=(C(n-tot2,k)+C(n-tot1,k-tot1))%Mod;
		printf("%d\n",ans);
	}
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
