#include<bits/stdc++.h>
typedef long long LL;
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
int n, K, m, ans;
int fa[10005];
struct data{int x,y,c1,c2;}e[20005];
inline int getfa(int x)
{
	return fa[x] == x ? x : fa[x] = getfa(fa[x]);
 } 
bool jud(int x)
{
	for(register int i = 1 ; i <= n ; i++)	fa[i] = i;
	int cnt = 0;
	for(int i = 1 ; i <= m ; i++)
	{
		if(e[i].c1 > x)	continue;
		int p = getfa(e[i].x) , q = getfa(e[i].y);
		if(p != q)
		fa[p] = q , cnt++;
	}
	if(cnt < K) return false;
	for(int i = 1; i <= m ; i++)
	{
		if(e[i].c2 > x) continue;
		int p = getfa(e[i].x) , q = getfa(e[i].y);
		if(p != q)
		fa[p] = q , cnt++;
	}
	if(cnt != n-1) return false;
	else return true;
}
int main()
{
	n = read() , K = read() , m = read();
	for(int i = 1 ; i < m ; i++)
		e[i].x = read() , e[i].y = read() , e[i].c1 = read() , e[i].c2 = read();
	int l = 1 , r = 30000;
	while ( l <= r)
	{
		int mid = (l + r) >> 1;
		if(jud(mid)) ans = mid , r = mid - 1;
		else l = mid + 1;
	}
	printf("%d",ans);
}
