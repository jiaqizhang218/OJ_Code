#include<bits/stdc++.h>
const int MAXN = 100010;
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
//#define  getchar() nc()
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
struct edge{
    int first,next,to;
}a[MAXN*2];
struct tree{
    int ls,rs,sum;
}tr[5000010];
int dep[MAXN],son[MAXN],size[MAXN],fa[MAXN],top[MAXN],dfn[MAXN],w[MAXN];
int numed,numtr,numcl,numdfn,n,q;
int roof[MAXN*3],color[MAXN];
map<int,int> mp;
char s[3];

void addedge(int from,int to){
    a[++numed].to=to;
    a[numed].next=a[from].first;
    a[from].first=numed;
}

void dfs1(int now,int f){
    fa[now]=f,dep[now]=dep[f]+1,size[now]=1;
    for(int i=a[now].first;i;i=a[i].next){
        int to=a[i].to;
        if(to==f) continue;
        dfs1(to,now);
        if(size[to]>size[son[now]]) son[now]=to;
        size[now]+=size[to];
    }
}

void dfs2(int now,int tp){
    top[now]=tp;dfn[now]=++numdfn;
    if(son[now]) dfs2(son[now],tp);
    for(int i=a[now].first;i;i=a[i].next){
        int to=a[i].to;
        if(to==fa[now]||to==son[now]) continue;
        dfs2(to,to);
    }
}

inline void change(int &x,int l,int r,int pos,int zhi){
    if(!x) x=++numtr;
    if(l==r&&l==pos){
        tr[x].sum+=zhi;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid) change(tr[x].ls,l,mid,pos,zhi);
    else change(tr[x].rs,mid+1,r,pos,zhi);
    tr[x].sum=tr[tr[x].ls].sum+tr[tr[x].rs].sum;
}

inline int query(int x,int L,int R,int l,int r){
    if(!x) return 0;
    if(L==l&&R==r){
        return tr[x].sum;
    }
    int mid=(L+R)/2;
    if(r<=mid) return query(tr[x].ls,L,mid,l,r);
    else if(l>mid) return query(tr[x].rs,mid+1,R,l,r);
    else return query(tr[x].ls,L,mid,l,mid)+query(tr[x].rs,mid+1,R,mid+1,r);
}

int work(int x,int y,int rf){
    int topx=top[x],topy=top[y],ans=0;
    while(topx!=topy){
        if(dep[topx]<dep[topy]) swap(topx,topy),swap(x,y);
        ans+=query(rf,1,n,dfn[topx],dfn[x]);
        x=fa[topx];
        topx=top[x];
    }
    if(dep[x]<dep[y]) swap(x,y);
    ans+=query(rf,1,n,dfn[y],dfn[x]);
    return ans;
}

int main()
{
    n=read(),q=read();
    for(int i=1;i<=n;i++){
        int x=read();
        if(!mp[x]) mp[x]=++numcl;
        color[i]=mp[x];
    }
    for(int i=1;i<=n-1;i++){
        int x=read(),y=read();
        addedge(x,y),addedge(y,x);
    }
    dfs1(1,0),dfs2(1,1);
    for(int i=1;i<=n;i++)
        change(roof[color[i]],1,n,dfn[i],1);
    while(q--){
        scanf("%s",s);
        if(s[0]=='C'){
            int x=read(),y=read();
            if(!mp[y]) mp[y]=++numcl;
            change(roof[color[x]],1,n,dfn[x],-1);
            color[x]=mp[y];
            change(roof[color[x]],1,n,dfn[x],1);
        }
        else{
            int x=read(),y=read(),z=read();
            if(!mp[z]) mp[z]=++numcl;
            printf("%d\n",work(x,y,roof[mp[z]]));
        }
    }
    return 0;
}
