#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
unsigned int now,ans[50005];
int n,m;
int a[50005],disc[50005],belong[50005];
int t[50005];
struct queuy{
	int l,r,id;
	bool operator < (const queuy& rhs) const{
		return belong[l] == belong[rhs.l] ? r < rhs.r : belong[l] < belong[rhs.l];
	}
}q[50005];
inline void add(int x,int val)
{
	for(int i = x; i <= n ; i += i&-i)
		t[i] += val;
}
unsigned int query(int x)
{
	unsigned int sum = 0;
	for(int i = x; i ; i -= i & -i)
		sum += t[i];
	return sum;
}
void solve()
{
	sort(q+1,q+1+m);
	int l = 1 , r = 0;
	for(int i = 1 ; i <= m ; i++)
	{
		while(l < q[i].l)
			add(a[l],-1),now -= query(a[l]-1),l++;
		while(r > q[i].r)
			add(a[r],-1),now -= r-l-query(a[r]),r--;
		while(l > q[i].l)
			l--,add(a[l],1),now += query(a[l]-1);
		while(r < q[i].r)
			r++,add(a[r],1),now += r - l + 1 - query(a[r]);
		ans[q[i].id] = now;		
	}
}
int main()
{
	n = read();
	int t = sqrt(n);
	for(int i = 1 ; i <= n ; i++)	disc[i] = a[i] = read();
	sort(disc+1,disc+1+n);
	for(int i = 1 ; i <= n ; i++)	
		a[i] = lower_bound(disc+1,disc+1+n,a[i]) - disc;
	m = read();
	for(int i = 1; i <= m ; i++)
		q[i].l = read() , q[i].r = read() , q[i].id = i;
	for(int i = 1 ; i <= n ; i++)
		belong[i] = (i-1)/t+1;
	solve();
	for(int i = 1 ; i <= m ; i++)
		printf("%d\n",ans[i]);
	return 0;
}
