#include<bits/stdc++.h>
#define inf 0x7fffffff
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,K,sz;
int v[100005],id[100005],fa[100005],root[100005];
int ls[1800000],rs[1800000],sum[1800000];
int get(int x)
{
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void insert(int &k,int l,int r,int val)
{
	if(!k)k=++sz;
	if(l==r)
	{
		sum[k]=1;return;
	}
	int mid=(l+r)>>1;
	if(val<=mid)insert(ls[k],l,mid,val);
	else insert(rs[k],mid+1,r,val);
	sum[k]=sum[ls[k]]+sum[rs[k]];
}
int query(int k,int l,int r,int rank)
{
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(sum[ls[k]]>=rank)return query(ls[k],l,mid,rank);
	else return query(rs[k],mid+1,r,rank-sum[ls[k]]);
}
int merge(int x,int y)
{
	if(!x)return y;
	if(!y)return x;
	ls[x]=merge(ls[x],ls[y]);
	rs[x]=merge(rs[x],rs[y]);
	sum[x]=sum[ls[x]]+sum[rs[x]];
	return x;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
		v[i]=read();
	for(int i=1;i<=n;i++)
		fa[i]=i;
	int x,y;
	for(int i=1;i<=m;i++)
	{
		x=read(),y=read();
		int p=get(x),q=get(y);
	    fa[p]=q;
	}
	for(int i=1;i<=n;i++)
	{
		insert(root[get(i)],1,n,v[i]);
		id[v[i]]=i;
	}
	K=read();char ch[2];
	while(K--)
	{
		scanf("%s",ch);
		x=read();y=read();
		if(ch[0]=='Q')
		{
			int p=get(x);
			if(sum[root[p]]<y)
			{
				puts("-1");continue;
			}
			int t=query(root[p],1,n,y);
		    printf("%d\n",id[t]);
		}
		else 
		{
			int p=get(x),q=get(y);
			if(p!=q)
			{
				fa[p]=q;
				root[q]=merge(root[p],root[q]);
			}
		}
	}
	return 0;
}
