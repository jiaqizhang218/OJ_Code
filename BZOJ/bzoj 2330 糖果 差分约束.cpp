#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int MAXN = 100005;
using namespace std;
int n,k,cnt,q[MAXN+5],cir[MAXN],dis[MAXN],head[MAXN];
LL ans;
bool inq[MAXN];
struct data{
	int to,next,v;
}e[MAXN<<2];
inline void insert(int u,int v,int w)
{
	e[++cnt].to = v , e[cnt].v = w , e[cnt].next = head[u] , head[u] = cnt;
}
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
bool spfa()
{
     int t=0,w=1,now;
     q[0]=0;inq[0]=1;cir[0]=1;
     while(t!=w)
     {
               now=q[t];t++;if(t==MAXN)t=0;
               for(int i=head[now];i;i=e[i].next)
               {
                       if(dis[now]+e[i].v>dis[e[i].to])
                       {
                           dis[e[i].to]=dis[now]+e[i].v;
                           if(++cir[e[i].to]>=n)return 0;
                           if(!inq[e[i].to])
                           {
                               inq[e[i].to]=1;q[w++]=e[i].to;
                               if(w==MAXN)w=0;
                           }
                       }
               }
     inq[now]=0;
     }
     return 1;
 }
int main()
{
	n = read() , k = read();
	while(k--)
	{
		int x = read() , a = read() , b = read();
		switch(x)
		{
			case 1:insert(a,b,0);insert(b,a,0);break;
			case 2:if(a==b){printf("-1");return 0;}insert(a,b,1);break;
			case 3:insert(b,a,0);break;
			case 4:if(a==b){printf("-1");return 0;}insert(b,a,1);break;
			case 5:insert(a,b,0);break;
		}
	}
	for(int i = n ; i > 0 ; i--)	insert(0,i,1);
	if(!spfa())
	{
		printf("-1");return 0;
	}
	for(int i = 1 ; i <= n ; i++)
		ans += dis[i];
	printf("%lld",ans);
}
