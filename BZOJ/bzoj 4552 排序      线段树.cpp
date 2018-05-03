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
const int MAXN = 100010;
int n,m,a[MAXN],L[MAXN],R[MAXN],s[MAXN<<2],ch[MAXN<<2],c[MAXN];
int p;
inline void ud(int x)
{
	s[x]=s[x<<1]+s[x<<1|1];
}
inline void toch(int x,int y,int z,int cv) {
	ch[x]=cv;
	s[x]=(z-y+1)*cv;
}
inline void pd(int x,int y,int z) {
	if(ch[x]!=-1) {
		int mid=y+z>>1;
		toch(x<<1,y,mid,ch[x]);
		toch(x<<1|1,mid+1,z,ch[x]);
		ch[x]=-1;
	}
}
inline void build(int x,int y,int z,int l) {
	ch[x]=-1;
	if(y==z) {
		if(a[y]<=l) {
			s[x]=0;
		}
		else {
			s[x]=1;
		}
		return;
	}
	int mid=y+z>>1;
	build(x<<1,y,mid,l);
	build(x<<1|1,mid+1,z,l);
	ud(x);
}
inline int ask(int x,int y,int z,int l,int r) {
	if(y==l&&z==r) {
		return s[x];
	}
	pd(x,y,z);
	int mid=y+z>>1;
	if(r<=mid) {
		return ask(x<<1,y,mid,l,r);
	}
	else if(l>mid) {
		return ask(x<<1|1,mid+1,z,l,r);	
	}
	else {
		return ask(x<<1,y,mid,l,mid)+ask(x<<1|1,mid+1,z,mid+1,r);	               	
	}     	
}
inline void change(int x,int y,int z,int l,int r,int cv) {
	if(l>r)	return;
	if(y==l&&z==r) {
		toch(x,y,z,cv);
		return;
	}	
	pd(x,y,z);
	int mid=y+z>>1;
	if(r<=mid)	{
		change(x<<1,y,mid,l,r,cv);
	}	else if(l>mid) {
		change(x<<1|1,mid+1,z,l,r,cv);
	}	else {
		change(x<<1,y,mid,l,mid,cv);
		change(x<<1|1,mid+1,z,mid+1,r,cv);
	}
	ud(x);
}
bool OK(int x) {
	int i;
	build(1,1,n,x);
	for(i=1;i<=m;i++) {
		int t=ask(1,1,n,L[i],R[i]);
		if(!c[i]) {
			change(1,1,n,L[i],R[i]-t,0);
			change(1,1,n,R[i]-t+1,R[i],1);
		}else {
			change(1,1,n,L[i],L[i]+t-1,1);
			change(1,1,n,L[i]+t,R[i],0);
		}
	}
	return !ask(1,1,n,p,p);
}
int main()                                              
{
	int i;
	n=read(),m=read();
	for(i=1;i<=n;i++) {
		a[i]=read();
	}
	for(i=1;i<=m;i++) {
		c[i]=read();L[i]=read();R[i]=read();
	}
	p=read();
	int l=1,r=n;
	int ans;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(OK(mid))	ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans;
	return 0;
}
