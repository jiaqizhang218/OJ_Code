#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 301000
#define ls son[x][0]
#define rs son[x][1]
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3fll
#define check {puts("!!!");exit(0);}
using namespace std;
bool ai[N];
int murders[N],fa[N];
long long hi[N],vi[N];
int ans[N],n,m;
struct Merge_Heap
{
    int son[N][2],root[N],id[N],cnt;

    long long val[N],ad[N],mu[N];
    int level[N],exper[N];

    void pushdown(int x)
    {
        if(mu[x]!=1)
        {
            val[x]*=mu[x];
            mu[ls]*=mu[x],mu[rs]*=mu[x];
            ad[ls]*=mu[x],ad[rs]*=mu[x];
            mu[x]=1;
        }
        if(ad[x])
        {
            val[x]+=ad[x];
            ad[ls]+=ad[x],ad[rs]+=ad[x];
            ad[x]=0;
        }
        if(exper[x])
        {
            level[x]+=exper[x];
            exper[ls]+=exper[x],exper[rs]+=exper[x];
            exper[x]=0;
        }
    }
    int merge(int x,int y)
    {
        if(!y)return x;
        if(!x)return y;
        pushdown(x),pushdown(y);
        if(val[x]>val[y])swap(x,y);
        int d=rand()&1;
        son[x][d]=merge(son[x][d],y);
        return x;
    }
    int newnode(long long _val,int _id)
    {
        val[++cnt]=_val;
        id[cnt]=_id;
        mu[cnt]=1;
        return cnt;
    }
    void add(int p,long long val,int id)
    {root[p]=merge(root[p],newnode(val,id));}
    void kill(int p)
    {
        for(int x=root[p];x;x=root[p])
        {
            pushdown(x);
            if(val[x]>=hi[p])return ;
            ans[id[x]]=level[x];
            murders[p]++;
            root[p]=merge(ls,rs);
        }
    }
    void hold(int p)
    {
        pushdown(root[p]);
        if(ai[p])mu[root[p]]=vi[p];
        else ad[root[p]]=vi[p];
        exper[root[p]]++;
        root[fa[p]]=merge(root[fa[p]],root[p]);
    }
}mh;
int d[N],stk[N],top;
int main()
{
    int i,j,k;
    int a,b,c;
    long long t;

    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%lld",&hi[i]);
    for(i=2;i<=n;i++)scanf("%d%d%lld",&fa[i],&ai[i],&vi[i]),d[fa[i]]++;
    for(i=1;i<=m;i++)
    {
        scanf("%lld%d",&t,&a);
        mh.add(a,t,i);
    }
    d[0]=1,hi[0]=INF;
    for(i=1;i<=n;i++)if(!d[i])stk[++top]=i;
    while(top)
    {
        k=stk[top--];
        mh.kill(k);
        if(k)
        {
            mh.hold(k);
            d[fa[k]]--;
            if(!d[fa[k]])stk[++top]=fa[k];
        }
    }
    for(i=1;i<=n;i++)printf("%d\n",murders[i]);
    for(i=1;i<m;i++)printf("%d\n",ans[i]);printf("%d",ans[m]);
    return 0;
}
