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
const int N = 10005;
int f[N][505],v[N];
int n,m; 
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		v[i]=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]=f[i-1][j-1]+v[i];
			if(i+j<=n)	f[i+j][0]=max(f[i+j][0],f[i][j]);
		}
		f[i][0]=max(f[i-1][0],f[i][0]);
	}
	cout<<f[n][0]<<endl;
	return 0;
}
