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
int m;
LL n,ans;
inline LL phi(LL x)
{
	LL t=x;
	for(LL i=2;i<=m;i++)
		if(x%i==0)
		{
			t=t/i*(i-1);
			while(x%i==0)	x/=i;
		}
	if(x>1)	t=t/x*(x-1);
	return t;
}
int main()
{
	cin>>n;
	m=sqrt(n);
	for(int i=1;i<=m;i++)
	{
		if(n%i==0)
		{
			ans+=(LL)i*phi(n/i);
			if(i*i<n)	ans+=(LL)(n/i)*(phi(i));
		}
	}
	cout<<ans;
	return 0;
}
