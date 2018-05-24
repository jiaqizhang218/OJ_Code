#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e5 + 5;
vector<int> G[MXN];
int a[MXN],n,k,ans;
inline int dfs(int x,int fro) {
	int d=1;
	for(auto w:G[x]) {
		if(w==fro) continue;
		d=max(d,dfs(w,x)+1);
	}
	if(d==k&&fro!=1&&fro!=0) d=0,++ans;
	return d;
}
int main() {
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=2;i<=n;++i) {
		G[i].push_back(a[i]),G[a[i]].push_back(i);
	}
	if(a[1]!=1) ans++;
	dfs(1,0);
	cout<<ans;
}
