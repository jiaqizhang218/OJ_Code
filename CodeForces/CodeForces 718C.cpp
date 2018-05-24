#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e5 + 5 , Mod = 1e9 + 7;
int n,m;
struct mtx {
	int a[2][2];
	mtx() {memset(a,0,sizeof a);}
	mtx(int) {memset(a,0,sizeof a);a[0][0]=a[1][1]=1;}
	mtx operator + (const mtx &rhs) const {
		mtx c = mtx();
		for(int i=0;i<2;++i) 
			for(int j=0;j<2;++j) 
				c.a[i][j]=(a[i][j]+rhs.a[i][j])%Mod;
		return c;
	}
	mtx operator * (const mtx &rhs) const {
		mtx c = mtx();
		for(int k=0;k<2;++k) 
			for(int i=0;i<2;++i)
				for(int j=0;j<2;++j) 
					(c.a[i][j]+=1LL*a[i][k]*rhs.a[k][j]%Mod)%=Mod;
		return c;
	}
};
struct node {
	mtx a,tag;
	node() {
		a = mtx();
		tag = mtx(1);
	}
	inline void work(mtx x) {
		a = a * x;
		tag = tag * x;
	}
	node operator + (const node &rhs) const {
		node tmp=node();
		tmp.a=a+rhs.a;
		return tmp;
	}
};
node tr[MXN<<2];
inline void pushdown(int k) {
	tr[k<<1].work(tr[k].tag);
	tr[k<<1|1].work(tr[k].tag);
	tr[k].tag=mtx(1);
}
inline void Ins(int k,int l,int r,int ql,int qr,mtx c) {
	if(l > qr || r < ql) return;
	if(l >= ql && r <= qr) {
		tr[k].work(c);
		return;
	}
	int mid = l + r >> 1;
	pushdown(k);
	Ins(k<<1,l,mid,ql,qr,c),Ins(k<<1|1,mid+1,r,ql,qr,c);
	tr[k]=tr[k<<1]+tr[k<<1|1];
}
inline mtx Query(int k,int l,int r,int ql,int qr) {
	if(l > qr || r < ql) return mtx();
	if(l >= ql && r <= qr) return tr[k].a;
	pushdown(k);
	int mid = l + r >> 1;
	return Query(k<<1,l,mid,ql,qr)+Query(k<<1|1,mid+1,r,ql,qr);
}
inline mtx fpw(mtx x,int y) {
	mtx ret = mtx(1);
	for(;y;y>>=1,x=x*x) if(y&1) ret=ret*x;
	return ret;
}
int a[MXN]; mtx unit;
inline void build(int k,int l,int r) {
	if(l==r) {
		tr[k]=node(); tr[k].a=fpw(unit,a[l]); return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid),build(k<<1|1,mid+1,r);
	tr[k]=tr[k<<1]+tr[k<<1|1];
}
int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
#endif 
	ios::sync_with_stdio(false);
	cin>>n>>m;
	unit.a[0][0]=unit.a[1][0]=unit.a[0][1]=1;
	for(int i=1;i<=n;++i) cin>>a[i];
	build(1,1,n);
	for(int i=1;i<=m;++i) {
		int opt; cin>>opt;
		if(opt==1) {
			int l,r,x;
			cin>>l>>r>>x;
			Ins(1,1,n,l,r,fpw(unit,x));
		} else {
			int l,r;
			cin>>l>>r;
			mtx ret = Query(1,1,n,l,r);
			cout<<ret.a[1][0]<<endl;
		}
	}
}
