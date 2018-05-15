#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define cls(x,y) memset(x,y,sizeof x)
typedef long long LL;
const int INF = 0x7fffffff;
const int oo = 0x3f3f3f3f;
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
const int MXN = 1e5 + 5;
struct SGT{
	LL mx,mn,mk,sum;
}t[MXN<<2];
int n,m,a[MXN];
inline void upd(int k) {
	t[k].mx=max(t[k<<1].mx,t[k<<1|1].mx);
	t[k].mn=min(t[k<<1].mn,t[k<<1|1].mn);
	t[k].sum=t[k<<1].sum+t[k<<1|1].sum;
}
void build(int l,int r,int k) {
	if(l==r) {
		t[k].mx=t[k].mn=t[k].sum=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,k<<1),build(mid+1,r,k<<1|1);
	upd(k);
}
inline void pushdown(int k,int l,int r) {
	if(!t[k].mk) return;
	LL x=t[k].mk;
	t[k<<1].mx+=x; t[k<<1].mn+=x; t[k<<1|1].mx+=x; t[k<<1|1].mn+=x;
	t[k<<1].mk+=x; t[k<<1|1].mk+=x;
	int mid=(l+r)>>1;
	t[k<<1].sum+=x*(mid-l+1); t[k<<1|1].sum+=x*(r-mid);
	t[k].mk=0;
}
void change(int l,int r,int k,int sa,int se,int to) {
	if(l>se||r<sa) return;
	if(sa<=l && r<=se) {
		t[k].mx+=to; t[k].mn+=to; t[k].mk+=to;
		t[k].sum+=(LL)to*(r-l+1);
		return;
	}
	pushdown(k,l,r);
	int mid=l+r>>1;
	change(l,mid,k<<1,sa,se,to),change(mid+1,r,k<<1|1,sa,se,to);
	upd(k);
}
void sqt(int l,int r,int k,int sa,int se) {
	if(l>se||r<sa) return;
	if(sa<=l && r<=se) {
		if(t[k].mx==t[k].mn) {
			LL tmp=(LL)sqrt(t[k].mx)-t[k].mx;
			t[k].sum+=(LL)tmp*(r-l+1); t[k].mn+=tmp; t[k].mx+=tmp; t[k].mk+=tmp; 
			return;
		}
		LL tmp1=sqrt(t[k].mx),tmp2=sqrt(t[k].mn);
		if(t[k].mx==t[k].mn+1&&tmp1==tmp2+1) {
			t[k].sum+=(LL)(tmp1-t[k].mx)*(r-l+1);
			t[k].mn+=tmp1-t[k].mx; t[k].mk+=tmp1-t[k].mx;
			t[k].mx+=tmp1-t[k].mx;
			return;
		}
	}
		pushdown(k,l,r);
		int mid=l+r>>1;
		sqt(l,mid,k<<1,sa,se),sqt(mid+1,r,k<<1|1,sa,se);
		upd(k);
}
LL query(int l,int r,int k,int sa,int se) {
	if(l>se||r<sa)return 0;
	if(sa<=l && r<=se) return t[k].sum;
	pushdown(k,l,r);
	int mid=(l+r)>>1;
	return query(l,mid,k<<1,sa,se)+query(mid+1,r,k<<1|1,sa,se);
}
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(n),rd(m); rep(i,1,n) rd(a[i]);
	build(1,n,1); int opt,x,y,z;
	while(m--) {
		rd(opt),rd(x),rd(y);
		if(opt==1) {
			rd(z),change(1,n,1,x,y,z);
		}
		else if(opt==2) sqt(1,n,1,x,y);
		else if(opt==3) printf("%lld\n",query(1,n,1,x,y));
	}
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
