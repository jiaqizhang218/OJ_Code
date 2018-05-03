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
const int N = 100010;
const int M = 1000010;
int to[M],nxt[M],pre[N],cnt=1;
inline void ae(int ff,int tt) {
	to[++cnt]=tt;nxt[cnt]=pre[ff];pre[ff]=cnt;
}
int n,m,dfn[N],low[N],cn,siz[N];
LL ans[N];
inline LL sqr(int x) {
	return (LL)x*x;
}
inline void tarjan(int x,int com) {
	int i,j,re=n-1;
	dfn[x]=low[x]=++cn;
	siz[x]=1;
	for(int i=pre[x];i;i=nxt[i]) {
		if(i!=(com^1)) {
			j=to[i];
			if(!dfn[j]) {
				tarjan(j,i);
				siz[x] += siz[j];
				if(low[j]>=dfn[x]) {
					ans[x]-=sqr(siz[j]);
					re-=siz[j];
				}
				low[x]=min(low[x],low[j]);
			}
			else low[x]=min(low[x],dfn[j]);
		}
	}
	ans[x]-=sqr(re);
} 
int main()
{
	n=read(),m=read();
	int i,j,x,y;
	for(i=1;i<=n;i++) {
		x=read(),y=read();
		ae(x,y),ae(y,x);
	}
	for(i=1;i<=n;i++) 
		ans[i]=sqr(n-1);
	tarjan(1,0);
	for(i=1;i<=n;i++) 
		printf("%lld\n",ans[i]+2*(n-1));
	return 0;
}
