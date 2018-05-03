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
//f[i][j][k]表示以i为根，需要联通块大小为j，当前联通块大小为k的最小值
const int N = 55;
int n,fir[N],cnt,k1,k2;
double sm,v[N],g[N],f[N][N][N];
struct edge{
	int to,nxt;
}e[N<<1];
inline void AE(int u,int v) {
	e[++cnt].to=v;e[cnt].nxt=fir[u];fir[u]=cnt;
	e[++cnt].to=u;e[cnt].nxt=fir[v];fir[v]=cnt;
}
inline void dfs(int x,int fa) {
	g[x]=INF;
	rpg(i,x) if(e[i].to!=fa) dfs(e[i].to,x);
	rep(j,k1,k2) {
		f[x][j][1]=v[x]/j;
		rpg(i,x) {
			int v=e[i].to;
			if(v!=fa) per(k,j,1) {
				f[x][j][k]+=g[v];
				rep(l,1,k-1) 
					f[x][j][k]=min(f[x][j][k],f[x][j][k-l]+f[v][j][l]);
			}
		}
		g[x]=min(g[x],f[x][j][j]); 
	}
}
int main()
{
#ifdef	iloi
	freopen("test.txt","r",stdin);
#endif
	rd(n),rd(k1),rd(k2);
	rep(i,1,n) scanf("%lf",&v[i]),sm+=v[i];
	for(int i=1,x,y;i<n;++i) rd(x),rd(y),AE(x,y);
	rep(i,0,n) rep(j,1,k2) rep(k,0,k2) f[i][j][k]=INF;
	dfs(1,0);
	if(g[1]==INF) g[1]=sm*2;
	printf("%.2lf\n",g[1]);
}
