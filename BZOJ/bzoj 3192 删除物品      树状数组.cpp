#include<bits/stdc++.h>
#define rep(i,j,k) for((i)=(j);(i)<=(k);++i)
#define per(i,j,k) for((i)=(j);(i)>=(k);--i)
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
#define  getchar() nc()
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int N = 100100;
int n1,n2,n,i,u,pos,a[N],b[N],c[N]; LL ans;
bool cmp(int x,int y)	{return a[x]>a[y];}
inline void add(int x,int y)	{for(;x<N;x+=(x&(-x))) c[x]+=y;}
inline int ask(int x)	{int u=0;for(;x;x-=(x&(-x))) u+=c[x]; return u;}
int main()
{
	for(n1=read(),n2=read(),n=n1+n2,i=n1;i;--i)	a[i]=read();
	for(i=n1+1;i<=n;++i)	a[i]=read(); pos=n1;
	for(i=1;i<=n;i++)	b[i]=i,add(i,1);
	sort(b+1,b+1+n,cmp);
	for(i=1;i<=n;add(b[i++],-1))	
	if(b[i]>pos)	ans+=ask(b[i]-1)-ask(pos),pos=b[i]-1;	
	else ans+=ask(pos)-ask(b[i]),pos=b[i];
	printf("%lld\n",ans);
	return 0;
}
