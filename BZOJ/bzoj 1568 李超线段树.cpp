#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
template <typename T>
inline void rd(T &x) {
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}

const int MXN = 5e4 + 10;
int n,m,x;
struct line {
	double k,b; int id;
	double getf(int x) {return k*x+b;}
}t[MXN<<2];

inline bool cmp(line a,line b,int x) {
	if(!a.id) return 1;
	return a.getf(x) != b.getf(x) ? a.getf(x) < b.getf(x) : a.id < b.id;
}

line Query(int k,int l,int r,int x) {
	if(l == r) return t[k];
	int mid = l+r>>1; line tmp;
	if(x <= mid) tmp = Query(k<<1,l,mid,x);
	else tmp = Query(k<<1|1,mid+1,r,x);
	return cmp(t[k],tmp,x) ? tmp : t[k];
}

void ins(int k,int l,int r,line x) {
	if(!t[k].id) t[k] = x;
	if(cmp(t[k], x, l)) swap(t[k],x);
	if(l==r || t[k].k == x.k) return;
	int mid=l+r>>1;
	double X = (t[k].b - x.b) / (x.k - t[k].k);
	if(X < l || X > r) return;
	if(X <= mid) ins(k<<1,l,mid,t[k]),t[k]=x;
	else ins(k<<1|1,mid+1,r,x);
}

void Ins(int k,int l,int r,int x,int y,line v) {
	if(x <= l && r <= y) {
		ins(k,l,r,v);
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) Ins(k<<1,l,mid,x,y,v);
	if(y>mid) Ins(k<<1|1,mid+1,r,x,y,v);
}
int main()
{
#ifdef iloi
	   freopen("test.in","r",stdin);
#endif
	rd(m); n=50000;
	char opt[15];
  while (m--) {
    scanf("%s", opt);
    if (opt[0] == 'P') {
      double k, b;
      scanf("%lf %lf", &k, &b);
      line tmp;  tmp.k = b;  tmp.b = k - b;  tmp.id = 1;
      Ins(1, 1, n, 1, n, tmp);
    }
    if (opt[0] == 'Q') {
      rd(x);
      printf("%lld\n", (LL)(Query(1, 1, n, x).getf(x) / 100 + 1e-8));
    }
  }
	return 0;
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
