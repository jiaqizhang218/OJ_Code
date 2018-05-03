#include<bits/stdc++.h> 
using namespace std;
const int Maxn=150;
const double eps=1e-8;
const double inf=1e9;
struct node{int x,y,next,other; double c;}edge[Maxn*Maxn*Maxn]; int len,first[Maxn];
void ins(int x,int y,double c)
{
  len++; int k1=len; edge[len].x=x; edge[len].y=y; edge[len].c=c; edge[len].next=first[x]; first[x]=len;
  len++; int k2=len; edge[len].x=y; edge[len].y=x; edge[len].c=0; edge[len].next=first[y]; first[y]=len;
  edge[k1].other=k2; edge[k2].other=k1;
}
queue<int>Q; int dep[Maxn],ST,ED; int N,M;
bool BFS()
{
  while(!Q.empty()) Q.pop(); Q.push(ST);
  memset(dep,0,sizeof(dep)); dep[ST]=1;
  while(!Q.empty())
  {
    int x=Q.front();
    for(int k=first[x];k!=-1;k=edge[k].next)
    {
      int y=edge[k].y;
      if(dep[y]==0 && edge[k].c>eps){dep[y]=dep[x]+1; Q.push(y);}
    }
    Q.pop();
  }
  return dep[ED]>0;
}
inline double DFS(int x,double flow)
{
  if(x==ED) return flow;
  double delta=0;
  for(int k=first[x];k!=-1;k=edge[k].next)
  {
    int y=edge[k].y;
    if(dep[y]==dep[x]+1 && edge[k].c>eps && flow>delta)
    {
      double minf=DFS(y,min(edge[k].c,flow-delta));
      edge[k].c-=minf; edge[edge[k].other].c+=minf;
      delta+=minf;
    }
  }
  if(x==ED) dep[x]=0;
  return delta;
}
double A[Maxn],B[Maxn];
int str[Maxn][Maxn];
bool Build(double k)
{
  len=0; memset(first,-1,sizeof(first));
  ST=N+M+1; ED=N+M+2; double ans=0.0;
  for(int i=1;i<=M;i++) ins(ST,i,k*B[i]);
  for(int i=1;i<=M;i++) for(int j=1;j<=N;j++) if(str[i][j]==1) ins(i,M+j,inf);
  for(int i=1;i<=N;i++) ins(i+M,ED,A[i]),ans+=A[i];
  double delta;
  while(BFS())
  {
    if(delta=DFS(ST,inf))
      ans-=delta;
  }
  return ans<eps;
}
int main()
{
  scanf("%d%d",&N,&M);
  for(int i=1;i<=N;i++) scanf("%lf",&A[i]);
  for(int i=1;i<=M;i++) scanf("%lf",&B[i]);
  for(int i=1;i<=M;i++) for(int j=1;j<=N;j++) scanf("%d",&str[i][j]);
  double L=0.0; double R=5000000;
  while(R-L>eps)
  {
      double mid=(L+R)/2;
      if(Build(mid)) R=mid;
      else L=mid;
  }
  return printf("%.6lf\n",L),0;
}
