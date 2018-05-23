#include<bits/stdc++.h>
using namespace std;
#define rpg1(i,x) for(register int i=g1.fir[x];i;i=g1.e[i].nxt)
#define rpg2(i,x) for(register int i=g2.fir[x];i;i=g2.e[i].nxt)
const int MXN = 2e5 + 5;
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define debug(...) fprintf(stderr,__VA_ARGS__)
struct graph {
	int fir[MXN],edge_cnt;
	struct edge {
		int to,nxt;
	}e[MXN<<1];
	inline void AE(int u,int v) {
		e[++edge_cnt].to=v;e[edge_cnt].nxt=fir[u];fir[u]=edge_cnt;
	}
	inline void clear() {
		memset(fir,0,sizeof fir); edge_cnt=1;
	}
}g1,g2;
int stk[MXN],fa[MXN],dep[MXN],T,m,q,S,w[MXN],a[MXN],tps_siz[MXN],low[MXN],dfn[MXN],top,tp[MXN],dfs_clock,sz,n;
inline void tarjan(int x,int fro) {
	dfn[x]=low[x]=++dfs_clock; 
	rpg1(i,x) {
		if(i==(fro^1)) continue;
		if(!dfn[g1.e[i].to]) {
			stk[++top]=i;
			tarjan(g1.e[i].to,i);
			low[x]=min(low[x],low[g1.e[i].to]);
			if(low[g1.e[i].to]>=dfn[x]) {
				++sz; int v=0;
				while(v!=i) {
					v=stk[top--]; 
					g2.AE(sz+n,g1.e[v].to);g2.AE(g1.e[v].to,sz+n);
				} g2.AE(sz+n,x);g2.AE(x,sz+n);
			}
		} else low[x]=min(low[x],dfn[g1.e[i].to]);
	}
}
inline void dfs1(int x) {
	tps_siz[x]=1;
	rpg2(i,x) {
		int v=g2.e[i].to;
		if(v==fa[x]) continue;
		fa[v] = x; dep[v]=dep[x]+1;
		dfs1(v); tps_siz[x]+=tps_siz[v];
	}
}
inline void dfs2(int x,int chain) {
	w[x]=w[fa[x]]+(x<=n);  dfn[x]=++dfs_clock;  tp[x]=chain;
	int v=0,mx=0;
	rpg2(i,x) {
		if(g2.e[i].to==fa[x]) continue;
		if(tps_siz[g2.e[i].to]>mx) mx=tps_siz[g2.e[i].to],v=g2.e[i].to;
	}
	if(v) dfs2(v,chain);
	rpg2(i,x) {
		if(g2.e[i].to==fa[x]||g2.e[i].to==v) continue;
		dfs2(g2.e[i].to,g2.e[i].to);
	}
}
inline int LCA(int x,int y) {
	while(tp[x]!=tp[y]) {
		if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
		x=fa[tp[x]];
	}
	return dep[x]<dep[y]?x:y;
}
inline bool cmp(int a,int b) {
	return dfn[a]<dfn[b];
}
int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
	freopen("233.out","w",stdout);
#endif
	ios::sync_with_stdio(false);
	cin>>T;
	for(register int owo=1;owo<=T;++owo) {
		g1.clear();g2.clear();memset(dfn,0,sizeof dfn);memset(fa,0,sizeof fa);memset(dep,0,sizeof dep);memset(tp,0,sizeof tp);memset(w,0,sizeof w);memset(tps_siz,0,sizeof tps_siz);memset(low,0,sizeof low);sz=0;top=0;
		cin>>n>>m;
		for(register int x,y,i=1;i<=m;++i) {
			cin>>x>>y; g1.AE(x,y),g1.AE(y,x);
		}
		cin>>q;
		tarjan(1,0),dfs_clock=0;dfs1(1),dfs2(1,1);
		for(register int ooo=1;ooo<=q;++ooo) {
			cin>>S; for(register int i=1;i<=S;++i) cin>>a[i];
			sort(a+1,a+1+S,cmp);
			stk[top=1]=1; int ans=1,flag=0;
			if(a[1]==1) flag=1;
			for(register int i=1;i<=S;++i) {
				if(stk[top]==a[i]) continue;
				int f=LCA(a[i],stk[top]);
				if(f==stk[top]) {stk[++top]=a[i];continue;}
				while(top>1&&dep[stk[top-1]]>=dep[f]) ans+=w[stk[top]]-w[stk[top-1]],top--,flag|=(stk[top]==1);
				if(dep[stk[top]]>dep[f]) ans+=w[stk[top]]-w[f],flag|=(f==1),top--;
				if(stk[top]!=f) stk[++top]=f;
				stk[++top]=a[i];
			}
			while(top>1) ans+=w[stk[top]]-w[stk[top-1]],top--;
			if(!flag) ans-=w[fa[stk[2]]];
			cout<<ans-S<<endl;
		}
	}
#ifdef iloi
	fprintf(stderr,"My time is %.3lfs\n",(double)clock()/CLOCKS_PER_SEC);
#endif
}
