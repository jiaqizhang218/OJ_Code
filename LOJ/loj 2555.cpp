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
/*const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc() //*/
template <typename T>
inline void rd(T &x) {
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 1e5 + 5;
struct juice {
	int d,p,l;
	bool operator < (const juice &rhs) const {
		return d > rhs.d;
	}
}a[MXN];
struct tr {
	int ls,rs,x;LL l,sum;
}tr[MXN*20];
int cnt,n,m,rt[MXN];
inline void Ins(int &y,int x,int l,int r,int p,int lim) {
	tr[y=++cnt]=tr[x]; tr[y].sum+=1LL*lim*p,tr[y].l+=lim;
	if(l==r) return; int mid=l+r>>1;
	if(p<=mid) Ins(tr[y].ls,tr[x].ls,l,mid,p,lim);
	else Ins(tr[y].rs,tr[x].rs,mid+1,r,p,lim);
}
inline LL query(int x,int l,int r,LL t) {
	if(l==r) return 1LL*t*l; int mid=l+r>>1;
	if(t<=tr[tr[x].ls].l) return query(tr[x].ls,l,mid,t);
	else return tr[tr[x].ls].sum+query(tr[x].rs,mid+1,r,t-tr[tr[x].ls].l);
}

int main()
{
#ifdef iloi
	   freopen("test.in","r",stdin);
#endif
	rd(n),rd(m);
	rep(i,1,n) rd(a[i].d),rd(a[i].p),rd(a[i].l);
	sort(a+1,a+1+n); 
	rep(i,1,n) Ins(rt[i],rt[i-1],0,1e5,a[i].p,a[i].l);
	a[0].d=-1;
//	rep(i,1,n) debug("rt[%d].l = %d\n",i,tr[rt[i]].l);
	rep(i,1,m) {
		LL G,L; rd(G),rd(L);
		int l=0,r=n,mid,gery=0;
		while(l<=r) {
			mid=l+r>>1;
//			 dbg(L); dbg(tr[rt[mid]].sum);
			if(L<=tr[rt[mid]].l&&query(rt[mid],0,1e5,L)<=G) gery=mid,r=mid-1;
			else l=mid+1;
		}
//		dbg(l);
		printf("%d\n",a[gery].d);
	}

#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
