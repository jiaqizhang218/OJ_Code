#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 1000 + 5;
int n,k,cnt,f[maxn];
int x[maxn],y[maxn];
struct Point{
	int x,y;
	double v;
	bool operator < (const Point& rhs)const {
		return v<rhs.v;
	}
}e[maxn*maxn];
int findfather(int x)
{
	return x == f[x] ? x :f[x] = findfather(f[x]);
}
void insert(int a,int b)
{
	e[++cnt].x = a;
	e[cnt].y = b;
	e[cnt].v = hypot(x[a]-x[b],y[a]-y[b]);
}
void init()
{
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= n ; i++)
		scanf("%d%d",&x[i],&y[i]),f[i]=i;
		
	for(int i = 1 ; i <= n ; i++)
		for(int j = i+1 ; j <= n ; j++)
			insert(i,j);
	sort(e+1,e+cnt+1);
}
int main()
{
	ios::sync_with_stdio(false);
	init();
	for(int i = 1 ; i <= cnt ; i++)
	{
		int u1 = findfather(e[i].x); int v1 = findfather(e[i].y);
		if(u1!=v1)
		{
			if(n > k)
			{
				n--;
				f[u1] = v1;
			}
			else
			{
				printf("%.2lf",e[i].v); return 0 ;
			}
		}
	}
	return 0;
}
