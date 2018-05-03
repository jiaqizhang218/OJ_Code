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
inline int rd()
{
    int x = 0 , f = 1; char CH = getchar();
    while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
    while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    return f ? x : -x;
}
const int N = 200050;
const int M = 400050;
int n,m,son[N][2],fa[N],q[M][2],del[M][2],fir[N],cnt,vis[N],ans[N];
struct edge{int to,nxt;}e[M];
inline void AE(int u,int v){e[++cnt].to=v;e[cnt].nxt=fir[u];fir[u]=cnt;e[++cnt].to=u;e[cnt].nxt=fir[v];fir[v]=cnt;}
inline int findfa(int x){return (x==fa[x])?x:(fa[x]=findfa(fa[x]));}
inline void merge(int x,int y){int fx=findfa(x),fy=findfa(y);fa[fx]=fy;}
inline void dfs(int x,int step){
	vis[x]=1;
	ans[x]=step;
	rpg(i,x) 
		if(!vis[e[i].to]) 
			dfs(e[i].to,step);
	vis[x]=0;
}
int main()
{
#ifdef	iloi
	freopen("test.txt","r",stdin);
#endif
	n=rd(),m=rd(); int a,b;
	rep(i,1,n)	son[i][0]=rd(),son[i][1]=rd(),fa[i]=i;
	rep(i,1,m)	q[i][0]=rd(),q[i][1]=rd()-1,del[q[i][0]][q[i][1]]=1;
	rep(i,1,n) {
		if(!del[i][0]&&son[i][0]!=-1)	{merge(i,son[i][0]); AE(i,son[i][0]);}
		if(!del[i][1]&&son[i][1]!=-1)	{merge(i,son[i][1]); AE(i,son[i][1]);}
	}
	per(i,m,1) {
		a=son[q[i][0]][q[i][1]],b=q[i][0];
		int fx=findfa(a),fy=findfa(b);
		if(fx==fy)	continue;
		if(fx==findfa(1)) {dfs(fy,i),merge(fx,fy),AE(a,b);}
		else if(fy==findfa(1)) {dfs(fx,i),merge(fx,fy),AE(a,b);}
		else {merge(fx,fy),AE(a,b);}
	}
	rep(i,1,n)	printf("%d\n",ans[i]-1);
}
