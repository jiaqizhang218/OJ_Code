#include<bits/stdc++.h>
typedef long long LL;
#define lowbit(x)	x&(-x)
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
struct abcd{
	int d,rnk;
	bool operator < (const abcd& rhs)const {
			return d<rhs.d;
	}
}yy[100010];
struct ppp{
	int x,y,z;
	bool operator < (const ppp& rhs)const {
		return x<rhs.x||x==rhs.x&&y<rhs.y;
	}
}p[100010];
int f[100010],c[100010],n,m,k,cnt,mx;
inline void add(int x,int d)
{
	for(;x<=cnt;x+=lowbit(x))
		c[x]=max(c[x],d);
}
inline int ask(int x)
{
	int s=0;
	for(;x;x-=lowbit(x))
		s=max(c[x],s);
	return s;
}
int main()
{
	n=read(),m=read(),k=read();
	for(int i=1;i<=k;i++)
	{
		p[i].x=read(),p[i].y=yy[i].d=read(),p[i].z=read();
		yy[i].rnk=i;
	}
	sort(yy+1,yy+k+1);
	yy[0].d=-1;
	for(int i=1;i<=k;i++)
	{
		if(yy[i].d!=yy[i-1].d)	cnt++;
		p[yy[i].rnk].y=cnt;
	}
	sort(p+1,p+k+1);
	for(int i=1;i<=k;i++)
	{
		f[i]=p[i].z+ask(p[i].y);
		add(p[i].y,f[i]);
		mx=max(mx,f[i]);
	}
	cout<<mx;
	return 0;
}
