#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff , Mod = 66662333 , MXN = 301000; 
template <typename T>
inline void rd(T &x) {
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
 
inline int lowbit(int x) {return x&-x;}
 
LL bin[MXN]; int n,T=1;
 
struct ds{
	LL c[MXN];
	inline void Add(int x,int f) {
		if(!f) for(int i=x;i<=n;i+=lowbit(i)) (c[i]+=bin[i-x+1])%=Mod;
		else for(int i=x;i>=1;i-=lowbit(i)) (c[i]+=bin[x-i+1])%=Mod;
	}
	inline LL Ask(int x,int f) {
		LL ans=0;
		if(!f) for(int i=x;i>=1;i-=lowbit(i)) ans=(ans+c[i]*bin[x-i+1])%Mod;
		else for(int i=x;i<=n;i+=lowbit(i)) ans=(ans+c[i]*bin[i-x+1])%Mod;
		return ans;
	}
	inline void clear() {memset(c,0,sizeof c);}
}a,b;
 
int main()
{
#ifdef iloi
	   freopen("test.in","r",stdin);
#endif
	bin[1]=1; rep(i,2,MXN-1) bin[i]=(bin[i-1]*2) % Mod;
	for(;T--;) {
		rd(n);
		rep(i,1,n) {
			int x; rd(x);	int len=min(x-1,n-x);
			if(!len) {a.Add(x,0),b.Add(x,1); continue;}
			LL fi=(a.Ask(x-1,0)-a.Ask(x-len-1,0)*bin[len+1]%Mod+Mod)%Mod;
			LL se=(b.Ask(x+1,1)-b.Ask(x+len+1,1)*bin[len+1]%Mod+Mod)%Mod;
			if((fi^se)!=0) {
				puts("YES");
				rep(j,i+1,n) rd(x);
				goto Ed;
			}
			a.Add(x,0),b.Add(x,1);
		}
		puts("NO");
		Ed:
		a.clear(),b.clear();
	}
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
