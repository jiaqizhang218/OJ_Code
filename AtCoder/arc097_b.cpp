#include<bits/stdc++.h>
using namespace std;
const int MXN = 2e5 + 5;
int ans,n,m,dfn[MXN],stk[MXN],top,bel[MXN],scc,inq[MXN],low[MXN],dfs_clock;
vector<int> G[MXN];
inline void tarjan(int x) {
	dfn[x]=low[x]=++dfs_clock; stk[++top]=x; inq[x]=1;
	for(auto w:G[x]) {
		if(!dfn[w]) {
			tarjan(w); low[x]=min(low[x],low[w]);
		} else if(inq[w]) low[x]=min(low[x],dfn[w]);
	}

	if(low[x]==dfn[x]) {
		int v=0;  ++scc;
		do {
			v=stk[top--];
			inq[v]=0;
			bel[v]=scc;
		} while(v!=x);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1,x;i<=n;++i) cin>>x,G[x+n].push_back(i),G[i].push_back(x+n);
	for(int i=1,x,y;i<=m;++i) cin>>x>>y,G[x].push_back(y),G[y].push_back(x);
	for(int i=1;i<=n*2;++i) 
		if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;++i) 
		if(bel[i]==bel[i+n]) ++ans;
	cout<<ans<<endl;
}
