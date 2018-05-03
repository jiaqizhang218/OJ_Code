#include<set>
#include<map>
#include<ctime>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define inf 1000000000
#define pa pair<int,int>
#define ll long long 
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int mx,n,K,tot,cnt=1,dia;
int last[100005];
int s1[100005],s2[100005];
struct edge{
    int to,next,v;       
}e[200005];
void insert(int u,int v)
{
    e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;e[cnt].v=1;
    e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;e[cnt].v=1;
}
int dfs(int x,int fa)
{
    int mx1=0,mx2=0;
    for(int i=last[x];i;i=e[i].next)
        if(e[i].to!=fa)
        {
            int v=e[i].v+dfs(e[i].to,x);//dfs返回回来的是走到最远的地方的值 
            if(v>mx1)	mx2=mx1,mx1=v,s2[x]=s1[x],s1[x]=i;
            else if(v>mx2)	mx2=v,s2[x]=i;
        }
    if(mx1+mx2>dia)dia=mx1+mx2,mx=x; 	//最远+次远即为最长链 
    return mx1;
}
int main()
{
    n=read();K=read();tot=2*(n-1);			//每条边都要走两次 
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        insert(u,v);
    }
    dfs(1,0);tot=tot-dia+1; 
    if(K==2)
    {
        dia=0;
        for(int i=s1[mx];i;i=s1[e[i].to])	e[i].v=e[i^1].v=-1;	//就是把这两个点中间的两条有向边的权值设为-1 
        for(int i=s2[mx];i;i=s1[e[i].to])	e[i].v=e[i^1].v=-1;		//从根向两边出发 
        dfs(1,0);tot=tot-dia+1;
    }
    printf("%d\n",tot);
    return 0;
}
