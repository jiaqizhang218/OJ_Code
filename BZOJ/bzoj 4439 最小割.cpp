#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100050
int n,m,S,T;
inline int pos(int i,int j){return (i-1)*m+j;}
char str[100];
int lj[N],to[N],v[N],fro[N],cnt=1;
void add(int a,int b,int c){fro[++cnt]=lj[a];to[cnt]=b;v[cnt]=c;lj[a]=cnt;}
void ins(int a,int b,int c){add(a,b,c);add(b,a,0);}
int q[N],dis[N],l,r;
bool bfs()
{
    int x;l=0;r=1;
    memset(dis,0,sizeof(dis));
    dis[S]=1;q[1]=S;
    while(l!=r)
    {
        x=q[l++];if(l==N) l=0;
        for(int i=lj[x];i;i=fro[i])
        {
            if(v[i]&&!dis[to[i]])
            {
                dis[to[i]]=dis[x]+1;
                if(to[i]==T) return 1;
                q[r++]=to[i];if(r==N) r=0;
            }
        }
    }
    return 0;
}
int dfs(int x,int p)
{
    if(x==T) return p;
    int tp,res=0;
    for(int i=lj[x];i;i=fro[i])
    {
        if(v[i]&&dis[to[i]]==dis[x]+1)
        {
            tp=dfs(to[i],min(p-res,v[i]));
            v[i]-=tp;v[i^1]+=tp;
            res+=tp;
            if(res==p) return p;
        }
    }
    if(res==0) dis[x]=0;
    return res;
}
int a,b,ans;
int main()
{
    scanf("%d%d%d%d",&n,&m,&a,&b);
    S=0;T=n*m+1;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",str+1);
        for(int j=1;j<=m;j++)
        {
            if(str[j]=='#') ins(S,pos(i,j),b);
            else ins(pos(i,j),T,b);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i>1) ins(pos(i,j),pos(i-1,j),a);
            if(i<n) ins(pos(i,j),pos(i+1,j),a);
            if(j>1) ins(pos(i,j),pos(i,j-1),a);
            if(j<m) ins(pos(i,j),pos(i,j+1),a);
        }
    }
    while(bfs()) ans+=dfs(S,0x3f3f3f3f);
    printf("%d\n",ans);
    return 0;
}
