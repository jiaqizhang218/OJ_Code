#include<iostream>  
#include<cstdio>  
#include<cstring>  
#define N 1000010  
using namespace std;  
int point[N],next[N<<1],f[N],id[N],v[N],deep[N],x,y,n,cnt,m,ans[N],be[N],p[N],fa[N],sum[N],kind;  
struct use{int st,en,p;}e[N<<1];  
void add(int x,int y,int p){  
  next[++cnt]=point[x];point[x]=cnt;  
  e[cnt].en=y;e[cnt].p=p;  
}  
int find(int x){if (f[x]==x) return f[x];else return f[x]=find(f[x]);}  
void dfs(int x){  
  for (int i=point[x];i;i=next[i])  
    if (e[i].en!=fa[x]){  
      id[e[i].en]=e[i].p;fa[e[i].en]=x;  
      deep[e[i].en]=deep[x]+1;  
      dfs(e[i].en);  
    }  
}   
void up(int x,int y,int k){  
    x=find(x);y=find(y);  
    while (x!=y){  
        if (deep[x]<deep[y]) swap(x,y);  
        if (be[x]!=m+1) x=f[x];  
        else be[x]=k,f[x]=f[fa[x]],x=f[x];  
    }  
}  
int main(){  
  scanf("%d%d",&n,&m);int now=n;  
  for (int i=1;i<=n-1;i++){  
    scanf("%d%d",&x,&y);  
    add(x,y,i);add(y,x,i);   
  }   
  for (int i=1;i<=n;i++) f[i]=i,be[i]=m+1;  
  dfs(1);memset(p,-1,sizeof(p));  
  for (int i=1;i<=m;i++){  
    scanf("%d",&kind);  
    if (kind==2){scanf("%d%d",&x,&y);up(x,y,i);}  
    else {scanf("%d",&x);p[i]=x;}  
  }  
  for (int i=1;i<=n;i++) sum[be[i]]++;  
  for (int i=2;i<=m+1;i++) sum[i]+=sum[i-1];   
  for (int i=1;i<=n;i++) v[sum[be[i]]--]=i;  
  for (int i=1;i<=n;i++) f[i]=i;  
  //for (int i=1;i<=n;i++) cout<<id[i]<<endl;  
  for (int i=m+1;i>=1;i--){  
    if (p[i]!=-1) p[i]=id[find(p[i])];  
    else  
      for (;be[x=v[now]]==i&&now;now--) f[x]=f[fa[x]];    
  }  
  for (int i=1;i<=m;i++) if (p[i]!=-1) printf("%d\n",p[i]);  
}   

