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
typedef pair<int,int> PII;
typedef long long LL;
const int INF = 0x7fffffff;
const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc() //*/
template <typename T> inline void rd(T &x) {
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 3e5 + 5;
int n,atk,cnt;
struct line {
	LL k,b;
}s[MXN];
struct gery {
	int a,t;
	LL as,tp;
	inline bool operator < (const gery &rhs) const {
		return (LL)t*rhs.a < (LL)a*rhs.t;
	}
}p[MXN];
inline LL get(line l,int x) {
	return l.k*x+l.b;
}
void modify(int k,int l,int r,line p) {
	if(s[k].k==p.k) {
		s[k].b=max(s[k].b,p.b);
		return;
	}
	int mid=l+r>>1;
	double f=(double)(p.b-s[k].b)/(s[k].k-p.k);
	if(f<l||f>r||l==r) {
		if(get(p,mid)>get(s[k],mid)) s[k]=p;
		return;
	}
	if(f<(int)mid+0.5) {
		if(get(p,r)>get(s[k],r)) swap(s[k],p);
		modify(k<<1,l,mid,p);
	} else {
		if(get(p,l)>get(s[k],l)) swap(s[k],p);
		modify(k<<1|1,mid+1,r,p);
	}
	
}

LL query(int k,int l,int r,int p) {
	int mid=l+r>>1;
	LL ret=get(s[k],p);
	if(l<r) {
		if(p<=mid) ret=max(ret,query(k<<1,l,mid,p));
		else ret=max(ret,query(k<<1|1,mid+1,r,p));
	}
	return ret;
}
	
int main() {
#ifdef iloi
	   freopen("test.in","r",stdin);
#endif
	rd(n),rd(atk);
	rep(i,1,n) rd(p[i].a),rd(p[i].t),p[i].t=(p[i].t-1)/atk+1;
	sort(p+1,p+1+n);
	rep(i,2,n) p[i].tp=p[i-1].tp+p[i-1].t;
	p[n].as=p[n].a; per(i,n-1,1) p[i].as=p[i+1].as+p[i].a;
	rep(i,0,MXN-5) s[i].b=-1e18;
	LL tmp=0;
	per(i,n,1) {
		LL ret=p[i].as*p[i].t+p[i].tp*p[i].a-p[i].a;
		if(query(1,1,10000,p[i].t)+ret>tmp) {
			cnt=0;tmp=query(1,1,10000,p[i].t)+ret;
		}
		if(++cnt>2000) break;
		modify(1,1,10000,(line){-p[i].a,ret});
//		cout<<query(1,1,10000,p[i].t)+ret<<endl;
	}
	LL ans=0;
	rep(i,1,n) ans+=p[i].as*p[i].t-p[i].a;
	ans-=tmp;
	cout<<ans;
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
