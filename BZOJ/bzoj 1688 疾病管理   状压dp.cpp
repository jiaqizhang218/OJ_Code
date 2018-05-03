#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
const int N = 16; 
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int n,m,k,d,mi[N];
int f[1<<N];
int a[1003],pd[1<<N];
int main()
{
	n = read() , d = read() , k = read();
	mi[0] = 1;
	for(int i = 1; i <= d ; i++)
		mi[i] = mi[i-1] << 1;
	for(int i = 1; i <= n ; i++)
	{
		int x = read();
		for(int j = 1; j <= x ; j++)
				a[i] += mi[read()-1];
	}
	int tot = (1<<d) - 1;
	for(int i = 0 ; i <= tot ; i++)
	{
		int t = 0;
		for(int j = i ; j ; j >>= 1)
			if(j & 1)	t++;
		if(t <= k)	pd[i] = 1;
	}
	for(int i = 1 ; i <= n ; i++)
		for(int j = tot; j >= 0 ; j--)
			f[j|a[i]] = max(f[j|a[i]],f[j]+1);
	int ans = 0;
	for(int i = 0 ; i <= tot ; i++)
		if(pd[i])	ans = ans > f[i] ? ans : f[i];
	cout<<ans; 
}
