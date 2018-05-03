#include<bits/stdc++.h>
#define debug(x) cerr<<#x" = "<<x<<endl
typedef long long LL;
const int INF = 0x7fffffff;
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
const int N = 10100;
int n,m;
LL ans,a[N];
int main()
{
#ifdef	iloi
	freopen("test.txt","r",stdin);
#endif
	n=read(),m=read();
	int i,x,y,z;
	for(int i=1;i<=n;i++)
	{
		z=read(),ans-=z,a[i]=z<<1;
	}
	for(int i=1;i<=m;i++)
	{
		x=read(),y=read(),z=read();
		ans-=z;a[x]+=z,a[y]+=z;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i+=2)
		ans+=a[i];
	return cout<<ans,0;
}

