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
const int g = 3;
const LL Mod = 1004535809;
template <typename T> inline void rd(T &x) {
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 1e6 + 5;
LL a[MXN],b[MXN],q[MXN],h[MXN];
int rev[MXN],M,vis[MXN],tmp,n,m,tot,X;

inline LL fpw(LL x,LL y) {
	LL ret=1;
	for(;y;y>>=1,x=x*x%Mod) if(y&1) ret=ret*x%Mod;
	return ret;
}

inline LL fpw(LL x,LL y,LL Mod) {
	LL ret=1;
	for(;y;y>>=1,x=x*x%Mod) if(y&1) ret=ret*x%Mod;
	return ret;
}

inline int get(LL x) {
	if(x==2) return 1;
	for(int i=2;;++i) {
		bool flag=1;
		for(int j=2;j*j<x;++j) 
			if(fpw(i,(x-1)/j,x)==1) {
				flag=0;
				break;
			}
		if(flag) return i;
	}
}

inline void NTT(LL *A,int f) {
	LL wn,w0,i,j,k; for(int i=0;i<M;++i) if(rev[i]>i) swap(A[rev[i]],A[i]);
	for(i=1;i<M;i<<=1) {
		wn=fpw(g,(Mod-1)/(i<<1));
		if(f==-1) wn=fpw(wn,Mod-2);
		for(j=0;j<M;j+=i<<1) {
			w0=1;
			for(k=0;k<i;++k) {
				int x=A[j+k],y=w0*A[j+k+i]%Mod;
				A[j+k]=(x+y)%Mod;
				A[j+k+i]=(x-y+Mod)%Mod;
				w0=w0*wn%Mod;
			}
		}
	}
	if(f==-1) {
		LL inv = fpw(M,Mod-2);
		for(int i=0;i<M;++i) A[i]=A[i]*inv%Mod;
	}
}

inline void mul(LL *h,LL *q) {
	rep(i,0,M-1) a[i]=h[i]%Mod,b[i]=q[i]%Mod;
	NTT(a,1),NTT(b,1);
	rep(i,0,M-1) a[i]=a[i]*b[i]%Mod;
	NTT(a,-1);
	rep(i,0,m-2) h[i]=(a[i]+a[i+m-1])%Mod;
}

inline void solve(int x) {
	h[0]=1;
	for(;x;x>>=1,mul(q,q)) if(x&1) mul(h,q);
}

main() {
#ifdef iloi
	   freopen("test.in","r",stdin);
#endif
    rd(n),rd(m),rd(X),rd(tot);
    for (int i=1;i<=tot;i++) {
        int x;rd(x),vis[x]=1;
    } 
    int gg=get(m),pos=-1;
    for (int i=0,j=1;i<m-1;i++,j=(j*gg)%m) {
        if (vis[j]) q[i]=1;
        if (j==X) pos=i;   
    }
	for(M=1,tmp=0;M<=(m-1)*2;M<<=1,tmp++); tmp--;
	rep(i,0,M-1) rev[i]=(rev[i>>1]>>1)|((i&1)<<(tmp));
	solve(n);
	if(pos!=-1) printf("%lld\n",h[pos]%Mod);
	else cout<<0;
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
