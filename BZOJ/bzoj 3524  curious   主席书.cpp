#include<bits/stdc++.h>
#define rep(i,j,k) for((i)=(j);(i)<=(k);++i)
#define per(i,j,k) for((i)=(j);(i)>=(k);--i)
const int N=500010;
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
int siz,root[N],ls[N*20],rs[N*20],sum[N*20];
inline void update(int l,int r,int x,int &y,int z)
{
	y=++siz; sum[y]=sum[x]+1;
	if(l==r)	return;
	int mid=l+r>>1;
	ls[y]=ls[x]; rs[y]=rs[x];
	if(z<=mid)	update(l,mid,ls[x],ls[y],z);
	else update(mid+1,r,rs[x],rs[y],z);	
} 
inline int query(int l,int r,int x,int y,int z)
{
	if(l==r)	return l;
	int mid=l+r>>1;
	if(sum[ls[y]]-sum[ls[x]]>z)	return query(l,mid,ls[x],ls[y],z);
	if(sum[rs[y]]-sum[rs[x]]>z)	return query(mid+1,r,rs[x],rs[y],z);
	return 0;
}
int main()
{
	int i,n,m,x,y;
	for(n=read(),m=read(),i=1;i<=n;i++)
	{
		x=read();update(1,n,root[i-1],root[i],x);
	}
	while(m--)
	{
		x=read(),y=read();
		printf("%d\n",query(1,n,root[x-1],root[y],(y-x+1)/2));
	}
	return 0;
}
