#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
typedef long long LL;
const int INF = 0x7fffffff;
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 1e6 + 6 , Mod = 19930726 ;

LL sum[MXN] , k , ans = 1 , cnt = 0;
int p[MXN] , n , m ; 
char s[MXN];

inline LL qpow(LL x,LL y) {
	LL ret=1; 
	for(;y;y>>=1,x=x*x%Mod) if(y&1) ret=ret*x%Mod;
	return ret;
}

inline void manacher() {
	scanf("%d%lld",&n,&k);  
    scanf("%s",s+1);  
    int mx=0,id=0;s[0]='#';s[n+1]='!';  
    for (int i=1;i<=n;i++) {  
        if (mx>i) p[i]=min(p[2*id-i],mx-i); else p[i]=1;  
        while (s[i+p[i]]==s[i-p[i]]) p[i]++;  
        if (i+p[i]>mx) mx=i+p[i],id=i;  
        sum[0]++;sum[p[i]+1]--;  
    }  
}

int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	manacher();
	rep(i,1,n) sum[i] += sum[i-1];
	per(i,n,1) {
		if( cnt + sum[i] < k) ans = ans * qpow(2 * i - 1 , sum[i]) % Mod , cnt += sum[i];
		else {ans = ans * qpow(2 * i - 1 , k - cnt) % Mod ; cnt = k ; break; }
	}
	if( cnt < k ) puts("-1");
	else printf("%lld\n",ans);
	return 0;
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
