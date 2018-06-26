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
#define pb push_back
#define bin(i) (1<<i)
#define cls(x,y) memset(x,y,sizeof x)
typedef pair<int,int> PII;
typedef long long LL;
const int INF = 0x7fffffff;
/*const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc() //*/
template <typename T> inline void rd(T &x) {
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 2e6 + 5 , Mod = 1e9 + 7;;
bool vis[MXN+5];
int p[MXN+5],n,pri_num,inv6;
int phi[MXN+5];
inline int fpw(int x,int y) {
	int ret=1;
	for(;y;y>>=1,x=1LL*x*x%Mod) if(y&1) ret=1LL*ret*x%Mod;
	return ret;
}
inline void sieve() {
	phi[1]=1; inv6=fpw(6,Mod-2);
	rep(i,2,MXN) {
		if(!vis[i]) {p[++pri_num]=i;phi[i]=i-1;}
		for(int j=1;j<=pri_num&&p[j]*i<=MXN;++j) {
			vis[p[j]*i]=1;
			if(i%p[j]) {
				phi[i*p[j]]=phi[i]*(p[j]-1);
			} else {
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
		}
	}
	rep(i,2,MXN) phi[i]=1LL*phi[i]*i%Mod,phi[i]=(phi[i]+phi[i-1])%Mod;
}
map<int,int> f;
inline int G(int x) {
	return 1LL*x*(x+1)/2%Mod;
}
int F(int x) {
	if(x<MXN) return phi[x];
	else if(f.count(x)) return f[x];
	int ans=1LL*x*(x+1)%Mod*(x<<1|1)%Mod*inv6%Mod;
	for(int i=2,j;i<=x;i=j+1) {
		j=min(x/(x/i),x);
		ans=(ans-1LL*F(x/i)*(G(j)-G(i-1)+Mod)%Mod+Mod)%Mod;
	}
	return f[x]=ans;
}
int main() {
#ifdef iloi
	   freopen("test.in","r",stdin);
#endif
	rd(n); sieve();
	printf("1\n%d\n",F(n));
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
