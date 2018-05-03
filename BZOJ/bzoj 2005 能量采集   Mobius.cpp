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
LL n , m , f[100005] , ans;
int main()
{
	n = read() , m = read();
	for(int g = min(n,m) ; g ; g--)
	{
		f[g] = (n/g) * (m/g);
		for(int d = g << 1 ; d <= min(n,m) ; d += g) f[g] -= f[d];
	}
	for(int g = min(n,m);g;g--)	ans+=f[g] * (2*g-1);
	printf("%lld",ans); 
}


