#include<bits/stdc++.h>
#define T 101
#define inf 0x7fffffff
using namespace std;
int sc[51];
int n,tot,cnt=1,ans,head[105],h[105];
struct data{int to,next,v;}e[50001];
void ins(int u,int v,int w)
{cnt++;e[cnt].to=v;e[cnt].v=w;e[cnt].next=head[u];head[u]=cnt;}
void insert(int u,int v,int w)
{ins(u,v,w);ins(v,u,0);}
bool bfs()
{
     int q[105],t=0,w=1,i,now;
     memset(h,-1,sizeof(h));
     q[0]=h[0]=0;
     while(t!=w)
     {
            now=q[t];t++;if(t==101)t=0;
            i=head[now];
            while(i)
            {
                  if(e[i].v&&h[e[i].to]<0)
                        {h[e[i].to]=h[now]+1;q[w++]=e[i].to;if(w==101)w=0;}
                  i=e[i].next;
             }
     }
     if(h[T]==-1)return 0;
     return 1;
     }
int dfs(int x,int f)
{
    if(x==T)return f;
    int i=head[x],w,used=0;
    while(i)
    {
            if(e[i].v&&h[e[i].to]==h[x]+1)
            {
                w=f-used;
                w=dfs(e[i].to,min(w,e[i].v));   
                e[i].v-=w;
                e[i^1].v+=w;
                used+=w;
                if(used==f)return f;                      
                }
                i=e[i].next;
            }
    if(!used)h[x]=-1;
    return used;
    }
void dinic(){while(bfs())ans+=dfs(0,inf);}
int main()
{
	int test;scanf("%d",&test);
	while(test--)
	{
		tot=ans=0;cnt=1;
		memset(head,0,sizeof(head));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
		    scanf("%d",&sc[i]);
		    if(sc[i])
		        insert(i+n,T,1);//如果是在校学生，则有床位 
        }
		int x;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if((sc[i]&&!x)||!sc[i]) 
			{
		    	insert(0,i,1);//不回家或者外校的需要床 
		    	tot++;
		    }
		}
		for(int i=1;i<=n;i++)
		   for(int j=1;j<=n;j++)
           {
           	   scanf("%d",&x);
           	   if(x||i==j)insert(i,j+n,1);//可以睡的床 
           }
        dinic();
        if(ans==tot)puts("^_^");
        else puts("T_T");
	}
    return 0;
}
