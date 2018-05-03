#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int MAXN = 2000 + 5;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int n,h,ans,f[MAXN];
struct data {
	int x,y;
	bool operator < (const data& rhs) const {
		return x+y<rhs.x+rhs.y;
	}
}a[MAXN];
int main()
{
	n=read();
	memset(f,-1,sizeof f);
	f[0]=0;
	for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read(),f[0]+=a[i].x;
	h=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) {
		for(int j=ans;j>=0;j--) 
			if(f[j]+a[i].y>=h)	f[j+1]=max(f[j+1],f[j]-a[i].x);
			if(f[ans+1]>=0)	ans++;
	}
	printf("%d\n",ans);
	return 0;
}
