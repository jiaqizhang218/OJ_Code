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
int n,ans;
int main()
{
	n = read();
	while( n ^ 1)
	{
		++ans;
		if(n&1)
			 n=n*3+1;
		else 
			 n>>=1;
	}
	printf("%d",ans);
	return 0;
}

