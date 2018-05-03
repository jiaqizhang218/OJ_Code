#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100005
#define inf 0x7fffffff
using namespace std;
int n,cnt=1,sz;
int head[N],deep[N],size[N],pos[N],belong[N];
int fa[N][17],id[N];
struct edge{int to,next,v;}e[N<<1];
struct seg{int l,r,mx,a,c;}t[N<<2];

void insert(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].next=head[u];e[cnt].v=w;head[u]=cnt;
	e[++cnt].to=u;e[cnt].next=head[v];e[cnt].v=w;head[v]=cnt;
}

int lca(int x,int y)
{
    if(deep[x]<deep[y])	swap(x,y);
    int t = deep[x]-deep[y];
    for(int i=0;i <= 16;i++)
       if(t&(1<<i))x=fa[x][i];
    for(int i=16;i>=0;i--)
       if(fa[x][i]!=fa[y][i])
       {x=fa[x][i];y=fa[y][i];}
    if(x==y)return x;
    return fa[x][0];
}

void pushdown(int k)
{
	//莫非如同lazy标记？？ 
	if(t[k].l==t[k].r)	return;
	if(t[k].c!=-1)
	{
		t[k<<1].a = t[k<<1|1].a = 0;
		t[k<<1].c = t[k<<1|1].c = t[k].c;
		t[k<<1].mx = t[k<<1|1].mx = t[k].c;
		t[k].c=-1;
	}
	if(t[k].a)
	{
		t[k<<1].mx+=t[k].a;t[k<<1|1].mx+=t[k].a;
		if(t[k<<1].c!=-1)t[k<<1].c+=t[k].a;
		else t[k<<1].a+=t[k].a;
		if(t[k<<1|1].c!=-1)t[k<<1|1].c+=t[k].a;
		else t[k<<1|1].a+=t[k].a;
		t[k].a=0;
	}
}

void build(int k,int l,int r)
{
	t[k].l=l; t[k].r=r; t[k].c=-1;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}

void pushup(int k)
{	t[k].mx = max( t[k<<1].mx , t[k<<1|1].mx ); }

void change(int k,int x,int y,int v)
{
	pushdown(k);
	int l=t[k].l , r=t[k].r;
	if( l == x && y == r ){ t[k].mx = t[k].c=v; return; }
	int mid=(l+r)>>1;
	if(mid>=y)change(k<<1,x,y,v);
	else if(mid<x)change(k<<1|1,x,y,v);
	else 
	{
		change(k<<1,x,mid,v);
		change(k<<1|1,mid+1,y,v);
	}
	pushup(k);
}
void add(int k,int x,int y,int v)
{
	pushdown(k);
	int l=t[k].l,r=t[k].r;
	if(l==x&&y==r){t[k].mx+=v;t[k].a=v;return;}
	int mid=(l+r)>>1;
	if(mid>=y)add(k<<1,x,y,v);
	else if(mid<x)add(k<<1|1,x,y,v);
	else 
	{
		add(k<<1,x,mid,v);
		add(k<<1|1,mid+1,y,v);
	}
	pushup(k);
}

int ask(int k,int x,int y)
{
	pushdown(k);
	int l=t[k].l,r=t[k].r;
	if(l==x&&y==r)return t[k].mx;
	int mid=(l+r)>>1;
	if(mid>=y)return ask(k<<1,x,y);
	else if(mid<x)return ask(k<<1|1,x,y);
	else return max(ask(k<<1,x,mid),ask(k<<1|1,mid+1,y));
}

void solvechange(int x,int f,int v)
{
    while(belong[x]!=belong[f])
    {
        change(1,pos[belong[x]],pos[x],v);
        x=fa[belong[x]][0]; 
    }
    if(pos[f]+1<=pos[x])
    change(1,pos[f]+1,pos[x],v);
}

void solveadd(int x,int f,int v)
{
    while(belong[x]!=belong[f])
    {
        add(1,pos[belong[x]],pos[x],v);
        x=fa[belong[x]][0]; 
    }
    if(pos[f]+1<=pos[x])
    add(1,pos[f]+1,pos[x],v);
}

int solveask(int x,int f)
{
	int mx=-inf;
    while(belong[x]!=belong[f])
    {
        mx=max(mx,ask(1,pos[belong[x]],pos[x]));
        x=fa[belong[x]][0]; 
    }
    if(pos[f]+1<=pos[x])
        mx=max(mx,ask(1,pos[f]+1,pos[x]));
    return mx;
}

void solve()
{
	char s[10];
	int u,v,w,f;
	while(1)
	{
		scanf("%s",s);
		
		switch(s[1])
		{
			case 't':return;break;
			
			case 'd':scanf("%d%d%d",&u,&v,&w);f=lca(u,v);
			         solveadd(u,f,w);solveadd(v,f,w);break;
			         
			case 'o':scanf("%d%d%d",&u,&v,&w);f=lca(u,v);
				     solvechange(u,f,w);solvechange(v,f,w);break;
				     
			case 'h':scanf("%d%d",&u,&w);change(1,pos[id[u]],pos[id[u]],w);break;
			
			case 'a':scanf("%d%d",&u,&v);f=lca(u,v);
			         printf("%d\n",max(solveask(u,f),solveask(v,f)));break;
		}
	}
}
// 下面就是普通的划分重链 
void dfs1(int x,int f)
{
	size[x]=1;
	for(int i=1;i<=16;i++)
	    if((1<<i)<=deep[x])
		    fa[x][i]=fa[fa[x][i-1]][i-1];
        else break;
    for(int i=head[x];i;i=e[i].next)
    {
    	if(e[i].to==f)continue;
    	deep[e[i].to]=deep[x]+1;
    	fa[e[i].to][0]=x;
    	dfs1(e[i].to,x);
    	size[x]+=size[e[i].to];
    }
}

void dfs2(int x,int chain)
{
	belong[x]=chain;
	pos[x]=++sz;
	int k=0;
	for(int i=head[x];i;i=e[i].next)
	{
	   if(deep[x]<deep[e[i].to])
	   {
	       if(size[e[i].to]>size[k])k=e[i].to;
	   }
	   else {id[i>>1]=x;add(1,pos[x],pos[x],e[i].v);}
    }
    if(!k)return;
    dfs2(k,chain);
    for(int i=head[x];i;i=e[i].next)
    	if(deep[x]<deep[e[i].to]&&k!=e[i].to)
    	    dfs2(e[i].to,e[i].to);
}

int main()
{
	scanf("%d",&n);
	for(int i = 1 ; i < n ; i++ )
    {
    	int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
    	insert(u,v,w);
    }
    
    build(1,1,n);
    dfs1(1,0);
	dfs2(1,1);
    solve();
	return 0;
}
