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
int n,a[100001],b[100001],ab[100001],ans,tmp;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)	
	{
		a[i]=read(),b[i]=read();
		ab[i]=a[i-1]-b[i-1]+ab[i-1];
	}
	ab[1]=a[n]-b[n]+ab[n];
	sort(ab+1,ab+n+1);
	if(n&1)	tmp=ab[n/2+1];
	else tmp=ab[n/2];
	for(int i=1;i<=n;i++)
		ans+=abs(ab[i]-tmp);
	cout<<ans;
	return 0; 
}
