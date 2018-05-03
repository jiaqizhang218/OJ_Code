#include<bits/stdc++.h> 
#define M 100002
#define low(x) (x&(-x))
using namespace std;
int W,n,ans;
int d[M],f[M],Y[M];	
struct os
{
    int x,y,t,p,v;
    bool operator <(const os& other)const
    {
        if (x==other.x) return y>other.y;
        return x<other.x;
    }
}a[M];
int get(int x)
{
    int mx=0;
    for (;x;x-=low(x)) mx=max(mx,d[x]);
    return mx;
}
void add(int x,int data)
{
    for (;x<=n+1;x+=low(x))
        d[x]=max(d[x],data);
}
main()
{
    scanf("%d%d",&W,&n);
    a[0].x=a[0].y=a[0].t=-W;
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[i].t,&a[i].p,&a[i].v);
        a[i].t<<=1;
        a[i].x=a[i].t+a[i].p;
        a[i].y=a[i].t-a[i].p;
    }
    sort(a,a+n+1);
    for (int i=0;i<=n;i++) Y[i]=a[i].y;
    sort(Y,Y+n+1);
    for (int i=0;i<=n;i++) a[i].y=lower_bound(Y,Y+n+1,a[i].y)-Y+1;
    //½«y×ø±êÀëÉ¢»¯
    for (int i=1;i<=n;i++)
    {
        f[i]=a[i].v+get(a[i].y);
        add(a[i].y,f[i]);
    }
    for (int i=1;i<=n;i++) ans=max(ans,f[i]);
    printf("%d",ans);
}
