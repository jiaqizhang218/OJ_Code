#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
typedef long long LL;
const int INF = 0x7fffffff;
template <typename T>
inline void rd(T &x) {
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int Mod = 1e9+7 , MXN = 131072 * 4 + 5; 
const double pi = acos(-1.0);
char str[MXN],s[MXN];
struct Cp {
	double x,y;
	Cp (double _x=0,double _y=0) {x=_x,y=_y;}
	Cp operator * (const Cp &rhs) {return Cp(x*rhs.x-y*rhs.y,x*rhs.y+y*rhs.x);}
	Cp operator + (const Cp &rhs) {return Cp(x+rhs.x,y+rhs.y);}
	Cp operator - (const Cp &rhs) {return Cp(x-rhs.x,y-rhs.y);}
}A[MXN],B[MXN],w0,w,x;
int M,n,rev[MXN],m,tmp,ina[MXN],inb[MXN],p[MXN],pw[MXN]; LL ans;
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
inline int manacher() {
	str[0]='$'; str[1]='#';
	for(int i=0,j=1;s[i+1];++i) {
		str[++j]=s[i+1],str[++j]='#';
	}
	int mx=0,mxid=0,ret=0; memset(p,0,sizeof p);
	for(int i=1;str[i];++i) {
		if(mx>i) p[i]=(p[2*mxid-i]<(mx-i)?p[2*mxid-i]:(mx-i));
			else p[i]=1;
		while(str[i-p[i]]==str[i+p[i]]) p[i]++;
		if(i+p[i]>mx) mx=p[i]+i,mxid=i;
		ret=(ret+p[i]/2)%Mod;
	}
	return ret;
}
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	scanf("%s",s+1); n=strlen(s+1); m = n << 1;
	rep(i,1,n) if(s[i]=='a') ina[i]++; else if(s[i]=='b') inb[i]++;
	rep(i,1,n) A[i]=Cp(ina[i],0),B[i]=Cp(inb[i],0); rep(i,n+1,M-1) A[i]=B[i]=Cp(0,0);
	for(M=1,tmp=0;M<=m;M<<=1,tmp++); rep(i,1,M-1) rev[i]=(rev[i>>1]>>1)|((i&1)<<(tmp-1)); 
	FFT(A,1),FFT(B,1); rep(i,0,M-1) A[i]=A[i]*A[i]+B[i]*B[i];
	FFT(A,-1); pw[0]=1;
	rep(i,1,MXN-1) pw[i]=(pw[i-1]*2)%Mod;
	rep(i,0,M-1) {
		tmp = (int)(A[i].x+0.5);
		ans = ( ans + (LL) pw[(tmp+1)>>1]-1) % Mod;
	}
	printf("%lld\n",((ans+Mod-manacher())%Mod));
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
