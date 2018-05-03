#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int maxn = 1200005;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int n,cnt;
int fa[maxn],f[maxn],p[maxn],size[maxn];
int main()
{
	n=read();
	for(int i=1;i*i<=n;i++)	if(n%i==0)	
	{
		p[++cnt]=i; if(i*i!=n)	p[++cnt]=n/i;
	}
	sort(p+1,p+cnt+1);
	for(int t=1;t<=10;t++)
	{
		printf("Case #%d:\n",t);
		memset(size,0,sizeof size);
		memset(f,0,sizeof f);
		for(int i=2;i<=n;i++)	fa[i]=t==1?read():(fa[i]+19940105)%(i-1)+1;
		for(int i=n;i>=1;i--)	size[fa[i]]+=(++size[i]);
		for(int i=1;i<=n;i++)	f[size[i]]++;
		for(int i=1;i<=cnt;i++)
		{
			int tmp=0;
			for(int j=1;j<=n/p[i];j++)	tmp+=(f[p[i]*j]);
			if(tmp==n/p[i])	printf("%d\n",p[i]);
		 } 
	}
	return 0;
}
