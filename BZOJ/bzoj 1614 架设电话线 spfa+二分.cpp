#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
using namespace std;
struct data{
	int to,nxt,v;
}e[maxn<<1];
int n,p,k,cnt,head[maxn],dis[maxn],q[maxn],vis[maxn],ans = -1;
void insert(int u,int v,int w)
{
	e[++cnt].to = v ; e[cnt].nxt = head[u] ; head[u] = cnt ; e[cnt].v = w; 
	e[++cnt].to = u ; e[cnt].nxt = head[v] ; head[v] = cnt ; e[cnt].v = w;
 }
bool spfa(int x)
{
	memset(dis,127/3,sizeof(dis));
	int t = 0 , w = 1 , i , now , s ;
	dis[1] = 0; q[t] = 1; vis[1] = 1;
	while(t != w)
	{
		now = q[t++] ; if(t == 1001) t = 0;
		for(int i = head[now] ; i ; i = e[i].nxt)
		{
			if(e[i].v > x)  s = dis[now] + 1;	//权值比二分出的权值的大 就多一 
			else s = dis[now];
			if( s < dis[e[i].to])
			{
					dis[e[i].to] = s;
					if(!vis[e[i].to])
					{
						q[w++] = e[i].to;
						vis[e[i].to] = 1;
						if(w == 1001) w = 0;
					}
			 } 
		 } 
		 vis[now] = 0;
	}
	if(dis[n] <= k) return true;//比mid大的边比k少 才能更新答案 
	else return false;
 } 
 
 int main()
 {
 	scanf("%d%d%d",&n,&p,&k);
 	for(int i = 1 ; i <= p ; i++)
 	{
 		int u,v,w;
 		scanf("%d%d%d",&u,&v,&w);
 		insert(u,v,w);
	 }
	int l = 0 , r = 1e6;
	while (l <= r)
	{
			int mid = (l + r) >> 1;
			if(spfa(mid))
			{
				ans = mid  ; r = mid-1;  //切记正确的时候才能更新答案 
			}
			else 
				  l = mid+1;
	}
	printf("%d",ans);
 }
