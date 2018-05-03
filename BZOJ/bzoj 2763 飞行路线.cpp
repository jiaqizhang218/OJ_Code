#include<bits/stdc++.h>
#define ll long long
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std;
int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x * f;
}
struct Node
{
    int dis,u;
    bool operator<(const Node x)const
    {
        return dis>x.dis;
    }
};
int n,m,k,s,t;
int cnt,to[3000000],nxt[3000000],c[3000000],head[1000000],dis[1000000];
bool check[1000000];
priority_queue <Node> q;
void add(int u,int v,int w)
{
	to[++cnt] = v; nxt[cnt] = head[u] ; head[u] = cnt; c[cnt] = w;
}
int dijkstra(int s,int t)
{
	memset(dis,127/3,sizeof(dis));
	dis[s] = 0; q.push((Node){0,s});
	while(!q.empty())
	{
		Node now = q.top(); q.pop();
		if(check[now.u]) continue;
		check[now.u] = true;
		for(int temp = head[now.u];temp;temp = nxt[temp])
		if (dis[now.u]+c[temp]<dis[to[temp]])
            {
                dis[to[temp]]=dis[now.u]+c[temp];
                q.push((Node){dis[to[temp]],to[temp]});
            }
	}
	int ans=INF;
    for (int i=0;i<=k;i++)
        ans=min(ans,dis[i*n+t]);//分了k层 找到每一层的最小值 
    return ans;
}

int main()
{
	n =read(),m=read(),k=read(),s=read()+1,t=read()+1;
	for(int i = 1 ; i <= m ; i++)
	{
		int x =  read()+1, y = read()+1,z = read();
		for(int j = 0 ; j <= k ; j++)
		{
			add(j*n+x,j*n+y,z);//建立k层图
			add(j*n+y,j*n+x,z); 
			if(j < k)
				add(j*n+x , (j + 1) * n + y , 0),
				add(j*n+y , (j + 1) * n + x , 0);			
		}	
	}
	printf("%d\n",dijkstra(s,t));
	return 0;	
}

