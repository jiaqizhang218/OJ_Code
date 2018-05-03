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
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		int t=(m-1)*(n/m)+max(n%m-1,0);
		if(t&1)	cout<<0<<endl;
		else cout<<1<<endl;
	}
	return 0;
}
