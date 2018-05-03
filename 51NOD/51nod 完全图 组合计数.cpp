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
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const LL Mod = 998244353;
const int MXN = 505;
LL C[MXN][MXN];
inline void pre() {
	rep(i,0,502) {
		C[i][0]=C[i][i]=1;
      	rep(j,1,i-1)	C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
    }
}
inline LL qpow(LL a,LL b) {
	LL ret=1;
	for(;b;b>>=1,(a*=a)%=Mod)if(b&1)(ret*=a)%=Mod;
	return ret;
}
LL n,m,f[MXN][MXN];
int main() {
	pre(); rd(n), rd(m);
	f[1][1]=1;
	rep(i,2,n) {
		rep(j,2,i) {
			f[i][j]=0;
			rep(k,1,i-(j-1)) 
				(f[i][j] += (C[i-1][k-1] * f[k][1] % Mod * f[i-k][j-1]) % Mod )%=Mod;
		}
		f[i][1]=qpow(2,i*(i-1)/2);
		rep(k,2,i) f[i][1]=(f[i][1]-f[i][k]+Mod)%Mod;
	}
	if(m==1) cout<<f[n][1]-1<<endl;
	else cout<<f[n][m]<<endl;
	return 0;		
}
