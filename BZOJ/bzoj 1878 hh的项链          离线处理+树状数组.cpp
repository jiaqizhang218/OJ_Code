#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int n,m,mx;
int a[50005],next[50005],t[50005];
int p[1000005];
struct data{int l,r,id,ans;}q[200005];
bool cmp1(data a,data b)
{return a.l==b.l?a.r<b.r:a.l<b.l;}
bool cmp2(data a,data b)
{return a.id<b.id;}
int lowbit(int x){return x&(-x);}
void update(int x,int v)
{
	for(int i=x;i<=n;i+=lowbit(i))
	    t[i]+=v;
}
int ask(int x)
{
	int tmp=0;
	for(int i=x;i>0;i-=lowbit(i))
	    tmp+=t[i];
	return tmp;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	    a[i]=read(),mx=max(mx,a[i]);
	for(int i=n;i>0;i--)
	    next[i]=p[a[i]],p[a[i]]=i;
	for(int i=1;i<=mx;i++)
	    if(p[i])update(p[i],1);
	m=read();
	for(int i=1;i<=m;i++)
	    q[i].l=read(),q[i].r=read(),q[i].id=i;
	sort(q+1,q+m+1,cmp1);
	int l=1;
	for(int i=1;i<=m;i++)
	{
		while(l<q[i].l)
		{
			if(next[l])update(next[l],1);
			l++;
		}
		q[i].ans=ask(q[i].r)-ask(q[i].l-1);
	}
	sort(q+1,q+m+1,cmp2);
	for(int i=1;i<=m;i++)
	    printf("%d\n",q[i].ans);
	return 0;
}
