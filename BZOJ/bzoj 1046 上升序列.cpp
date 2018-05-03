#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int n,m,cnt;
int a[1000005],f[1000005],best[100005];
inline int find(int x)
{
	int l=1,r=cnt,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(best[mid]>x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
inline void pre()
{
	for(int i = n ; i ; i--)
	{
		int t = find(a[i]);
		f[i] = t + 1;
		cnt = cnt > f[i] ? cnt : f[i];
		best[t + 1] = a[i] > best[t + 1] ? a[i] : best[t + 1];
	}
}
inline void solve(int x)
{
	int last = 0;
	for(int i = 1; i <= n ; i++)
	{
		if(f[i] >= x && a[i] > last)
		{
			printf("%d",a[i]);
			if(x != 1) printf(" ");
			last = a[i];
			if(!(--x)) break;
		}
	}
	cout<<endl;
}
int main()
{
	n = read();
	for(int i = 1; i <= n ; i++)
		a[i] = read();
	pre();
	m = read();
	for(int i = 1;  i <= m ; i++)
	{
		int x = read();
		if(x <= cnt) solve(x);
		else puts("Impossible");
	}
	return 0;
}
