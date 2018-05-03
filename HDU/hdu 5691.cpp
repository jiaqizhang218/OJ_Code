#include<bits/stdc++.h>
using namespace std;
#define bin(i) (1<<i)
#define RG register
#define rep(i,j,k) for(RG int i=(j),i##_end=k;i<=i##_end;++i)
#define per(i,j,k) for(RG int i=(j),i##_end=k;i>=i##_end;--i)
const int MXN = (1<<17) + 5 ,INF = 0x7fffffff;

#define int long long

int f[MXN][20],ans,n,pos[20],p[20],a[20],T,ccnt;

inline int calc(int x) {
	int cnt = 0;
	while(x) {
		if(x & 1) cnt++;
		x >>= 1;
	}
	return cnt;
}

inline void work() {
	cin>>n; ans = -INF;
	for(int i=0;i<n;++i) {
		cin>>a[i]>>p[i];
	}
	for(int i=0;i<bin(n);++i) for(int j=0;j<n;++j) f[i][j]=-INF;
	for(int i=0;i<n;++i) 
		if(p[i]==-1 || p[i]==0)
			f[bin(i)][i]=0;
	for(int i=0;i<bin(n);++i) {
		for(int j=0;j<n;++j) {
			if(f[i][j]!=-INF) {
				for(int k=0;k<n;++k) {
					if( (!(i&bin(k))) && (p[k] == -1 || p[k] == calc(i)) ) {
						f[i|bin(k)][k] = max(f[i|bin(k)][k] ,f[i][j] + a[j] * a[k]);
					}
				}
			}
		}
	}
	for(int i=0;i<n;++i) ans=max(ans,f[bin(n)-1][i]);
	printf("Case #%lld:\n%lld\n",++ccnt,ans);
}
main() {
	ios::sync_with_stdio(false);
	cin>>T; while(T--) work();
}
