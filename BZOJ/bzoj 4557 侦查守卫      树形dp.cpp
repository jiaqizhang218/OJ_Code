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
    if (mark[x]) f[x][0]=g[x][0]=w[x];//���λ��һ��Ҫ��   
    F(i,1,d) g[x][i]=w[x];//��ʼ״̬�Ǽ���xλ�÷�������֮�����ܱ�����   
    g[x][d+1]=inf;//ֻ��x�����еĵ㲻�������ϸ���d+1�㣬���Ե���inf   
    for(int i=head[x];i;i=e[i].next)  
    {  
        int y=e[i].to;  
        if (y==fa) continue;  
        dp(y,x);  
        D(j,d,0) g[x][j]=min(g[x][j]+f[y][j],g[y][j+1]+f[x][j+1]);//��y�������е��������ܻ��Ѹ���   
        D(j,d,0) g[x][j]=min(g[x][j],g[x][j+1]);//��g[x][j+1]������g[x][j]   
        f[x][0]=g[x][0];//�����൱�ڼȲ�������Ҳ����������չ   
        F(j,1,d+1) f[x][j]+=f[y][j-1];//ֱ�Ӽ��ϾͿ���   
        F(j,1,d+1) f[x][j]=min(f[x][j-1],f[x][j]);//��f[x][j-1]������f[x][j]   
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
