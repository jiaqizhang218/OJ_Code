#include<iostream>
#include<cstdio>
#include<cstring>
#define M 10000005
using namespace std;
// 简而言之就是每个信仰建一棵树 因为数据小 水过 
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int n,m,cnt,place,size;
int s[17];
int w[100005],c[100005],root[100005];
int fa[100005][17],deep[100005],pl[100005],belong[100005],son[100005];
int ls[M],rs[M],mx[M],sum[M];
bool vis[100005];
struct data{int to,next;}e[200005];int head[100005];
void ins(int u,int v)
{
    e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;
    e[++cnt].to=u;e[cnt].next=head[v];head[v]=cnt;
}

//==========================================================
void dfs1(int x)
{
    vis[x]=1;son[x]=1;
    for(int i=1;i<=16;i++)
        if(s[i]<=deep[x])fa[x][i]=fa[fa[x][i-1]][i-1];
        else break;
    for(int i=head[x];i;i=e[i].next)
    {
        if(vis[e[i].to])continue;
        deep[e[i].to]=deep[x]+1;
        fa[e[i].to][0]=x;
        dfs1(e[i].to);
        son[x]+=son[e[i].to];
    }
}
void dfs2(int x,int chain)
{
    place++;pl[x]=place;belong[x]=chain;
    int k=0;
    for(int i=head[x];i;i=e[i].next)
        if(deep[e[i].to]>deep[x]&&son[e[i].to]>son[k])
            k=e[i].to;
    if(k)dfs2(k,chain);
    for(int i=head[x];i;i=e[i].next)
        if(deep[e[i].to]>deep[x]&&e[i].to!=k)
            dfs2(e[i].to,e[i].to); 
}
int lca(int x,int y)
{
    if(deep[x]<deep[y])swap(x,y);
    int t=deep[x]-deep[y];
    for(int i=0;i<=16;i++)
        if(s[i]&t)x=fa[x][i];
    for(int i=16;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    if(x==y)return x;
    return fa[x][0];
}
//===========================================================预处理 
void update(int x)
{
    mx[x]=max(mx[ls[x]],mx[rs[x]]);
    sum[x]=sum[ls[x]]+sum[rs[x]]; 
}
void change(int &k,int l,int r,int x,int num)
{
    if(!k)k=++size;
    if(l==r){mx[k]=sum[k]=num;return;}
    int mid=(l+r)>>1;
    if(x<=mid)change(ls[k],l,mid,x,num);
    else change(rs[k],mid+1,r,x,num);
    update(k);
}
int askmx(int k,int l,int r,int x,int y)
{
    if(!k)return 0;
    if(l==x&&y==r)return mx[k];
    int mid=(l+r)>>1;
    if(y<=mid)return askmx(ls[k],l,mid,x,y);
    else if(x>mid)return askmx(rs[k],mid+1,r,x,y);
    else return max(askmx(ls[k],l,mid,x,mid),askmx(rs[k],mid+1,r,mid+1,y));
}
int asksum(int k,int l,int r,int x,int y)
{
    if(!k)return 0;
    if(l==x&&y==r)return sum[k];
    int mid=(l+r)>>1;
    if(y<=mid)return asksum(ls[k],l,mid,x,y);
    else if(x>mid)return asksum(rs[k],mid+1,r,x,y);
    else return asksum(ls[k],l,mid,x,mid)+asksum(rs[k],mid+1,r,mid+1,y);
}
//===========================================================线段树
int solvemx(int c,int x,int f)
{
    int mx=0;
    while(belong[x]!=belong[f])
    {
        mx=max(mx,askmx(root[c],1,n,pl[belong[x]],pl[x]));
        x=fa[belong[x]][0];
    }
    mx=max(mx,askmx(root[c],1,n,pl[f],pl[x]));
    return mx;
}
int solvesum(int c,int x,int f)
{
    int sum=0;
    while(belong[x]!=belong[f])
    {
        sum+=asksum(root[c],1,n,pl[belong[x]],pl[x]);
        x=fa[belong[x]][0];
    }
    sum+=asksum(root[c],1,n,pl[f],pl[x]);
    return sum;
}
//===========================================================树链剖分 
int main()
{
    s[0]=1;for(int i=1;i<=16;i++)s[i]=(s[i-1]<<1);
    n=read();m=read();
    for(int i=1;i<=n;i++)
        w[i]=read(),c[i]=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        ins(u,v);
    }
    dfs1(1);dfs2(1,1);
    for(int i=1;i<=n;i++)
        change(root[c[i]],1,n,pl[i],w[i]);
    for(int i=1;i<=m;i++)
    {
        char ch[5];scanf("%s",ch);
        int x=read(),y=read();
        if(ch[0]=='C')
        {
            if(ch[1]=='C')
            {
                change(root[c[x]],1,n,pl[x],0);
                c[x]=y;
                change(root[c[x]],1,n,pl[x],w[x]);
            }
            else {change(root[c[x]],1,n,pl[x],y);w[x]=y;}
        }
        else
        {
            int f=lca(x,y);
            if(ch[1]=='S')
            {
                int t=solvesum(c[x],x,f)+solvesum(c[x],y,f);
                if(c[x]==c[f])t-=w[f];
                printf("%d\n",t);
            }
            else
                printf("%d\n",max(solvemx(c[x],x,f),solvemx(c[x],y,f)));
        }
    }
    return 0;
}
