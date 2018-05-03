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
int m,n,k;
struct mtx {
	double m[1005];
	mtx() {
		rep(i,0,1000)	m[i]=0;
	}
	friend mtx operator * ( mtx x, mtx y)  {
		mtx z;
		rep(i,1,n) rep(j,1,n) z.m[i]+=x.m[j]*(y.m[(i-j+n)%n+1]);
		return z;
	}
}a,b,c;
inline void mtx_qpow(int k) {
	for(;k;k>>=1,c=c*c)if(k&1)b=b*c;
//	debug("%lf\n",b.m[1]);
}
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(n),rd(m),rd(k);
	if(n==1)	return cout<<fixed<<setprecision(3)<<1.0*m<<endl,0;
	rep(i,1,n)	cin>>a.m[i]; //debug("%lf\n",a.m[1]);
	b.m[1]=1;c.m[1]=-1.0/m+1;c.m[2]=1.0/m;
	mtx_qpow(k);
	a=a*b;
	rep(i,1,n)	cout<<fixed<<setprecision(3)<<a.m[i]<<endl;
}

