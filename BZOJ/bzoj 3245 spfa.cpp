#include<cstdio>
#include<cstring>
using namespace std;
int n,m,d,cnt;
int head[151],fromn[151][501],fromv[151][501],q[75001],v[75001];
double dis[151][501];
bool inq[151][501];
struct data{int to,next,v,l;}e[50001];
void insert(int a,int b,int v,int l)
{
	e[++cnt].to=b;e[cnt].v=v;e[cnt].l=l;
	e[cnt].next=head[a];head[a]=cnt;
}
void spfa()
{
	int t=0,w=1,i,v0,now;
	memset(dis,127,sizeof(dis));
	q[0]=0;v[0]=70;
	dis[0][70]=0;
	inq[0][70]=1;
	while(t!=w)
	{
		now=q[t]; v0=v[t++]; if(t==75001)t=0;
		for(i=head[now];i;i=e[i].next)
	    {
	    	if(!e[i].v&&(double)e[i].l/v0+dis[now][v0]<dis[e[i].to][v0])
	    	{
	    		dis[e[i].to][v0]=(double)e[i].l/v0+dis[now][v0];
	    		fromn[e[i].to][v0]=now;
	    		fromv[e[i].to][v0]=v0;
	    		if(!inq[e[i].to][v0]){
	    			inq[e[i].to][v0]=1;
		    		q[w]=e[i].to;
		    		v[w]=v0;
		    		w++;
		    		if(w==75001)w=0;
				}
	    	}
	    	if(e[i].v&&(double)e[i].l/e[i].v+dis[now][v0]<dis[e[i].to][e[i].v])
            {
            	dis[e[i].to][e[i].v]=(double)e[i].l/e[i].v+dis[now][v0];
    	        fromn[e[i].to][e[i].v]=now;
	    		fromv[e[i].to][e[i].v]=v0;
            	if(!inq[e[i].to][e[i].v]){
	           		inq[e[i].to][e[i].v]=1;
	            	q[w]=e[i].to;
		    		v[w]=e[i].v;
		    		w++;
		    		if(w==75001)w=0;
				}
            }
	    }
	    inq[now][v0]=0;
	}
}
void print(int x,int y)
{
	if(x!=0)print(fromn[x][y],fromv[x][y]);
	printf("%d",x);
	if(x!=d)printf(" ");
}
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=m;i++)
	{
		int a,b,v,l;
		scanf("%d%d%d%d",&a,&b,&v,&l);
		insert(a,b,v,l);
	}
	spfa();
	int ans;double mn=0x7fffffff;
	for(int i=0;i<=500;i++)
	{if(dis[d][i]<mn){ans=i;mn=dis[d][i];}}
	print(d,ans);
	return 0;
}
