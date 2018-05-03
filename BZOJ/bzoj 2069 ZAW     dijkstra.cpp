#include<bits/stdc++.h>
#define INF 1e9
#define IN inline
#define RG register
using namespace std;
typedef long long LL;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
#define  getchar() nc()
inline int gi() {
    register int w=0,q=0;register char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')q=1,ch=getchar();
    while(ch>='0'&&ch<='9')w=w*10+ch-'0',ch=getchar();
    return q?-w:w;
}
const int N=5010,M=N<<2;
int n,m,t,ans;int d[N],fr[N];int to[M],ne[M],W[M];bool u[N];
struct node{
    int s,p;
    bool operator<(node a)const{return s>a.s;}
};
priority_queue<node>q;
IN void link(RG int u,RG int v,RG int w){
    to[++t]=v;ne[t]=fr[u];fr[u]=t;W[t]=w;
}
void read(){
    n=gi(),m=gi();
    while(m--){
        int u=gi(),v=gi(),w=gi(),w1=gi();
        link(u,v,w);link(v,u,w1);
    }
}
IN int Dij(RG int begin,RG int end,int w){
    for(int i=1;i<=n;i++)d[i]=INF;
    q.push((node){d[begin]=0,begin});
    memset(u,0,sizeof(u));
    while(!q.empty()){
        while(u[q.top().p]&&!q.empty())q.pop();
        if(q.empty())break;
        int x=q.top().p;q.pop();u[x]=1;
        if(w+d[x]>=ans)break;//this
        if(x==end)return d[1];
        for(int o=fr[x],y;y=to[o],o;o=ne[o])
            if(d[x]+W[o]<d[y]){
                d[y]=d[x]+W[o];
                if(d[y]>=ans)continue;//this
                q.push((node){d[y],y});
            }
    }
    return d[1];
}
void Work(){
    read();ans=INF;
    for(int i=fr[1],w;i;i=ne[i]){
        if(W[i]>=ans)continue;//this
        if(i&1)w=W[i+1],W[i+1]=INF;else w=W[i-1],W[i-1]=INF;
        ans=min(ans,W[i]+Dij(to[i],1,W[i]));
        if(i&1)W[i+1]=w;else W[i-1]=w;
    }
    printf("%d",ans);
}
int main()
{
    Work();
    return 0;
}
