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
#define V G[x][i]
const int MXN = 30004;
int n,m,d[MXN],q[MXN],cnt,ans; vector<int> G[MXN];
bitset<MXN> f[MXN];
inline void toposort() {
	queue<int> que;	rep(i,1,n) if(!d[i]) que.push(i);
	while(!que.empty()) {
		int x = que.front(); q[++cnt]=x; que.pop();
		for(int i=0;i<G[x].size();++i) 
			if(!(--d[V])) que.push(V);
	}
}
 
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(n),rd(m);
	for(register int x,y,i=1;i<=m;i++) rd(x),rd(y),G[x].pb(y),d[y]++;
	toposort();
	per(i,cnt,1) {
		int x = q[i]; 
		for(int i=0;i<G[x].size();++i) {
			f[x]|=f[V];
		}
		for(int i=0;i<G[x].size();++i) {
			if(f[x][V]) ans++;
			f[x].set(V);
		}
	}
	printf("%d\n",ans);
}
