#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int N = 200000+10,maxd=100000000;
int a[N],tree[N*30],lef[N*30],rig[30*N],root[N];
int i,j,k,l,t,n,m,tot,ans;
inline void insert(int &x,int y,int l,int r,int a,int b)
{
	x=++tot;
	tree[x]=tree[y];
	lef[x]=lef[y];
	rig[x]=rig[y];
	if(l==r)
	{
		tree[x]=b;
		return;
	}
	int mid=(l+r)>>1;
	if(a<=mid)	insert(lef[x],lef[y],l,mid,a,b);
	else insert(rig[x],rig[y],mid+1,r,a,b);
	tree[x]=min(tree[lef[x]],tree[rig[x]]);
}
inline int query(int x,int l,int r,int a) {
	if (l == r) return l;
	int mid = (l+r)>>1;
	if(tree[lef[x]]>=a)	return query(rig[x],mid+1,r,a);
	else return query(lef[x],l,mid,a);
} 
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) 
	{
		a[i]=read();
		insert(root[i],root[i-1],0,maxd,a[i],i);
	}
	while(m--)
	{
		j=read(),k=read();
		ans=query(root[k],0,maxd,j);
		printf("%d\n",ans);
	}
}
