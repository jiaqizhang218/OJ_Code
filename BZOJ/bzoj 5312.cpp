#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define dbg(x) cerr<<#x<<" = "<<x<<endl
const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc()
template <typename T>
inline void rd(T &x){x = 0; int f = 1; char CH = getchar();while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}x=(f==1)?x:-x;return;}
const int MXN = 2e5 + 5;
int mx[MXN*20],mn[MXN*20],n,m,l,r,x,flag[MXN*20],a[MXN],opt,ls[MXN*20],rs[MXN*20];
inline int chmax(int x,int y){return x>y?x:y;}
inline int chmin(int x,int y){return x<y?x:y;}
inline void pushup(int k) {
	mx[k]=chmax(mx[k<<1],mx[k<<1|1]);
	mn[k]=chmin(mn[k<<1],mn[k<<1|1]);
}
inline void pushdown(int k) {
	if(!flag[k]) return;
	flag[k]=0; flag[k<<1]=flag[k<<1|1]=1;
	mx[k<<1]=mx[k<<1|1]=mx[k];
	mn[k<<1]=mn[k<<1|1]=mn[k];
}
inline void build(int k,int cl,int cr) {
	ls[k]=cl,rs[k]=cr;
	if(cl==cr) {
		mx[k]=mn[k]=a[cl];
		return;
	}
	build(k<<1,cl,((cl+cr)>>1)),build(k<<1|1,((cl+cr)>>1)+1,cr);
	pushup(k);
}
inline void Change1(int k,int l,int r) {
	if(mn[k]==mx[k]&&l<=ls[k]&&rs[k]<=r) {
		flag[k]=1,mx[k]=mn[k]=mx[k]&x; return;
	}
	pushdown(k);
	if(r<=(ls[k]+rs[k]>>1)) Change1(k<<1,l,r);
	else if(l>(ls[k]+rs[k]>>1)) Change1(k<<1|1,l,r);
	else Change1(k<<1,l,(ls[k]+rs[k]>>1)),Change1(k<<1|1,((ls[k]+rs[k]>>1)+1),r);
	pushup(k);
}
inline void Change2(int k,int l,int r) {
	if(mn[k]==mx[k]&&l<=ls[k]&&rs[k]<=r) {
		flag[k]=1,mx[k]=mn[k]=mx[k]|x; return;
	}
	pushdown(k);
	if(r<=(ls[k]+rs[k]>>1)) Change2(k<<1,l,r);
	else if(l>(ls[k]+rs[k]>>1)) Change2(k<<1|1,l,r);
	else Change2(k<<1,l,(ls[k]+rs[k]>>1)),Change2(k<<1|1,((ls[k]+rs[k]>>1)+1),r);
	pushup(k);
}
inline int Query(int k,int l,int r) {
	if(l<=ls[k]&&rs[k]<=r) {
		return mx[k];
	}
	pushdown(k);
	int mid = ls[k] + rs[k] >> 1;
	if(r<=mid) return Query(k<<1,l,r);
	if(l>mid) return Query(k<<1|1,l,r);
	return chmax(Query(k<<1,l,mid),Query(k<<1|1,mid+1,r));
}

int main() {
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	rd(n),rd(m);
	rep(i,1,n) rd(a[i]);
	build(1,1,n);
	while(m--) {
//		dbg(m);
		rd(opt);
		if(opt==1) {
			rd(l),rd(r),rd(x);
			Change1(1,l,r);
		} else if(opt==2) {
			rd(l),rd(r),rd(x);
			Change2(1,l,r);
		} else {
			rd(l),rd(r);
			printf("%d\n",Query(1,l,r));
		}
	}
}
