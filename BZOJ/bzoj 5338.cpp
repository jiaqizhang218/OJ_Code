#include<bits/stdc++.h>
using namespace std;
#define rpg(i,x) for(int i=fir[x];i;i=e[i].nxt)
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define debug(...) fprintf(stderr,__VA_ARGS__)
const int MXN = 1e5 + 5;
int fir[MXN],edge_cnt,in[MXN],pos[MXN],dfs_clock,fa[MXN][20],dep[MXN],w[MXN],Q,n,out[MXN];
struct edge{int to,nxt;}e[MXN<<1];
inline void AE(int u,int v) {
	e[++edge_cnt].to=v;e[edge_cnt].nxt=fir[u];fir[u]=edge_cnt;
}
inline void Ins(int u,int v) {
	AE(u,v),AE(v,u);
}

inline void dfs1(int x,int fon) {
	in[x]=++dfs_clock; pos[dfs_clock]=x;;
	for(int i=1;i<=17;++i) fa[x][i]=fa[fa[x][i-1]][i-1];
	rpg(i,x) {
		int v=e[i].to;
		if(v==fon) continue;
		fa[v][0]=x;dep[v]=dep[x]+1;dfs1(v,x);
	}
	out[x]=dfs_clock;
}

inline int lca(int u,int v) {
	if(dep[u]<dep[v]) swap(u,v);
	for(int k=17;~k;--k) if(dep[fa[u][k]]>=dep[v]) u=fa[u][k];
	if(u==v) return u;
	for(int k=17;~k;--k) if(fa[u][k]!=fa[v][k]) u=fa[u][k],v=fa[v][k];
	return fa[u][0];
}
struct Trie {
	int rt[MXN],ch[MXN*40][2],cnt=0,sz[MXN*40];
	inline void Change(int x,int &y,int k) {
		y = ++cnt; int i,now=y,d;
		for(i=1<<30;i;i>>=1) {
			d = (k&i) > 0;
			ch[now][d] = ++cnt , ch[now][d^1] = ch[x][d^1] , now = ch[now][d] , x = ch[x][d] , sz[now] = sz[x] + 1;
		}
	}
	inline int Query(int l,int r,int k) {
		int i,sum=0,d;
		for(i=1<<30;i;i>>=1) {
			d = !(k&i);
			if( sz[ ch[r][d] ] - sz[ ch[l][d] ] ) l = ch[l][d] , sum |= i , r = ch[r][d];
			else l = ch[l][d^1] , r = ch[r][d^1];
		}
		return sum;
	}
	inline int Query(int x,int y,int z,int k) {
		int i,sum=0,d;
		for(i=1<<30;i;i>>=1) {
			d = !(k&i);
			if(sz[ ch[x][d] ] + sz[ ch[y][d] ] - 2 * sz[ ch[z][d] ]) x = ch[x][d],y = ch[y][d],z=ch[z][d],sum|=i;
			else x = ch[x][d^1],y = ch[y][d^1],z = ch[z][d^1];
		}
		return sum;
	}
}T1,T2;
inline void D(int x) {
	T2.Change(T2.rt[fa[x][0]],T2.rt[x],w[x]);
	rpg(i,x) {
		int v=e[i].to;
		if(v!=fa[x][0]) D(v);
	}
}
int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
#endif
	ios::sync_with_stdio(false);
	cin>>n>>Q;
	for(int i=1;i<=n;++i) cin>>w[i];
	for(int i=1;i<n;++i) {
		int x,y;cin>>x>>y;
		Ins(x,y);
	}
	dep[1]=1;dfs1(1,0);T1.Change(0,T1.rt[0],0);
	for(int i=1;i<=n;++i) T1.Change(T1.rt[i-1],T1.rt[i],w[pos[i]]);
//	dbg(T1.cnt);
//	for(int i=1;i<=T1.cnt;++i) dbg(T1.sz[i]);
	T2.Change(0,T2.rt[0],0);
	D(1);
	while(Q--) {
		int opt; cin>>opt;
		if(opt==1) {
			int u,x,qres=0;
			cin>>u>>x;
			cout<<T1.Query(T1.rt[in[u]-1],T1.rt[out[u]],x)<<endl;
		} else {
			int u,v,x; cin>>u>>v>>x;
			int t=lca(u,v);
			cout<<max(w[t]^x,T2.Query(T2.rt[u],T2.rt[v],T2.rt[t],x))<<endl;
		}
	}
}
