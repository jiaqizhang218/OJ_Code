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
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
    while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;
    return;
}
const int N = 200005;
int n,m,t[N],ans[N];
struct node{int a,b,c,s,ans;}a[N],p[N];
inline bool cmp(node a,node b) {
	if(a.a==b.a&&a.b==b.b) return a.c<b.c;
	else if(a.a==b.a)	return a.b<b.b;
	else return a.a<b.a;
}
inline bool operator <(node a,node b) {
	if(a.b==b.b) return a.c<b.c;
	return a.b<b.b;
}
inline int lbt(int x){return x&(-x);};
inline void update(int x,int val){for(;x<=m;x+=lbt(x))t[x]+=val;}
inline int ask(int x){int tmp=0;for(;x;x-=lbt(x))tmp+=t[x];return tmp;}
inline void cdq(int l,int r) {
	if(l==r)	return;
	int mid=(l+r)>>1;
	cdq(l,mid),cdq(mid+1,r);
	sort(p+l,p+mid+1); sort(p+mid+1,p+r+1);
	int i=l,j=mid+1;
	while(j<=r) {
		while(i<=mid&&p[i].b<=p[j].b) {
			update(p[i].c,p[i].s);
			++i;
		}
		p[j].ans+=ask(p[j].c);
		++j;
	}
	rep(j,l,i-1) update(p[j].c,-p[j].s);
}
int main()
{
#ifdef	iloi
	freopen("test.txt","r",stdin);
#endif
	int FK; rd(FK),rd(m);
	rep(i,1,FK) rd(a[i].a),rd(a[i].b),rd(a[i].c);
	sort(a+1,a+FK+1,cmp);
	int cnt=0;
	rep(i,1,FK) {
		++cnt;
		if(a[i].a!=a[i-1].a||a[i].b!=a[i-1].b||a[i].c!=a[i-1].c) {
			p[++n]=a[i];
			p[n].s=cnt;
			cnt=0;
		}
	}
	cdq(1,n);
	rep(i,1,n) ans[p[i].ans+p[i].s-1]+=p[i].s;
	rep(i,0,FK-1) printf("%d\n",ans[i]);
	return 0;
}
