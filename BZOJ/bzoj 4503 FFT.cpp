#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff , MXN = 2e5 + 5;
const double pi = acos(-1.0);
template <typename T>
inline void rd(T &x) {
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}

char S[MXN];
double a[MXN],b[MXN];

struct Cp {
    double x,y;
    Cp (double _x=0,double _y=0) {x=_x,y=_y;}
    Cp operator + (const Cp &rhs) {return Cp(x+rhs.x,y+rhs.y);}
    Cp operator - (const Cp &rhs) {return Cp(x-rhs.x,y-rhs.y);}
    Cp operator * (const Cp &rhs) {return Cp(x*rhs.x-y*rhs.y,x*rhs.y+y*rhs.x);}
    Cp operator / (const double &rhs) {return Cp(x/rhs,y/rhs);}
}A[MXN<<1],B[MXN<<1],C[MXN<<1],w0,w,x;
int ln,lm,tmd,M,ans[MXN],rev[MXN<<1];

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

int main()
{
#ifdef iloi
	   freopen("test.in","r",stdin);
#endif
	scanf("%s",S); ln = strlen(S);	rep(i,0,ln-1) a[i]=S[i]-'a'+1;
	scanf("%s",S); lm = strlen(S);	rep(i,0,lm-1) b[i]=S[lm-i-1] !='?' ? (S[lm-i-1]-'a'+1) : 0;
	
	for(M=1,tmd=0;M<2*ln;M<<=1,tmd++); rep(i,0,M-1) rev[i] = (rev[i>>1]>>1) | ((i&1)<<(tmd-1));
	
	rep(i,0,ln-1) A[i]=Cp(a[i]*a[i],0) , B[i]=Cp(b[i],0);
	FFT(A,1) , FFT(B,1);
	rep(i,0,M-1) C[i] = A[i] * B[i];
	rep(i,0,M-1) A[i] = B[i] = Cp(0,0);
	
	rep(i,0,ln-1) A[i]=Cp(a[i],0) , B[i]=Cp(b[i]*b[i],0);
	FFT(A,1) , FFT(B,1);
	rep(i,0,M-1) C[i] = C[i] - A[i] * B[i] - A[i] * B[i];
	rep(i,0,M-1) A[i] = B[i] = Cp(0,0);
	
	rep(i,0,ln-1) A[i]=Cp(1,0) , B[i]=Cp(b[i]*b[i]*b[i],0);
	FFT(A,1) , FFT(B,1);
	rep(i,0,M-1) C[i] = C[i] + A[i] * B[i];
	
	FFT(C,-1);
	rep(i,lm-1,ln-1) if(fabs(C[i].x)<0.5) ans[++ans[0]]=i-lm+1;
	rep(i,0,ans[0]) printf("%d\n",ans[i]);
	
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
