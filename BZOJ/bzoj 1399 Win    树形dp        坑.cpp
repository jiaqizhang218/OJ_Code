#include<bits/stdc++.h>
using namespace std;  
  
int n,m,fi[16],w[200],ne[200],cnt,f[16][1<<16][6],num[1<<16],deep,now;  
  
inline int read()  
{  
    int x=0,f=1;char ch=getchar();  
    while(ch<'0' || ch>'9') {if(ch=='-') f=-1;ch=getchar();}  
    while(ch>='0' && ch<='9') {x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}  
    return x*f;   
}  
  
inline void add(int u,int v)  
{  
    w[++cnt]=v;ne[cnt]=fi[u];fi[u]=cnt;  
}  
//f[i][j][k]表示i点为根，点的状态为j，深度为k的状态，然后，f[i][j][k]=f[i][j-j'][k-1]*f[w[u]][j'][k-1]
inline int dfs(int u,int v,int dep)  
{  
    if(f[u][v][dep]!=-1) return f[u][v][dep];  
    if((1<<dep)<num[v]) return f[u][v][dep]=0;  
    if((1<<u)==v) return f[u][v][dep]=1;  
    if(!dep) return f[u][v][dep]=0;  
    f[u][v][dep]=0;  
    for(int i=v&(v-1);i;i=(i-1)&v)  
    {  
        if((1<<u)&i) continue;  
        for(int j=fi[u];j;j=ne[j])  
          if((1<<w[j])&i) f[u][v][dep]+=dfs(u,v-i,dep-1)*dfs(w[j],i,dep-1);  
    }  
    return f[u][v][dep];  
}  
  
int main()  
{  
    for(int i=1;i<65536;i++) num[i]=num[i>>1]+(i&1);  
    while(scanf("%d",&n)!=EOF)  
    {  
        memset(f,-1,sizeof(f));  
        memset(fi,0,sizeof(fi));cnt=0;  
        m=read()-1;deep=0;now=1;  
        while(now<n) now<<=1,deep++;  
        for(int i=0;i<n;i++)  
          for(int j=0;j<n;j++) if(read()) add(i,j);  
        printf("%d\n",dfs(m,(1<<n)-1,deep));  
    }  
    return 0;  
}  
