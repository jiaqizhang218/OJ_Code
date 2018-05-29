#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_end=(b);i>=i##_end;--i)
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ull;
template <typename T> inline void rd(T &x) {
    x=0;int f=1;char CH=getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;return;
}
template <typename T> inline bool chMin(T &a,T b) {
    return a>b?a=b,true:false;
}
const int MXN = 2e6 + 5,INF=0x7fffffff;
struct node {
	int l,r,id,len;
}a[MXN];
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r
inline bool cmp(const node &a,const node &b) {
	return a.len<b.len;	
}
int tag[MXN<<2],n,m,mx[MXN<<2],cnt,gery[MXN<<2],ans=INF;
inline void pushup(int k) {
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
}
inline void pushdown(int k) {
	if(tag[k]) {
		tag[k<<1]+=tag[k];tag[k<<1|1]+=tag[k];
		mx[k<<1]+=tag[k];mx[k<<1|1]+=tag[k];
		tag[k]=0;
	}
}
inline void update(int k,int l,int r,int ql,int qr,int val) {
	if(l>=ql&&r<=qr) {
		tag[k]+=val,mx[k]+=val;
		return;
	}
	int mid=l+r>>1;
	pushdown(k);
	if(qr<=mid) update(lson,ql,qr,val);
	else if(ql>mid) update(rson,ql,qr,val);
	else update(lson,ql,mid,val),update(rson,mid+1,qr,val);
	pushup(k);
}
int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
#endif
	rd(n),rd(m);
	rep(i,1,n) {
		rd(a[i].l),rd(a[i].r),a[i].len=a[i].r-a[i].l+1;
		gery[++cnt]=a[i].l,gery[++cnt]=a[i].r;
	}
	sort(gery+1,gery+1+cnt); cnt=unique(gery+1,gery+1+cnt)-gery-1;
//	cerr<<"yes"<<endl;
	rep(i,1,n) {
		a[i].l=lower_bound(gery+1,gery+cnt+1,a[i].l)-gery;
		a[i].r=lower_bound(gery+1,gery+cnt+1,a[i].r)-gery;
	}
//	debug("gery[cnt = %d] = %d\n",cnt,gery[cnt]);
	sort(a+1,a+1+n,cmp);
	int fc=1;
	rep(i,1,n) {
		update(1,1,cnt,a[i].l,a[i].r,1);
		while(mx[1]>=m) {
			chMin(ans,a[i].len-a[fc].len);
			update(1,1,cnt,a[fc].l,a[fc].r,-1);
			fc++;
		}
	}
	if(ans==INF) ans=-1;
	cout<<ans;
}
