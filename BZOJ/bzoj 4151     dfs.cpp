#include<bits/stdc++.h>
#define N 300300
int T,n,m,i,x,y,u,w,tot,ans,a[N],b[N],c[N],fir[N],ne[N<<1],la[N<<1],d[3][N];
void ins(int x,int y){la[++tot]=y;ne[tot]=fir[x];fir[x]=tot;}
void dfs(int x,int fa,int dis,int p){
    d[p][x]=dis;
    for(int i=fir[x];i;i=ne[i])if(la[i]!=fa)dfs(la[i],x,dis+1,p);
}
int main(){
    for(scanf("%d",&T);T--;memset(fir,0,sizeof(fir)),tot=0){
        for(scanf("%d%d",&n,&m),i=1;i<n;i++)scanf("%d%d",&x,&y),ins(x,y),ins(y,x);
        for(dfs(1,0,0,0),ans=-1e9,i=1;i<=m;i++){
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            if(d[0][a[i]]+d[0][b[i]]-c[i]>ans)ans=d[0][a[i]]+d[0][b[i]]-c[i],u=i;
        }
        for(dfs(a[u],0,0,1),dfs(b[u],0,0,2),w=0,i=1;i<=n;i++)if(d[1][i]+d[2][i]<=c[u])if(d[0][i]<ans||!w)ans=d[0][i],w=i;
        for(dfs(w,0,0,0),i=1;i<=m;i++)if(d[0][a[i]]+d[0][b[i]]>c[i]){w=0;break;}
        if(!w)puts("NIE");else printf("TAK %d\n",w);
    }
}
