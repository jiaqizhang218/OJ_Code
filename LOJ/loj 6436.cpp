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
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
template <typename T> inline void rd(T &x) {
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int Mod = 998244353 , g = 3;
const int MXN = 3e6 + 5;
int tmp,n,M,len,rev[MXN],a[MXN],b[MXN];
char str[MXN];

inline int fpw(int x,int y) {
	int ret = 1;
	for(;y;y>>=1,x=1LL*x*x%Mod) if(y&1) ret=1LL*ret*x%Mod;
	return ret;
}

inline void NTT(int *A,int f) {
	int wn,w0,i,j,k; for(int i=0;i<M;++i) if(rev[i]>i) swap(A[rev[i]],A[i]);
	for(i=1;i<M;i<<=1) {
		wn=fpw(g,(Mod-1)/(i<<1));
		if(f==-1) wn=fpw(wn,Mod-2);
		for(j=0;j<M;j+=i<<1) {
			w0=1;
			for(k=0;k<i;++k) {
				int x=A[j+k],y=1LL*w0*A[j+k+i]%Mod;
				A[j+k]=(x+y)%Mod;
				A[j+k+i]=(x-y+Mod)%Mod;
				w0=1LL*w0*wn%Mod;
			}
		}
	}
	if(f==-1) {
		int inv = fpw(M,Mod-2);
		for(int i=0;i<M;++i) A[i]=1LL*A[i]*inv%Mod;
	}
}

int main()
{
#ifdef iloi
	   freopen("test.in","r",stdin);
#endif
	scanf("%s",str); len=strlen(str);
	for(M=1,tmp=0;M<=len*2;M<<=1,tmp++);
	rep(i,0,M-1) rev[i]=((rev[i>>1]>>1)|((i&1)<<(tmp-1)));
	rep(i,0,len-1) a[i]=(str[i]=='1'),b[i]=(str[len-i-1]=='0');
	NTT(a,1),NTT(b,1);
	rep(i,0,M-1) a[i]=1LL*a[i]*b[i]%Mod;
	NTT(a,-1);
	LL ans = 1LL * len * len;
	rep(i,1,len-1) {
		bool gery=0;
		for(int j=i;j<len;j+=i) if(a[len-j-1]||a[len+j-1]) {gery=1;break;}
		if(!gery) ans^=(1LL*(len-i)*(len-i));
	}
	cout<<ans;
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
