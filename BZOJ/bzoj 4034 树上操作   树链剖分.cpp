#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200003
#define LL long long
using namespace std;
int tot,n,m,next[N],point[N],v[N],deep[N],fa[N],size[N],son[N];
LL tr[N*4],delta[N*4];
int val[N],l[N],r[N],q[N],pos[N],cnt,belong[N];
void add(int x,int  y)
{
	next[++tot]=point[x]; point[x]=tot; v[tot]=y;
	next[++tot]=point[y]; point[y]=tot; v[tot]=x;
}
void dfs(int x,int f)
{
	deep[x]=deep[f]+1;
	size[x]=1;
	for (int i=point[x];i;i=next[i])
	 if (v[i]!=f) {
	 	fa[v[i]]=x;
	 	dfs(v[i],x);
	 	size[x]+=size[v[i]];
	 	if (size[son[x]]<size[v[i]]) son[x]=v[i];
	 }
}
void dfs1(int x,int chain)
{
	belong[x]=chain; pos[x]=++cnt; l[x]=r[x]=cnt; q[cnt]=x;
	if (!son[x]) return;
	dfs1(son[x],chain);
	for (int i=point[x];i;i=next[i])
	 if (v[i]!=fa[x]&&v[i]!=son[x])
	  dfs1(v[i],v[i]);
	r[x]=cnt;
}
void update(int now)
{
	tr[now]=tr[now<<1]+tr[now<<1|1];
}
void build(int now,int l,int r)
{
	if (l==r) {
		tr[now]=(LL)val[q[l]];
		return;
	}
	int mid=(l+r)/2;
	build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
	update(now);
}
void pushdown(int now,int l,int r)
{
	int mid=(l+r)/2;
	if (delta[now]) {
		tr[now<<1]+=(LL)(mid-l+1)*delta[now];
		tr[now<<1|1]+=(LL)(r-mid)*delta[now];
		delta[now<<1]+=delta[now];
		delta[now<<1|1]+=delta[now];
		delta[now]=0;
	}
}
void pointchange(int now,int l,int r,int x,int v)
{
	if (l==r) {
		tr[now]+=(LL)v;
		return;
	}
	int mid=(l+r)/2;
	pushdown(now,l,r);
	if (x<=mid) pointchange(now<<1,l,mid,x,v);
	else pointchange(now<<1|1,mid+1,r,x,v);
	update(now);
}
void qjchange(int now,int l,int r,int ll,int rr,int v)
{
	if (ll<=l&&r<=rr) {
		tr[now]+=(LL)v*(LL)(r-l+1);
		delta[now]+=(LL)v;
		return;
	}
	int mid=(l+r)/2;
	pushdown(now,l,r);
	if (ll<=mid) qjchange(now<<1,l,mid,ll,rr,v);
	if (rr>mid) qjchange(now<<1|1,mid+1,r,ll,rr,v);
	update(now);
}
LL qjsum(int now,int l,int r,int ll,int rr)
{
	if (ll<=l&&r<=rr) return tr[now];
	int mid=(l+r)/2; LL ans=0;
	pushdown(now,l,r);
	if (ll<=mid) ans+=qjsum(now<<1,l,mid,ll,rr);
	if (rr>mid) ans+=qjsum(now<<1|1,mid+1,r,ll,rr);
	return ans;
}
LL solve(int x,int y)
{
	LL ans=0;
	while (belong[x]!=belong[y]) {
		if (deep[belong[x]]<deep[belong[y]]) swap(x,y);
		ans+=qjsum(1,1,n,pos[belong[x]],pos[x]);
		x=fa[belong[x]];
	}
	if(deep[x]>deep[y]) swap(x,y);
	ans+=qjsum(1,1,n,pos[x],pos[y]);
	return ans;
}
int main()
{
	freopen("a.in","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&val[i]);
	for (int i=1;i<n;i++) {
		int x,y; scanf("%d%d",&x,&y);
		add(x,y);
	}
	dfs(1,0); dfs1(1,1);
	build(1,1,n);
	for (int i=1;i<=m;i++) {
		int opt,x,y; scanf("%d",&opt);
		if (opt==1) {
			scanf("%d%d",&x,&y);
			pointchange(1,1,n,pos[x],y);
		}
		if (opt==2) {
			scanf("%d%d",&x,&y);
			qjchange(1,1,n,l[x],r[x],y);
		}
		if (opt==3) {
			scanf("%d",&x);
			printf("%I64d\n",solve(1,x));
		}
	}
}
