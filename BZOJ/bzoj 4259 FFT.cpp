#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
typedef long long LL;
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 1200005;
const double pi = acos(-1.0);
struct Cp {
	double x,y;
	Cp (double _x=0,double _y=0) {x=_x,y=_y;}
	Cp operator + (const Cp &rhs) {return Cp(x+rhs.x,y+rhs.y);}
	Cp operator - (const Cp &rhs) {return Cp(x-rhs.x,y-rhs.y);}
	Cp operator * (const Cp &rhs) {return Cp(x*rhs.x-y*rhs.y,x*rhs.y+y*rhs.x);}
	Cp operator / (const double &rhs) {return Cp(x/rhs,y/rhs);}
}A[MXN],B[MXN],C[MXN],x,y,w0,w;

int M,rev[MXN];
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

char s1[300005],s2[300005],s3[300005];
int n,m,ans[MXN],st[300005],top;

int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	ios::sync_with_stdio(false);
	cin>>n>>m>>s3>>s2; int l=0;//rd(n),rd(m); scanf("%s",s3); scanf("%s",s2); int l=0;
	for(M=1;M<=2*m;M<<=1,l++); rep(i,0,M-1) rev[i] = (rev[i>>1]>>1) | ((i & 1) << (l-1));
	rep(i,0,n-1) s1[i]=s3[n-i-1];
	
	rep(i,0,m-1) {
		int tmp=s2[i]-'a'+1; double p=tmp+0.0;
		if(s2[i]=='*') p=0; B[i]=Cp(p,0);
	}
	rep(i,0,n-1) {
		int tmp=s1[i]-'a'+1; double p=tmp+0.0;
		if(s1[i]=='*') p=0; A[i]=Cp(p*p*p,0);
	}
	FFT(A,1),FFT(B,1); 
	rep(i,0,M-1) C[i]=A[i]*B[i];
	rep(i,0,M-1) A[i]=B[i]=Cp(0,0);
	
	
	rep(i,0,m-1) {
		int tmp=s2[i]-'a'+1; double p=tmp+0.0;
		if(s2[i]=='*') p=0; B[i]=Cp(p*p,0);
	}
	rep(i,0,n-1) {
		int tmp=s1[i]-'a'+1; double p=tmp+0.0;
		if(s1[i]=='*') p=0; A[i]=Cp(p*p,0);
	}
	FFT(A,1),FFT(B,1);
	rep(i,0,M-1) C[i]=C[i]-(A[i]*B[i])-(A[i]*B[i]); 
	rep(i,0,M-1) A[i]=B[i]=Cp(0,0);
	
	
	rep(i,0,m-1) {
		int tmp=s2[i]-'a'+1; double p=tmp+0.0;
		if(s2[i]=='*') p=0; B[i]=Cp(p*p*p,0);
	}
	rep(i,0,n-1) {
		int tmp=s1[i]-'a'+1; double p=tmp+0.0;
		if(s1[i]=='*') p=0; A[i]=Cp(p,0);
	}
	FFT(A,1),FFT(B,1); rep(i,0,M-1) C[i]=C[i]+A[i]*B[i];
	
	FFT(C,-1);
	
	rep(i,n-1,m-1) 
		if(fabs(C[i].x)<0.5) 
			st[++top] = i-n+2;
	printf("%d\n",top);
	rep(i,1,top) printf("%d ",st[i]);
	
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
