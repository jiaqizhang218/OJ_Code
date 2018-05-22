#include<bits/stdc++.h>
using namespace std;
const int MXN = 6e6 + 5,Mod = 1e9 + 7,INF = 0x3fffffff;
int a[MXN],b[MXN],ans,cnt,mx1[MXN],mx2[MXN],mn1[MXN],mn2[MXN],t1[MXN],t2[MXN],T,n,k,fac[MXN],inv[MXN];
inline int C(int n,int m) {
	return 1LL*fac[n]*inv[m]%Mod*inv[n-m]%Mod;
}
inline int calc(int n) {
	if(n<=0) return 1;
	return (C(n+n,n)-C(n+n,n-1)+Mod)%Mod;
}
int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
#endif
	ios::sync_with_stdio(false);
	fac[0]=inv[0]=inv[1]=fac[1]=1;
	for(int i=2;i<MXN;++i) fac[i]=1LL*fac[i-1]*i%Mod;
	for(int i=2;i<MXN;++i) inv[i]=1LL*(Mod-Mod/i)*inv[Mod%i]%Mod;
	for(int i=2;i<MXN;++i) inv[i]=1LL*inv[i-1]*inv[i]%Mod;
	cin>>T;
	while(T--) {
		cin>>n>>k;ans=1;cnt=0;
		for(int i=1;i<=k;++i) cin>>a[i];
		if(!k) {
			cout<<calc(n)<<endl;
			continue;
		}
		for(int i=1;i<=k;++i) b[i]=a[i];
		sort(b+1,b+k+1);
		t1[0]=t2[0]=t1[k+1]=t2[k+1]=1;mn1[0]=mn2[k+1]=INF;mx1[0]=mx2[k+1]=-INF;
		for(int i=2;i<=k;++i) ans=1LL*ans*calc(b[i]-b[i-1]-1)%Mod;
		ans=1LL*ans*calc(n+b[1]-b[k])%Mod;
		assert(ans>=0);
		//cerr<<ans<<endl;
		for(int i=1;i<=k;++i) mx1[i]=max(mx1[i-1],a[i]),mn1[i]=min(mn1[i-1],a[i]),t1[i]=(t1[i-1]&&(mx1[i]==a[i]||mn1[i]==a[i]));
		for(int i=k;i;--i) mx2[i]=max(mx2[i+1],a[i]),mn2[i]=min(mn2[i+1],a[i]),t2[i]=(t2[i+1]&&(mx2[i]==a[i]||mn2[i]==a[i]));
		for(int i=1;i<=k;++i) cnt+=(t1[i]&&t2[i]&&((a[i]==mn1[i]&&a[i]==mx2[i])||(a[i]==mn2[i]&&a[i]==mx1[i])));
		ans=1LL*ans*cnt%Mod;
		cout<<ans<<endl;
	}

}
