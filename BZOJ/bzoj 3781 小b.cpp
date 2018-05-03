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
int n,m,K;
int b[50005];
LL cnt[50005],res[50005];
struct query{
	int l,r,block,id;
	bool operator < (const query& rhs)const{
		return block == rhs.block ? r < rhs.r : block < rhs.block;
	}
}a[50005];
inline void solve()
{
	sort(a+1,a+1+m);
	int l = 1 , r = 0; LL ans = 0;
	for(int i = 1 ; i <= m ; i++)
	{
		while(l > a[i].l) l--,cnt[b[l]]++,ans+=(cnt[b[l]]<<1)-1;
		while(r < a[i].r) r++,cnt[b[r]]++,ans+=(cnt[b[r]]<<1)-1;
		while(l<a[i].l)cnt[b[l]]--,ans-=2*cnt[b[l]]+1,l++;
		while(r>a[i].r)cnt[b[r]]--,ans-=2*cnt[b[r]]+1,r--;
		res[a[i].id]=ans;
	}
}
int main()
{
	n = read() , m = read() , K = read();
	int siz = sqrt(n);
	for(int i = 1 ; i <= n ; i++)	b[i] = read();
	for(int i = 1 ; i <= m ; i++)	
	{
		a[i].l = read() , a[i].r  = read();
		a[i].id = i;
		a[i].block = (a[i].l-1) / siz + 1;
	}
	solve();
	for(int i = 1; i <= m ; i++)
		printf("%lld\n",res[i]);
	return 0;
}
