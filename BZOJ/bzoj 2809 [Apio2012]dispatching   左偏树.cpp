#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int MAXN = 100010,MAXM = 100010;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int C[MAXN],L[MAXN],siz[MAXN],root[MAXN],n,m,pre[MAXM],now[MAXN],son[MAXM],tot;
LL ans,sum[MAXN];
inline void add(int a,int b) {
	pre[++tot]=now[a],now[a]=tot;son[tot]=b;
}
struct ltree {
	int v[MAXN],l[MAXN],r[MAXN],dis[MAXN],tot;
	int newnode(int val) {
		v[++tot]=val;l[tot]=r[tot]=dis[tot]=0;return tot;
	}
	int merge(int x,int y) {
		if(!x||!y)	return x+y;
		if(v[x]<v[y])	swap(x,y);
		r[x] = merge(r[x],y);
		if(dis[r[x]]>dis[l[x]]) swap(r[x],l[x]);
		dis[x]=dis[r[x]]+1;
		return x;
	}
	void pop(int &x) {
		x=merge(l[x],r[x]);
	}
	int top(int x) {
		return v[x];
	}
}h;
inline void dfs(int x) {
	root[x]=h.newnode(C[x]);
	siz[x]=1,sum[x]=C[x];
	for(int y=now[x];y;y=pre[y]) {
		dfs(son[y]);
		sum[x] += sum[son[y]];
		siz[x] += siz[son[y]];
		root[x] = h.merge(root[x],root[son[y]]);
	}
	for(;sum[x]>m;)	sum[x]-=h.top(root[x]),h.pop(root[x]),siz[x]--;
	ans = max(ans,1LL * L[x] * siz[x]);
}
int main()
{
	n=read(),m=read();
	for(int i=1,x;i<=n;i++)	x=read(),C[i]=read(),L[i]=read(),add(x,i);
	dfs(1);
	printf("%lld",ans);
	return 0;
}
