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
int n;
int f[5005],d[5005],s[5005]; 
int main()
{
	n = read();
	for(int i = 1 ; i <= n ; i++)
	{
		int x = read();
		s[i] = s[i-1] + x;
		f[i] = x;
	}
	for(int l = 1 ; l < n ; l++)
	{
		for(int i = 1 ; i <= n - l; i++)
		{
			f[i] = s[i+l] - s[i-1] - min(f[i],f[i+1]); //i~lÕâÒ»¶Î 
		}
	}
	printf("%d",f[1]);
}

