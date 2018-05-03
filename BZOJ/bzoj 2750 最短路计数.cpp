#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rpg(i,x) for(register int i=head[x];i;i=e[i].next)
#define pa pair<int,int>
using namespace std;
const int N=5005;
typedef long long ll;
const ll ccz=1000000007;
int head[N],tot,dis[N],u,v,w,n,m,cnt,c[N];
ll a[N],b[N],ans[N];
struct zs{
    int to,next,w,id;
}e[N];
bool in[N];
inline void ins(int u,int v,int w,int id){
    e[++tot].to=v; e[tot].next=head[u]; head[u]=tot; e[tot].w=w; e[tot].id=id;
}
inline void dijkstra(int s){
    priority_queue<pa,vector<pa>,greater<pa> >q;
    memset(in,0,sizeof in);
    memset(dis,60,sizeof dis); dis[s]=0; q.push(make_pair(0,s));
    cnt=0;
    while(!q.empty()){
        int x=q.top().second; q.pop();
        if(in[x]) continue; in[x]=1; c[++cnt]=x;
        rpg(k,x) if(dis[x]+e[k].w<dis[e[k].to]) {
            dis[e[k].to]=e[k].w+dis[x];
            q.push(make_pair(dis[e[k].to],e[k].to));
        }
    }
    memset(a,0,sizeof a); memset(b,0,sizeof b);
    rep(i,1,cnt) b[c[i]]=1;
    a[s]=1;
    rep(i,1,cnt) rpg(k,c[i]) if(dis[c[i]]+e[k].w==dis[e[k].to])(a[e[k].to]+=a[c[i]])%=ccz;
    per(i,cnt,1) rpg(k,c[i]) if(dis[c[i]]+e[k].w==dis[e[k].to])(b[c[i]]+=b[e[k].to])%=ccz;
    rep(i,1,n) rpg(k,i) if(dis[i]+e[k].w==dis[e[k].to])(ans[e[k].id]+=a[i]*b[e[k].to])%=ccz;
}
int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,m) scanf("%d%d%d",&u,&v,&w),ins(u,v,w,i);
    rep(i,1,n) dijkstra(i);
    rep(i,1,m) printf("%lld\n",ans[i]);
}
