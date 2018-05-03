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
struct building{
	int t1,t2;
	bool operator <(const building& y) const{
		return t2 < y.t2;
	}
}a[150001];
priority_queue <int> Q;
int main()
{
	int n = read();
	for(int i = 1 ; i <= n ; i++)
		a[i].t1 = read() , a[i].t2 = read();
	sort(a+1,a+1+n);
	int sum = 0 , ans = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		if(sum + a[i].t1 <= a[i].t2)
			{
				++ans;
				Q.push(a[i].t1);
				sum += a[i].t1;
			}
		else
		{
			if(Q.empty())
				continue;
			int t = Q.top();
			if(t <= a[i].t1)
				continue;
			sum -= t;
			sum += a[i].t1;
			Q.pop();
			Q.push(a[i].t1);
		}
	}
	printf("%d",ans);
	return 0;
}

