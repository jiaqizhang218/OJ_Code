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
const int M = 1001001;
int n,q;
LL a[M];
int main()
{
	LL temp=0,sum=0;
	cin>>n>>q;
	for(int x,i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		(sum+=a[i]*i)%=n-1;
	}
	if(sum)
		a[sum]--;
	for(int i=1;i<n;i++)
		a[i]+=a[i-1];
	for(int i=1;i<=q;i++)
	{
		scanf("%lld",&temp);
		int ans=upper_bound(a,a+n,temp)-a;
		if(ans==n)	ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
