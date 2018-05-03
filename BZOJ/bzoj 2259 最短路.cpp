#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#define N 3000030
#define pa pair<int,int>
using namespace std;
int tot,n,point[N],v[N],c[N],dis[N],nxt[N],pre[N],to[N];
void add(int x,int y,int z)
{
    tot++; nxt[tot]=point[x]; point[x]=tot; v[tot]=y; c[tot]=z;
//  cout<<x<<" "<<y<<" "<<z<<endl;
}
void dijkstra()
{
    for (int i=1;i<=n+1;i++) dis[i]=1e9+3;
    dis[1]=0; 
    priority_queue<pa,vector<pa>,greater<pa> > p;
    p.push(make_pair(0,1));
    while (!p.empty()) {
        int now=p.top().second; p.pop();
        for (int i=point[now];i;i=nxt[i])
         if (dis[v[i]]>dis[now]+c[i]) {
            dis[v[i]]=dis[now]+c[i];
            p.push(make_pair(dis[v[i]],v[i]));
         }
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        int x;  scanf("%d",&x);
        for (int j=i+x+1;j<=n&&!to[j];j++) 
         to[j]=1,add(j,j+1,1);
        for (int j=i+1;j<=min(i+x+1,n)&&!pre[j];j++)
         pre[j]=1,add(j,j-1,1);
        if (i+x+1<=n+1) add(i,i+x+1,0);
        else add(i,n+1,i+x-n);
    }
    dijkstra();
    printf("%d\n",dis[n+1]);
}
