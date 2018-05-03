#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<algorithm>  
#include<iostream>  
using namespace std;  
const int N=100008;  
struct node{  
    int y,next;  
}sa[400010];int first[N],len=0;  
int n,m;  
void ins(int x,int y)  
{    
    sa[++len].y=y;  
    sa[len].next=first[x];  
    first[x]=len;  
}  
int dfn[N],low[N],dep[N],fa[N],cnt=0,f[N],g[N];
//f[i]表示选i,g[i]表示不选i  
void dp(int root,int x)  
{  
    int u1=0,u0=0,v1,v0;//u1表示可以取，u0不可以取，v1取了后的值，v0没取的值  
    for(int i=x;i!=root;i=fa[i])  
    {  
        v1=u1+f[i];    v0=u0+g[i];  
        u1=v0;   u0=max(v1,v0);  
     }   
     //因为x取了，所以root不能取   
     g[root]+=u0;  
     u1=-99999999,u0=0;  
    for(int i=x;i!=root;i=fa[i])  
    {  
        v1=u1+f[i];   v0=u0+g[i];  
        u1=v0;u0=max(v1,v0);  
     }   
     //因为u1太小，所以x没有取   
     f[root]+=u1;  
}int val[N];  
void dfs(int x)  
{  
    dfn[x]=low[x]=++cnt;  
    for(int i=first[x];i!=-1;i=sa[i].next)  
    {  
        int y=sa[i].y;  
        if(y!=fa[x])  
        {  
            if(!dfn[y])  
            {  
                dep[y]=dep[x]+1;  
                fa[y]=x;  
                dfs(y);  
                low[x]=min(low[x],low[y]);  
            }  
            else low[x]=min(low[x],dfn[y]);  
        }  
    }  
    f[x]=val[x];  
    for(int i=first[x];i!=-1;i=sa[i].next)  
    {  
        int y=sa[i].y;  
        if(fa[y]!=x&&dfn[x]<dfn[y])  
        	dp(x,y);  
    }  
}  
  
int main()  
{  
    memset(first,-1,sizeof(first));  
    scanf("%d%d",&n,&m);  
    for(int i=1;i<=m;i++)  
    {  
        int a,b;  
        scanf("%d%d",&a,&b);  
        ins(a,b);ins(b,a);  
    }  
    for(int i=1;i<=n;i++)  
    	scanf("%d",&val[i]);  
    dfs(1);  
    printf("%d",max(f[1],g[1]));   
 }
