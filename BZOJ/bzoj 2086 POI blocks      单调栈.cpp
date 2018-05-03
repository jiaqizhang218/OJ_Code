#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int MAXN = 1000010;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
LL a[MAXN],b[MAXN],pre[MAXN];
LL s[MAXN],t,n,m;
bool flag;
inline void solve()
{
	LL i,j,x,y;
	s[t=1]=0;
	for(i=1;i<=n;i++)
		if(pre[s[t]]>pre[i])
			s[++t]=i;
	LL ans = 0;
	s[t+1]=n;
	for(i=n;i>=1;i--)
	{
		while(t&&pre[s[t]]<=pre[i])	t--;
		ans = ans > (i - s[t+1]) ? ans : (i - s[t+1]);
	}
	printf("%lld",ans);
	if(!flag) printf(" ");
}
int main()
{
	scanf("%lld%lld",&n,&m);
	LL i,j,x,y;
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&x);
		for(j=1;j<=n;j++)
		{
			b[j]=a[j]-x;
			pre[j]=pre[j-1]+b[j];
		}
		if(i==m)	flag=true;
		solve();
	}
	return 0;
}
