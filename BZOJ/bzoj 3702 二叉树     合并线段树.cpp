#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int N = 400010;
int cnt,t[N*10],root[N],ls[N*10],rs[N*10],v[N],n,l[N],r[N],sz;
LL ans,a,b;
inline void buildtree(int x) {
	v[x]=read();
	if(v[x]==0) {
		l[x]=++sz;
		buildtree(l[x]);
		r[x]=++sz;
		buildtree(r[x]);
	}
} 
inline void update(int k) {
	t[k]=t[ls[k]]+t[rs[k]];
}
inline void build(int &k,int l,int r,int v) {
	if(!k)	k=++cnt;
	if(l==r)	{t[k]=1;return;}
	int mid=(l+r)>>1;
	if(v<=mid)	build(ls[k],l,mid,v);
	else build(rs[k],mid+1,r,v);
	update(k);
}
inline int merge(int x,int y) {
	if(!x)	return y;
	if(!y)	return x;
	a+=(long long)t[ls[x]]*t[rs[y]];
	b+=(long long)t[rs[x]]*t[ls[y]];
	ls[x]=merge(ls[x],ls[y]);
	rs[x]=merge(rs[x],rs[y]);
	update(x);
	return x;
}
inline void solve(int x) {
	if(x==0)	return;
	solve(l[x]);	solve(r[x]);
	if(!v[x]) {
		a=0,b=0;
		root[x]=merge(root[l[x]],root[r[x]]);
		ans+=min(a,b);
	}
}
int main()
{
	n=read();
	sz=1;buildtree(1);
	for(int i=1;i<=sz;i++) {
		if(v[i])	build(root[i],1,n,v[i]);
	}
	solve(1);
	cout<<ans<<endl;
	return 0;
}
