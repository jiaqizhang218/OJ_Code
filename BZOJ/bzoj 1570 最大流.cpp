#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#define M 5010  
#define S 0  
#define T (M-1)  
#define INF 0x3f3f3f3f  
using namespace std;  
struct edge{  
    int x,y,z;  
}edges[M];  
int n,m,t;  
namespace Max_Flow{  
    struct abcd{  
        int to,f,next;  
    }table[1001001];  
    int head[M],tot=1;  
    int dpt[M];  
    void Add(int x,int y,int z)  
    {  
        table[++tot].to=y;  
        table[tot].f=z;  
        table[tot].next=head[x];  
        head[x]=tot;  
    }  
    void Link(int x,int y,int z)  
    {  
        Add(x,y,z);  
        Add(y,x,0);  
    }  
    bool BFS()  
    {  
        static int q[M];  
        int i,r=0,h=0;  
        memset(dpt,-1,sizeof dpt);  
        dpt[S]=1;q[++r]=S;  
        while(r!=h)  
        {  
            int x=q[++h];  
            for(i=head[x];i;i=table[i].next)  
                if(table[i].f&&!~dpt[table[i].to])  
                {  
                    dpt[table[i].to]=dpt[x]+1;  
                    q[++r]=table[i].to;  
                    if(table[i].to==T)  
                        return true;  
                }  
        }  
        return false;  
    }  
    int Dinic(int x,int flow)  
    {  
        int i,left=flow;  
        if(x==T) return flow;  
        for(i=head[x];i&&left;i=table[i].next)  
            if(table[i].f&&dpt[table[i].to]==dpt[x]+1)  
            {  
                int temp=Dinic(table[i].to,min(left,table[i].f) );  
                left-=temp;  
                table[i].f-=temp;  
                table[i^1].f+=temp;  
            }  
        if(left) dpt[x]=-1;  
        return flow-left;  
    }  
}  
int main()  
{  
    using namespace Max_Flow;  
    int i,j,x,y,z;  
    cin>>n>>m>>t;  
    for(i=1;i<=m;i++)  
    {  
        scanf("%d%d%d",&x,&y,&z);  
        edges[i].x=x;  
        edges[i].y=y;  
        edges[i].z=z;  
    }  
    int temp=0;  
    Link(S,1,t);  
    for(i=1;i<=n+t;i++)  
    {  
        for(j=1;j<=m;j++)  
            Link(i*n-n+edges[j].x,i*n+edges[j].y,edges[j].z);  
        for(j=1;j<=n;j++)  
            Link(i*n-n+j,i*n+j,INF);  
        Link(i*n+n,T,INF);  
        while( BFS() )  
            temp+=Dinic(S,INF);  
        if(temp==t)  
            return cout<<i<<endl,0;  
    }  
    return 0;  
} 
