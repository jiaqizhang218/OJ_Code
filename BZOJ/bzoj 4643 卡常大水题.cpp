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
const int MXN = 155;
int n,fir[MXN],cnt;
struct edge{
	int u,v,a,b;
}e[MXN*MXN];
int a[MXN*MXN],b[MXN*MXN];  bool flag[MXN*MXN];
inline bool cmp_a(edge &a,edge& b) {return a.a<b.a;}
inline bool cmp_b(edge &a,edge& b) {return a.b<b.b;}
int deg_in[MXN],deg_out[MXN];
int dfn[MXN],low[MXN],dfs_clock;
int vis[MXN];
int A,B;
vector<int> scc[MXN];
inline bool tarjan(int x) {
	vis[x]=1,low[x]=dfn[x]=++dfs_clock;
	for(int i=scc[x].size();i--;) {
		if(!vis[scc[x][i]]&&!tarjan(scc[x][i]))return false;
		low[x]=min(low[x],low[scc[x][i]]);
	}
	vis[x]=-1;
	return x==1||low[x]!=dfn[x];
}
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(n);
	rep(i,1,n) rep(j,1,n) 
	if(i==j) rd(e[cnt].a); else e[cnt]=(edge){i,j},rd(e[cnt++].a);
	cnt=1;
	rep(i,1,n) rep(j,1,n)
	rd(e[cnt].b),cnt+=(i!=j);
	for(int i=cnt;--i;)a[i]=b[i]=i;
	sort(a+1,a+cnt,cmp_a),sort(b+1,b+cnt,cmp_b);
	int ans=INF;
	for(int i=1,j=cnt-1;i<cnt;++i) {
		for(;j&&e[a[i]].a+e[b[j]].b>=ans;--j)
			if(flag[b[j]]) {
				for(int i=scc[e[b[j]].u].size();i--;)
					if(scc[e[b[j]].u][i]==e[b[j]].v) {
						scc[e[b[j]].u].erase(scc[e[b[j]].u].begin()+i);
						break;
					}
				flag[b[j]]=0;
				--deg_in[e[b[j]].v],--deg_out[e[b[j]].u];
			}
			if(!j) break;
			if(e[a[i]].a+e[a[i]].b<ans) {
				scc[e[a[i]].u].pb(e[a[i]].v);
				flag[a[i]]=1;
				++deg_in[e[a[i]].v],++deg_out[e[a[i]].u];
				
				cls(vis,0); dfs_clock=0;
				while(*min_element(deg_in+1,deg_in+n+1)&&*min_element(deg_out+1,deg_out+1+n)&&tarjan(1)&&*max_element(vis+1,vis+n+1)==-1) {
					ans=e[a[i]].a+e[b[j]].b;
					for(;j&&e[a[i]].a+e[b[j]].b>=ans;--j)
						if(flag[b[j]]) {
							for(int i=scc[e[b[j]].u].size();i--;) 
								if(scc[e[b[j]].u][i]==e[b[j]].v) {
									scc[e[b[j]].u].erase(scc[e[b[j]].u].begin()+i);
									break;
								}
							flag[b[j]]=0;
							--deg_in[e[b[j]].v],--deg_out[e[b[j]].u];
						}
					cls(vis,0);
					dfs_clock=1;
				}
			}
		}		 
	printf("%d\n",ans);
#ifdef iloi
	debug("\nMy Time: %.4lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

