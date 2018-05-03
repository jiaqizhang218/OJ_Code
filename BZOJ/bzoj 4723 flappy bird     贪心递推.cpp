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
const int M = 500500;
int n,X; 
struct ppp {
	int x,a,b,limit;
	void Input()
	{
		scanf("%d%d%d",&x,&a,&b);
		a++,b--;
		limit = a - x;
		if(limit&1) ++limit;
	}
}a[M];
int main()
{
	int ans=0;
	cin>>n>>X;
	for(int i=1;i<=n;i++)
	{
		a[i].Input();
	}
	for(int i=n-1;i>0;i--)
	{
		a[i].limit=max(a[i].limit,a[i+1].limit);
	}
	int x=0,y=0;
	for(int i=1;i<=n;i++)
	{
		int temp=(y-x)-a[i].limit>>1;
		if(temp<0)	temp=0;
		temp=a[i].x-x-temp;
		if(temp<0) temp=0;
		y+=temp; y-=a[i].x-x-temp;
		x=a[i].x;
		if(y<a[i].a||y>a[i].b)
			return cout<<"NIE"<<endl,0;
		ans+=temp;
	}
	cout<<ans;
	return 0;
}
