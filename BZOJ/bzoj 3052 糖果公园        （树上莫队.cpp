#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int maxn = 100010;
struct edge {
	int to,next;
}e[maxn<<2];
struct ask {
	int u,v,id,pre,t;
}a1[maxn],a2[maxn];
LL res[maxn],ans;
int pos[maxn],v[maxn],w[maxn],dfn[maxn],bin[20],fa[maxn][20],deep[maxn],st[maxn],p[maxn],vis[maxn],head[maxn];
int c[maxn],pre[maxn];
int block,blonum,n,m,q,cnt,cnt1,cnt2,top;
inline void link(int u,int v) {
	e[++cnt].to = v , e[cnt].next = head[u] , head[u] = cnt;
	e[++cnt].to = u , e[cnt].next = head[v] , head[v] = cnt;
}
bool cmp(ask a,ask b) {
	if(pos[a.u]==pos[b.u] && pos[a.v]==pos[b.v]) return a.t<b.t;
	if(pos[a.u]==pos[b.u])	return pos[a.v] < pos[b.v];
	return pos[a.u] < pos[b.u];
}
inline int dfs(int x) {   //预处理+分块
    int size=0;
    dfn[x]=++cnt;
    for (int i=1;i<20;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
    for (int i=head[x];i;i=e[i].next) if (e[i].to!=fa[x][0]) {
            deep[e[i].to]=deep[x]+1;
            fa[e[i].to][0]=x;
            size+=dfs(e[i].to);
            if (size>=block) {
                blonum++;
                while (size--) pos[st[top--]]=blonum;
                size=0;
            }
        }
    st[++top]=x;
    return size+1;
}
inline void work(int x) {
    if (!vis[x]) {vis[x]=1;p[c[x]]++;ans+=(LL)w[p[c[x]]]*v[c[x]];}
    else {vis[x]=0;ans-=(LL)w[p[c[x]]]*v[c[x]];p[c[x]]--;}
}
inline void modify(int x,int y) {   //修改操作
    if (vis[x]) {work(x);c[x]=y;work(x);}
    else c[x]=y;
}
inline void solve(int x,int y) {
    while (x!=y) {
        if (deep[x]<deep[y]) work(y),y=fa[y][0];
        else work(x),x=fa[x][0];
    }
}
inline int lca(int x,int y) {
    if (deep[x]<deep[y]) swap(x,y);
    int t=deep[x]-deep[y];
    for (int i=0;bin[i]<=t;i++) if (bin[i]&t) x=fa[x][i];
    for (int i=19;i>=0;i--)
        if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    return x==y?x:fa[x][0];
}
int main()
{
	bin[0]=1;for (int i=1;i<20;i++) bin[i]=bin[i-1]<<1;
    scanf("%d%d%d",&n,&m,&q);
    for (int i=1;i<=m;i++) v[i]=read();
    for (int i=1;i<=n;i++) w[i]=read();
    for (int i=1;i<n;i++) {
        int u=read(),v=read();
        link(u,v);
    }
    for (int i=1;i<=n;i++) c[i]=read(),pre[i]=c[i];
    block=(int)pow(n,0.6);
    cnt=0;dfs(1);
    cnt1=0,cnt2=0;
    for (int i=1;i<=q;i++) {
        int x=read(),u=read(),v=read();
        if (x) {   //查询操作
            cnt1++;
            if (dfn[u]>dfn[v]) swap(u,v);
            a1[cnt1].u=u;a1[cnt1].v=v;a1[cnt1].id=cnt1;a1[cnt1].t=cnt2;   //查询时间
        }
        else {   //修改操作
            cnt2++;
            a2[cnt2].u=u;a2[cnt2].v=v;a2[cnt2].pre=pre[u];pre[u]=v;   //邻接表存一个节点的修改顺序
        }
    }
    sort(a1+1,a1+cnt1+1,cmp);
    for (int i=1;i<=a1[1].t;i++) modify(a2[i].u,a2[i].v);
    solve(a1[1].u,a1[1].v);
    int t=lca(a1[1].u,a1[1].v);
    work(t);
    res[a1[1].id]=ans;
    work(t);
    for (int i=2;i<=cnt1;i++) {
        for (int j=a1[i-1].t+1;j<=a1[i].t;j++) modify(a2[j].u,a2[j].v);  //时间流逝，修改
        for (int j=a1[i-1].t;j>a1[i].t;j--) modify(a2[j].u,a2[j].pre);   //时间倒流，逆修改
        solve(a1[i-1].u,a1[i].u);
        solve(a1[i-1].v,a1[i].v);
        t=lca(a1[i].u,a1[i].v);
        work(t);
        res[a1[i].id]=ans;
        work(t);
    }
    for (int i=1;i<=cnt1;i++) printf("%lld\n",res[i]);
    return 0;
}
