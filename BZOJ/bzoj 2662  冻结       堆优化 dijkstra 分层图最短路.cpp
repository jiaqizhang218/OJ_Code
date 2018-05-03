#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<iostream>  
#include<cmath>  
#include<algorithm>  
#include<queue>  
#include<set>  
#include<map>  
#include<vector>  
#include<complex>  
#define pa pair<int,int>  
using namespace std;  
int dis[55][55],d[5555][3],head[55],mark[55][55];  
int n,m,K,tot=0;  
priority_queue<pa,vector<pa>,greater<pa> >q;  
void insert(int x,int y,int v)  
{  
    d[++tot][0]=y; d[tot][1]=v; d[tot][2]=head[x]; head[x]=tot;  
}  
void spfa()  
{  
    memset(dis,127,sizeof(dis)); dis[1][0]=0;  
    q.push(make_pair(0,55));   
    while(!q.empty())  
    {  
        int x=q.top().second/55,u=q.top().second%55; q.pop();  
        if(mark[x][u]) continue; mark[x][u]=1;  
        for(int i=head[x]; i; i=d[i][2])  
        {  
            if(dis[d[i][0]][u]>dis[x][u]+d[i][1])  
            {  
                dis[d[i][0]][u]=dis[x][u]+d[i][1];  
                q.push(make_pair(dis[d[i][0]][u],d[i][0]*55+u));  
            }  
            if(u<K && dis[d[i][0]][u+1]>dis[x][u]+d[i][1]/2)  
            {  
                dis[d[i][0]][u+1]=dis[x][u]+d[i][1]/2;  
                q.push(make_pair(dis[d[i][0]][u+1],d[i][0]*55+u+1));  
            }  
        }  
    }  
}  
int main()  
{  
    scanf("%d%d%d",&n,&m,&K);  
    for(int i=1; i<=m; i++)  
    {  
        int x,y,v; scanf("%d%d%d",&x,&y,&v);  
        insert(x,y,v);  
        insert(y,x,v);  
    }  
    spfa();  
    int ans=211111111;  
    for(int i=0; i<=K; i++) ans=min(ans,dis[n][i]);  
    printf("%d",ans);  
    return 0;  
}
