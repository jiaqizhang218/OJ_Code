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
int n,sum,ans;
bitset<2000000>a;
int main()
{
	n = read();
	a[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		int x = read();
		a = a ^ (a << x);
	}
	for(int i = 1 ; i <= 2000000; i++)
		if(a[i]) ans^=i;
	printf("%d",ans);
}

