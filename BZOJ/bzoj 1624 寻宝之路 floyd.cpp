#include<bits/stdc++.h>
#define ll long long
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std;
int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x * f;
}
int n,m,ans;
int g[105][105],a[10005]; 
int main()
{
	n = read(); m =read();
	for(int i = 1 ; i <= m ; i++)
		a[i]=read();
	for(int i = 1 ; i <= n ;i++)
		for(int j = 1 ; j <= n ; j++)
			g[i][j] = read();
	for(int k = 1 ; k <= n ; k ++)
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= n ; j++)
			g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
	for(int i=2;i<=m;i++)	ans += g[a[i-1]][a[i]];
    	ans += g[1][a[1]]; ans += g[a[m]][n];
    printf("%d",ans);
    return 0;	
}

