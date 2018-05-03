#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T,l,r,ans,mn;
int add(int x)
{
	int k=1;
	while(x%10==0)k*=10,x/=10;
	return k;
}
int cal(int x)
{
	while(x%10==0)x/=10;
	int t=x%10,a=0;
	while(x)x/=10,a++;
	if(t==5)return 2*a-1;
	return 2*a;
}
int main()
{
	T=read();
	while(T--)
	{
		l=read();r=read();
		mn=cal(l);ans=l;
		while(1)
		{
			l+=add(l);
			if(l>r)break;
			int t=cal(l);
			if(t<mn)mn=t,ans=l;
		}
		printf("%d\n",ans);
	}
	return 0;
}


