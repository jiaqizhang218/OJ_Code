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
const int oo = 0x3f3f3f3f;
/*
const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc() //*/
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 131072 * 3;
const double pi = acos(-1.0);
struct Cp{
	double r,i;
}A[MXN],B[MXN],C[MXN];
int a[MXN],b[MXN],n,m,rev[MXN],t,M;
Cp operator + (Cp a,Cp b){Cp z; z.r=a.r+b.r; z.i=a.i+b.i; return z;}
Cp operator - (Cp a,Cp b){Cp z; z.r=a.r-b.r; z.i=a.i-b.i; return z;}
Cp operator * (Cp a,Cp b){Cp z; z.r=a.r*b.r-a.i*b.i; z.i=a.i*b.r+a.r*b.i; return z;}
inline void FFT(Cp *A,int f) {
	int i,j,k; Cp x,w,w0;
	for(i=0;i<M;i++) if(rev[i]>i) swap(A[i],A[rev[i]]);
	for(i=1;i<M;i<<=1) {
		w.r=cos(pi/i),w.i=f*sin(pi/i);
		for(j=0;j<M;j+=i<<1) {
			w0.r=1,w0.i=0;
			for(k=0;k<i;k++) {
				x=A[j+k];
				A[j+k]=x+(w0*A[i+j+k]);	//a[k]=a[k](0)+w(k,n)a[k](1) 
				A[i+j+k]=x-(w0*A[i+j+k]);//a[k+n/2]=a[k](0)-w(k,n)a[k](1)+a[k](0)+w(k+n/2,n)a[k](1)
				w0=w0*w;
			}
		}
	}
	if(f==-1) for(i=0;i<M;i++) A[i].r/=M;
}
int main()
{
	rd(n);for(int x,y,i=0;i<n;i++) rd(x),rd(y),A[n-i-1].r=x,B[i].r=y;
	for(M=1,t=0;M<=n+n-2;M<<=1,t++);
	for(int i=1;i<M;i++) rev[i]=rev[i>>1]>>1|((i&1)<<(t-1));
	FFT(A,1),FFT(B,1);
	rep(i,0,M-1) A[i]=A[i]*B[i];
	FFT(A,-1);
	per(i,n-1,0) printf("%d\n",(int)(A[i].r+0.5));
}

