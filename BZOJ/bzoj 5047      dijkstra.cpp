#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
//���������sʱ��ʹ��װ�ã���ô��Ҫ����((a_i*s+b_i) mod c_i)+d_i��λʱ�������ɴ���
//��һ�а���4��������n,m,s,e(2<=n<=100000,1<=m<=50,1<=s<=2000,1<=e<=200000)
//�ֱ��ʾ����ĸ������ռ䴫��װ�õ�����������ǰ��ʱ���Լ��ռ䴫��װ�õĸ�����
//������m�У�ÿ��4��������a_i,b_i,c_i,d_i(1<=a_i,b_i,c_i,d_i<=2000)����������ÿ��װ�õĲ�����
//������e�У�ÿ��3��������u_i,v_i,w_i(1<=u_i,v_i<=n,u_i!=v_i,1<=w_i<=m)
//��ʾ������u_i����ʹ�õ�w_i��װ�õ����͵�����v_i��
struct data{
	int ai,bi,ci,di;
}mac[55];
struct edge{
	int to,next,k;
}e[200005];
bool vis[100005];
int n,m,s,ee,head[200005],cnt,dis[100005],pre[2005][55],minn[55];
inline void AE(int u,int v,int c)
{
	e[++cnt].to=v; e[cnt].k=c; e[cnt].next=head[u]; head[u]=cnt;
} 
inline void init()
{
	for(int x=1;x<=m;x++)
	{
		int xxx=99999999;
		for(int i=0;i<=mac[x].ci;i++)
		{
			pre[i][x]=(mac[x].ai*i+mac[x].bi)%mac[x].ci+mac[x].di;
			if(pre[i][x]<xxx)	
			{
				xxx=pre[i][x],minn[x]=i;
			}
		}
	}
}
priority_queue<pair<int,int>,vector<pair<int,int> > , greater<pair<int,int> > > q; 
inline void dijkstra()
{
	memset(dis,-1,sizeof dis);
	q.push(make_pair(1,s));
	while(!q.empty())
	{
		int now = q.top().second , nowdis = q.top().first; q.pop();
		 for(int i = head[now] ; i ; i = e[i].next)
		 	{
		 		int kin = e[i].k,v = e[i].to;
		 		if(dis[v]!=-1)	continue;
		 		if(now%mac[kin].ci<minn[kin])
		 		{
		 			int dist=minn[kin]-(now%mac[kin].ci);
		 			if(dist+pre[minn[kin]][kin]<pre[now%mac[kin].ci][kin])
		 			{
		 				dis[v]=dis[now]+dist+pre[minn[kin]][kin];
		 				
		 				q.push(make_pair(dis[v],v));
					 }
					 else
					 {
					 	dis[v]=pre[now%mac[kin].ci][kin]+dis[now];
					 	q.push(make_pair(dis[v],v));
					 }
				 }
				 else if(now%mac[kin].ci>minn[kin])
				 {
				 	int dist=minn[kin]+mac[kin].ci-(now%mac[kin].ci);
				 	if(dist+pre[minn[kin]][kin]<pre[now%mac[kin].ci][kin])
				 	{
				 		dis[v]=dis[now]+dist+pre[minn[kin]][kin];
				 		q.push(make_pair(dis[v],v));
					 }
					 else 
					 {
					 	dis[v]=pre[now%mac[kin].ci][kin]+dis[now];
					 	q.push(make_pair(dis[v],v));
					 }
				 }
				 else {
				 	dis[v]=pre[now%mac[kin].ci][kin]+dis[now];
				 	q.push(make_pair(dis[v],v));
				 }
			 }
	}
}
int main()
{
	n=read(),m=read(),s=read(),ee=read();
	for(int i=1;i<=m;i++)
		mac[i].ai=read(),mac[i].bi=read(),mac[i].ci=read(),mac[i].di=read();
	for(int i=1;i<=ee;i++)
		{int x=read(),y=read(),z=read();AE(x,y,z);}
	init(); 
	dijkstra();
	for(int i=2;i<=n;i++)
		cout<<dis[i]<<" ";
	return 0;	
}
