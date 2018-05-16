#include<bits/stdc++.h>
using namespace std;
const int MXN = 3e3 + 5 , Mod = 59393;
int g[MXN],n,k,a[15],f[MXN],c[MXN];

int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
#endif
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=0;i<=k;++i) cin>>a[i];
	for(int i=1;i<=n;++i) {
		int x=1;
		for(int j=0;j<=k;++j) {
			c[i]+=a[j]*x;
			x=1LL*x*i%Mod;
		}
		c[i]%=Mod;
	}
	if(n==2) {
		printf("1 %d\n",n*c[1]);
		printf("1 2");
		return 0;
	} else if(n==1) {
		printf("0 %d\n",a[0]);
		return 0;
	}
	f[0]=c[1]*n;
	for(int i=1;i<=n-2;++i) {
		f[i]=-1;
		for(int j=2;j<=i+1;++j) {
			if(f[i]<=f[i-j+1]-c[1]+c[j]) {
				g[i]=i-j+1;
				f[i]=f[i-j+1]-c[1]+c[j];
			}
		}
	}
	printf("%d %d\n",n-1,f[n-2]);
	int p=n,q=1;
	for(int i=n-2;i;i=g[i],--p) {
		int cnt=i-g[i];
		if(p<n) printf("%d %d\n",p+1,p),--cnt;
		while(cnt--) printf("%d %d\n",q++,p);
	}
	printf("%d %d\n",p,p+1);
}
