#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e5 + 5 , INF = 0x7fffffff;
#define rpg(i,x) for(int i=fir[x];i;i=e[i].nxt)
typedef long long LL;
int pos[MXN],vis[MXN],dfn[MXN],dfs_clock,n,m,fir[MXN],edge_cnt,dep[MXN],fa[MXN],siz[MXN],top[MXN];
LL w[MXN],ans,tmp,t;
set<int> S;
struct edge {
	int to,nxt,w;
}e[MXN<<1];
inline void AE(int u,int v,int w) {
	e[++edge_cnt].to=v;e[edge_cnt].nxt=fir[u];fir[u]=edge_cnt;e[edge_cnt].w=w;
}
inline void dfs1(int x) {
	siz[x]=1;
	rpg(i,x) {
		int v=e[i].to;
		if(v==fa[x]) continue;
		w[v]=w[x]+e[i].w; fa[v]=x; dep[v]=dep[x]+1;
		dfs1(v); siz[x]+=siz[v];
	}
}
inline void dfs2(int x,int chain) {
	dfn[x]=++dfs_clock; top[x]=chain; pos[dfs_clock]=x;
	int v=0,mx=0;
	rpg(i,x) {
		if(e[i].to!=fa[x]) {
			if(siz[e[i].to]>mx) mx=siz[e[i].to],v=e[i].to;
		}
	}
	if(v)
		dfs2(v,chain);
	rpg(i,x) {
		if(e[i].to!=fa[x]&&e[i].to!=v) {
			dfs2(e[i].to,e[i].to);
		}
	}
}
inline int LCA(int x,int y) {
	while(top[x]!=top[y]) {
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}

int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
#endif
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1,x,y,z;i<n;++i) {
		cin>>x>>y>>z;
		AE(x,y,z),AE(y,x,z);
	}
	dfs1(1),dfs2(1,1); S.insert(INF),S.insert(-INF);
	while(m--) {
		int x; cin>>x; if(vis[x]) S.erase(dfn[x]),t=-1; else S.insert(dfn[x]),t=1;
		vis[x]^=1; auto l=*--S.lower_bound(dfn[x]),r=*S.upper_bound(dfn[x]);
		if(l!=-INF) ans+=1LL*t*(w[pos[l]]+w[x]-w[LCA(pos[l],x)]*2);
		if(r!=INF) ans+=1LL*t*(w[pos[r]]+w[x]-w[LCA(x,pos[r])]*2);
		if(l!=-INF&&r!=INF) ans-=1LL*t*(w[pos[l]]+w[pos[r]]-2*w[LCA(pos[l],pos[r])]);
		if(S.size()>3) tmp=(w[pos[*S.upper_bound(-INF)]]+w[pos[*--S.lower_bound(INF)]]-2*w[LCA(pos[*S.upper_bound(-INF)],pos[*--S.lower_bound(INF)])]); else tmp=0;
		cout<<ans+tmp<<endl;
	}
}
