#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=(j),i##_end=(k);i<=i##_end;++i)
const int MXN = 5e5 + 5;
const int INF = 0x7fffffff;
int n,a[MXN],k,p[MXN],mn[MXN<<2],deg[MXN],A[MXN],cnt;
vector<int> G[MXN];

inline void pushup(int k) {
	mn[k]=min(mn[k<<1],mn[k<<1|1]);
}
inline void update(int k,int l,int r,int p,int x) {
	if(l==r) {
		mn[k]=x;	return;
	}
//	cerr<<"k = "<<k<<endl;
	int mid=l+r>>1;
	if(p<=mid) update(k<<1,l,mid,p,x);
	else update(k<<1|1,mid+1,r,p,x);
	pushup(k);
}
inline int query(int k,int l,int r,int L,int R) {
	if(L>R) return INF;
	if(l>=L&&r<=R) {
		return mn[k];
	}
//	fprintf(stderr,"k = %d , l = %d , r = %d L = %d R = %d\n",k,l,r,L,R);
	if(!k) exit(0);
	int mid=l+r>>1;
	if(L>mid) return query(k<<1|1,mid+1,r,L,R);
	else if(R<=mid) return query(k<<1,l,mid,L,R);
	else return min(query(k<<1,l,mid,L,mid),query(k<<1|1,mid+1,r,mid+1,R));
}

int main() {
	ios::sync_with_stdio(false);
	cin>>n>>k;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n) p[a[i]]=i;
	rep(i,0,MXN*4-1) mn[i]=INF;
	for(int i=n;i;--i) {
		int ret=query(1,1,n,p[i]+1,min(p[i]+k-1,n));
		if(ret!=INF) G[p[i]].push_back(p[ret]),deg[p[ret]]++;
		ret = INF; ret = query(1,1,n,max(1,p[i]-k+1),p[i]-1);
		if(ret!=INF) G[p[i]].push_back(p[ret]),deg[p[ret]]++;
		update(1,1,n,p[i],i);
	}
	priority_queue<int,vector<int>,greater<int> > Q;
	rep(i,1,n) if(!deg[i]) Q.push(i);
	while(!Q.empty()) {
		int now = Q.top(); Q.pop();
		A[now]=++cnt;
		for(auto w:G[now]) {
			if(!--deg[w]) Q.push(w);
		}
	}
	rep(i,1,n) cout<<A[i]<<endl;
}
