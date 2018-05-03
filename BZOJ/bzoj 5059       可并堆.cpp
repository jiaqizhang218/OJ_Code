#include<bits/stdc++.h>
typedef long long LL;
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
const int N = 500010;
int n,a[N],num;
struct tree{
	int c,l,r,dis,sz;
	tree()
	{
		c=l=r=sz=0;
		dis=-1;
	}
}tr[N];
struct que{
	int l,r,c;
}q[N];
LL ans;
inline int merge(int x,int y)
{
	
    if(!x)return y;
    if(!y)return x;
    if(tr[x].c<tr[y].c)swap(x,y);
    	tr[x].r=merge(tr[x].r,y);
    if(tr[tr[x].l].dis<tr[tr[x].r].dis)
    	swap(tr[x].l,tr[x].r);
    tr[x].dis=tr[tr[x].r].dis+1;
    tr[x].sz=tr[tr[x].l].sz+tr[tr[x].r].sz+1;
    return x;
}
inline int ins(int x)
{
	int i=++num;
	tr[i].c=x; tr[i].l=tr[i].r=tr[i].dis=0;
	tr[i].sz=1;
	return i;
}
inline int pop(int x)
{
	return merge(tr[x].l,tr[x].r);
}
inline int top(int x)
{
	return tr[x].c;
}
inline int md(int x)
{
	return x-x/2;
}
int main()
{
	n=read();
	int ed=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		q[++ed]={i,i,ins(a[i])};
		while(ed>=2&&top(q[ed-1].c)>top(q[ed].c))
		{
			q[ed-1].c=merge(q[ed-1].c,q[ed].c);
			q[ed-1].r=q[ed].r;
			while(tr[q[ed-1].c].sz>md(q[ed-1].r-q[ed-1].l+1))
				q[ed-1].c=pop(q[ed-1].c);
				ed--;
		}
	}
	for(int i=1;i<=ed;i++)
		for(int j=q[i].l;j<=q[i].r;j++)
			ans+=abs(top(q[i].c)-a[j]);
	printf("%lld",ans);
	return 0;
}
