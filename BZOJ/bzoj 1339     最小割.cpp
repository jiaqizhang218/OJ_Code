#include<bits/stdc++.h>  
using namespace std;  
const int maxn=425;  
struct edge{  
    int u,v,cap,flow;  
    edge(int _u=0,int _v=0,int _cap=0,int _flow=0):  
        u(_u),v(_v),cap(_cap),flow(_flow){}   
};  
vector<edge>edges;  
vector<int>G[maxn];  
int vis[maxn];  
int cur[maxn];  
int hash[maxn][2];  
int d[maxn],n,m,s,t;  
void add(int u,int v,int cap){  
    edges.push_back(edge(u,v,cap));  
    G[u].push_back(edges.size()-1);  
    edges.push_back(edge(v,u,0));  
    G[v].push_back(edges.size()-1);  
}  
bool bfs(){  
    memset(vis,0,sizeof vis);d[s]=0;  
    queue<int>q;q.push(s);vis[s]=1;  
    while(!q.empty()){  
        int u=q.front();q.pop();  
        for(int i=0;i<G[u].size();i++){  
            edge e=edges[G[u][i]];  
            if(!vis[e.v]&&e.cap>e.flow){  
                d[e.v]=d[u]+1;  
                vis[e.v]=1;  
                q.push(e.v);  
            }  
        }  
    }return vis[t];  
}  
int dfs(int u,int a){  
    if(u==t||a==0)return a;  
    int flow=0,f;  
    for(int &i=cur[u];i<G[u].size();i++){  
        edge e=edges[G[u][i]];  
        if(d[e.v]==d[u]+1&&(f=dfs(e.v,min(a,e.cap-e.flow)))>0){  
            flow+=f;  
            a-=f;  
            edges[G[u][i]].flow+=f;  
            edges[G[u][i]^1].flow-=f;  
            if(!a)break;  
        }  
    }return flow;  
}  
int Dinic(){  
    int flow=0;  
    while(bfs()){  
        int x=0;  
        memset(cur,0,sizeof cur);  
        while(x=dfs(s,INT_MAX)){  
            flow+=x;  
            memset(cur,0,sizeof cur);  
        }  
    }return flow;  
}  
void deb(){  
    for(int i=0;i<edges.size();i++)if(i%2==0)  
    printf("%d -> %d cap:%d\n",edges[i].u,edges[i].v,edges[i].cap);  
}  
int cost[maxn];  
int main(){  
    scanf("%d%d",&n,&m);  
    int tot=0;  
    for(int i=1;i<=n;i++)hash[i][0]=++tot,hash[i][1]=++tot;  
    int ss,tt;  
    scanf("%d%d",&s,&t);  
    s=hash[s][0];  
    t=hash[t][1];  
    for(int i=1;i<=n;i++){  
        int x;scanf("%d",&x);cost[i]=x;  
        add(hash[i][0],hash[i][1],x);  
    }  
    for(int i=1;i<=m;i++){  
        int u,v;scanf("%d%d",&u,&v);  
        add(hash[u][1],hash[v][0],INT_MAX);  
        add(hash[v][1],hash[u][0],INT_MAX);  
    }  
    //deb();  
    int ans=Dinic();  
    cout<<ans<<endl;  
    return 0;  
}  
