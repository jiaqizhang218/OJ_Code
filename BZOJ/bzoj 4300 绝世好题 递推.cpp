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
int n,d[36];
int main()
{
	n = read();
	for(int i = 1 ; i <= n ; i++)
	{
		int tmp = read();
		int cal = 0;
		for(int j = 0 ; j <= 30 ; j++)
			if( tmp&(1<<j) )
				cal = max(d[j]+1,cal);
		for(int j = 0 ; j <= 30 ; j++)
			if( tmp&(1<<j) )
				d[j]= max(d[j],cal);
	}
	int ans=0;
	for(int i = 0 ; i <= 30 ; i++)
		ans = max(ans,d[i]);
	printf("%d",ans);
	return 0;
}

