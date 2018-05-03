#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
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
const double pi = acos(-1.0);
const int MXN = 131072 , t = 16; 
struct Cp{double x,y;}A[MXN],B[MXN],C[MXN],x,w,w0;
int n,i,rev[MXN],ans[MXN]; char s[MXN];
Cp operator + (Cp x,Cp y){Cp z;z.x=x.x+y.x;z.y=x.y+y.y;return z;}
Cp operator - (Cp x,Cp y){Cp z;z.x=x.x-y.x;z.y=x.y-y.y;return z;}
Cp operator * (Cp x,Cp y){Cp z;z.x=x.x*y.x-x.y*y.y;z.y=x.y*y.x+x.x*y.y;return z;}
inline void FFT(Cp *A,int f) {
	int i,j,k;for(i=0;i<MXN;++i) if(rev[i]>i) swap(A[i],A[rev[i]]);
	for(i=1;i<MXN;i<<=1) {
		w.x=cos(pi/i),w.y=sin(pi/i)*f;
		for(j=0;j<MXN;j+=i<<1) {
			w0.x=1;w0.y=0;
			for(k=0;k<i;++k) {
				x=A[j+k];
				A[j+k]=x+(w0*A[j+k+i]);
				A[j+k+i]=x-(w0*A[j+k+i]);
				w0=w0*w;
			}
		}
	}
	if(f==-1) for(i=0;i<MXN;++i) A[i].x/=MXN;
}
int main()
{
	rd(n); 
	scanf("%s",s+1); rep(i,1,n) A[n-i].x=(double)(s[i]-'0');
	scanf("%s",s+1); rep(i,1,n) B[n-i].x=(double)(s[i]-'0');
	for(i=1;i<MXN;++i) rev[i]=rev[i>>1]>>1|((i&1)<<t);
	FFT(A,1),FFT(B,1);
	for(i=0;i<MXN;++i) C[i]=A[i]*B[i];
	FFT(C,-1);
	for(i=0;i<=2*n-2;++i) {
		ans[i]+=(int)(C[i].x+0.5);
		if(ans[i]>=10) ans[i+1]+=ans[i]/10,ans[i]%=10;
	}
	if(ans[2*n-1]) printf("%d",ans[2*n-1]);
	for(i=2*n-2;i>=0;--i) printf("%d",ans[i]);
}
