#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int inf = 0x3f3f3f3f;
const double eps = 1e-5;
const int maxn = 50005;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
int head[maxn],to[maxn<<3],c[maxn<<3],next[maxn<<3],q[maxn],d[maxn];
int num=1,n,m,s,t,ans,tot;
inline void addedge(int x,int y,int t)
{
	to[++num] = y; c[num] = t , next[num] = head[x] , head[x] = num;
	to[++num] = x; c[num] = 0 , next[num] = head[y] , head[y] = num;
 }
bool bfs()
{
	memset(d,-1,sizeof d);
	int l = 0 , r = 1; 
	q[l] = s , d[s] = 0;
	while(l != r)
	{
		int x = q[l++]; if(l == 50000) l = 0;
		for(int i = head[x] ; i ; i = next[i])
		{
			if(c[i] &&  d[to[i]] == -1)
			{
				d[to[i]] = d[x] + 1;
				q[r++] = to[i];
				if(r == 50000) r = 0;
			}
		}
	}
	return d[t] == -1 ? false : true; 
}
inline int dfs(int x,int f)
{
	if(x == t || f == 0)  return f;
	int w,used = 0;
	for(int i = head[x] ; i ; i = next[i])
		if(c[i] && d[to[i]] == d[x] + 1 && (w = dfs(to[i],min(c[i],f))))
		{
			c[i] -= w;
			c[i^1] += w;
			f -= w; 
			used += w;
			if(f == 0) return used;
		 }
	if(f) d[x] = -1;
	return used; 
 } 
inline int cal(int x,int y)
{
	return (x-1)*n+y;
}
int main()  
{  
    scanf("%d%d",&n,&m);  
    num=1;s=0;t=5*n*m;tot=n*m;  
    for (int i=1;i<=n;i++)  
      for (int j=1;j<=m;j++)  
      {  
        int x;  
        scanf("%d",&x);  
        addedge(s,cal(i,j),x);ans+=x;  
      }  
    for (int i=1;i<=n;i++)  
      for (int j=1;j<=m;j++)  
      {  
        int x;  
        scanf("%d",&x);  
        addedge(cal(i,j),t,x);ans+=x;  
      }  
    for (int i=1;i<n;i++)  
      for (int j=1;j<=m;j++)  
      {  
        int x;  
        scanf("%d",&x);  
        tot++;addedge(s,tot,x);  
        addedge(tot,cal(i,j),inf);addedge(tot,cal(i+1,j),inf);  
        ans+=x;  
      }  
    for (int i=1;i<n;i++)  
      for (int j=1;j<=m;j++)  
      {  
        int x;  
        scanf("%d",&x);  
        tot++;addedge(tot,t,x);  
        addedge(cal(i,j),tot,inf);addedge(cal(i+1,j),tot,inf);  
        ans+=x;  
      }  
    for (int i=1;i<=n;i++)  
      for (int j=1;j<m;j++)  
      {  
        int x;  
        scanf("%d",&x);  
        tot++;addedge(s,tot,x);  
        addedge(tot,cal(i,j),inf);addedge(tot,cal(i,j+1),inf);  
        ans+=x;  
      }  
    for (int i=1;i<=n;i++)  
      for (int j=1;j<m;j++)  
      {  
        int x;  
        scanf("%d",&x);  
        tot++;addedge(tot,t,x);  
        addedge(cal(i,j),tot,inf);addedge(cal(i,j+1),tot,inf);  
        ans+=x;  
      }  
    while (bfs()) ans-=dfs(s,inf);
    printf("%d\n",ans);  
    return 0;  
} 
