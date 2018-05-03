#include<bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
const int N = 30000 + 5;
const int M = 60000 + 5;
int n,q,cnt,sz;
int v[N],dep[N],size[N],fa[N];
int pos[N],bl[N];
int to[M],head[M],nxt[M];
struct seg{
	int l , r , mx , sum;
}t[100005];

void insert(int u,int v)
{
	to[++cnt] = v ; nxt[cnt] = head[u] ; head[u] = cnt;
	to[++cnt] = u ; nxt[cnt] = head[v] ; head[v] = cnt;
}

void init()
{
	scanf("%d",&n);
	for(int i = 1 ; i < n ; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		insert(x,y);
	}
	for(int i = 1 ; i <= n ; i++) scanf("%d",&v[i]);
}

void dfs1(int x)
{
	size[x] = 1 ;
	for(int i = head[x] ; i ; i = nxt[i])
	{
		if(to[i] != fa[x])
		{
			dep[to[i]] = dep[x] + 1;
			fa[to[i]] = x;
			dfs1(to[i]);
			size[x] += size[to[i]];
		}
	}
}

void dfs2(int x,int chain)
{
	int k = 0 ; 
	pos[x] = ++sz;  // 分配x节点在线段树中的编号 
	bl[x] = chain;
	for(int i = head[x] ; i ; i = nxt[i])
		if(to[i] != fa[x] && size[to[i]] > size[k])
			k = to[i]; //找重儿子 
	if(k == 0) return ;
	dfs2(k,chain);
	for(int i = head[x] ; i ; i = nxt[i])
		if(to[i] != fa[x] && k != to[i])
				dfs2(to[i],to[i]); //其他儿子新开重链 
}

void build(int k,int l ,int r)   //见线段树 
{
	t[k].l = l; t[k].r = r;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
}

void change(int k,int x,int y) // 线段树单点修改 
{
	int l = t[k].l , r = t[k].r ,mid = (r + l ) >> 1;
	if(l == x )
	{
		t[k].sum = t[k].mx = y ; return;
 	 } 
 	if(x <= mid) change(k<<1,x,y);
 	else change(k<<1|1,x,y);
 	t[k].sum = t[k<<1].sum + t[k<<1|1].sum ;
 	t[k].mx = max(t[k<<1].mx,t[k<<1|1].mx);
}

int querysum(int k,int x,int y)  // 线段树区间求和
{
	int l = t[k].l , r = t[k].r , mid = (l + r) >> 1;
	if(l == x && r == y)	return t[k].sum;
	if(y <=mid) return querysum(k<<1,x,y);
	else if(x >= mid) return querysum(k<<1|1,x,y);
	else return querysum(k<<1,x,mid)+querysum(k<<1|1,mid+1,y); 
}

int querymx(int k,int x,int y)
{
	int l = t[k].l , r = t[k].r , mid = (l + r) >> 1;
	if(l == x && r == y) return t[k].mx;
	if(y<=mid)	return querymx(k<<1,x,y);
    else if(x>mid)	return querymx(k<<1|1,x,y);
    else return max(querymx(k<<1,x,mid),querymx(k<<1|1,mid+1,y));
}

int solvesum(int x,int y)
{
	int sum = 0;
	while(bl[x] != bl[y])
	{
		if(dep[bl[x]] < dep[bl[y]]) swap(x,y);
		sum += querysum(1,pos[bl[x]],pos[x]);
		x = fa[bl[x]];
	}
	if(pos[x] > pos[y]) swap(x,y);
	sum += querysum(1,pos[x],pos[y]);
	return sum;
 } 
 
int solvemx(int x,int y)
{
	int mx = -INF;
	while(bl[x] != bl[y])
	{
		if(dep[bl[x]] < dep[bl[y]]) swap(x,y);
		mx = max(querymx(1,pos[bl[x]],pos[x]),mx);
		x = fa[bl[x]];
	}
	if(pos[x] > pos[y] ) swap(x,y);
	mx = max(mx,querymx(1,pos[x],pos[y]));
	return mx;
}

void solve()
{
	dfs1(1);
	dfs2(1,1);
	build(1,1,n);
	for(int i = 1 ; i <= n ; i++)
		change(1,pos[i],v[i]);
	scanf("%d",&q);
	int x,y; char ch[10];
	for(int i=1;i<=q;i++) 
    {
        int x,y;scanf("%s%d%d",ch,&x,&y);
        if(ch[0]=='C'){v[x]=y;change(1,pos[x],y);}
        else
        {
            if(ch[1]=='M')
               printf("%d\n",solvemx(x,y));
            else
                printf("%d\n",solvesum(x,y));
        }
    }
}
int main()
{
	init();
	solve();
	return 0;
}
