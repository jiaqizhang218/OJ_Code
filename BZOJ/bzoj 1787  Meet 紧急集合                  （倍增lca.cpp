#include<bits/stdc++.h> 
using namespace std;  
struct data{  
    int to,next;  
}e[1000001];  
int n,m,cnt,head[500001],deep[500001],fa[500001][20];  
bool vis[500001];  
inline int read(){    
    int x=0,f=1;char ch=getchar();    
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}    
    while(ch>='0'&&ch<='9'){x*=10;x+=ch-'0';ch=getchar();}    
    return x*f;    
}    
void insert(int u,int v){e[++cnt]=(data){v,head[u]};head[u]=cnt;}  
void ins(int u,int v){insert(u,v);insert(v,u);}  
void dfs(int x){  
    vis[x]=1;  
    for(int i=1;i<=19;i++){  
        if(deep[x]<(1<<i))break;  
        fa[x][i]=fa[fa[x][i-1]][i-1];  
    }  
    for(int i=head[x];i;i=e[i].next){  
        if(vis[e[i].to])continue;  
        deep[e[i].to]=deep[x]+1;  
        fa[e[i].to][0]=x;  
        dfs(e[i].to);  
    }  
}  
int lca(int x,int y){  
    if(deep[x]<deep[y])swap(x,y);  
    int d=deep[x]-deep[y];  
    for(int i=0;i<=19;i++)  
        if((1<<i)&d)x=fa[x][i];  
    for(int i=19;i>=0;i--)  
        if(fa[x][i]!=fa[y][i])  
            x=fa[x][i],y=fa[y][i];  
    if(x==y)return x;  
    else return fa[x][0];  
}  
int dis(int a,int b){  
    return deep[a]+deep[b]-2*deep[lca(a,b)];  
}  
int main(){  
    n=read();m=read();  
    for(int i=1;i<=n-1;i++){  
        int a=read(),b=read();  
        ins(a,b);  
    }  
    dfs(1);  
    for(int i=1;i<=m;i++){  
        int a=read(),b=read(),c=read();  
        int ab=lca(a,b),bc=lca(b,c),ac=lca(a,c);  
        if(ab==ac)printf("%d %d\n",bc,dis(a,bc)+dis(b,bc)+dis(c,bc));  
        else if(bc==ac)printf("%d %d\n",ab,dis(a,ab)+dis(b,ab)+dis(c,ab));  
        else if(ab==bc)printf("%d %d\n",ac,dis(a,ac)+dis(b,ac)+dis(c,ac));  
    }  
    return 0;  
}  
