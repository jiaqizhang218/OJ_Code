#include<bits/stdc++.h>
using namespace std;
const int MXN = 5e5 + 5;
const double eps = 1e-8;
int k,n,m,a[MXN],s[MXN]; double f[MXN];
int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
#endif
	ios::sync_with_stdio(false);
	cin>>m>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	double l=-1e9,r=0;
	while(r-l>eps) {
		double mid = (l+r)/2;
		for(int i=2;i<=n;++i) {
			f[i]=f[i-1];s[i]=s[i-1];
			if(f[i-2]+a[i]-a[i-1]+mid<f[i]) f[i]=f[i-2]+a[i]-a[i-1]+mid,s[i]=s[i-2]+1;
		}
		if(s[n]==m) {
			printf("%lld\n",(long long)(f[n]-mid*m+1e-3));
			return 0;
		}
		if(s[n]>m) l=mid; else r=mid;
	}
	for(int i=2;i<=n;++i) {
		f[i]=f[i-1];s[i]=s[i-1];
		if(f[i-2]+a[i]-a[i-1]+l<f[i]) f[i]=f[i-2]+a[i]-a[i-1]+l,s[i]=s[i-2]+1;
	}
	printf("%lld\n",(long long)(f[n]-l*m+1e-3));
#ifdef iloi
	fprintf(stderr,"My time is %.3lf\n",(double)clock()/CLOCKS_PER_SEC);
#endif
}
