#include<bits/stdc++.h>
using namespace std;
int n,m,tot,S,T,p[200010],a[400010],w[400010],next[400010],point[500010];
bool ext[500010];
const long long inf=1e18;
struct edge{
    int to,nxt;
    long long cst;
    void add(int x,int y,long long v){
        to=y;nxt=point[x];cst=v;point[x]=tot;
    }
}e[2000010];
struct Node{
    int pos;
    long long dis;
    bool operator < (const Node &a)const{
        return dis>a.dis;
    }
};
priority_queue<Node> q;
int comp(int x,int y){return w[x]<w[y];}
void add(int x,int y,int v){
    ++tot;a[tot]=y;next[tot]=p[x];p[x]=tot;w[tot]=v;
}
void Buildgraph(){
    int sor[400010],cnt;
    S=0;T=tot+1;
    cnt=tot;tot=0;
    for (int i=1;i<=cnt;i+=2){
        e[++tot].add(i,i+1,w[i]);
        e[++tot].add(i+1,i,w[i]);
    }
    tot=cnt;
    for (int i=1;i<=n;i++){
        cnt=0;
        for (int j=p[i];j!=0;j=next[j])
          sor[++cnt]=j;//把从点i连出去的边排序
        sort(sor+1,sor+cnt+1,comp);
        for (int j=1;j<cnt;j++){
            int x=sor[j],y=sor[j+1];
            e[++tot].add(x,y,w[y]-w[x]);//向比它大的边连边权为差值的边
            e[++tot].add(y,x,0);//向比它小的边连边权为0的边
        }
    }
    for (int i=p[1];i!=0;i=next[i])
      e[++tot].add(S,i,w[i]);
    for (int i=p[n];i!=0;i=next[i])
      e[++tot].add((i%2==0)?i-1:i+1,T,w[i]);   
}
long long Dijkstra(int S,int T){
    long long ans=inf;
    Node now;
    now.pos=S;now.dis=0;
    q.push(now);
    while (!q.empty()){
        Node u=q.top();q.pop();
        if (ext[u.pos]==true) continue;
        if (u.pos==T) return u.dis;
        for (int i=point[u.pos];i!=0;i=e[i].nxt)
          if (ext[e[i].to]==false){
              Node v;
              v.pos=e[i].to;
              v.dis=u.dis+e[i].cst;
              q.push(v);
          }
        ext[u.pos]=true;
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        add(x,y,v);add(y,x,v);
    }
    Buildgraph();
    printf("%lld\n",Dijkstra(S,T));
    return 0;
}
