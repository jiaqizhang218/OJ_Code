#include<bits/stdc++.h> 
#define inf 1000000000
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,K,cnt;
int last[5005],d[5005][2];
int q[10005],f[10005],ans[1000005];
bool lk[5005];
struct data{int to,next;}e[10005];
struct query{int x,y,d,id;}que[1000005];
bool operator<(query a,query b)
{
    return a.x<b.x;
}
void insert(int u,int v)
{
    e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}
void bfs(int x)
{
    memset(d,-1,sizeof(d));
    int head=0,tail=1;
    q[0]=x;f[0]=0;d[x][0]=0;
    while(head!=tail)
    {
		int now=q[head],flag=f[head];head++;
		int to=flag^1;
		for(int i=last[now];i;i=e[i].next)
		{
			if(d[e[i].to][to]==-1)
			{
				d[e[i].to][to]=d[now][flag]+1;
				q[tail]=e[i].to;f[tail]=to;tail++;
			}
		}
    }
}
int main()
{
    n=read();m=read();K=read();
    for(int i=1;i<=m;i++)
    {
		int u=read(),v=read();
		insert(u,v);
		insert(v,u);
		lk[u]=lk[v]=1;
    }
    for(int i=1;i<=K;i++)
		que[i].id=i,que[i].x=read(),que[i].y=read(),que[i].d=read();
    sort(que+1,que+K+1);
    int now=1;
    for(int k=1;k<=K;k=now+1,now=k)
    {
		while(que[now+1].x==que[k].x&&now<K)now++;
		bfs(que[now].x);
		for(int t=k;t<=now;t++)
		{
			int x=que[t].x,y=que[t].y,v=que[t].d,id=que[t].id;
			if(x==y&&!lk[x])continue;
			int dis=d[y][v&1];
			if(dis!=-1&&v>=dis)ans[id]=1;
		}
    }
    for(int i=1;i<=K;i++)
		if(ans[i])puts("TAK");
		else puts("NIE");
    return 0;
}
