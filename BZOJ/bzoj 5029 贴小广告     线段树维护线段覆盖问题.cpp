#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#define mod 20101009
#define ll long long 
#define N 10000005 
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int tot,n,ans,t[400005],b[100005][2];
struct node{int x,l,r,id;}a[200005];
bool vis[100005];
bool cmp(node a,node b){return a.x<b.x;}
void pushdown(int k,int l,int r)
{
    int c=t[k];t[k]=0;
    if (l==r) return;
    t[k<<1]=t[k<<1|1]=c;
}
void modify(int k,int l,int r,int x,int y,int z)
{
    if (l==x&&r==y){t[k]=z;return;}
    if (t[k]) pushdown(k,l,r);
    int mid=(l+r)>>1;
    if (y<=mid) modify(k<<1,l,mid,x,y,z);
    else if (x>mid) modify(k<<1|1,mid+1,r,x,y,z);
    else modify(k<<1,l,mid,x,mid,z),modify(k<<1|1,mid+1,r,mid+1,y,z);
}
void find(int k,int l,int r)
{
    if (t[k])
    {
        if (!vis[t[k]]) ans++;
        vis[t[k]]=1;
        return;
    }
    if (l==r) return;
    int mid=(l+r)>>1;
    find(k<<1,l,mid);find(k<<1|1,mid+1,r);
}
int main()
{
    n=read();
    for (int i=1;i<=n;i++)
    {
        a[(i<<1)-1].x=read();a[i<<1].x=read();
        a[(i<<1)-1].l=1;a[i<<1].r=1;
        a[(i<<1)-1].id=i;a[i<<1].id=i;
    }
    sort(a+1,a+(n<<1)+1,cmp);
    for (int i=1;i<=n<<1;i++)
    {
        int tmp=(a[i].r==1);
        if (a[i].x!=a[i-1].x) tot++;
        b[a[i].id][tmp]=tot;
    }
    for (int i=1;i<=n;i++) modify(1,1,tot,b[i][0],b[i][1],i);
    find(1,1,tot);
    printf("%d",ans);
    return 0;
}
