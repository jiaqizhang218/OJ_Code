#include<bits/stdc++.h>
#define ll long long
const int INF = 0x7fffffff;
const int mx = 30005;
const double eps = 1e-5;
using namespace std;
int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x * f;
}
//f[i]这个状态表示a机器花了i分钟，b机器花了f[i]分钟  好奇怪的状态... 
int n,m,f[30001],a[6001],b[6001],c[6001];
int main()
{
	n = read();
	for(int i = 1 ; i <= n ; i++)
	{
		a[i] = read(),b[i] = read(),c[i] = read();
		if(!a[i]) a[i] = mx; if(!b[i]) b[i] = mx; if(!c[i]) c[i] = mx;	
		int t = mx;
		t = min(min(t,min(a[i],b[i])),c[i]);//t是第x个部件需要的最少时间 
		m += t;//m是需要的最少时间的总和 
	}
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = m ; j >= 0 ; j--)
		{	
			int t = mx;
			if(j - a[i] >= 0)
				t = min(t,f[j-a[i]]);
			t = min(t,f[j]+b[i]);
			if(j - c[i] >= 0)
				t = min(t,f[j-c[i]]+c[i]);
			//由上面描述的转移方程可得  三种情况全部转移一下就是最优解 
			f[j] = t;
		}
	}
	int ans = mx;
	for(int i = 0 ; i <= m ; i++)	ans = min(ans,max(i,f[i]));//二取一大中取小 
	printf("%d",ans);
	return 0;
}

