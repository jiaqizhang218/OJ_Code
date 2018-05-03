#include<iostream>  
#include<cstdio>  
#include<algorithm>  
#include<cstring>  
#include<cstdlib>  
#include<cmath>  
#define F(i,j,n) for(int i=j;i<=n;i++)  
#define D(i,j,n) for(int i=j;i>=n;i--)  
#define LL long long  
#define pa pair<int,int>  
#define MAXN 50005  
#define INF 1000000000  
using namespace std;  
int n,m,rt=0,tot=0;  
int a[MAXN],fa[MAXN],t[MAXN][2],mx[MAXN],tag[MAXN],size[MAXN];  
bool rev[MAXN];  
inline int read()  
{  
    int ret=0,flag=1;char ch=getchar();  
    while (ch<'0'||ch>'9'){if (ch=='-') flag=-1;ch=getchar();}  
    while (ch>='0'&&ch<='9'){ret=ret*10+ch-'0';ch=getchar();}  
    return ret*flag;  
}  
inline void pushup(int k)  
{  
    int l=t[k][0],r=t[k][1];  
    mx[k]=max(max(mx[l],mx[r]),a[k]);  
    size[k]=size[l]+size[r]+1;  
}  
inline void pushdown(int k)  
{  
    int l=t[k][0],r=t[k][1],tg=tag[k];  
    if (tg)  
    {  
        tag[k]=0;  
        if (l){tag[l]+=tg;mx[l]+=tg;a[l]+=tg;}  
        if (r){tag[r]+=tg;mx[r]+=tg;a[r]+=tg;}  
    }  
    if (rev[k])  
    {  
        rev[k]=0;  
        rev[l]^=1;rev[r]^=1;  
        swap(t[k][0],t[k][1]);  
    }  
}  
inline void rotate(int &k,int x)  
{  
    int y=fa[x],z=fa[y],l,r;  
    if (t[y][0]==x) l=0;else l=1;r=l^1;  
    if (k==y) k=x;  
    else{if (t[z][0]==y) t[z][0]=x;else t[z][1]=x;}  
    fa[x]=z;  
    fa[y]=x;  
    fa[t[x][r]]=y;  
    t[y][l]=t[x][r];  
    t[x][r]=y;  
    pushup(y);pushup(x);  
}  
inline void splay(int &k,int x)  
{  
    while (x!=k)  
    {  
        int y=fa[x],z=fa[y];  
        if (y!=k)  
        {  
            if ((t[y][0]==x)^(t[z][0]==y)) rotate(k,x);  
            else rotate(k,y);  
        }  
        rotate(k,x);  
    }  
}  
inline int find(int k,int rank)  
{  
    if (tag[k]||rev[k]) pushdown(k);  
    int l=t[k][0],r=t[k][1];  
    if (size[l]+1==rank) return k;  
    else if (size[l]>=rank) return find(l,rank);  
    else return find(r,rank-size[l]-1);  
}  
inline void add(int l,int r,int val)  
{  
    int x=find(rt,l),y=find(rt,r+2);  
    splay(rt,x);  
    splay(t[x][1],y);  
    int z=t[y][0];  
    tag[z]+=val;mx[z]+=val;a[z]+=val;  
}  
inline void reverse(int l,int r)  
{  
    int x=find(rt,l),y=find(rt,r+2);  
    splay(rt,x);splay(t[x][1],y);  
    rev[t[y][0]]^=1;  
}  
inline void query(int l,int r)  
{  
    int x=find(rt,l),y=find(rt,r+2);  
    splay(rt,x);splay(t[x][1],y);  
    printf("%d\n",mx[t[y][0]]);  
}  
inline void build(int l,int r,int last)  
{  
    if (l>r) return;  
    if (l==r)  
    {  
        fa[l]=last;size[l]=1;  
        if (l<last) t[last][0]=l;  
        else t[last][1]=l;  
        return;  
    }  
    int mid=(l+r)>>1;  
    build(l,mid-1,mid);build(mid+1,r,mid);  
    fa[mid]=last;pushup(mid);  
    if (mid<last) t[last][0]=mid;  
    else t[last][1]=mid;  
}  
int main()  
{  
    mx[0]=-INF;  
    n=read();m=read();  
    build(1,n+2,0);  
    rt=(n+3)>>1;  
    F(i,1,m)  
    {  
        int flag=read(),l=read(),r=read(),val;  
        if (flag==1){val=read();add(l,r,val);}  
        else if (flag==2) reverse(l,r);  
        else query(l,r);  
    }  
    return 0;  
} 
