#include<iostream>  
#include<cstdio>  
#include<cstring>  
#define mid (l+r)/2  
#define lch i<<1,l,mid  
#define rch i<<1|1,mid+1,r  
#define inf 2147483647  
using namespace std;  
struct hp{  
    int fat,dep,size,wson,top,ls,rs;
	//father deep size zhongerzi lianding zuo you          feng fu  
    int lca[18];  
}tree[100001];  
struct hq{  
    int u,v;  
}a[200001];  
struct hr{  
    int minn,delta;  
}seg[400001];
  
int point[100001],next[100001];  
int val[400001],plc[100001];  
int n,m,ans,e=1,totw=0,root;  
void add(int x,int y)  
{  
    e++; a[e].u=x; a[e].v=y; next[e]=point[x]; point[x]=e;  
    e++; a[e].u=y; a[e].v=x; next[e]=point[y]; point[y]=e;  
}  
void build_tree(int last,int x,int depth)  
{  
    int i;  
    tree[x].lca[0]=tree[x].fat=last;  
    tree[x].size=1;  
    tree[x].wson=0;  
    tree[x].dep=depth;  
    for (i=1;i<=17;++i)  
      {  
        if (tree[x].dep >= 1<<i)  
          tree[x].lca[i]=tree[tree[x].lca[i-1]].lca[i-1];  
      }  
    for (i=point[x];i;i=next[i])  
      if (a[i].v!=last)  
        {  
          build_tree(x,a[i].v,depth+1);  
          if (tree[tree[x].wson].size<tree[a[i].v].size)  
            tree[x].wson=a[i].v;  
        }  
}  
void build_seg(int now,int tp)  
{  
    int i;  
    tree[now].top=tp;  
    tree[now].ls=plc[now]=++totw;  
    if (tree[now].wson!=0)  
      build_seg(tree[now].wson,tp);  
    for (i=point[now];i;i=next[i])  
      if (a[i].v!=tree[now].fat&&a[i].v!=tree[now].wson)  
        build_seg(a[i].v,a[i].v);  
    tree[now].rs=totw;  
}
int LCA(int x,int y)  
{  
    int i,t;  
    if (tree[x].dep<tree[y].dep) swap(x,y);  
    t=tree[x].dep-tree[y].dep;  
    for (i=0;i<=17;++i)  
      {  
        if (t&(1<<i))  
          x=tree[x].lca[i];  
      }  
    for (i=17;i>=0;--i)  
      if (tree[x].lca[i]!=tree[y].lca[i])  
        {x=tree[x].lca[i]; y=tree[y].lca[i];}  
    if (x==y) return x;  
    else return tree[x].fat;  
}  

void updata(int i)  
{  
    seg[i].minn=min(seg[i<<1].minn,seg[i<<1|1].minn);  
}  
void paint(int i,int a)  
{  
    seg[i].minn=a;  
    seg[i].delta=a;  
}  
void pushdown(int i)  
{  
    paint(i<<1,seg[i].delta);  
    paint(i<<1|1,seg[i].delta);  
    seg[i].delta=0;  
}  
void build(int i,int l,int r)  
{  
    if (l==r)  
      {  
        seg[i].minn=val[l];  
        return;  
      }  
    build(lch); build(rch);  
    updata(i);  
}  


void insert_seg(int i,int l,int r,int x,int y,int a)  
{  
    if (x<=l&&y>=r)  
      {  
        paint(i,a);  
        return;  
      }  
    if (seg[i].delta!=0)  
      pushdown(i);  
    if (x<=mid) insert_seg(lch,x,y,a);  
    if (y>mid) insert_seg(rch,x,y,a);  
    updata(i);  
}   
void insert(int x,int y,int a)  
{  
	// x~~~~y 改成a 
    int f1=tree[x].top,f2=tree[y].top;  
    while (f1!=f2)  
      {  
        if (tree[f1].dep<tree[f2].dep) {swap(f1,f2); swap(x,y);}  //保持f1这边比较深 
        insert_seg(1,1,n,plc[f1],plc[x],a);  //把根节点为1的树从1-n范围内的f1到x这一段改成a 
        x=tree[f1].fat; f1=tree[x].top;   
      }  
    if (tree[x].dep>tree[y].dep) swap(x,y);  
    insert_seg(1,1,n,plc[x],plc[y],a);  
}  
int bz(int x,int depth)  
{  
    int i,v=x;  
    for (i=0;i<=17;++i)  
      {  
        if (depth&(1<<i))  
          v=tree[v].lca[i];  
      }  
    return v;  
}  
void query_seg(int i,int l,int r,int x,int y)  
{  
    if (x<=l&&y>=r)  
      {  
        ans=min(ans,seg[i].minn);  
        return;  
      }  
    if (seg[i].delta!=0)  
      pushdown(i);  
    if (x<=mid) query_seg(lch,x,y);  
    if (y>mid) query_seg(rch,x,y);  
}   

void work(int x)  
{  
    int lca,v,rootx=root,xx=x;  
    lca=LCA(root,x);  
    if (rootx==xx)//情况1  
      printf("%d\n",seg[1].minn);  
    else  
      {  
        if (lca!=xx)//情况2  
          query_seg(1,1,n,tree[xx].ls,tree[xx].rs);  
          
        else//情况三  
          {  
            v=bz(rootx,tree[rootx].dep-tree[xx].dep-1);  
            if (tree[v].ls>1)  
              query_seg(1,1,n,1,tree[v].ls-1);  
            if (tree[v].rs<n)  
              query_seg(1,1,n,tree[v].rs+1,n);	//不是1或者n就行了    
          }  
        printf("%d\n",ans);  
      }  
    root=rootx;  
}  
int main()  
{  
    int i,x,y,opt,a;  
    scanf("%d%d",&n,&m);  
    for (i=1;i<n;++i)  
      {  
        scanf("%d%d",&x,&y);  
        add(x,y);  
      }  
    build_tree(0,1,0);  
    build_seg(1,1);  
    //这不就是dfs1 和dfs2 我还以为是啥 
    for (i=1;i<=n;++i)  
      scanf("%d",&val[plc[i]]);
	    
    build(1,1,n);  
    
    scanf("%d",&root);  
    for (i=1;i<=m;++i)  
      {  
        scanf("%d",&opt);  
        switch(opt)
        {
        	case 1: scanf("%d",&x);root = x ; break;
        	case 2: scanf("%d%d%d",&x,&y,&a); insert(x,y,a);break;
        	case 3: scanf("%d",&x); ans = inf; work(x);
		}  
      }  
}  
