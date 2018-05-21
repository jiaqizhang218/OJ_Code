#include<bits/stdc++.h>
using namespace std;
int a[20],cnt;
long long ans;
char s[20];
int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
#endif
	for(int i=0;i<=9;++i) cin>>a[i],cnt+=a[i]==0;
	cin>>s; int flag=0;
	for(int i=0;i<strlen(s);++i) {
		if(i>0&&a[0]) {
			ans=(ans+1)*cnt;
		} else {
			ans*=cnt;
		}
		if(!flag) {
			for(int j=0;j<s[i]-'0';++j) {
				if(!a[j]) {
					ans++;
				}
			}
		}
		if(a[s[i]-'0']) {
			flag=1;
		}
	}
	cout<<ans<<endl;
}
