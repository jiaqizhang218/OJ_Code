#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int N = 1000001;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
int n,ans,v[N],a[N],b[N];
inline bool jud(int x)
{
	a[1] = b[1] = v[1];
	for(int i = 2 ; i <= n ; i++)
	{
		b[i] = min(v[i],v[1]-a[i-1]);
		a[i] = max(0,v[i]+v[1]+v[i-1]-b[i-1]-x); 
	}
	return a[n] == 0;
}
int main()
{
	n = read();
	for(int i = 1;  i<= n ; i++)
	{
		v[i] = read();
		ans = max(v[i] + v[i-1],ans);
	}
	int l = ans, r = ans << 1;
	while(l <= r)
	{
		int mid = (r + l) >> 1;
		if(jud(mid))	r = mid-1;
		else l = mid+1;
	}
	printf("%d",l);
	return 0;
}
