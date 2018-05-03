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
set <int> s;
int main()
{
	int t,n,r,i;
	t = read();
	while(t--)
	{
		n = read();
		s.clear();
		r = read() , cout<<r ; s.insert(r);
		for(int i = 2 ; i <= n ; i++)
			{
				r = read();
				if(s.count(r)==0)	printf(" %d",r);
				s.insert(r);
			}
		cout<<endl;
	}
	return 0;
}
