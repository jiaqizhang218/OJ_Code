#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int MAXN = 100010;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int c[MAXN],p[MAXN],n,tot,ans;
inline void change(int x,int y)
{
	for(;x<=n;x+=(x&-x))
		c[x]+=y; 
}
inline int ask(int x)
{
	int sum = 0;
	for(;x;x-=(x&-x))
		sum += c[x];
	return sum;
}
int main()
{
	n = read() << 1;
	for(int i = 1 ; i <= n ; i++)
		{
			int x = read();
			if(!p[x]){
				p[x] = i;
				tot++;
				change(i,1);
			}
			else
			{
				ans += tot - ask(p[x]);
				change(p[x],-1);
				tot--;
			}
		}
	cout<<ans;
	return 0;
}

