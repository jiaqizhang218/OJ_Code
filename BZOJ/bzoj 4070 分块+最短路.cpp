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
const int MXN = 3030005;
int n,block,cnt,fir[MXN],dis[MXN],m,s,t;
struct Edge{int to,nxt,w;}e[MXN*6];
inline void AE(int u,int v,int w){e[++cnt].to=v;e[cnt].nxt=fir[u];fir[u]=cnt;e[cnt].w=w;}
inline void ins(int u,int v,int w){AE(u,v,w),AE(v,u,w);}
priority_queue <pa,vector<pa>,greater<pa> > q;
bool vis[MXN];
#define pos(x,y) (x*n+y)
#define mp make_pair
inline void dijkstra() {
	rep(i,0,block*n+n) dis[i]=oo;
	dis[s]=0; q.push(mp(0,s));
	while(!q.empty()) {
		int now=q.top().se; q.pop();
		rpg(i,now) {
			#define V e[i].to
			if(dis[V]>dis[now]+e[i].w) {
				dis[V]=dis[now]+e[i].w;
				q.push(mp(dis[V],V));
			}
		}
	}
}
int main()
{
#ifdef iloi
//	   freopen("test.txt","r",stdin);
#endif
	rd(n),rd(m); block=min(100,(int)sqrt(n+0.5));
	rep(i,1,block) rep(j,1,n) AE(pos(i,j),j,0);
	rep(i,1,block) rep(j,1,n-i) ins(pos(i,j),pos(i,i+j),1);
	rep(i,1,m) {
		int x,y;
		rd(x),rd(y); x++;
		if(i==1) s=x;
		else if(i==2) t=x;
		if(y<=block) AE(x,pos(y,x),0);
		else  {
			for(int j=1;x+j*y<=n;++j) AE(x,x+j*y,j);
			for(int j=1;x-j*y>0;++j) AE(x,x-j*y,j);
		}
	}
	dijkstra();
	printf("%d\n",dis[t]==oo?-1:dis[t]);
#ifdef iloi
	debug("\nMy Time: %.4lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
