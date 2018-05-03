#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 100005
#define M 325
#define ll long long
using namespace std;

int n,m,a[N],pos[N],sta[M],end[M],sum[N][M],t[N],c[N],block;
ll ans[M][M];
struct data{int val,id;}b[N];

bool cmp(data a,data b)
{
    return a.val<b.val;
}

ll query(int l,int r)
{
    if (pos[l]==pos[r])
    {
        ll tot=0;
        for (int i=l;i<=r;i++)
        {
            t[a[i]]++;
            tot=max(tot,(ll)t[a[i]]*c[a[i]]);
        }
        for (int i=l;i<=r;i++)
            t[a[i]]--;
        return tot;
    }
    ll tot=ans[pos[l]+1][pos[r]-1];
    for (int i=l;i<=end[pos[l]];i++)
    {
        t[a[i]]++;
        tot=max(tot,(ll)(t[a[i]]+sum[a[i]][pos[r]-1]-sum[a[i]][pos[l]])*c[a[i]]);
    }
    for (int i=sta[pos[r]];i<=r;i++)
    {
        t[a[i]]++;
        tot=max(tot,(ll)(t[a[i]]+sum[a[i]][pos[r]-1]-sum[a[i]][pos[l]])*c[a[i]]);
    }
    for (int i=l;i<=end[pos[l]];i++)
        t[a[i]]--;
    for (int i=sta[pos[r]];i<=r;i++)
        t[a[i]]--;
    return tot;
}

int main()
{
    scanf("%d%d",&n,&m);
    block=sqrt(n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        pos[i]=(i+block-1)/block;
        if (!sta[pos[i]]) sta[pos[i]]=i;
        end[pos[i]]=i;
        b[i].id=i;b[i].val=a[i];
    }
    sort(b+1,b+n+1,cmp);
    int rank=0;
    for (int i=1;i<=n;i++)
    {
        if (i==1||b[i].val!=b[i-1].val)
        {
            rank++;
            c[rank]=b[i].val;
        }
        a[b[i].id]=rank;
    }
    for (int i=1;i<=pos[n];i++)
    {
        for (int j=i;j<=pos[n];j++)
        {
            ans[i][j]=ans[i][j-1];
            for (int k=sta[j];k<=end[j];k++)
            {
                t[a[k]]++;
                ans[i][j]=max(ans[i][j],(ll)t[a[k]]*c[a[k]]);
            }
        }
        for (int j=sta[i];j<=n;j++)
            t[a[j]]--;
    }
    for (int i=1;i<=n;i++)
        sum[a[i]][pos[i]]++;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=pos[n];j++)
            sum[i][j]+=sum[i][j-1];
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",query(x,y));
    }
    return 0;
}
