#include<bits/stdc++.h> 
#define F(i,j,n) for(int i=j;i<=n;i++)  
#define D(i,j,n) for(int i=j;i>=n;i--)  
#define ll long long  
#define N 500005  
#define inf 1000000000  
using namespace std;  
int n,m,d,cnt;  
int w[N],head[N],f[N][25],g[N][25];  
bool mark[N];  
struct edge{int next,to;}e[N*2];  
inline int read()  
{  
    int x=0,f=1;char ch=getchar();  
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}  
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  
    return x*f;  
}  
inline void add_edge(int x,int y)  
{  
    e[++cnt]=(edge){head[x],y};head[x]=cnt;  
    e[++cnt]=(edge){head[y],x};head[y]=cnt;  
}  
void dp(int x,int fa)  
{  
    if (mark[x]) f[x][0]=g[x][0]=w[x];//这个位置一定要放   
    F(i,1,d) g[x][i]=w[x];//初始状态是假设x位置放守卫，之后会可能被更新   
    g[x][d+1]=inf;//只用x子树中的点不可能向上覆盖d+1层，所以等于inf   
    for(int i=head[x];i;i=e[i].next)  
    {  
        int y=e[i].to;  
        if (y==fa) continue;  
        dp(y,x);  
        D(j,d,0) g[x][j]=min(g[x][j]+f[y][j],g[y][j+1]+f[x][j+1]);//用y的子树中的守卫可能花费更少   
        D(j,d,0) g[x][j]=min(g[x][j],g[x][j+1]);//用g[x][j+1]来更新g[x][j]   
        f[x][0]=g[x][0];//这里相当于既不能向上也不能向下扩展   
        F(j,1,d+1) f[x][j]+=f[y][j-1];//直接加上就可以   
        F(j,1,d+1) f[x][j]=min(f[x][j-1],f[x][j]);//用f[x][j-1]来更新f[x][j]   
    }  
}  
int main()  
{  
    n=read();d=read();  
    F(i,1,n) w[i]=read();  
    m=read();  
    F(i,1,m){int x=read();mark[x]=true;}  
    F(i,1,n-1){int x=read(),y=read();add_edge(x,y);}  
    dp(1,0);  
    printf("%d\n",f[1][0]);  
    return 0;  
}  
