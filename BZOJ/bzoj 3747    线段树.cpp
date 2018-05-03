#include<bits/stdc++.h>
#define ll long long
#define mod 999911659 //2 3 4679 35617
#define N 5000051
using namespace std;
int sc()
{
    int i=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')i=i*10+c-'0',c=getchar();
    return i*f;
}
long long mx[N],tag[N],ans;
int p[N/5],nxt[N/5],n,m,w[N/5],f[N/5];
void push_down(int x)
{
    if(tag[x])
    {
        int l=x<<1,r=x<<1|1;
        tag[l]+=tag[x];
        tag[r]+=tag[x];
        mx[l]+=tag[x];
        mx[r]+=tag[x];
        tag[x]=0;
    }

}
inline void change(int x,int L,int R,int l,int r,int v)
{
    if(l==L&&R==r)
    {
        mx[x]+=v;
        tag[x]+=v;
        return;
    }
    push_down(x);
    int mid=L+R>>1;
    if(r<=mid)change(x<<1,L,mid,l,r,v);
    else if(l>mid)change(x<<1|1,mid+1,R,l,r,v);
    else change(x<<1,L,mid,l,mid,v),change(x<<1|1,mid+1,R,mid+1,r,v);
    mx[x]=max(mx[x<<1],mx[x<<1|1]);
}
int main()
{
    n=sc();m=sc();
    for(int i=1;i<=n;i++)f[i]=sc();
    for(int i=1;i<=m;i++)w[i]=sc();
    for(int i=n;i>=1;i--)nxt[i]=p[f[i]],p[f[i]]=i;
    for(int i=1;i<=m;i++)
    {
        if(!p[i])continue;
        int y=nxt[p[i]]?nxt[p[i]]:n+1;
        change(1,1,n+1,p[i],y-1,w[i]);
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,mx[1]);
        int y=nxt[i]?nxt[i]:n+1;
        change(1,1,n+1,i,y-1,-w[f[i]]);
        if(y!=n+1)
        {
            int t=nxt[y]?nxt[y]:n+1;
            change(1,1,n+1,y,t-1,w[f[i]]);
        }
    }
    cout<<ans;
}
