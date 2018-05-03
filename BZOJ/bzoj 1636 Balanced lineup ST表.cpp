#include<bits/stdc++.h>
using namespace std;
const int maxn = 50000 + 5;
int x,y,q,n,a[maxn];
int g[maxn][20],f[maxn][20];

void init_query ()
{
	for(int j = 1 ; j <= 20 ; j++)
		for(int i = 1 ; i <= n ; i++)
			if(i + (1<<j) - 1 <= n)
			{
				f[i][j] = max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
				g[i][j] = min(g[i][j-1],g[i+(1<<(j-1))][j-1]);
			}
}

int query_rmq(int l ,int r)
{
	int k = log(r-l+1) / log (2);
	return max(f[l][k],f[r-(1<<k)+1][k])-min(g[l][k],g[r-(1<<k)+1][k]);
}
void init()
{
	scanf("%d%d",&n,&q);
	for(int i = 1 ; i <= n ; i++)
	scanf("%d",&a[i]),f[i][0] = g[i][0] = a[i];
	init_query();
	for(int i = 1 ; i <= q ; i++)
	scanf("%d%d",&x,&y),printf("%d\n",query_rmq(x,y));
	
}
int main()
{
	init();
 } 
