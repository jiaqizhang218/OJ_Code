#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define For(i,a,b) for(register int i=(a),i##_end=(b);i<i##_end;++i)
#define fi first
#define se second
#define pb push_back
#define bin(i) (1<<i)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
template <typename T>
inline void rd(T &x) {
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 20 , Mod = 998244353;
int n,a[MXN],ans,sum[1<<MXN],f[1<<MXN],g[1<<MXN];
#define lowbit(x) (x&(-x))
int main() {
#ifdef iloi
	   freopen("test.in","r",stdin);
#endif
	rd(n); For(i,0,n) rd(a[i]);
	int ed=bin(n)-1;
	For(s,0,bin(n)) {
		For(i,0,n) {
			if(s&bin(i)) sum[s]+=a[i];
		}
	}
	g[0]=1;
	For(s,0,bin(n)) {
		if(sum[s]>0) continue;
		int tmp=s;
		while(tmp) {
			int tmps=lowbit(tmp);
			tmp-=tmps;
			g[s]=(g[s]+g[s^tmps])%Mod;
		}
	}
	For(i,0,n) f[bin(i)]=1;
	For(s,1,bin(n)) {
		int tmp=s;
		while(tmp) {
			int tmps=lowbit(tmp);
			tmp-=tmps;
			if(sum[s^tmps]>0) {
				f[s]=(f[s]+f[s^tmps])%Mod;
			}
		}
	}
	For(s,0,bin(n)) {
		int tmp=ed^s;
		sum[s]=(sum[s]%Mod+Mod)%Mod;
		ans=(ans+1LL*sum[s]*f[s]%Mod*g[tmp]%Mod)%Mod;
	}
	cout<<ans;
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
