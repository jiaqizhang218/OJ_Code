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
const int N = 1000100;
int match[N],nowtime,n,vis[N<<1],fir[N],cnt;
struct edge{
	int frm,to,nxt;
}e[N<<1];
inline void AE(int u,int v) {
	e[++cnt].frm=u;e[cnt].to=v;e[cnt].nxt=fir[u];fir[u]=cnt;
}
bool dfs(int x) {
	rpg(i,x) {
		int v=e[i].to;
		if(vis[v]!=nowtime) {
			vis[v]=nowtime;
			if(!match[v]||dfs(match[v])) {
				match[v]=x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
#ifdef	iloi
	freopen("test.txt","r",stdin);
#endif
	rd(n);
	for(int i=1,x,y;i<=n;i++) rd(x),rd(y),AE(x,i),AE(y,i);
	rep(i,1,n) {
		nowtime++;
		if(!dfs(i)) {
			printf("%d\n",i-1);
			return 0;
		}
	}
	printf("%d\n",n);
	return 0;
}
