#include<cstdio>
#include<iostream>
using namespace std;
struct data{
int to,next;
}e[50001],d[50001];
int head[10001];
int n,m,cnt,top;
int dfn[10001],low[10001],q[10001];
int scc,h[10001],belong[10001],hav[10001];
bool vis[10001],inq[10001];
int ans;

void dfs(int a)
{
	int now; 
	vis[a]=inq[a]=1;
	low[a]=dfn[a]=++cnt;
	q[++top]=a;
	for(int c = head[a] ; c ; c = e[c].next)
	{
		if(!vis[e[c].to])
		{
			dfs(e[c].to);
			low[a]=min(low[a],low[e[c].to]);
		}
		else if(inq[e[c].to])	low[a] = min(low[a],dfn[e[c].to]);
	}
	
	if(low[a]==dfn[a])
	{
	    scc++;				//	找到一个联通分量 
	    while(now!=a)
        {
            now=q[top--];
            inq[now]=0;  		// 出栈 同时记录 
            belong[now]=scc; //最后belong数组前n个都是任意scc
            ++hav[scc];  	//hav数组 scc存了几个数字  即这个连通分量的点的个数 					 
        }
	}
}

void rebuild()   //重建QAQ     这是不是就是传说中的缩点 
{
	cnt=0;
	for(int i=1;i<=n;i++)	
		for(int c = head[i] ; c ; c = e[c].next)
			if(belong[i]!=belong[e[c].to])   //不属于一个联通分量 
		    {
		    	d[++cnt].to=belong[e[c].to];
		    	d[cnt].next=h[belong[i]]; 		//建图 
		    	h[belong[i]]=cnt;
		    }	
}

void tarjan()
{
	for(int i=1;i<=n;i++)	if(!vis[i])	dfs(i);
    rebuild();
}

void work()
{
	for(int i=1;i<=scc;i++)
	   if(!h[i])	// 不存在以第i个联通分量出发的点    
	   {
	   	   if(ans)
	   	   {
	   	   	  ans=0;	return;
	   	   }
	   	   else ans=hav[i];
	   }
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
    {
    	int x,y;
    	scanf("%d%d",&x,&y);
    	e[i].to=y;
    	e[i].next=head[x];
    	head[x]=i;
    }
    tarjan();
    work();
    printf("%d",ans);
	return 0;
}
