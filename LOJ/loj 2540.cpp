#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_end=(b);i>=i##_end;--i)
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ull;
#define bin(i) (1<<(i))
#define lowbit(x) (x&(-x))
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
const int MXN = 21,Mod = 998244353;
int w[MXN],n,m,f[MXN][1<<MXN],cnt[1<<MXN],fac[MXN],inv[MXN];
inline int A(int x,int y) {
	return 1LL*fac[x]*inv[x-y]%Mod;
}
int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
#endif 
	fac[0]=inv[0]=fac[1]=inv[1]=1;
	rep(i,2,MXN-1) fac[i]=1LL*fac[i-1]*i%Mod;
	rep(i,2,MXN-1) inv[i]=1LL*(Mod-Mod/i)*inv[Mod%i]%Mod;
	rep(i,2,MXN-1) inv[i]=1LL*inv[i-1]*inv[i]%Mod;
	rd(n),rd(m);
	rep(owo,1,m) {
		int x,y; rd(x),rd(y); --x,--y;
		w[x]|=bin(y),w[y]|=bin(x);
	}
	rep(i,0,n-1) w[i]|=bin(i);
	const int ed = bin(n)-1;
	rep(i,1,ed) {
		int now=i; while(now) cnt[i]++,now-=lowbit(now);
	}
	f[0][0]=1;
	rep(i,0,n-1)
		rep(j,0,ed)
			if(f[i][j]) 
				rep(k,0,n-1)
					if(!(j&bin(k)))
						f[i+1][j|w[k]]=(f[i+1][j|w[k]]+1LL*f[i][j]*A(n-cnt[j]-1,cnt[w[k]-(w[k]&j)]-1)%Mod)%Mod;
	per(i,n,1)
		if(f[i][ed])
			return printf("%lld",1LL*f[i][ed]*inv[n]%Mod),0;
}
