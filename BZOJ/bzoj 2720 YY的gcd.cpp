#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
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
const int MXN = 10000005, N = 1e7 + 5;
int T,n,m,cnt; LL ans;
int pri[MXN],mu[MXN]; bool mark[MXN];
LL f[MXN];
inline void prephi() {
	mu[1]=1;
	for(int i=2;i<N;++i) {
		if(!mark[i]) mark[i]=1,pri[++cnt]=i,mu[i]=-1;
		for(int j=1;i*pri[j]<N&&j<=cnt;j++) {
			mark[i*pri[j]]=1;
			if(i%pri[j]) 
				mu[i*pri[j]]=-mu[i];
			else {mu[i*pri[j]]=0; break;}
		}
	}
	for(int i=1;i<=cnt;i++) {
		int p=pri[i]; for(int j=1;j*p<=N;++j)	f[j*p]+=mu[j];
	}
	for(int i=1;i<=N;++i) f[i]+=f[i-1];
}
int main()
{
#ifdef iloi
//	   freopen("test.txt","r",stdin);
#endif
	prephi();
	rd(T);
	while(T--) {
		rd(n),rd(m); if(n>m) swap(n,m); ans=0;
		for(int j,i=1;i<=n;i=j+1) {
			j = min(n/(n/i),m/(m/i));
			ans += (f[j] - f[i-1]) * (n/i) * (m/i);
		}
		printf("%lld\n",ans);
	}
}

