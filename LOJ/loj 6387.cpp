#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e6 + 5;
int T,n,f[MXN],p[MXN],mr,pos;
char s[MXN];
inline void work() {
	cin>>s+1; n = strlen(s+1);
	memset(p,0,sizeof p) , memset(f,0,sizeof f); mr=pos=p[1]=1;
	s[0]=666;
	for(int i=2;i<=n;++i) {
		if(i<mr) {
			p[i]=min(mr-i+1,p[2*pos-i]);
		} else p[i]=1;
		while(s[i+p[i]]==s[i-p[i]]) p[i]++;
		if(i+p[i]>mr) mr=i+p[i]-1,pos=i;
	}
	for(int i=n;i>=1;--i) {
		if(i+p[i]-1==n) f[i]=1;
		else if(p[i]==i&&f[i+p[i]-1]) f[i]=1;
	}
	for(int i=1;i<=n;++i) {
		if(f[i]) cout<<i<<" ";
	}
	cout<<endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--) work();
}
