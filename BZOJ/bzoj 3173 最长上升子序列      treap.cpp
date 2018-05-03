#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int N = 100000 + 5;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int n,cnt,root,now,mx;
int mn[N],ans[N];
int v[N],size[N],rnd[N],l[N],r[N];
inline void update(int x) {
	size[x] = size[l[x]]+size[r[x]]+1;
} 
inline void lturn(int &k) {
	int t=r[k];r[k]=l[t];l[t]=k;
	update(k);update(t);
	k=t;
}
inline void rturn(int &k) {
	int t=l[k];l[k]=r[t];r[t]=k;
	update(k);update(t);
	k=t;
}
inline void insert(int &x,int rank) {
	if(!x) {
		x=++cnt;
		rnd[x]=rand();size[x]=1;
		return;
	}
	size[x]++;
	if(size[l[x]]<rank) {
		insert(r[x],rank-size[l[x]]-1);
		if(rnd[r[x]]<rnd[x]) lturn(x);
	}
	else {
		insert(l[x],rank);
		if(rnd[r[x]]<rnd[x]) rturn(x);
	}
}
inline void dfs(int x) {
	if(!x) return;
	dfs(l[x]);
	v[++now]=x;
	dfs(r[x]); 
}
inline void solve() {
	memset(mn,127,sizeof mn);
	mn[0]=-INF;
	for(int i=1;i<=n;i++) {
		int t=upper_bound(mn,mn+mx+1,v[i])-mn;
			mn[t]=min(mn[t],v[i]);
			ans[v[i]]=t;
			mx=max(t,mx);
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++) {
		int x=read();
		insert(root,x);
	}
	dfs(root);
	solve();
	for(int i=1;i<=n;i++) {
		ans[i]=max(ans[i-1],ans[i]);
		printf("%d\n",ans[i]);
	}
	return 0;
}
