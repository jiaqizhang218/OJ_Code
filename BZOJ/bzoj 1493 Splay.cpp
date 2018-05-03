#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
#define MAXN 500010
int N,C,Q,a[MAXN];
 
namespace SplayTree{
#define lson(x) son[x][0]
#define rson(x) son[x][1]
    int size[MAXN],fa[MAXN],son[MAXN][2],sz,root;
    int val[MAXN],lc[MAXN],rc[MAXN],cnt[MAXN],rev[MAXN],cov[MAXN];
    inline void Newnode(int &x,int last,int v)
    {
        x=++sz;
        fa[x]=last; son[x][0]=son[x][1]=0;
        val[x]=lc[x]=rc[x]=v;
        cnt[x]=v? 1:0;
    }
    inline void Update(int x)
    {
        if (!x) return;
        size[x]=size[lson(x)]+size[rson(x)]+1;
        cnt[x]=cnt[lson(x)]+cnt[rson(x)]+1;
        lc[x]=rc[x]=val[x];
        if (lson(x)) lc[x]=lc[lson(x)],cnt[x]-=(val[x]==rc[lson(x)]? 1:0);
        if (rson(x)) rc[x]=rc[rson(x)],cnt[x]-=(val[x]==lc[rson(x)]? 1:0);
    }
    inline int Build(int l,int r,int last)
    {
        int mid=(l+r)>>1,x;
        Newnode(x,last,a[mid]);
        if (mid-1>=l) son[x][0]=Build(l,mid-1,x);
        if (mid+1<=r) son[x][1]=Build(mid+1,r,x);
        Update(x);
        return x;
    }
    inline void Rev(int x) {if (!x) return; rev[x]^=1; swap(son[x][1],son[x][0]); swap(lc[x],rc[x]);}
    inline void Cov(int x,int c) {if (!x) return; cov[x]=c; rev[x]=0; cnt[x]=1; lc[x]=rc[x]=val[x]=c;}
    inline void Pushdown(int x)
    {      
        if (cov[x])
            Cov(son[x][0],cov[x]),Cov(son[x][1],cov[x]),cov[x]=0;
        if (rev[x])
            Rev(son[x][0]),Rev(son[x][1]),rev[x]^=1;
    }
    inline int Right(int x) {return son[fa[x]][1]==x;}
    inline void Rotate(int x)
    {
        int y=fa[x],z=fa[y],w=Right(x);
        Pushdown(y); Pushdown(x);
        son[y][w]=son[x][w^1]; fa[son[y][w]]=y;
        fa[y]=x; son[x][w^1]=y; fa[x]=z;
        if (z) son[z][son[z][1]==y]=x;
        Update(y); Update(x);
    }
    inline void Splay(int x,int tar)
    {
        for (int y; (y=fa[x])!=tar; Rotate(x))
            if (fa[y]!=tar) Rotate(Right(x)==Right(y) ? y:x);
        if (!tar) root=x;
    }
    inline int Find(int x,int k)
    {
        Pushdown(x);
        if (size[son[x][0]]>=k) return Find(son[x][0],k);
        if (size[son[x][0]]+1==k) return x;
        return Find(son[x][1],k-size[son[x][0]]-1);
    }
    inline int Split(int l,int r)
    {
        int x=Find(root,l),y=Find(root,r+2);
        Splay(x,0); Splay(y,root); return lson(rson(root));
    }
    inline void Move(int k)
    {
        if (!k || k==N) return;
        int x=Split(N-k+1,N),y=fa[x];
        fa[x]=0; son[y][0]=0;
        Update(y); Update(fa[y]);
        int xx=Find(root,1),yy=Find(root,2);
        Splay(xx,0); Splay(yy,root);
        son[rson(root)][0]=x; fa[x]=rson(root);
        Update(rson(root)); Update(root);
    }
    inline void Cover(int l,int r,int c)
    {
        int x;
        if (l<=r)
            x=Split(l,r),Cov(x,c);
        else
            Move(N-l+1),Cover(1,r+N-l+1,c),Move(l-1);
    }
    inline int Query(int l,int r)
    {
        int x;
        if (l<=r)
            return cnt[Split(l,r)];
        else
            return Move(N-l+1),x=Query(1,r+N-l+1),Move(l-1),x;
    }
    inline int Query()
    {
        int x=cnt[Split(1,N)],lc=val[Find(root,2)],rc=val[Find(root,N+1)];
        return rc==lc? max(x-1,1):x;
    }
    inline void Swap(int x,int y)
    {
        int xc=val[Find(root,x+1)],yc=val[Find(root,y+1)];
        Cover(x,x,yc); Cover(y,y,xc);
    }
    inline void Rever() {int x=Split(2,N); Rev(x);}
}using namespace SplayTree;
 
int main()
{
    N=read(),C=read();
    for (int i=1; i<=N; i++) a[i]=read();
     
    Newnode(root,0,0);
    Newnode(son[root][1],root,0);
    son[son[root][1]][0]=SplayTree::Build(1,N,son[root][1]);
     
    Q=read();
    while (Q--) {
        char opt[3]; scanf("%s",opt+1);
        int x,y,c,k;
        switch (opt[1]) {
            case 'R' : k=read(); SplayTree::Move(k); break;
            case 'F' : SplayTree::Rever(); break;
            case 'S' : x=read(),y=read(); SplayTree::Swap(x,y); break;
            case 'P' : x=read(),y=read(),c=read(); SplayTree::Cover(x,y,c); break;
            case 'C' : if (opt[2]=='S') x=read(),y=read(),printf("%d\n",SplayTree::Query(x,y)); else printf("%d\n",SplayTree::Query()); break;
        }
    }
    return 0;
}
