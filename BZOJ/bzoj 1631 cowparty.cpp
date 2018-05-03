#include <iostream>  
#include <cstring>  
#include <algorithm>  
#include <cstdlib>  
#include <cstdio>  
#include <queue>  
#define inf 0x3f3f3f3f  
using namespace std;  
int n,m,f,ans,d[1005][3],inq[1005],tot=0,h[1005][3];  
struct edge  
{  
    int y,v,ne;  
}e[200005][3];  
void Addedge(int k,int x,int y,int v)  
{  
    if (!k) tot++;  
    e[tot][k].y=y;  
    e[tot][k].ne=h[x][k];  
    e[tot][k].v=v;  
    h[x][k]=tot;  
}  
void spfa(int k)  
{  
    for (int i=1;i<=n;i++)  
        inq[i]=0,d[i][k]=inf;  
    d[f][k]=0;  
    queue<int> q;  
    q.push(f),inq[f]=1;  
    while (!q.empty())  
    {  
        int x=q.front();  
        q.pop();  
        inq[x]=0;  
        for (int i=h[x][k];i;i=e[i][k].ne)  
        {  
            int y=e[i][k].y;  
            if (d[y][k]>d[x][k]+e[i][k].v)  
            {  
                d[y][k]=d[x][k]+e[i][k].v;  
                if (!inq[y]) q.push(y),inq[y]=1;  
            }  
        }  
    }  
}  
int main()  
{  
        scanf("%d%d%d",&n,&m,&f);  
    for (int i=1;i<=m;i++)  
    {  
        int x,y,v;  
        scanf("%d%d%d",&x,&y,&v);  
        Addedge(0,x,y,v);  
        Addedge(1,y,x,v);  
    }  
    spfa(0);  
    spfa(1);  
    int ans=0;  
    for (int i=1;i<=n;i++)  
        ans=max(ans,d[i][0]+d[i][1]);  
    printf("%d\n",ans);  
    return 0;  
}
