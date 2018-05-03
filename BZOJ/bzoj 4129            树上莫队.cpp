#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int N=5e4+5;
inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

int n,Q,a[N],t[N],op,x,y;
struct edge{int v,ne;} e[N<<1];
int cnt,h[N];
inline void ins(int u,int v){
    e[++cnt]=(edge){v,h[u]}; h[u]=cnt;
    e[++cnt]=(edge){u,h[v]}; h[v]=cnt;
}
int block, pos[N], m, st[N], top;
int fa[N][18], deep[N];
void dfs(int u){
    for(int i=1; (1<<i)<=deep[u]; i++)
        fa[u][i]=fa[ fa[u][i-1] ][i-1];
    int bot=top;
    for(int i=h[u];i;i=e[i].ne) if(e[i].v!=fa[u][0]){
        fa[e[i].v][0]=u; deep[e[i].v]=deep[u]+1;
        dfs(e[i].v);
        if(top-bot>=block){
            m++;
            while(top!=bot) pos[st[top--]]=m;
        }
    }
    st[++top]=u;
}
inline int lca(int x,int y){
    if(deep[x]<deep[y]) swap(x, y);
    int bin=deep[x]-deep[y];
    for(int i=0;i<17;i++) if((1<<i)&bin) x=fa[x][i];
    if(x==y) return x;
    for(int i=16;i>=0;i--) 
        if(fa[x][i]!=fa[y][i]) x=fa[x][i], y=fa[y][i];
    return x==y ? x : fa[x][0];
}


struct cmeow{int u, next, last;}cq[N];
struct meow{
    int u, v, tim, id;
    bool operator <(const meow &a) const {
        return pos[u]==pos[a.u] ? (pos[v]==pos[a.v] ? tim<a.tim : pos[v]<pos[a.v]) : pos[u]<pos[a.u];
    }
}q[N];
int p, tim, u, v, cur, ans[N], vis[N];

struct Block{
    int n,pos[N],m,block;
    struct _blo{int l,r;} b[350];
    void ini(){
        block=sqrt(n); m=(n-1)/block+1;
        for(int i=1;i<=n;i++) pos[i]=(i-1)/block+1;
        for(int i=1;i<=m;i++) b[i].l=(i-1)*block+1, b[i].r=i*block;
        b[m].r=n;
    }
    int cou[N], sum[350];
    inline void add(int v) { if(v<=n) sum[pos[v]]+= (++cou[v])==1; }
    inline void del(int v) { if(v<=n) sum[pos[v]]-= (--cou[v])==0; }
    inline int mex(){
        for(int i=1;i<=m;i++) if(sum[i] != b[i].r-b[i].l+1)
            for(int j=b[i].l; j<=b[i].r; j++) if(!cou[j]) return j;
        return -1;
    }
}B;
inline void cha(int u,int d){ 
    if(vis[u]) B.del(a[u]), B.add(d); 
    a[u]=d;
}
inline void Xor(int u){
    if(vis[u]) B.del(a[u]), vis[u]=0;
    else B.add(a[u]), vis[u]=1;
}
inline void move(int x,int y){ 
    if(deep[x]<deep[y]) swap(x, y);
    while(deep[x]>deep[y]) Xor(x), x=fa[x][0];
    while(x!=y) Xor(x), Xor(y), x=fa[x][0], y=fa[y][0];
}

void modui(){
    u=v=1;
    for(int i=1;i<=p;i++){
        while(cur<q[i].tim) cur++, cha(cq[cur].u, cq[cur].next);
        while(cur>q[i].tim) cha(cq[cur].u, cq[cur].last), cur--;
        if(u!=q[i].u) move(u, q[i].u), u=q[i].u;
        if(v!=q[i].v) move(v, q[i].v), v=q[i].v;
        int anc=lca(u, v);
        Xor(anc); ans[q[i].id]=B.mex()-1; Xor(anc);
    }
}

int main(){
    n=read(); Q=read();
    for(int i=1;i<=n;i++) a[i]=t[i]=read()+1;
    for(int i=1;i<n ;i++) ins(read(), read() );
    block=pow(n, 0.45);
    dfs(1);
    while(top) pos[st[top--]]=m;
    for(int i=1;i<=Q;i++){
        op=read(); x=read(); y=read();
        if(op) p++, q[p]=(meow){x, y, tim, p};
        else tim++, cq[tim]=(cmeow){x, y+1, t[x]}, t[x]=y+1;
    } 

    B.n = n+1; B.ini();
    sort(q+1, q+1+p);
    modui();
    for(int i=1;i<=p;i++) printf("%d\n",ans[i]);
}
