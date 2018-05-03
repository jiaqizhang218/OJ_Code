#include<bits/stdc++.h>
using namespace std;
const int maxn = 50000 + 5;
int n,q,a[maxn],x,y;
int f[maxn][20],h[maxn][20];
void init_rmq()
{
	for(int j = 1 ; j < 20 ; j++)
	for(int i = 1 ; i <= n ; i++)
	{
		if(i+(1<<(j-1))<=n)
		{
			f[i][j] = max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			h[i][j] = min(h[i][j-1],h[i+(1<<(j-1))][j-1]);
		}
	}
}

int query_rmq(int l,int r)
{
	int k = log(r-l+1) / log(2);
	return max(f[l][k],f[r-(1<<k)+1][k])-min(h[l][k],h[r-(1<<k)+1][k]);
}

void init()
{
	scanf("%d%d",&n,&q);
	for(int i = 1 ; i <= n ; i++)
		scanf("%d",&a[i]),h[i][0]=f[i][0]=a[i];
	init_rmq();
	for(int i = 1 ; i <= q ; i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",query_rmq(x,y));
	}
 } 
 
 int main()
 {
 	init();
 }
