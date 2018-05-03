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
int n,ans,a[2005],b[2005],f[2005][2005];
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)	a[i]=b[i]=read();
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)	f[i][0]=INF;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=min(f[i][j-1],f[i-1][j]+abs(a[i]-b[j]));
	ans=f[n][n];
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=min(f[i][j-1],f[i-1][j]+abs(a[i]-b[j]));
	printf("%d",min(ans,f[n][n]));
	return 0;
}
