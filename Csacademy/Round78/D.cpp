#include<bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff, MXN = 2e4 + 5;
inline void chmax(int &a,int b) {a=a>b?a:b;}
int a[6][MXN],f[MXN*4][6][6];
int n,q,m;
inline void build(int k,int l,int r) {
	for(int i=1;i<=n;++i) 
		for(int j=1;j<=n;++j)
				f[k][i][j]=-INF;
	if(l==r) {
		for(int i=1;i<=n;++i) {
			f[k][i][i]=a[i][l];
			if(i>1) f[k][i][i-1]=a[i][l];
			if(i<n) f[k][i][i+1]=a[i][l];
		}
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid),build(k<<1|1,mid+1,r);
	for(int i=1;i<=n;++i) 
		for(int j=1;j<=n;++j) 
			for(int kk=1;kk<=n;++kk) 
				chmax(f[k][i][kk],f[k<<1][i][j]+f[k<<1|1][j][kk]);
}
inline void update(int k,int l,int r,int x) {
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j) 
			f[k][i][j]=-INF;
	if(l==r) {
		for(int i=1;i<=n;++i) {
			f[k][i][i]=a[i][l];
			if(i>1) f[k][i][i-1]=a[i][l];
			if(i<n) f[k][i][i+1]=a[i][l];
		}
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) update(k<<1,l,mid,x);
	else update(k<<1|1,mid+1,r,x);
	for(int i=1;i<=n;++i) 
		for(int j=1;j<=n;++j)
			for(int kk=1;kk<=n;++kk)
				chmax(f[k][i][kk],f[k<<1][i][j]+f[k<<1|1][j][kk]);
}

int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
#endif 
	ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin>>a[i][j];
	build(1,1,m);
	while(q--) {
		int r,c,t; cin>>r>>c>>t;
		a[r][c]=t;
		update(1,1,m,c);
		int ans=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				chmax(ans,f[1][i][j]);
		cout<<ans<<endl;
	}
}
