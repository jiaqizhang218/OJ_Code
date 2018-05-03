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
int f[30001][4],a[30001],ans=INF,n;
//f数组表示前i头牛以编号j结尾的最少修改次数 
void dp()
{
	memset(f,127,sizeof(f));
	f[0][1] = f[0][2] = f[0][3] = 0;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= 3 ; j++)
			for(int k = 1 ; k <= j ; k++)
				if(a[i] == j)
					f[i][j] = min(f[i][j],f[i-1][k]);		//无需修改	 
				else f[i][j] = min(f[i][j],f[i-1][k]+1);	//需要修改 
	for(int i = 1 ; i <= 3 ; i++)	ans = min(ans,f[n][i]);
}
int main()
{
	n = read();
	for(int i = 1 ; i <= n ; i++)
		a[i] = read();
	dp();
	for(int i = 1 ; i <= (n>>1) ; i++)
		swap(a[i],a[n-i+1]);
	dp();
	printf("%d",ans);
}

