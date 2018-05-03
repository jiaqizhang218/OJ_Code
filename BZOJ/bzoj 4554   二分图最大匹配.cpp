#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int to[2510],next[2510],head[2510],from[2510],vis[2510];
int bel[60][60];
int n,m,tx,ty,now,ans,cnt;
char str[60][60];
void add(int a,int b)
{
    to[cnt]=b;
    next[cnt]=head[a];
    head[a]=cnt++;
}
int dfs(int x)
{
    for(int i=head[x];i!=-1;i=next[i])
    {
        if(vis[to[i]]==now) continue;
        vis[to[i]]=now;
        if(!from[to[i]]||dfs(from[to[i]]))
        {
            from[to[i]]=x;
            return 1;
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d",&n,&m);
    int i,j;
    memset(head,-1,sizeof(head));
    tx=ty=1;
    for(i=1;i<=n;i++)
    {
        scanf("%s",&str[i]);
        for(j=1;j<=m;j++)
        {
            if(str[i][j-1]=='#')    tx++;
            else bel[i][j]=tx;
        }
        if(str[i][m-1]!='#')    tx++;
    }
    for(j=1;j<=m;j++)
    {
        for(i=1;i<=n;i++)
        {
            if(str[i][j-1]=='#')    ty++;
            if(str[i][j-1]=='*')    add(bel[i][j],ty);
        }
        if(str[n][j-1]!='#')    ty++;
    }
    for(now=1;now<=tx;now++) ans+=dfs(now);
    printf("%d",ans);
    return 0;
}
