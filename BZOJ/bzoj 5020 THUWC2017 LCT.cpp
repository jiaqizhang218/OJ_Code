#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
typedef long long LL;
const int INF = 0x7fffffff , MXN = 200010;
const double E = pow(2, 1.0 / log(2));

int n , m , c[MXN][2] , fa[MXN] , rev[MXN] , s[MXN] ;
double w[MXN][17] , sum[MXN][17];

inline bool dir(int x) { return c[ fa[x] ][1] == x; }

inline bool isrt(int x) { return c[ fa[x] ][1] != x && c[ fa[x] ][0] != x;}

inline void upd(int x) { rep(i,0,15) sum[x][i] = sum[ c[x][0] ][i] + sum[ c[x][1] ][i] + w[x][i]; }

inline void pd(int x) { if(!rev[x]) return; rev[x] ^= 1; rev[ c[x][0] ] ^= 1; rev[ c[x][1] ] ^= 1; swap(c[x][0] , c[x][1]); }

inline void rot(int x) {
	int y = fa[x] , z = fa[y] , d = dir(x);
	if(!isrt(y)) c[z][dir(y)] = x;           fa[x] = z;
	c[y][d] = c[x][d^1] , fa[ c[x][d^1] ] = y , fa[y] = x , c[x][d^1] = y; upd(y);
}

inline void gop(int x) {if(!isrt(x)) gop(fa[x]); pd(x);}

inline void splay(int x) {
	gop(x);
	for(int y = fa[x] ; !isrt(x) ; rot(x) , y = fa[x])
		if(!isrt(y)) dir(x) ^ dir(y) ? rot(x) : rot(y);
	upd(x);
}

inline void access(int x) {
	for(int y = 0 ; x ; x = fa[ y = x ]) 
		splay(x) , c[x][1] = y , upd(x);
}

inline void mkrt(int x) {
	access(x) , splay(x) , rev[x] ^= 1;
}

inline void link(int x,int y) {
	mkrt(x) , fa[x] = y;
}

inline void cut(int x,int y) {
	mkrt(x) , access(y) , splay(y) , c[y][0] = fa[x] = 0;
}

inline int fdrt(int x) {
	access(x);splay(x); while(c[x][0]) x=c[x][0]; splay(x); return x;
}

inline void Calc(int x,int f,double a,double b) {
	rep(i,0,15) w[x][i]=0;
	if(f == 3) w[x][0] = b , w[x][1] = a;
	else if(f == 1) {
		double aa = 1; w[x][0] = sin(b);
		rep(i,1,15) {
			aa *= a;
			if(i % 4 == 1) w[x][i] = aa * cos(b);
			else if(i % 4 == 2) w[x][i] = -aa * sin(b);
			else if(i % 4 == 3) w[x][i] = -aa * cos(b);
			else w[x][i] = aa * sin(b);
		}
	}
	else {
		w[x][0] = pow(E,b);
		rep(i,1,15) w[x][i] = w[x][i-1] * a;
	}
}

inline double Query(int x,int y,double xx) {
	mkrt(x),access(y),splay(y);
	double ans=sum[y][0] , fac = 1 , xxx = 1;
	rep(i,1,15) fac *= i , xxx *= xx , ans += sum[y][i] / fac * xxx;
	return ans;
}

int main() {
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	char tmd[5];
	scanf("%d %d %s",&n,&m,tmd);
	int u,v,p,f; double x,a,b;
	rep(i,1,n) scanf("%d %lf %lf",&f,&a,&b),Calc(i,f,a,b);
	while(m--) {
		scanf("%s",tmd);
		if(tmd[0] == 'a') scanf("%d %d",&u,&v),++u,++v,link(u,v);
		else if(tmd[0] == 'd') scanf("%d %d",&u,&v),++u,++v,cut(u,v);
		else if(tmd[0] == 'm') scanf("%d %d %lf %lf",&p,&f,&a,&b),++p,Calc(p,f,a,b),splay(p);
		else {
			scanf("%d %d %lf",&u,&v,&x); ++u,++v;
			if(fdrt(u) != fdrt(v)) puts("unreachable");
			else printf("%.8e\n",Query(u,v,x));
		}
	}
	return 0;
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
