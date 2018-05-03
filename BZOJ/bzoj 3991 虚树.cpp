#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rpg(i,x) for(register int i=fir[x];i;i=e[i].nxt)
#define ull unsigned long long
#define cls(x,y) memset(x,y,sizeof x)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
const int oo = 0x3f3f3f3f;
/*const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc() //*/
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int Mod = 1e7+7;

int n,bin[22],fac[22],a[5050];
LL ans;
inline bool check(int x,int k) {
	rep(i,1,bin[k]-1) if(a[x+i]!=a[x+i-1]+1) return 0;
	else return 1;
}
inline void swap(int x,int y,int k) {
	for(int i=0;i<bin[k];++i) 
		swap(a[x+i],a[y+i]);
}
inline void dfs(int k,int now) {
	if(k==n+1) {
		rep(i,1,bin[n]) if(a[i]<a[i-1]) return;
		ans+=fac[now];
		return;
	}
	int t1=0,t2=0;
	for(int i=1;i<=bin[n];i+=bin[k]) {
		if(!check(i,k)) {
			if(!t1) t1=i;
			else if(!t2) t2=i;
			else return;
		}
	}
	if(!t1&&!t2) dfs(k+1,now);
	else if(t1&&!t2) {
		swap(t1,t1+bin[k-1],k-1);
		dfs(k+1,now+1);
		swap(t1,t1+bin[k-1],k-1);
	}
	else {
		for(int x=0;x<=1;x++) 
			for(int y=0;y<=1;++y) {
				swap(t1+x*bin[k-1],t2+y*bin[k-1],k-1);
				if(check(t1,k)&&check(t2,k)) {
					dfs(k+1,now+1);
					swap(t1+x*bin[k-1],t2+y*bin[k-1],k-1);
					break;
				}
				swap(t1+x*bin[k-1],t2+y*bin[k-1],k-1);
		}
	}
}
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	bin[0]=1;rep(i,1,20) bin[i]=bin[i-1]<<1;
	fac[0]=1;rep(i,1,20) fac[i]=fac[i-1]*i;
	rd(n); rep(i,1,bin[n]) rd(a[i]);
	dfs(1,0); printf("%lld\n",ans);	return 0;
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

