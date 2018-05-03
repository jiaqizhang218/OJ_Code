#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int N = 100003;  
const int M = 1000003;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
int n,m;
int belong[N],ans[M],num[N],p[320],mark[N],size;
struct data{
	int l , r , a , b , num;
	bool operator <(const data& rhs)const{
		return (belong[l]==belong[rhs.l]) ? r < rhs.r : belong[l] < belong[rhs.l];
	}
}a[M];
inline int ask(int x,int y)
{
	int ans = 0;
	if(belong[x] == belong[y])
	{
		for(int i = x ; i <= y ; i++)
			if(mark[i]) ans++;
		return ans;
	}
	else
	{
		for(int i = x; i <= belong[x] * size ; i++)
			if(mark[i])	ans++;
		for(int i = (belong[y]-1)*size+1;i<=y;i++)
			if(mark[i]) ans++;
		for(int i = belong[x] + 1; i < belong[y] ; i++)
			ans += p[i];
		return ans;
	}
}
int main()
{
	n = read() , m = read();
	for(int i = 1 ; i <= n ; i++)
		num[i] = read();
	for(int i = 1 ; i <= m ; i++)
		a[i].l=read(),a[i].r=read(),a[i].a=read(),a[i].b=read(),a[i].num=i;
	size = ceil(sqrt(n));
	for(int i = 1 ; i <= n ; i++)
		belong[i] = (i-1)/size+1;
	sort(a+1,a+1+m);
	int l = 1 , r = 0;
	for(int i = 1 ; i <= m ; i++)
	{
		while(r < a[i].r)	{r++;mark[num[r]]++;if(mark[num[r]]==1) p[belong[num[r]]]++;}
		while(r > a[i].r)	{mark[num[r]]--;if(!mark[num[r]]) p[belong[num[r]]]--; r--;}
		while(l < a[i].l)	{mark[num[l]]--;if(!mark[num[l]]) p[belong[num[l]]]--; l++;}
		while(l > a[i].l)	{l--;mark[num[l]]++;if(mark[num[l]]==1) p[belong[num[l]]]++;}
		ans[a[i].num]=ask(a[i].a,a[i].b);
	}
	for(int i = 1 ; i <= m ; i++)
		printf("%d\n",ans[i]);
}
