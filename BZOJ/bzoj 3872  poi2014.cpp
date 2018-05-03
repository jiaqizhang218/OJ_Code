#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
const int N = 2000010;
inline LL read()
{
	LL x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
LL m[N>>1];
LL to[N],nxt[N],pre[N>>1],cnt;
LL d[N>>1];
inline void ae(LL ff,LL tt) {
	to[++cnt]=tt;
	nxt[cnt]=pre[ff];
	pre[ff]=cnt;
	d[ff]++;
}
LL mn[N>>1],mx[N>>1];
LL n,g,k;
inline void build(LL x,LL ff) {
	LL i,j;
	for(i=pre[x];i;i=nxt[i]) {
		j=to[i];
		if(j==ff) continue;
		mn[j]=mn[x]*(d[x]-1);
		mx[j]=mx[x]*(d[x]-1)+d[x]-2;
		mx[j]=min(mx[j],m[g]);
		if(mn[j]<=m[g])
			build(j,x);
	}
}
LL cal(LL x) {
	LL L=1,R=g+1,mid;
	while(L<R)	{
		mid=(L+R)>>1;
		if(m[mid]<=x)	L=mid+1;
		else R=mid;
	}
	return L-1;
}
int main()
{
	n=read(),g=read(),k=read();
	LL i,j,x,y;
	for(int i=1;i<=g;i++)	m[i]=read();
	sort(m+1,m+g+1);
	LL s1=read(),s2=read();
	ae(s1,s2),ae(s2,s1);
	for(int i=2;i<n;i++) {
		x=read(),y=read();
		ae(x,y),ae(y,x); 
	}
	mn[s1]=mx[s1]=mx[s2]=mn[s2]=k;
	build(s1,s2);
	build(s2,s1);
	LL ans=0;
	for(int i=1;i<=n;i++)
		if(d[i]==1) {
			ans+=cal(mx[i])-cal(mn[i]-1);
		} 
	cout<<ans*k;
	return 0;
}
