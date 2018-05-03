#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
const int mod = 1000000007;
inline LL read()
{
	LL x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
LL ans;
LL n,m,k,sum;
struct data{
	int pos,val;
	bool operator <(const data& b)	const 
	{
		return (pos == b.pos) ? (val < b.val) : (pos < b.pos);
	}
}a[100005];
inline int qpow(LL a,LL b)
{
	LL ans = 1;
	for( ; b ; b >>= 1 , a = a * a % mod)
		if(b & 1)	ans = ans * a % mod;
	return ans;
}
int main()
{
	n = read() , m = read() , k = read();
	for(int i = 1 ; i <= k ; i++)
		a[i].pos = read() , a[i].val = read();
	sort(a+1,a+k+1);
	int tot = m;
	int sum = (LL) (n * (n + 1) / 2) % mod , tmp = sum;
	ans = 1;
	for(int i = 1 ; i <= k ; i++)
	{
		if(a[i].pos != a[i-1].pos && i != 1)
			ans = ans * tmp % mod , tmp = sum, tot--;
		if(a[i].pos != a[i-1].pos || a[i].val != a[i-1].val)
		{
			tmp -= a[i].val;
			tmp += (tmp < 0) ? mod : 0;
		}
	}
	tot--;
	ans = ans * tmp % mod;
	cout<<ans*qpow(sum,tot) % mod;
}
