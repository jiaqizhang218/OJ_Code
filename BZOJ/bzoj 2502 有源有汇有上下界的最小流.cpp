#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rpg(i,x) for(register int i=fir[x];i!=-1;i=e[i].nxt)
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
const int MXN = 205 , MXM = 100005;
struct edge{
	int to,nxt,w;
}e[MXM];
int cnt=0,fir[MXN],_fir[MXN];
inline void AE(int u,int v,int w) {
	e[cnt].to=v;e[cnt].nxt=fir[u];e[cnt].w=w;fir[u]=cnt++;
	e[cnt].to=u;e[cnt].nxt=fir[v];e[cnt].w=0;fir[v]=cnt++;
}
int q[MXN],vis[MXN],dis[MXN],head,tail,s,t,T,ss,tt;
inline bool bfs() {
	head=tail=0; vis[s]=++T; dis[s]=1; q[tail++]=s;
	while(head!=tail) {
		int x=q[head++];
		rpg(i,x) {
			if(e[i].w&&vis[e[i].to]!=T) {
				vis[e[i].to]=T; q[tail++]=e[i].to;
				dis[e[i].to]=dis[x]+1;
			}
		}
	}
	if(vis[t]==T) memcpy(_fir,fir,sizeof fir);
	return vis[t]==T;
}
int dfs(int x,int lim) {
	if(x==t)	return lim;
	int flow=0,a;
	for(int pt=_fir[x];pt!=-1;pt=e[pt].nxt) {
		_fir[x]=pt;
		if(e[pt].w&&dis[e[pt].to]==dis[x]+1&&(a=dfs(e[pt].to,min(e[pt].w,lim-flow)))) {
			e[pt].w-=a; e[pt^1].w+=a; flow+=a;
			if(flow==lim) return flow;
		}
	}
	return flow;
}
inline int dinic() {
	int ans=0,x;
	while(bfs()) {
		while(x=dfs(s,INF)) ans+=x;
	}
	return ans;
}
int totflow[MXN];
inline void del(int x) {rpg(i,x) e[i].w=e[i^1].w=0;}
int main()
{
#ifdef iloi
	//   freopen("test.txt","r",stdin);
#endif
	int n; rd(n);
	int x,y; memset(fir,-1,sizeof fir);
	rep(i,1,n) {
		rd(x);
		rep(j,1,x) {
			rd(y);
			totflow[i]--; totflow[y]++;
			AE(i,y,INF);
		}
	}
	s=0,t=n+1,ss=n+2,tt=n+3;
	rep(i,1,n) {
		AE(s,i,INF);
		AE(i,t,INF);
	}
	rep(i,1,n) {
		if(totflow[i]<0) AE(i,tt,-totflow[i]);
		else AE(ss,i,totflow[i]);
	}
	AE(t,s,INF);
	int tmps=s,tmpt=t;
	s=ss,t=tt;
	dinic();
	int flow0=e[cnt-1].w;
	e[cnt-1].w=e[cnt-2].w=0;
	del(ss),del(tt);
	s=tmpt,t=tmps;
	printf("%d\n",flow0-dinic());
	return 0;
}
