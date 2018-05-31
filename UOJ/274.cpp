#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
const int INF = 0x7fffffff;
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 4e5 + 5;

int n,m,tp,q[MXN],e[MXN][2],c[MXN][2],fa[MXN],rev[MXN];
struct node {
	int t,len,mn,sum;
}a[MXN];

inline bool isrt(int x) { return c[fa[x]][1] != x && c[fa[x]][0] != x; }

inline bool dir(int x) {return c[fa[x]][1] == x;}

inline void ps(int x) {
	node &o = a[x] , &l = a[c[x][0]] , &r = a[c[x][1]];
	o.mn = x, o.sum = o.len;
	if(c[x][0]) {
		if( a[l.mn].t < a[o.mn].t ) o.mn = l.mn ; o.sum += l.sum;
	}
	if(c[x][1]) {
		if( a[r.mn].t < a[o.mn].t ) o.mn = r.mn ; o.sum += r.sum;
	}
}

inline void rot(int x) {
	int y = fa[x], z = fa[y] , d = dir(x) ;
	if( !isrt(y) ) c[z][dir(y)] = x;
	fa[x] = z , fa[y] = x, c[y][d] = c[x][d ^ 1] , fa[c[x][d ^ 1]] = y , c[x][d ^ 1] = y;
	ps(y);
}

inline void pd(int x) {
	if(rev[x]) {
		swap(c[x][0] , c[x][1]); 
		rev[c[x][0]] ^= 1, rev[c[x][1]] ^= 1 , rev[x] = 0;
	}
}

inline void splay(int x) {
	int i,y,z; q[tp=1] = x;
	for(i=x; !isrt(i) ; i=fa[i]) q[++tp] = fa[i];
	while(tp) pd(q[tp--]);
	for( ; !isrt(x) ; rot(x)) {
		y=fa[x] , z=fa[y];
		if(!isrt(y)) rot(((c[z][0]==y) ^ (c[y][0]==x))?x:y);
	}
	ps(x);
}

inline void access(int x) {
	int y = 0 ; for( ; x ; y = x , x = fa[x] ) {
		splay(x) , c[x][1] = y , ps(x);
	}
}

inline void mkrt(int x) {
	access(x) , splay(x) , rev[x] ^= 1;
}

inline void link(int x,int y) {
	mkrt(x) , fa[x] = y;
}

inline void cut(int x,int y) {
	mkrt(x) , access(y) , splay(y) , c[y][0] = fa[x] = 0 , ps(y); 
}

inline int fdrt(int x) {
	access(x) , splay(x) ;  for( ; c[x][0] ; x = c[x][0]); splay(x);return x;  
}

int main()
{
#ifdef iloi
//	   freopen("test.txt","r",stdin);
#endif
	rd(n),rd(m); int i,k,x,y;
	char opt[10];  rep(i,1,n) a[i].t=INF;
	while(m--) {
		scanf("%s",opt);
		if(opt[0] == 'f') {
			rd(i),rd(x),rd(y),++i,++x,++y;
			i+=n , e[i][0] = x, e[i][1] = y;
			rd(a[i].t) , rd(a[i].len);
			if(fdrt(x) != fdrt(y)) {
				link(i,x),link(i,y);
			} else {
				mkrt(x) , access(y) , splay(y);
				if(a[ a[y].mn ].t < a[i].t ) {
					k = a[y].mn , cut(k,e[k][0]) ,cut(k,e[k][1]);
					link(i,x) , link(i,y);
				}
			}
		}
		else if(opt[0] == 'm') {
			rd(x),rd(y),++x,++y;
			if(fdrt(x) != fdrt(y)) puts("-1");
			else {
				mkrt(x),access(y),splay(y);
				printf("%d\n",a[y].sum);
			}
		}
		else {
			rd(x) , rd(y) , ++x;
			x+=n , splay(x) , a[x].len = y , ps(x);
		}
	}
	return 0; 
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
