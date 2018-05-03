#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define debug(x) cerr<<#x" = "<<x<<endl
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define per(i,a,b) for(register int i=(a);i>=(b);--i)
#define edeg(x) for(int i=fir[x];i;i=e[i].nxt)
#define ull unsigned long long
#define fi first
#define se second
#define cla(x) memset(x,0,sizeof x)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
//#define  getchar() nc()
inline LL rd()
{
	LL x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int N = 1000005; 
int n,k,l,r,i,ans[N],f[N],F[N];
LL m,a[N];
int main()
{
#ifdef	iloi
	freopen("test.txt","r",stdin);
#endif
	n=(int)rd(),k=(int)rd(); m=rd();
	rep(i,1,n) a[i]=rd();
	l=1,r=k+1;f[1]=r;
	rep(i,2,n) {
		while(r<n&&a[i]-a[l]>a[r+1]-a[i]) l++,r++;
		if(a[i]-a[l]>=a[r]-a[i]) f[i]=l; else f[i]=r;
	}
	rep(i,1,n) ans[i]=i;
	for(;m;m>>=1){
		if(m&1)	rep(i,1,n) ans[i]=f[ans[i]];
		rep(i,1,n) F[i]=f[f[i]];
		rep(i,1,n) f[i]=F[i];
	}
	rep(i,1,n)	printf(i==n?"%d":"%d ",ans[i]);
}

