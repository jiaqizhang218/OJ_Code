#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define pc (B=(B*A)%P)
using namespace std;
const int maxn=50010;
typedef long long ll;
ll A,P,B;
int n,nm,ans;
int x[maxn],y[maxn],z[maxn],p[maxn],q[maxn],tr[maxn],f[maxn];
struct NUM
{
    int v,org;
}num[maxn];
bool cmp(NUM a,NUM b)
{
    return a.v<b.v;
}
bool cmpx(int a,int b)
{
    if(x[a]==x[b]&&y[a]==y[b])  return z[a]<z[b];
    if(x[a]==x[b])  return y[a]<y[b];
    return x[a]<x[b];
}
bool cmpy(int a,int b)
{
    if(x[a]==x[b]&&y[a]==y[b])  return z[a]<z[b];
    if(y[a]==y[b])  return x[a]<x[b];
    return y[a]<y[b];
}
void updata(int a,int v)
{
    for(int i=a;i<=nm;i+=i&-i)   tr[i]=max(tr[i],v);
}
void clr(int a)
{
    for(int i=a;i<=nm;i+=i&-i)   tr[i]=0;
}
int query(int a)
{
    if(!a)  return 0;
    int i,ret=0;
    for(i=a;i;i-=i&-i)  ret=max(ret,tr[i]);
    return ret;
}
void dfs(int l,int r)
{
    if(l==r)    return ;
    int mid=l+r>>1,h1=l,h2=mid+1,i;
    dfs(l,mid);
    sort(p+l,p+mid+1,cmpy);
    sort(p+mid+1,p+r+1,cmpy);
    for(i=l;i<=r;i++)
    {
        if(h1<=mid&&(h2>r||(y[p[h1]]<y[p[h2]]&&x[p[h1]]<x[p[h2]]))) updata(z[p[h1]],f[p[h1]]),h1++;
        else    f[p[h2]]=max(f[p[h2]],query(z[p[h2]]-1)+1),h2++;
    }
    for(i=l;i<=mid;i++)  clr(z[p[i]]);
    sort(p+l+1,p+r+1,cmpx);
    dfs(mid+1,r);
}
int main()
{
    scanf("%lld%lld%d",&A,&P,&n);
    B=1;
    int i;
    for(i=1;i<=n;i++)
    {
        x[i]=pc,y[i]=pc,z[i]=pc;
        if(x[i]<y[i])    swap(x[i],y[i]);
        if(x[i]<z[i])    swap(x[i],z[i]);
        if(y[i]<z[i])    swap(y[i],z[i]);
        num[i].v=z[i],num[i].org=p[i]=i,f[i]=1;
    }
    sort(num+1,num+n+1,cmp);
    for(num[0].v=-1,i=1;i<=n;i++)
    {
        if(num[i].v>num[i-1].v)  nm++;
        z[num[i].org]=nm;
    }
    sort(p+1,p+n+1,cmpx);
    dfs(1,n);
    for(i=1;i<=n;i++)    ans=max(ans,f[i]);
    printf("%d",ans);
    return 0;
}
