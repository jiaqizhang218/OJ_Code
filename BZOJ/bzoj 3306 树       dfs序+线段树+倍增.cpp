#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000 
using namespace std;
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int bin[20];
int n,Q,ind,root,cnt;
int val[100005],l[100005],r[100005],q[100005],deep[100005];
int fa[100005][20];
struct edge{
	int to,next;
}e[100005];int last[100005];
struct seg{
	int l,r,mn;
}t[400005];
void insert(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}
void update(int k)
{
	t[k].mn=min(t[k<<1].mn,t[k<<1|1].mn);
}
void build(int k,int l,int r)
{
	t[k].l=l;t[k].r=r;
	if(l==r){t[k].mn=val[q[l]];return;}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	update(k);
}
void modify(int k,int pos,int val)
{
	int l=t[k].l,r=t[k].r,mid=(l+r)>>1;
	if(l==r)
	{
		t[k].mn=val;return;
	}
	if(pos<=mid)modify(k<<1,pos,val);
	else modify(k<<1|1,pos,val);
	update(k);
}
int query(int k,int x,int y)
{
	if(x>y)return inf;
	int l=t[k].l,r=t[k].r,mid=(l+r)>>1;
	if(l==x&&y==r)return t[k].mn;
	if(y<=mid)return query(k<<1,x,y);
	else if(x>mid)return query(k<<1|1,x,y);
	return min(query(k<<1,x,mid),query(k<<1|1,mid+1,y));
}
void dfs(int x)
{
	l[x]=++ind;q[ind]=x;
	for(int i=1;i<=16;i++)
		if(bin[i]<=deep[x])fa[x][i]=fa[fa[x][i-1]][i-1];
		else break;
	for(int i=last[x];i;i=e[i].next)
	{
		fa[e[i].to][0]=x;
		deep[e[i].to]=deep[x]+1;
		dfs(e[i].to);
	}
	r[x]=ind;
}
int main()
{
	bin[0]=1;for(int i=1;i<20;i++)bin[i]=bin[i-1]<<1;
	n=read(),Q=read();
	for(int i=1;i<=n;i++)
	{
		int f=read();val[i]=read();
		if(f)insert(f,i);
	}
	dfs(root=1);
	build(1,1,n);
	char ch[5];int x;
	for(int i=1;i<=Q;i++)
	{
		scanf("%s",ch);x=read();
		if(ch[0]=='V')
		{
			int val=read();
			modify(1,l[x],val);
		}
		else if(ch[0]=='E')root=x;
		else
		{
			if(root==x)printf("%d\n",t[1].mn);
			else if(l[x]<=l[root]&&r[x]>=r[root])
			{
				int y=root,d=deep[y]-deep[x]-1;
				for(int i=0;i<=16;i++)
					if(bin[i]&d)y=fa[y][i];
				printf("%d\n",min(query(1,1,l[y]-1),query(1,r[y]+1,n)));
			}
			else 
				printf("%d\n",query(1,l[x],r[x]));
		}
	}
	return 0;
}
