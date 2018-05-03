#include <iostream>  
#include <algorithm>  
#include <cstring>  
#include <cstdio>  
#include <cmath>  
using namespace std;  
#define maxn 844444  
#define INF 1000000000  
inline int getint()  
{  
    int x=0,f=1;char ch=getchar();  
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  
    return x*f;  
}  
int n,m,d;  
int st,ed,en;  
int first[maxn],dis[maxn],q[maxn];  
struct node  
{  
    int v,c,next;  
}e[maxn];  
int add(int a,int b,int c)  
{  
    en++;  
    e[en].v=b;  
    e[en].c=c;  
    e[en].next=first[a];  
    first[a]=en;  
   
    en++;  
    e[en].v=a;  
    e[en].c=0;  
    e[en].next=first[b];  
    first[b]=en;  
}  
struct node2  
{  
    int x,y,v,id;  
}a[maxn];  
bool cmp(node2 aa,node2 bb)  
{  
    return aa.v<bb.v;  
}  
bool bfs()  
{  
    memset(dis,-1,sizeof(dis));  
    int head=1;  
    int tail=1;  
    tail++;  
    q[tail]=st;  
    dis[st]=0;  
    while(head<tail)  
    {  
        head++;  
        int u=q[head];  
        for(int i=first[u];i!=-1;i=e[i].next)  
        {  
            if(e[i].c==0) continue;  
            if(dis[e[i].v]!=-1) continue;  
            dis[e[i].v]=dis[u]+1;  
            if(ed==e[i].v) return true;  
            tail++;  
            q[tail]=e[i].v;  
        }  
    }  
    return false;  
}  
int dfs(int x,int mx)  
{  
    int flow=0,f,ret=0;  
    if(x==ed||mx==0) return mx;  
    for(int i=first[x];i!=-1;i=e[i].next)  
    {  
        if(e[i].c==0) continue;  
        if(dis[e[i].v]!=dis[x]+1) continue;  
        f=dfs(e[i].v,min(mx,e[i].c));  
        if(f)  
        {  
            e[i].c-=f;  
            e[i^1].c+=f;  
            flow+=f;  
            mx-=f;  
            if(!mx) break;  
        }  
    }  
    if(flow==0) dis[x]=-1;  
    return flow;  
}  
   
void init()  
{  
    en=-1;  
    memset(first,-1,sizeof(first));  
}  
int dinic()  
{  
    int tmp=0,maxflow=0;  
    while(bfs())  
    {  
        while(tmp=dfs(st,INF)) maxflow+=tmp;  
    }  
    return maxflow;  
}  
int main()  
{  
    n=getint();m=getint();d=getint();  
    for(int i=1;i<=m;i++)  
        a[i].x=getint(),a[i].y=getint(),a[i].v=getint(),a[i].id=i;  
    init();  
    sort(a+1,a+m+1,cmp);  
    for(int i=1;i<=m;i++)  
    {  
        if(a[i].id==d)  
        {  
            st=a[i].x;ed=a[i].y;  
            d=i;  
            break;  
        }  
    }  
    for(int i=1;i<=m;i++)  
    {  
        if(i==d) continue;  
        if(a[i].v>a[d].v) break;  
        add(a[i].x,a[i].y,a[d].v+1-a[i].v);  
        add(a[i].y,a[i].x,a[d].v+1-a[i].v);  
    }  
    printf("%d",dinic());  
    return 0;  
} 
