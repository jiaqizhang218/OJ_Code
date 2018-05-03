#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> abcd;

inline char nc(){
  static char buf[100000],*p1=buf,*p2=buf;
  return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline void read(int &x){
  char c=nc(),b=1;
  for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;
  for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;
}

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
#define pb push_back
#define P(x,y) (((x)-1)*m+(y))

const int N=100005;

struct edge{
  int u,v,w,next;
}G[N<<2];
int head[N],inum;
inline void add(int u,int v,int w,int p){
  G[p].u=u; G[p].v=v; G[p].w=w; G[p].next=head[u]; head[u]=p;
}
inline void link(int u,int v,int w){
  add(u,v,w,++inum); add(v,u,w,++inum);
}

int n,m;
int qx1[N],qx2[N],qy1[N],qy2[N];
int ans[N];

int dis[N];

priority_queue<abcd> Q;

inline void Dij(int S,int x1,int x2,int y1,int y2){
  for (int i=x1;i<=x2;i++) for (int j=y1;j<=y2;j++) dis[P(i,j)]=1<<30;
  dis[S]=0; Q.push(abcd(0,S));
  while (!Q.empty()){
    int u=Q.top().second,d=Q.top().first; Q.pop();
    if (dis[u]!=-d) continue;
    int ux=(u-1)/m+1,uy=(u-1)%m+1;
    for (int p=head[u];p;p=G[p].next){
      int v=G[p].v,vx=(v-1)/m+1,vy=(v-1)%m+1;
      if (vx<x1 || vx>x2 || vy<y1 || vy>y2) continue;
      if (dis[v]>dis[u]+G[p].w){
    dis[v]=dis[u]+G[p].w;
    Q.push(abcd(-dis[v],v));
      }
    }
  }
}

#define Qu (P(qx1[que[j]],qy1[que[j]]))
#define Qv (P(qx2[que[j]],qy2[que[j]]))

inline void Solve(int x1,int x2,int y1,int y2,vector<int> &que){
  if (que.empty()) return;
  if (x2-x1>y2-y1){
    int mid=(x1+x2)>>1;
    for (int i=y1;i<=y2;i++){
      Dij(P(mid,i),x1,x2,y1,y2);
      for (int j=0;j<(int)que.size();j++)
    ans[que[j]]=min(ans[que[j]],dis[Qu]+dis[Qv]);
    }
    vector<int> q1,q2;
    for (int j=0;j<(int)que.size();j++)
      if (qx1[que[j]]<mid && qx2[que[j]]<mid)
    q1.pb(que[j]);
      else if (qx1[que[j]]>mid && qx2[que[j]]>mid)
    q2.pb(que[j]);
    Solve(x1,mid-1,y1,y2,q1);
    Solve(mid+1,x2,y1,y2,q2);
  }else{
    int mid=(y1+y2)>>1;
    for (int i=x1;i<=x2;i++){
      Dij(P(i,mid),x1,x2,y1,y2);
      for (int j=0;j<(int)que.size();j++)
    ans[que[j]]=min(ans[que[j]],dis[Qu]+dis[Qv]);
    }
    vector<int> q1,q2;
    for (int j=0;j<(int)que.size();j++)
      if (qy1[que[j]]<mid && qy2[que[j]]<mid)
    q1.pb(que[j]);
      else if (qy1[que[j]]>mid && qy2[que[j]]>mid)
    q2.pb(que[j]);
    Solve(x1,x2,y1,mid-1,q1);
    Solve(x1,x2,mid+1,y2,q2);
  }
}

int main(){
  int x;
  read(n); read(m);
  for (int i=1;i<=n;i++)
    for (int j=1;j<m;j++)0
      read(x),link(P(i,j),P(i,j+1),x);
  for (int i=1;i<n;i++)
    for (int j=1;j<=m;j++)
      read(x),link(P(i,j),P(i+1,j),x);
  vector<int> que;
  int Q; read(Q);
  for (int i=1;i<=Q;i++)
    read(qx1[i]),read(qy1[i]),read(qx2[i]),read(qy2[i]),que.pb(i),ans[i]=1<<30;
  Solve(1,n,1,m,que);
  for (int i=1;i<=Q;i++)
    printf("%d\n",ans[i]);
  return 0;
}
