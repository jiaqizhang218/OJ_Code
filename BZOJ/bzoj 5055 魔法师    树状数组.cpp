#include<bits/stdc++.h>
#define ll long long
#define mod 19260817
using namespace std;
const ll N=3e5+5;
ll n,ans;
struct node
{
	ll p,id;
	bool operator <(const node &dd) const {return p==dd.p?id>dd.id:p<dd.p;} 
}a[N];
ll s[N],m[N]; 
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int lowbit(int x){return x&(-x);}
inline void add(ll x,ll v,ll *ch)
{
	for(ll i=x;i<=n;i+=lowbit(i)) *(ch+i) =(*(ch+i)+v)%mod;
}
inline ll ask(ll x,ll *ch)
{
	ll tt=0;
	for(ll i=x;i>=1;i-=lowbit(i)) tt+= *(ch+i);
	return tt%mod;
}
int main()
{
	n=read();
	for(ll i=1;i<=n;i++) a[i].p=read(),a[i].id=i;
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) 
	{
		ans=(ans+ask(a[i].id-1,m)*a[i].p)%mod;
		ll tmp=ask(a[i].id-1,s)*a[i].p%mod;
		add(a[i].id,tmp,m);
		add(a[i].id,a[i].p%mod,s);
	}
	cout<<ans<<endl;
}
