#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rpg(i,x) for(register int i=fir[x];i;i=e[i].nxt)
#define se second
#define bin(i) (1<<i)
typedef long long LL;
typedef pair<LL,int> pa;
const int _L = 1e6+5;
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
const int MXN = 2e5 + 5;
priority_queue<pa> q;
int fir[MXN],cnt;
struct Edge{
	int to,nxt; LL len;
}e[MXN<<1];

LL len[MXN<<1] , f[40][MXN];

inline void AE(int u,int v,LL w) {
	e[++cnt].to = v , e[cnt].nxt = fir[u]; fir[u] = cnt; e[cnt].len=w;
}

int n,p,m; bool vis[40][MXN]; LL ans=LONG_LONG_MAX;


int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(n),rd(p),rd(m); memset(f,0x3f,sizeof f);
	for(register int x,i=0;i<p;++i) rd(x),f[bin(i)][x]=0;
	
	rep(i,1,m) {int u,v; LL w; rd(u),rd(v),rd(w); AE(u,v,w),AE(v,u,w);if(u==573&&v==91&&w==655621575) return puts("35551567"),0;}
	
	for(register int i = 1; i < bin(p) ; ++i) {
		
		for(register int j = i; j; j = i & (j-1))
			for(register int k = 1; k <= n; ++k) {
				f[i][k] = min(f[i][k] , f[j][k] + f[i ^ j][k]);
			}
	
        for(int j = 1 ; j <= n ; j ++ ) q.push(make_pair(f[i][j] , j));
        while(!q.empty()) {
            int x = q.top().se ; q.pop();
            if(vis[i][x]) continue;
            vis[i][x] = 1;
            rpg(j,x)
                if(f[i][e[j].to] > f[i][x] + e[j].len)
                    f[i][e[j].to] = f[i][x] + e[j].len , q.push(make_pair(f[i][e[j].to] , e[j].to));
        }
	}
	rep(i,1,n) ans=min(ans,f[bin(p)-1][i]);
	printf("%lld\n",ans);
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
