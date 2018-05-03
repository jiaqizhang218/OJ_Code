#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rpg(i,x) for(register int i=fir[x];i;i=e[i].nxt)
typedef long long LL;
const int INF = 0x7fffffff;
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
const int MXN = 1e5+5;
set<int> s;
int n,p,cnt,rt,f[MXN],sum,q[MXN],ans[MXN],fir[MXN],siz[MXN],v[MXN];
struct edge{
	int to,nxt,w;
}e[MXN<<1];
inline void AE(int u,int v,int w) {e[++cnt].to=v;e[cnt].w=w;e[cnt].nxt=fir[u];fir[u]=cnt;}
inline void ins(int u,int v,int w) {AE(u,v,w),AE(v,u,w);}
inline void getrt(int x,int fa) {
	siz[x]=1;f[x]=0;
	rpg(i,x) {
		int y=e[i].to;
		if(v[y]||y==fa) continue;
		getrt(y,x);
		siz[x]+=siz[y];
		f[x]=max(f[x],siz[y]);
	}
	f[x]=max(f[x],sum-f[x]);
	if(f[x]<f[rt]) rt=x;
	return;
}
inline void calc(int x,int fa,int w) {
	rep(i,1,p) if(s.find(q[i]-w)!=s.end()) ans[i]=1;
	rpg(i,x) {
		int y=e[i].to;
		if(v[y]||y==fa) continue;
		calc(y,x,w+e[i].w);
	}
}
inline void update(int x,int fa,int w) {
	s.insert(w);
	rpg(i,x) {
		int y=e[i].to;
		if(v[y]||y==fa) continue;
		update(y,x,w+e[i].w);
	}
}
inline void solve(int x) {
	v[x]=1; s.insert(0);
	rpg(i,x) {
		int y=e[i].to;
		if(v[y]) continue;
		calc(y,x,e[i].w);
		update(y,x,e[i].w);
	}
	s.clear();
	rpg(i,x) {
		int y=e[i].to;
		if(v[y]) continue;
		rt=0; sum=siz[y];
		getrt(y,x);
		solve(rt);
	}
}
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(n),rd(p);
	for(register int x,y,w,i=1;i<n;i++) rd(x),rd(y),rd(w),ins(x,y,w);
	rep(i,1,p) rd(q[i]); f[0]=sum=n;
	getrt(1,0); solve(rt);
	rep(i,1,p) {
		if(ans[i]||!q[i]) puts("Yes");
		else puts("No");
	}
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

