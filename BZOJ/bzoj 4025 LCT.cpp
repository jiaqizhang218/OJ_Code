#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rvc(i,S) for(register int i=(0);i<S.size();++i) 
#define rpg(i,x) for(register int i=fir[x];i;i=e[i].nxt)
#define pb push_back
typedef long long LL;
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

const int MXN = 1e5 + 5 , MXM = 3e5 + 5 , INF = 0x3f3f3f3f;

int rc , n , m , T , mnv[MXM] , val[MXM] , mnp[MXM] , sz[MXM];
vector<int> ins[MXN],del[MXN];
int fa[MXM] , ch[MXM][2] , rev[MXM] , on_tree[MXM] , ban[MXM] , tot_ban;

#define ls ch[x][0]
#define rs ch[x][1]
#define dir(x) (ch[fa[x]][1] == x)

inline bool isrt(int x) {return ch[fa[x]][0] != x && ch[fa[x]][1] != x;}

inline void ps(int x) {
	mnv[x] = min(val[x], min(mnv[ls],mnv[rs]) );
	if(mnv[x] == val[x]) mnp[x] = x;
	else if( mnv[x] == mnv[ls]) mnp[x] = mnp[ls];
	else if( mnv[x] == mnv[rs]) mnp[x] = mnp[rs];
	sz[x] = sz[ls] + sz[rs] + (x <= n);
}

inline void rever(int x) {
	rev[x] ^= 1;
	swap(ls , rs);
}

inline void pd(int x) {
	if(rev[x]) {
		rever(ls) , rever(rs);
		rev[x]=0;
	}
}

inline void gop(int x) {if(!isrt(x)) gop(fa[x]); pd(x);}

inline void rot(int x) {
	int p = fa[x] , d = dir(x);
	fa[x] = fa[p];
	if(!isrt(p)) ch[fa[p]][dir(p)] = x;
	ch[p][d] = ch[x][d ^ 1] , fa[ch[x][d ^ 1]] = p;
	ch[x][d ^ 1] = p; fa[p] = x;
	ps(p);
}

inline void splay(int x) {
	gop(x);
	while(!isrt(x)) {
		if(isrt(fa[x])) rot(x);
		else if(dir(fa[x]) == dir(x)) rot(fa[x]) , rot(x);
		else rot(x) , rot(x);
	}
	ps(x);
}

inline void access(int x) {
	for(int y = 0; x; x = fa[y = x]) 
		splay(x) , fa[rs = y] = x, ps(x);
}

inline void mkrt(int x) {
	access(x); splay(x);
	rever(x); ps(x);
}

inline void link(int x,int y) {
	mkrt(x); fa[x]=y;
}

inline void cut(int x,int y) {
	mkrt(x); access(y);
	splay(y); fa[x] = ch[y][0] = 0;
}

int fdrt(int x) {
	return fa[x] ? fdrt(fa[x]) : x;
}

struct Edge{
	int u,v,w;
}E[MXM];

int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(n), rd(m) , rd(T);
	mnv[0] = val[0] = INF;
	rep(i,1,n) {
		mnv[i] = val[i] = INF;
		mnp[i] = i; sz[i] = 1;
	}
	rep(i,1,m) {
		rd(E[n + i].u);
		rd(E[n + i].v);
		int st,ed; rd(st),st++,rd(ed),ed++;
		mnv[n+i] = val[n+i] = E[n+i].w = ed;
		mnp[n+i] = n + i;
		sz[n+i] = 0;
		ins[st].pb(n+i) , del[ed].pb(n+i);
	}
	rep(i,1,T) {
		rvc ( j , ins[i]) {
			int id = ins[i][j];
			Edge e = E[id];
			if( fdrt(e.u) != fdrt(e.v) ) {
				link(e.u , id);
				link(e.v , id);
				on_tree[id] = 1;
			}
			else {
				mkrt(e.u) ; access(e.v);
				splay(e.u); int p = mnp[e.u] , d = sz[e.u];
				if (val[id] <= val[p]) {
					if(d & 1) {
						ban[id] = 1;
						++tot_ban;
					}
				}
				else {
					Edge f = E[p];
					cut(f.u,p);	cut(f.v,p);
					on_tree[p] = 0;
					link(e.u , id);	link(e.v , id);
					on_tree[id] = 1;
					e = f , id = p;
					mkrt(e.u) , access(e.v); splay(e.u);
					p = mnp[e.u] , d = sz[e.u];
					if (d & 1) {
						ban[id] = 1;
						++tot_ban;
					}
				}
			}
		}
		rvc (j , del[i] ) {
			int id = del[i][j] ;
			Edge e = E[id];
			if(on_tree[id]) {
				cut(e.u , id) , 
				cut(e.v , id) ;
			}
			else if( ban[id] ) {
				ban[id] = 0;
				--tot_ban;
			}
		}
		if(tot_ban == 0) puts("Yes");
		else puts("No");
	}
	return 0;
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
