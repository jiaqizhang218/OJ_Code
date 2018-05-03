#include<bits/stdc++.h>
typedef long long LL;
const int N = 100005;
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
int fa[N],n,m;
bool vis[N];
inline int gf(int x)
{
	return x == fa[x] ? x : fa[x] = gf(fa[x]);
}
int main()
{
	n = read() , m = read();
	for(int i = 1 ; i <= n ; i++)	fa[i] = i;
	for(int i = 1 ; i <= m ; i++)	
	{
		int x = read() , y = read() , p = gf(x) , q = gf(y);
		if(p != q)
		{
			fa[p] = q;
			vis[q] |= vis[p];
		}
		else vis[p] = 1;
	}
	for(int i = 1 ; i <= n ; i++)
		if(!vis[gf(i)])
		{
			puts("NIE");
			return 0;
		}
	puts("TAK");
	return 0;
}


