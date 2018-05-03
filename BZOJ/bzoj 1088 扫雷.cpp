#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=0;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return f ? x : -x;
}
int ans , n , a[100005] , f[100005]; 
inline int jud()
{
	for(int i = 2 ; i < n ; i++)
	{
		f[i+1] = a[i] - f[i] - f[i-1];
		if(f[i+1] != 0 && f[i+1] != 1) return 0;
	}
	return f[n] + f[n-1] == a[n];
}
int main()
{
	n = read();
	for(int i = 1 ; i <= n ; i++)	a[i] = read();
	if(a[1] == 0 ) ans += jud();
	else if(a[1] == 1) 
	{
		f[1] = 1 , f[2] = 0 , ans += jud();
		f[1] = 0 , f[2] = 1 , ans += jud();
	}
	else 
		f[1] = 1 , f[2] = 1 , ans += jud();
	cout<<ans<<endl;
	return 0;	
}
