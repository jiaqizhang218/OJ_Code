#include<bits/stdc++.h>
#define N 100100
#define M 1000100
using namespace std;
struct node
{
    int x,y;
    friend bool operator < (node a,node b)
    {
        if(a.x==b.x)return a.y<b.y;
        return a.x<b.x;
    }
}b[N];
int d[M],a[N];
int n,ma,tot;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(i-a[i]<0)continue;
        b[++tot].x=i-a[i],b[tot].y=a[i];
    }
    sort(b+1,b+tot+1);
    memset(d,0x3f,sizeof(d)); 
    for(int i=1;i<=tot;i++)
    {
        int l=1,r=ma,ans=0;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(b[i].y>d[mid])ans=mid,l=mid+1;
            else r=mid-1;
        }
        ma=max(ma,ans+1);
        d[ans+1]=min(d[ans+1],b[i].y);
    }
    printf("%d\n",ma);
}
