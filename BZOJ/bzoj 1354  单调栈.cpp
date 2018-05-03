#include<bits/stdc++.h>
#define rep(i,j,k) for((i)=(j);(i)<=(k);++i)
#define per(i,j,k) for((i)=(j);(i)>=(k);--i)
typedef long long LL;
const int INF = 0x7fffffff;
const int N = 1000010;
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
//#define  getchar() nc()
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int n,t,v[N],st[N],ls[N],rs[N];
LL ans;
int main()
{
	int i;
	for(n=read(),i=1;i<=n;i++)	v[i]=read();
	for(t=0,i=1;i<=n;i++)	
	{
		while(t&&v[st[t]]<v[i])	t--;
		ls[i]=st[t],st[++t]=i;
	}
	for(t=0,i=n;i>=1;i--)
	{
		while(t&&v[st[t]]<=v[i])	t--;
		rs[i]=st[t],st[++t]=i;
	}
	for(i=1;i<=n;i++)
	{
		if(!ls[i]&&!rs[i])	continue;
		if(ls[i]&&(!rs[i]||v[ls[i]]<v[rs[i]]))	ans+=v[ls[i]];
		else ans+=v[rs[i]];
	}
	printf("%lld",ans);
	return 0;
}
