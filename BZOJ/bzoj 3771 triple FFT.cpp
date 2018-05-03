#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
typedef long long LL;
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const double pi = acos(-1.0);
const int MXN = 2e5 + 5;
struct Cp{
	double x,y;
	Cp (double _x=0, double _y=0) {x=_x,y=_y;}
	Cp operator + (const Cp& rhs) {return Cp(x+rhs.x,y+rhs.y);}
	Cp operator - (const Cp& rhs) {return Cp(x-rhs.x,y-rhs.y);}
	Cp operator * (const Cp& rhs) {return Cp(x*rhs.x-y*rhs.y,x*rhs.y+y*rhs.x);}
}A[MXN],B[MXN],C[MXN],D[MXN],x,w,w0;
int rev[MXN],M,n,maxl;

LL f[MXN],g[MXN],h[MXN],f2[MXN],f3[MXN],fg[MXN];

inline void FFT(Cp *A,int f) {
	int i,j,k; for(i=0;i<M;++i) if(rev[i]>i) swap(A[i],A[rev[i]]);
	for(i=1;i<M;i<<=1) {
		w.x=cos(pi/i),w.y=sin(pi/i)*f;
		for(j=0;j<M;j+=i<<1) {
			w0.x=1,w0.y=0;
			for(k=0;k<i;++k) {
				x=A[j+k];
				A[j+k]=x+(w0*A[i+j+k]);
				A[i+j+k]=x-(w0*A[i+j+k]);
				w0=w0*w;
			}
		}
	}
	if(f==-1) for(i=0;i<M;++i) A[i].x/=M;
}
int tmd;
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(n); for(register int x,i=1;i<=n;++i) rd(x),f[x]=1,g[x*2]=1,h[x*3]=1,maxl=max(maxl,x);
	
	for(M=1,tmd=0;M<=maxl*3;M<<=1,tmd++);	rep(i,1,M-1) rev[i]=(rev[i>>1]>>1)|((i&1)<<(tmd-1));
	
	rep(i,0,M-1) A[i]=Cp(f[i],0) , B[i]=Cp(g[i],0);
	FFT(A,1),FFT(B,1);
	
	rep(i,0,M-1) C[i]=A[i]*A[i],D[i]=A[i]*C[i],B[i]=B[i]*A[i];
	FFT(B,-1),FFT(C,-1),FFT(D,-1);
	
	rep(i,0,M-1) {
		f2[i]=C[i].x + 0.5 , f3[i]=D[i].x + 0.5 , fg[i]=B[i].x + 0.5;
	}
	
	rep(i,0,M-1) {
		LL t = (f3[i] - 3 * fg[i] + 2 * h[i]) / 6 + (f2[i] - g[i]) / 2 + f[i];
		if(t) printf("%d %lld\n",i,t);
	}
	return 0;
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
