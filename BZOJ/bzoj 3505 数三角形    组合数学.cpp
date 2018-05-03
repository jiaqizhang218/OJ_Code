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
inline int gcd(int x,int y)
{
	return y ? gcd(y,x%y) : x;
}
int n,m;
LL c[1005005][4];
LL ans,tmp;
inline void getc()
{
	c[0][0] = 1;
	for(int i = 1 ; i <= n * m ; i++)
	{
		c[i][0] = 1;
		for(int j = 1 ; j <= 3 ; j++)
			c[i][j] = c[i-1][j-1] + c[i-1][j];
	}
}
inline void solve()
{
	ans = c[n*m][3];
	ans -= n * c[m][3];
	ans -= m * c[n][3];
	for(int i = 1 ; i < n ; i++)
		for(int j = 1 ; j < m ; j++)
		{
			tmp = gcd(i,j)+1;
			if(tmp > 2)
				ans -= (tmp - 2) * 2 * (n-i) * (m-j);
		}
}
int main()
{
	n = read() + 1 , m = read() + 1;
	getc();
	solve();
	printf("%lld",ans);
	return 0;
}
