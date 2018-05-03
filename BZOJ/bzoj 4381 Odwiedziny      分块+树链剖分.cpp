#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int N = 50010;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}  
int a[N],to[N<<1],nxt[N<<1],pre[N],cnt;  
void ae(int ff,int tt)  
{    
    to[++cnt]=tt;  nxt[cnt]=pre[ff];  pre[ff]=cnt;  
    to[++cnt]=ff;  nxt[cnt]=pre[tt];  pre[tt]=cnt;
}  
int fa[N][120],d[N],siz[N],zs[N];  
void build(int x)  
{  
    int maxn=0,maxb=0;  
    int i,j;  
    siz[x]=1;d[x]=d[fa[x][1]]+1;  
    for(i=pre[x];i;i=nxt[i])  
    {  
        j=to[i];  
        if(j==fa[x][1]) continue;  
        fa[j][1]=x;  
        build(j);  
        siz[x]+=siz[j];  
        if(siz[j]>maxn)  
        {  
            maxn=siz[j];  
            maxb=j;  
        }  
    }  
    zs[x]=maxb;  
}  
int jut[N][120],top[N],sit[N],fan[N],cn;  
int n,m;  
void dfs(int x,int tt)  
{  
    cn++;sit[x]=cn;fan[cn]=x;  
    top[x]=tt;  
    int i,j;  
    for(i=1;i<=m;i++)  
    jut[x][i]=jut[fa[x][i]][i]+a[x];  
    if(zs[x]) dfs(zs[x],tt);  
    for(i=pre[x];i;i=nxt[i])  
    {  
        j=to[i];  
        if(j==fa[x][1]||j==zs[x]) continue;  
        dfs(j,j);  
    }  
}  
int LCA(int x,int y)  
{  
    while(top[x]!=top[y])  
    {  
        if(d[top[x]]<d[top[y]]) swap(x,y);  
        x=fa[top[x]][1];  
    }  
    if(d[x]<d[y]) swap(x,y);  
    return y;  
}  
int jump(int x,int k)  
{  
    int y=top[x];  
    while(k>=d[x]-d[y]+1&&x)  
    {  
        k-=d[x]-d[y]+1;  
        x=fa[y][1];y=top[x];  
    }  
    if(!x) return 0;  
    return fan[sit[x]-k];  
}  
int solve1(int x,int y,int k)  
{  
    int z=LCA(x,y),L=d[x]+d[y]-2*d[z],ret=0;  
    if(L%k!=0)  
    {  
        ret+=a[y];  
        y=jump(y,L%k);  
    }  
    L=d[x]-d[z];  
    int t;  
    if(L%k==0)  
    {  
        t=jump(z,k);  
        ret+=jut[x][k]+jut[y][k]-jut[z][k]-jut[t][k];  
    }  
    else  
    {  
        t=jump(z,k-L%k);  
        ret+=jut[x][k]-jut[t][k];  
        L=d[y]-d[z];  
        t=jump(z,k-L%k);  
        ret+=jut[y][k]-jut[t][k];  
    }  
    return ret;  
}  
int cal(int x,int k)  
{  
    int ret=0,y;  
    while(x)  
    {  
        ret+=a[x];  
        y=top[x];  
        if(d[x]-d[y]>=k) x=fan[sit[x]-k];  
        else x=jump(x,k);  
    }  
    return ret;  
}  
int solve2(int x,int y,int k)  
{  
    int z=LCA(x,y),L=d[x]+d[y]-2*d[z],ret=0;  
    if(L%k!=0)  
    {  
        ret+=a[y];  
        y=jump(y,L%k);  
    }  
    L=d[x]-d[z];  
    int t;  
    if(L%k==0)  
    {  
        t=jump(z,k);  
        ret+=cal(x,k)+cal(y,k)-cal(z,k)-cal(t,k);  
    }  
    else  
    {  
        t=jump(z,k-L%k);  
        ret+=cal(x,k)-cal(t,k);  
        L=d[y]-d[z];  
        t=jump(z,k-L%k);  
        ret+=cal(y,k)-cal(t,k);  
    }  
    return ret;  
}  
int b[N],c[N];  
int main()  
{  
    n = read();
    m=sqrt(n)/2;  
    int i,j,x,y;  
    for(i=1;i<=n;i++)	a[i] = read();
    for(i=1;i<n;i++)  ae(read(),read());
    build(1);  
    for(i=1;i<=n;i++)  
    for(j=2;j<=m;j++)  
    fa[i][j]=fa[fa[i][j-1]][1];  
    dfs(1,1);  
    for(i=1;i<=n;i++)  b[i] = read();
    for(i=1;i<n;i++)  
    {  
        x = read();
        if(x<=m) printf("%d\n",solve1(b[i],b[i+1],x));  
        else printf("%d\n",solve2(b[i],b[i+1],x));  
    }  
}

