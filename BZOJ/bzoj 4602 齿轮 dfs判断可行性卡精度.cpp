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
#define pb push_back
#define bin(i) (1<<i)
#define cla(x) memset(x,0,sizeof x)
#define meminf(x) memset(x,127,sizeof x)
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
inline int rd()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int N = 1005;
const int M = 10005;
const double eps = 1e-8;
int T,n,m,i,x,y,u,v,ok,cnt,Case,p[N],fir[N];
double f[N];
struct edge{
	int to,nxt;double val;
}e[M<<1];
inline void AE(int u,int v,double x)
{
	e[++cnt].to=v;e[cnt].val=x;e[cnt].nxt=fir[u];fir[u]=cnt;
}
inline bool dfs(int x)
{
	p[x]=1;
	edeg(x) {
		int y=e[i].to;
		if(!p[y]) {
			f[y]=f[x]*e[i].val;
			if(!dfs(y))	return 0;
		}
		else {
			if((f[x]*e[i].val-f[y])>eps)	return 0;
		}
	}
	return true;
}
int main()
{
#ifdef	iloi
	freopen("test.txt","r",stdin);
#endif
	T=rd();
	Case=0;
	while(T--) {
		n=rd(),m=rd();cnt=0;
		cla(fir); cla(p);  cla(f);
		rep(i,1,m) {
			u=rd(),v=rd(),x=rd(),y=rd();
			AE(u,v,1.0*x/y);
			AE(v,u,1.0*y/x);
		}
		ok=0;
		rep(i,1,n)	{
			if(!p[i]) {
				f[i]=1.0;
				if(!dfs(i)) {
					ok=1; break;
				}
			}
		}
		Case++;
		printf("Case #%d: ",Case);
		printf(ok?"No\n":"Yes\n");
	}
}
