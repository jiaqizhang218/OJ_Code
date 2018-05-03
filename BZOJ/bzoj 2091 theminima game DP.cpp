#include<bits/stdc++.h>
#define M 1000010
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
int a[M],f[M];
int main()
{
	int n = read();
	for(int i = 1 ; i <= n ; i++)
		a[i] = read();1
	sort(a+1,a+1+n);
	int mx=a[1];
	for(int i = 1; i <= n ;++i)
		mx=max(mx,a[i+1]-mx);
	printf("%d",mx);
	return 0;
}

