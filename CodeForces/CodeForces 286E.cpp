#include<bits/stdc++.h>
using namespace std;
const int MXN = 2e6 + 5;
const double pi = acos(-1.0);
#define dbg(x) cerr<<#x<<" = "<<x<<endl
struct Cp {
	double x,y;
	Cp(double _x=0,double _y=0){x=_x,y=_y;}
	Cp operator + (const Cp &rhs) {
		return Cp(x+rhs.x,y+rhs.y);
	}
	Cp operator * (const Cp &rhs) {
		return Cp(x*rhs.x-y*rhs.y,y*rhs.x+x*rhs.y);
	}
	Cp operator - (const Cp &rhs) {
		return Cp(x-rhs.x,y-rhs.y);
	}
}A[MXN<<1],w0,wn;
int M,a[MXN],rev[MXN<<1],b[MXN],n,sum,tmp,m;
inline void FFT(Cp *A,int f) {
	int i,j,k;	for(i=0;i<M;++i) if(rev[i]>i) swap(A[i],A[rev[i]]);
	for(i=1;i<M;i<<=1) {
		wn.x=cos(pi/i),wn.y=sin(pi/i)*f;
		for(j=0;j<M;j+=i<<1) {
			w0.x=1,w0.y=0;
			for(k=0;k<i;++k) {
				Cp x=A[j+k],y=w0*A[i+j+k];
				A[j+k]=x+y;
				A[i+j+k]=x-y;
				w0=w0*wn;
			}
		}
	}
	if(f==-1) for(i=0;i<M;++i) A[i].x/=M;
}

int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
#endif
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(register int i=1,x;i<=n;++i) cin>>x,A[x].x=a[x]=b[x]=1;
	for(tmp=0,M=1;M<=m+m;M<<=1,tmp++);
	for(register int i=0;i<M;++i) rev[i]=rev[i>>1]>>1|((i&1)<<(tmp-1));
	FFT(A,1);
	for(register int i=0;i<M;++i) A[i]=A[i]*A[i];
	FFT(A,-1);
	for(int i=1;i<=m;++i) if(A[i].x+0.5>=1) {
		if(!b[i]) {
			puts("NO");
			return 0;
		}
		b[i]=0;
	}
	cout<<"YES"<<endl;
	for(register int i=1;i<=m;++i) if(b[i]) sum++;
	cout<<sum<<endl;
	for(register int i=1;i<=m;++i) 
		if(b[i]) cout<<i<<" ";
}
