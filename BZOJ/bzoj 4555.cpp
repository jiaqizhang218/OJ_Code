#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define For(i,a,b) for(register int i=(a),i##_end=(b);i<i##_end;++i)
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
const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc() //*/
template <typename T> inline void rd(T &x) {
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int Mod = 998244353 , g = 3;
const int MXN = 1e5 + 50000;
int n,a[MXN<<1],b[MXN<<1],fac[MXN<<1],rev[MXN<<1],M,ans,tmp;

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
int main() {
	rd(n); fac[0]=1; rep(i,1,n) fac[i]=1LL*i*fac[i-1]%Mod;
	for(M=1,tmp=0;M<=n*2;M<<=1,tmp++);
	For(i,0,M) rev[i]=rev[i>>1]>>1|((i&1)<<(tmp-1));
	rep(i,0,n) {
		a[i]=fpw(fac[i],Mod-2);
		b[i]=(1-fpw(i,n+1)+Mod)%Mod;
		b[i]=1LL*b[i]*fpw(1-i,Mod-2)%Mod;
		b[i]=1LL*b[i]*a[i]%Mod;
		b[i]=(b[i]+Mod)%Mod;
		if(i&1) a[i]=Mod-a[i];
	}
	b[1]=n+1;
	NTT(a,1),NTT(b,1);
	For(i,0,M) a[i]=1LL*a[i]*b[i]%Mod;
	NTT(a,-1);
	rep(i,0,n) {
		tmp=1LL*fpw(2,i)*fac[i]%Mod*a[i]%Mod;
		ans=(ans+tmp)%Mod;
	}
	cout<<ans;
}
