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
const double eps = 1e-8;
const int MXN = 1e6 + 5;
struct Point {
	double x,y;
	Point (double _x=0,double _y=0) :x(_x),y(_y) {}
	Point operator - (const Point &rhs) const {
		return Point(x-rhs.x,y-rhs.y);
	}
	bool operator < (const Point &rhs) const {
		return x==rhs.x ? y > rhs.y : x > rhs.x;
	}
}P[MXN];
inline double Cross(const Point &A,const Point &B) {
	return (A.x*B.y-A.y*B.x)>eps?1:-1;
}
inline double slop(const int &a,const int &b) {
	return (P[b].y-P[a].y)/(P[b].x-P[a].x);
}
int top,n,stk[MXN];
inline void chMin(double &a,double b) {a=a>b?b:a;}
int main()
{
#ifdef iloi
	   freopen("test.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n) scanf("%lf%lf",&P[i].x,&P[i].y);
	sort(P+1,P+1+n);
	stk[top=1]=1;
	rep(i,2,n) {
		while(top>1&&Cross(P[i]-P[stk[top]],P[stk[top]]-P[stk[top-1]])>0) --top;
		stk[++top]=i;
	}
	while(top>1&&(P[stk[top]].y<=P[stk[top-1]].y)) --top;
	double k,ans=1e20;
	rep(i,1,top) {
		k=-sqrt(1.0*P[stk[i]].y/P[stk[i]].x);
		if((i==1|slop(stk[i-1],stk[i])<k)&&(i==top||slop(stk[i],stk[i+1])>k)) chMin(ans,P[stk[i]].x+P[stk[i]].y+2.0*sqrt(P[stk[i]].x*P[stk[i]].y));
		if(i!=top) 
			k=slop(stk[i],stk[i+1]),
			chMin(ans,P[stk[i]].x+P[stk[i]].y-P[stk[i]].x*k-P[stk[i]].y/k);
	}
	printf("%.4lf",ans);
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
