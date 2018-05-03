#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#define N 100010
#define M 320

using namespace std;

typedef unsigned long long ll;

int n,m,cnt,rt,block,blockm,g,op,u,v;
int t[M],G[N],L[N],R[N],b[N];
int f[N][M];
ll bit[N<<1],sum[M],A[N];
ll Ans;
struct edge{
  int t,nx;
}E[N<<2];

inline char nc(){
  static char buf[100000],*p1=buf,*p2=buf;
  if(p1==p2){
    p2=(p1=buf)+fread(buf,1,100000,stdin);
    if(p1==p2)return EOF;
  }
  return *p1++;
}

inline void reaD(ll &x){
  char c=nc(); x=0;
  for(;c>57||c<48;c=nc());for(;c>=48&&c<=57;x=x*10+c-48,c=nc());
}

inline void reaD(int &x){
  char c=nc(); x=0;
  for(;c>57||c<48;c=nc());for(;c>=48&&c<=57;x=x*10+c-48,c=nc());
}

inline void Insert(int x,int y){
  E[++cnt].t=y; E[cnt].nx=G[x]; G[x]=cnt;
  E[++cnt].t=x; E[cnt].nx=G[y]; G[y]=cnt;
}

inline void add(int x,int w){
  for(;x;x-=x&-x) bit[x]+=w;
}

inline ll query(int x){
  ll r=0;
  for(;x<=g;x+=x&-x) r+=bit[x];
  return r;
}

void dfs(int x,int p){
  t[b[x]]++;
  for(int i=1;i<=blockm;i++) f[x][i]=t[i];
  L[x]=++g; add(L[x],A[x]);
  for(int i=G[x];i;i=E[i].nx)
    if(E[i].t!=p) dfs(E[i].t,x);
  R[x]=++g; t[b[x]]--;
}

int w[30],wt;

inline void PutAns(ll x){
  if(x==0){putchar(48);putchar('\n');return ;}
  while(x) w[++wt]=x%10,x/=10;
  for(;wt;wt--) putchar(w[wt]+48); putchar('\n');
}

int main(){
  reaD(n); reaD(m); block=(int)sqrt(n); blockm=(n-1)/block+1;
  for(int i=1;i<=n;i++) reaD(A[i]);
  for(int i=1;i<=n;i++) b[i]=(i-1)/block+1;
  for(int i=1;i<=n;i++){
    reaD(u); reaD(v);
    if(u==0) rt=v;
    else Insert(u,v);
  }
  dfs(rt,0);
  for(int i=1;i<=n;i++)
    sum[b[i]]+=query(L[i])-query(R[i]);
  for(int i=1;i<=m;i++){
    reaD(op); reaD(u); reaD(v);
    if(op==1){
      add(L[u],v-A[u]);
      for(int j=1;j<=blockm;j++) sum[j]+=1ll*f[u][j]*(v-A[u]);
      A[u]=v;
    }
    else{
      Ans=0;
      if(b[u]==b[v])
    for(int j=u;j<=v;j++) Ans+=query(L[j])-query(R[j]);
      else{
    for(int j=b[u]+1;j<=b[v]-1;j++) Ans+=sum[j];
    for(int j=u;b[j]==b[u]&&j<=n;j++) Ans+=query(L[j])-query(R[j]);
    for(int j=v;b[j]==b[v]&&j;j--) Ans+=query(L[j])-query(R[j]);
      }
      //printf("%llu\n",Ans);
      PutAns(Ans);
    }
  }
  return 0;
}
