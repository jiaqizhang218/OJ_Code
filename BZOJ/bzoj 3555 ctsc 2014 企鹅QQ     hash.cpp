#include<bits/stdc++.h>
typedef unsigned long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int M = 30300;
const int BASE = 149;
int n,k,ans;
LL sum[M][210],power[210];
char s[210];
LL a[M];
inline void Calculate(int pos)
{
	for(int i=1;i<=n;i++)
		a[i]=sum[i][k]-sum[i][pos]*power[k-pos]+sum[i][pos-1]*power[k-pos+1];
	sort(a+1,a+n+1);
	int cnt;
	for(int i=1;i<=n;i++)
	{
		if(i==1||a[i]!=a[i-1])
			cnt=-1;
		cnt++;
		ans+=cnt;
	}
}
int main()
{
	cin>>n>>k;
	scanf("%*d");
	power[0]=1;
	for(int i=1;i<210;i++)
		power[i]=power[i-1]*BASE;
	for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=k;j++)
				sum[i][j]=sum[i][j-1]*BASE+s[j];
		}
	for(int i=1;i<=k;i++)
		Calculate(i);
	cout<<ans<<endl;
	return 0; 
}
