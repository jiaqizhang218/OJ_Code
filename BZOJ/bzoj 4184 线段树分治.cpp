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
#define mp make_pair
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
const int MXN = 5e5 + 10;
struct fc{
	int l,r;
	vector<int> d;
}t[MXN<<2];
struct fc1{
	int a[31];
	int& operator [](int x) {
		return a[x];
	}
}c;
int n,m,a[MXN];
set<pa > p;
fc1 insert(fc1 c,int x) {
	per(i,30,0) {
		if(x&(bin(i))) {
			if(!c[i]) {
				c[i]=x;
				break;
			}
			else x^=c[i];
		}
	}
	return c;
}
inline void build(int i,int l,int r) {
	t[i].l=l,t[i].r=r;
	if(l==r) return ;
	int mid=l+r>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
}
inline void insert(int i,int l,int r,int x) {
	if(l<=t[i].l&&t[i].r<=r) {
		t[i].d.pb(x);
		return;
	}
	int mid=(t[i].l+t[i].r)>>1;
	if(l<=mid) insert(i<<1,l,r,x);
	if(r>mid) insert(i<<1|1,l,r,x);
}
inline void dfs(int i,fc1 k) {
	for(int j=0;j<t[i].d.size();++j) k=insert(k,t[i].d[j]);
	if(t[i].l==t[i].r) {
		int now=0;
		per(i,30,0) if((now^k[i])>now) now^=k[i];
		printf("%d\n",now);
		return;
	}
	dfs(i<<1,k);
	dfs(i<<1|1,k);
}
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(n);
	build(1,1,n);
	rep(i,1,n) {
		int x;
		rd(x);
		if(x>0) p.insert(mp(x,i));
		else {
			pa q=*p.lower_bound(mp(abs(x),0));
			insert(1,q.second,i-1,abs(x));
			p.erase(q);
		}
	}
	set<pa >::iterator it;
	for(it=p.begin();it!=p.end();it++) insert(1,(*it).second,n,(*it).first);
	dfs(1,c);
	return 0;
}
