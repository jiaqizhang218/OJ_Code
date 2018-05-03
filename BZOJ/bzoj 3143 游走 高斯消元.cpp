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
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
//#define  getchar() nc()
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
    while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    return;
}
const int N = 502;
const int M = 202020;
int n,m,x,y,du[N],n1[M],n2[M];
double a[N][N],w[M],ans;
inline void guess() {
	int now=1,to; double t;
	rep(i,1,n) {
		t=a[now][i];
		rep(j,1,n+1) a[now][j]/=t;
		rep(j,1,n) {
			if(j!=now) {
				t=a[j][i];
				rep(k,1,n+1) a[j][k]-=t*a[now][k];
			}
		}
		now++;
	}
}
int main()
{
	rd(n),rd(m);
	rep(i,1,m) {
		rd(n1[i]),rd(n2[i]);
		du[n1[i]]++,du[n2[i]]++;
	}
	rep(i,1,m) {
		a[n1[i]][n2[i]]-=1.0/du[n2[i]];
		a[n2[i]][n1[i]]-=1.0/du[n1[i]];
	}
	rep(i,1,n-1) a[i][i]=1,a[i][n]=0;
	a[1][n]=1; n--;
	guess(); n++;
	rep(i,1,m) w[i]=a[n1[i]][n]/du[n1[i]]+a[n2[i]][n]/du[n2[i]];
	sort(w+1,w+m+1);
	rep(i,1,m) ans+=(m-i+1)*w[i];
	printf("%.3lf",ans);
	return 0;
}
