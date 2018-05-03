#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,q,m,block;
int a[1000001],b[1000001],pos[1000001],add[1000001];
void reset(int x)
{
    int l=(x-1)*block+1,r=min(x*block,n);
    for(int i=l;i<=r;i++)
        b[i]=a[i];
    sort(b+l,b+r+1);
}
int find(int x,int v)
{
    int l=(x-1)*block+1,r=min(x*block,n);
    int last=r;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(b[mid]<v)l=mid+1;
        else r=mid-1;
    }
    return last-l+1;
}
void update(int x,int y,int v)
{
    if(pos[x]==pos[y])
    {
        for(int i=x;i<=y;i++)a[i]=a[i]+v;
    }
    else 
    {
        for(int i=x;i<=pos[x]*block;i++)a[i]=a[i]+v;
        for(int i=(pos[y]-1)*block+1;i<=y;i++)a[i]=a[i]+v;
    }
    reset(pos[x]);reset(pos[y]);
    for(int i=pos[x]+1;i<pos[y];i++)
       add[i]+=v;
}
int query(int x,int y,int v)
{
    int sum=0;
    if(pos[x]==pos[y])
    {
        for(int i=x;i<=y;i++)if(a[i]+add[pos[i]]>=v)sum++;
    }
    else 
    {
        for(int i=x;i<=pos[x]*block;i++)
            if(a[i]+add[pos[i]]>=v)sum++;
        for(int i=(pos[y]-1)*block+1;i<=y;i++)
            if(a[i]+add[pos[i]]>=v)sum++;
    }
    for(int i=pos[x]+1;i<pos[y];i++)
        sum+=find(i,v-add[i]);
    return sum;
}
int main()
{
    scanf("%d%d",&n,&q);
    block=int(sqrt(n));
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        pos[i]=(i-1)/block+1;
        b[i]=a[i];
    }
    if(n%block)m=n/block+1;
    else m=n/block;
    for(int i=1;i<=m;i++)reset(i);
    for(int i=1;i<=q;i++)
    {
        char ch[5];int x,y,v;
        scanf("%s%d%d%d",ch,&x,&y,&v);
        if(ch[0]=='M')update(x,y,v);
        else printf("%d\n",query(x,y,v));
    }
    return 0;
}
