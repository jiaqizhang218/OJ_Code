#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int digit[20],t; 
LL f[20][(1<<8)][2600],n,m;
 
inline LL dfs(int l,int cnt,int sum,bool jud) {
	if( !l ) {
		for(int i=2;i<=9;++i) 
			if((1<<(i-2))&cnt && (sum%i)) 
				return 0;
		return 1;
	}
	if(!jud && f[l][cnt][sum] != -1) return f[l][cnt][sum];
	int Max = jud ? digit[l] : 9;
	LL ans = 0;
	for(int i=0;i<=Max;++i) {
		ans += dfs(l-1,i<2?cnt:(cnt|(1<<(i-2))),(((sum*10)+i)%2520),jud&&(i==digit[l]));
	}
	if(!jud) f[l][cnt][sum]=ans;
	return ans;
}
 
inline LL calc(LL k) {
	LL ans = 0 , pos = 0;
	while(k) {
		digit[++pos]=k%10;
		k/=10;
	}
	ans = dfs(pos,0,0,1);
	return ans;
}
 
int main() {
	memset(f,-1,sizeof f);
	cin>>t;
	while(t--) {
		cin>>m>>n;
		cout<<calc(n)-calc(m-1)<<endl;
	}
}
