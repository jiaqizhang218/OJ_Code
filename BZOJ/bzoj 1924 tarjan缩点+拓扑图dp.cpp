#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rpg(i,x) for(register int i=fir[x];i;i=e[i].nxt)
#define rpgd(i,x) for(register int i=fird[x];i;i=ed[i].nxt)
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
inline int rd()
{
    int x = 0 , f = 1; char CH = getchar();
    while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
    while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    return f ? x : -x;
}
const int N = 1000050;
map <LL,int> H;
int n,fir[N],fird[N],cntd,cnt,R,C,vis[N],inq[N],dfn[N],low[N],stk[N],top,siz[N],belong[N],dfs_clock,tot;LL ans;
struct edge{int to,nxt;}e[N<<2],ed[N];
inline void AE(int u,int v){e[++cnt].to=v;e[cnt].nxt=fir[u];fir[u]=cnt;}
inline void AED(int u,int v){ed[++cntd].to=v;ed[cntd].nxt=fird[u];fird[u]=cntd;}
struct data{int x,y,id,opt;}sc[N];
bool cmp_x(data a,data b){return a.x<b.x;}
bool cmp_y(data a,data b){return a.y<b.y;}
inline void tarjan(int x) {
	dfn[x]=low[x]=++dfs_clock; inq[x]=1; stk[++top]=x;
	rpg(i,x){ 
		int v=e[i].to;
		if(!dfn[v]) {
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(inq[v])	low[x]=min(low[x],dfn[v]);
	}
	int now=-1;
	if(low[x]==dfn[x]) {
		++tot;
		while(now!=x) {
			now=stk[top--];
			inq[now]=0;
			belong[now]=tot;
			siz[tot]++;
		}
	}
}
inline void rebuild() {
	rep(i,1,n) 
		rpg(j,i) 
			if(belong[i]!=belong[e[j].to]) 
				AED(belong[i],belong[e[j].to]);
}
inline void dfs(int x) {
	int maxx=0; vis[x]=1;
	rpgd(i,x) {
		int v=ed[i].to;
		if(!vis[v]) dfs(v);
		maxx=max(maxx,siz[v]);
	}
	ans=max(ans,(LL)(siz[x]+=maxx));
}
int main()
{
#ifdef	iloi
	freopen("test.txt","r",stdin);
#endif
	n=rd(),R=rd(),C=rd();
	rep(i,1,n) {sc[i].x=rd(),sc[i].y=rd(),sc[i].id=i,sc[i].opt=rd();H[(LL)((sc[i].x-1)*N+sc[i].y)]=i;}
	sort(sc+1,sc+1+n,cmp_x);
	rep(i,1,n) 
		if(sc[i].opt==1) {
			per(j,i-1,1) if(sc[j].x==sc[i].x) AE(sc[i].id,sc[j].id); else break;
			rep(j,i+1,n) if(sc[j].x==sc[i].x) AE(sc[i].id,sc[j].id); else break;
		}
	sort(sc+1,sc+1+n,cmp_y);
	rep(i,1,n) 
		if(sc[i].opt==2) {
			per(j,i-1,1) if(sc[j].y==sc[i].y) AE(sc[i].id,sc[j].id); else break;
			rep(j,i+1,n) if(sc[j].y==sc[i].y) AE(sc[i].id,sc[j].id); else break;
		}
	rep(i,1,n) 
		if(sc[i].opt==3)
			rep(x,sc[i].x-1,sc[i].x+1) 
				rep(y,sc[i].y-1,sc[i].y+1) 
					if(x!=sc[i].x||y!=sc[i].y) { //if(x<1||y<1||x>C||y>R) continue; 	
					if(H[(LL)((x-1)*N+y)]) AE(sc[i].id,H[((x-1)*N+y)]);}
	rep(i,1,n) if(!dfn[i]) tarjan(i);	rebuild();
//	rep(i,1,tot) if(!ds[i]) dfs(i);
	rep(i,1,tot) {if(!vis[i]) dfs(i);} 
	printf("%lld\n",ans);		
}
