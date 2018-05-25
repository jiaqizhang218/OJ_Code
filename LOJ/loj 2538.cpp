#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_end=(b);i>=i##_end;--i)
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ull;
template <typename T> inline void rd(T &x) {
    x=0;int f=1;char CH=getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;return;
}
template <typename T> inline bool chMax(T &a,T &b) {
    return a<b?a=b,true:false;
}
template <typename T> inline bool chMin(T &a,T &b) {
    return a>b?a=b,true:false;
}
const int MXN = 3e3 + 5 , Mod = 998244353;
int T,a[MXN],b[MXN],n,m,k,f[MXN][MXN],g[MXN][MXN],sum[MXN][MXN],C[MXN][MXN];
inline int F(int x,int y) {
	if(x<y) return 0;
	if(!y) return C[n][x];
	int ret=0;
	rep(i,x-y+1,n-y+1)
		ret=(ret+1LL*f[y][i]*C[i-1][x-y]%Mod)%Mod;
	return ret;
}
inline int G(int x,int y) {
	if(x<y) return 0;
	int ret=0;
	rep(i,x-y+1,n-y+1)
		ret=(ret+1LL*g[y][i]*C[i-1][x-y]%Mod)%Mod;
	return ret;
}
inline void work() {
	rep(i,1,n) f[1][i]=a[i],sum[1][i]=(sum[1][i-1]+a[i])%Mod;
	rep(i,2,n) {
		rep(j,1,n-i+1) f[i][j]=1LL*(sum[i-1][n]-sum[i-1][j]+Mod)*a[j]%Mod;
		rep(j,1,n) sum[i][j]=(sum[i][j-1]+f[i][j])%Mod;
	}
	rep(i,1,n) g[1][i]=b[i],sum[1][i]=(sum[1][i-1]+b[i])%Mod;
	rep(i,2,n) {
		rep(j,1,n-i+1) g[i][j]=((sum[i-1][n]-sum[i-1][j]+Mod)+1LL*b[j]*C[n-j][i-1]%Mod)%Mod;
		rep(j,1,n) sum[i][j]=(sum[i][j-1]+g[i][j])%Mod;
	}
	int ans=0;
	rep(i,0,m-1) {
		if(i<k) ans=(ans+1LL*F(i,i)*G(m-i,k-i)%Mod)%Mod;
		else ans=(ans+1LL*F(i,k-1)*G(m-i,1)%Mod)%Mod;
	}
	printf("%d\n",ans);
}
int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
#endif 
	rd(T); 
	rep(i,0,3000) {
		C[i][0]=1;
		rep(j,1,i) {
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
		}
	}
	rep(owo,1,T) {
		rd(n),rd(m),rd(k);
		rep(i,1,n) rd(a[i]); rep(i,1,n) rd(b[i]);
		sort(a+1,a+1+n),sort(b+1,b+1+n);
		rep(i,1,n) rep(j,1,n) f[i][j]=g[i][j]=0;
		work();
	}
}
