#include<bits/stdc++.h>
#define ll long long
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std;
int ans,n,m,a[100001];
int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x * f;
}
bool jud(int x)
{
	int s=0,tmp=1;
	for(int i=1;i<=n;i++)
	{
		if(s+a[i]<=x) s+=a[i];
		else {s=a[i];tmp++;if(tmp>m||a[i]>x)return false;}
	}
	return true;
}
int main()
{
	n = read(), m =read();
	for(int i = 1 ; i <= n ;i++)
		a[i]=read();
	int l = 1 , r = 100000000;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(jud(mid))	ans=mid,r=mid-1;
		else l = mid+1;
	}
	printf("%d",ans);
}

