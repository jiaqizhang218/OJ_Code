#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e5 + 5;
typedef long long LL;
int n,s[MXN],cnt[MXN];
LL f[MXN];
vector<int> stk[MXN];

inline LL get(int x,int y,int z){
    return f[x-1]+1ll*z*(y-s[x]+1)*(y-s[x]+1);
}
inline int find(int x,int y,int z){
    int l=max(s[x],s[y]),r=n;
    while(l<=r){
        int Mid=l+r>>1;
        if(get(x,Mid,z)<=get(y,Mid,z))r=Mid-1;else l=Mid+1;
    }
    return l;
}

int main() {
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1,x;i<=n;++i) {
		cin>>x; s[i]=++cnt[x];
		while(stk[x].size()>=2&&find(stk[x][stk[x].size()-1],stk[x][stk[x].size()-2],x)<find(i,stk[x][stk[x].size()-1],x)) stk[x].pop_back();
		stk[x].push_back(i);
		while(stk[x].size()>=2&&get(stk[x][stk[x].size()-1],s[i],x)<get(stk[x][stk[x].size()-2],s[i],x)) stk[x].pop_back();
		f[i]=get(stk[x][stk[x].size()-1],s[i],x);
	}
	cout<<f[n]<<endl;
}
