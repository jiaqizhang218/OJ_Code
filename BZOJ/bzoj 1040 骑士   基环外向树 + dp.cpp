#include<bits/stdc++.h>
#define LL long long  
#define M 1000005  
using namespace std;  
LL f[M][2],a[M];  
int n,v[M],h[M],root,_root,tot=1,cant;  
struct edge  
{  
    int y,ne;  
}e[M*2];  
void Addedge(int x,int y)  
{  
    tot++;  
    e[tot].y=y;  
    e[tot].ne=h[x];  
    h[x]=tot;  
}  
void dfs(int x,int fa)  
{  
    v[x]=1;  
    for (int i=h[x];i;i=e[i].ne)  
    {  
        int y=e[i].y;  
        if (y==fa) continue;  
        if (!v[y]) dfs(y,x);  
        else  
        {  
            cant=i;  
            root=x;  
            _root=y;  
        }  
    }  
}  
LL maxx(LL a,LL b)  
{  
    if (a>b) return a;  
    return b;  
}  
void dp(int x,int fa)  
{  
    f[x][0]=0,f[x][1]=a[x];  
    for (int i=h[x];i;i=e[i].ne)  
    {  
        int y=e[i].y;  
        if (y==fa||i==cant||i==(cant^1)) continue;  
        dp(y,x);  
        f[x][0]+=maxx(f[y][0],f[y][1]);  
        f[x][1]+=f[y][0];  
    }  
}  
int main()  
{  
        scanf("%d",&n);  
    for (int i=1;i<=n;i++)  
    {  
        int x;  
        scanf("%lld%d",&a[i],&x);  
        Addedge(x,i);  
        Addedge(i,x);  
    }  
    LL ans=0;  
    for (int i=1;i<=n;i++)  
        if (!v[i])  
        {  
            dfs(i,-1);  
            dp(root,-1);  
            LL temp=f[root][0];  
            dp(_root,-1);  
            temp=maxx(temp,f[_root][0]);  
            ans+=temp;  
        }  
    cout<<ans<<endl;  
    return 0;  
}  
