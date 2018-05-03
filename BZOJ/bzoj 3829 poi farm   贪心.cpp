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
const int N = 1000010;
int c[N];
int to[N],nxt[N],pre[N],cnt;
inline void ae(int ff,int tt) {
	to[++cnt]=tt;nxt[cnt]=pre[ff];pre[ff]=cnt;
}
struct ppp{
	int t,b;
}a[N];
int fa[N],ti[N];
bool cmp(ppp x,ppp y) {
	return max(x.b,2+x.t+y.b) < max(y.b,2+y.t+x.b);
}
inline void build(int x) {
	int i,j,cnt=0;
	for(i=pre[x];i;i=nxt[i]) {
		j=to[i];
		if(fa[x]==j)	continue;
		fa[j]=x;
		build(j);
		ti[x]+=2+ti[j];
	}
	for(i=pre[x];i;i=nxt[i]) {
		j=to[i];
		if(j==fa[x]) continue;
		cnt++;
		a[cnt].t=ti[j]; a[cnt].b=c[j];
	}
	sort(a+1,a+cnt+1,cmp);
	int sum=0,maxn=0;
	for(i=1;i<=cnt;i++) {
		sum++;
		maxn=max(maxn,sum+a[i].b);
		sum+=a[i].t+1;
	}
	if(x==1)	c[x]=max(sum+c[x],maxn);
	else c[x]=max(c[x],maxn);
}
int main()
{
	int n=read(),m;
	int i,j,x,y;
	for(i=1;i<=n;i++)	c[i]=read();
	for(i=1;i<n;i++) {
		x=read(),y=read();
		ae(x,y),ae(y,x);
	}
	build(1);
	printf("%d",c[1]);
}
