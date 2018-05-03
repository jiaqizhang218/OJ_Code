#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int MAXN = 1e7 + 5;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int a[MAXN]; 
int main()
{
	int n = read() , k ;
	if(n % 6 != 2 && n % 6 != 3)
	{
		for(int i = 1 ; i <= n ; ++i)	if(!(i&1)) a[++a[0]] = i;
		for(int i = 1 ; i <= n ; ++i)	if(i&1)	a[++a[0]] = i; 
	}
	else if(n % 6 == 2)
	{
		int k = n >> 1;
		for(int i = k ; i <= n ; i += 2)	a[++a[0]] = i;
		for(int i = k % 2 ? 1 : 2 ; i <= k - 2; i += 2)	a[++a[0]] = i;
		for(int i = k + 3 ; i <= n ; i += 2)	a[++a[0]] = i;
		for(int i = k % 2 ? 2 : 1 ; i <= k + 1 ; i += 2)	a[++a[0]] = i;
	}
	else if(n % 6 == 3)
	{
		int k = n >> 1;
		for(int i = k ; i < n ; i += 2)	a[++a[0]] = i;
		for(int i = k % 2 ? 1 : 2 ; i <= k - 2; i += 2)	a[++a[0]] = i;
		for(int i = k + 3 ; i < n ; i += 2)	a[++a[0]] = i;
		for(int i = k % 2 ? 2 : 1 ; i <= k + 1; i += 2)	a[++a[0]] = i;
		a[++a[0]] = n;
	}
	for(int i = 1 ; i <= a[0] ; i++)
		printf("%d\n",a[i]);
}
