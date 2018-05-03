#include<bits/stdc++.h>
const int maxn=210,maxm=40010,inf=1e9;  
using namespace std;  
int n,cnt,pre[maxm],now[maxn],son[maxm],val[maxm],tot,S=maxn-2,T=maxn-1;char ch[55][55];  
int q[maxm+10],head,tail,dis[maxn];  
void add(int a,int b,int c){pre[++tot]=now[a],now[a]=tot,son[tot]=b,val[tot]=c;}  
void ins(int a,int b,int c){add(a,b,c),add(b,a,0);}  
int id0(int x,int op){return op*n+x;}// 男生，0喜欢，1不喜欢  
int id1(int x,int op){return op*n+2*n+x;}//女生  
   
bool bfs(){  
    memset(dis,-1,sizeof(dis));  
    q[tail=1]=S,dis[S]=head=0;  
    while (head!=tail){  
        if (++head>maxm) head=1;  
        int x=q[head];  
        for (int y=now[x];y;y=pre[y]) if (val[y]&&dis[son[y]]==-1){  
            if (++tail>maxm) tail=1;  
            q[tail]=son[y],dis[son[y]]=dis[x]+1;  
        }  
    }  
    return dis[T]>0;  
}  
   
int dfs(int x,int low){  
    if (x==T) return low;  
    int y,res=0;  
    for (y=now[x];y;y=pre[y]){  
        if (dis[son[y]]!=dis[x]+1||!val[y]) continue;  
        int tmp=dfs(son[y],min(low,val[y]));  
        val[y]-=tmp,val[y^1]+=tmp,res+=tmp,low-=tmp;  
        if (!low) break;   
    }  
    if (!y) dis[x]=-1;  
    return res;  
}  
   
bool dinic(int lim){  
    int res=0;  
    memset(now,0,sizeof(now)),tot=1;  
    for (int i=1;i<=n;i++) ins(S,id0(i,0),lim),ins(id0(i,0),id0(i,1),cnt);  
    for (int i=1;i<=n;i++) ins(id1(i,0),T,lim),ins(id1(i,1),id1(i,0),cnt);  
       
    for (int i=1;i<=n;i++)  
        for (int j=1;j<=n;j++){  
            if (ch[i][j]=='Y') ins(id0(i,0),id1(j,0),1);  
            else ins(id0(i,1),id1(j,1),1);  
        }  
    while (bfs()) res+=dfs(S,inf);  
    return res>=lim*n;  
}  
   
void work(){  
    int l=1,r=n,mid=(l+r)>>1,ans=0;  
    while (l<=r){  
        if (dinic(mid)) l=mid+1,ans=mid;  
        else r=mid-1;  
        mid=(l+r)>>1;  
    }  
    printf("%d\n",ans);  
}  
   
int main(){  
    scanf("%d%d",&n,&cnt);  
    for (int i=1;i<=n;i++) scanf("%s",ch[i]+1);  
    work();  
    return 0;  
} 
