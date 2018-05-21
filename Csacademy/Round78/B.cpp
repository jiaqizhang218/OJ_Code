#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e5 + 5;
int n,a[MXN],ans1,ans2;
int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
#endif
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n); int Maxl=0,cnt=0;
	for(int i=2;i<n;++i) {
		if(a[i+1]-a[i]==Maxl) cnt++;
		if(a[i+1]-a[i]>Maxl) {
			Maxl=a[i+1]-a[i];
			cnt=1;
		}
	}
	if(cnt==1) {
		ans1=max(ans1,Maxl/2+(Maxl&1));
		for(int i=2;i<n;++i) {
			if(a[i+1]-a[i]==Maxl) continue;
			ans1=max(ans1,a[i+1]-a[i]);
		}
	} else ans1=max(ans1,Maxl);

	Maxl=0,cnt=0;
	for(int i=1;i<n-1;++i) {
		if(a[i+1]-a[i]==Maxl) cnt++;
		if(a[i+1]-a[i]>Maxl) {
			Maxl=a[i+1]-a[i];
			cnt=1;
		}
	}
	if(cnt==1) {
		ans2=max(ans2,Maxl/2+(Maxl&1));
		for(int i=1;i<n-1;++i) {
			if(a[i+1]-a[i]==Maxl) continue;
			ans2=max(ans2,a[i+1]-a[i]);
		}
	} else ans2=max(ans2,Maxl);
	cout<<min(ans1,ans2)<<endl;
}
