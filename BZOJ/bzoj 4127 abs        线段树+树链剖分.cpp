#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>
#define lson x<<1
#define rson x<<1|1
#define mp(A,B) make_pair(A,B)
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
const int maxn=100010;
const ll inf=1ll<<60;
int n,m,cnt;
int Siz[maxn],p[maxn],q[maxn],siz[maxn<<2],v[maxn],son[maxn],top[maxn];
int to[maxn<<1],next[maxn<<1],head[maxn],fa[maxn],dep[maxn],sp[maxn<<2];
ll s[maxn<<2],ts[maxn<<2],sm[maxn<<2];
inline int rd()
{
    int ret=0,f=1;  char gc=getchar();
    while(gc<'0'||gc>'9') {if(gc=='-')f=-f;   gc=getchar();}
    while(gc>='0'&&gc<='9')   ret=ret*10+gc-'0',gc=getchar();
    return ret*f;
}
void add(int a,int b)
{
    to[cnt]=b,next[cnt]=head[a],head[a]=cnt++;
}
void dfs1(int x)
{
    Siz[x]=1;
    for(int i=head[x];i!=-1;i=next[i])
    {
        if(to[i]!=fa[x])
        {
            fa[to[i]]=x,dep[to[i]]=dep[x]+1,dfs1(to[i]),Siz[x]+=Siz[to[i]];
            if(Siz[to[i]]>Siz[son[x]])   son[x]=to[i];
        }
    }
}
void dfs2(int x,int tp)
{
    top[x]=tp,p[x]=++p[0],q[p[0]]=x;
    if(son[x])  dfs2(son[x],tp);
    for(int i=head[x];i!=-1;i=next[i])  if(to[i]!=son[x]&&to[i]!=fa[x]) dfs2(to[i],to[i]);
}
void pushdown(int x)
{
    if(ts[x])
    {
        s[lson]+=ts[x]*siz[lson],s[rson]+=ts[x]*siz[rson],ts[lson]+=ts[x],ts[rson]+=ts[x];
        sm[lson]+=ts[x],sm[rson]+=ts[x],ts[x]=0;
    }
}
void pushup(int x)
{
    s[x]=s[lson]+s[rson],siz[x]=siz[lson]+siz[rson];
    if(sm[lson]>sm[rson])    sm[x]=sm[lson],sp[x]=sp[lson];
    else    sm[x]=sm[rson],sp[x]=sp[rson];
}
void build(int l,int r,int x)
{
    if(l==r)
    {
        sp[x]=l;
        if(v[q[l]]<0)    s[x]=-v[q[l]],sm[x]=v[q[l]],siz[x]=-1;
        else    s[x]=v[q[l]],sm[x]=-inf,siz[x]=1;
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,lson),build(mid+1,r,rson);
    pushup(x);
}
void updata(int l,int r,int x,int a,int b,ll c)
{
    if(a<=l&&r<=b)
    {
        s[x]+=siz[x]*c,sm[x]+=c,ts[x]+=c;
        return ;
    }
    pushdown(x);
    int mid=(l+r)>>1;
    if(a<=mid)   updata(l,mid,lson,a,b,c);
    if(b>mid)    updata(mid+1,r,rson,a,b,c);
    pushup(x);
}
pli getmax(int l,int r,int x,int a,int b)
{
    if(a<=l&&r<=b)    return mp(sm[x],sp[x]);
    pushdown(x);
    int mid=(l+r)>>1;
    if(b<=mid)   return getmax(l,mid,lson,a,b);
    if(a>mid)    return getmax(mid+1,r,rson,a,b);
    return max(getmax(l,mid,lson,a,b),getmax(mid+1,r,rson,a,b));
}
ll query(int l,int r,int x,int a,int b)
{
    if(a<=l&&r<=b)    return s[x];
    pushdown(x);
    int mid=(l+r)>>1;
    if(b<=mid)   return query(l,mid,lson,a,b);
    if(a>mid)    return query(mid+1,r,rson,a,b);
    return  query(l,mid,lson,a,b)+query(mid+1,r,rson,a,b);
}
void modify(int l,int r,int x,int a)
{
    if(l==r)
    {
        s[x]=-s[x],sm[x]=-inf,siz[x]=1;
        return ;
    }
    pushdown(x);
    int mid=(l+r)>>1;
    if(a<=mid)   modify(l,mid,lson,a);
    else    modify(mid+1,r,rson,a);
    pushup(x);
}
void deal(int x,int y,ll z)
{
    while(1)
    {
        pli tmp=getmax(1,n,1,x,y);
        if(tmp.first<-z) break;
        modify(1,n,1,tmp.second);
    }
    updata(1,n,1,x,y,z);
}
void change(int x,int y,ll z)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])  swap(x,y);
        deal(p[top[x]],p[x],z),x=fa[top[x]];
    }
    if(dep[x]>dep[y])    swap(x,y);
    deal(p[x],p[y],z);
}
void ask(int x,int y)
{
    ll ret=0;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])  swap(x,y);
        ret+=query(1,n,1,p[top[x]],p[x]),x=fa[top[x]];
    }
    if(dep[x]>dep[y])    swap(x,y);
    ret+=query(1,n,1,p[x],p[y]);
    printf("%lld\n",ret);
}
int main()
{
    memset(head,-1,sizeof(head));
    n=rd(),m=rd();
    int i,a,b,c;
    for(i=1;i<=n;i++)    v[i]=rd();
    for(i=1;i<n;i++) a=rd(),b=rd(),add(a,b),add(b,a);
    dep[1]=1,dfs1(1),dfs2(1,1);
    build(1,n,1);
    for(i=1;i<=m;i++)
    {
        if(rd()==1)
        {
            a=rd(),b=rd(),c=rd();
            change(a,b,c);
        }
        else
        {
            a=rd(),b=rd();
            ask(a,b);
        }
    }
    return 0;
}
