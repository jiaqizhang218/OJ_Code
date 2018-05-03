#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<queue>  
#define mp(x,y,z) (make_pair(make_pair(x,y),z))  
#define N 6010  
using namespace std;  
int a[210];  
int to[N],nxt[N],pre[210],cnt,t[N],w[N];  
void ae(int ff,int tt,int TT,int ww)  
{  
    cnt++;  
    to[cnt]=tt;  
    nxt[cnt]=pre[ff];  
    pre[ff]=cnt;  
    t[cnt]=TT;  
    w[cnt]=ww;  
}  
int d[210][1<<13];  
bool vis[210][1<<13];  
priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int> >,greater<pair<pair<int,int>,int> > >q;  
int n;  
int dij()  
{  
    q.push(mp(0,1,0));  
    memset(d,0x3f,sizeof(d));  
    d[1][0]=0;  
    int i,j,s,x,y,z;  
    while(!q.empty())  
    {  
        s=q.top().first.first;  
        x=q.top().first.second;  
        y=q.top().second;  
        q.pop();  
        if(x==n) return s;  
        if(vis[x][y]) continue;  
        vis[x][y]=true;  
        y|=a[x];  
        for(i=pre[x];i;i=nxt[i])  
        {  
            j=to[i];  
            if((w[i]|y)!=y) continue;  
            if(d[j][y]>s+t[i])  
            {  
                d[j][y]=s+t[i];  
                q.push(mp(d[j][y],j,y));  
            }  
        }  
    }  
    return -1;  
}  
int main()  
{  
    int m,p,k;  
    scanf("%d%d%d%d",&n,&m,&p,&k);  
    int i,j,x,y,l,z,o,u;  
    for(i=1;i<=k;i++)  
    {  
        scanf("%d%d",&x,&y);  
        for(j=1;j<=y;j++)  
        {  
            scanf("%d",&z);  
            a[x]|=(1<<(z-1));  
        }  
    }  
    for(i=1;i<=m;i++)  
    {  
        scanf("%d%d%d%d",&x,&y,&z,&o);  
        u=0;  
        for(j=1;j<=o;j++)  
        {  
            scanf("%d",&l);  
            u|=(1<<(l-1));  
        }  
        ae(x,y,z,u);ae(y,x,z,u);  
    }  
    printf("%d\n",dij());  
}
