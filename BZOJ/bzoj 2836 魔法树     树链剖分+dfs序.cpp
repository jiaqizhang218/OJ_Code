#include<bits/stdc++.h>
#define debug(x) cout<<(#x)<<" "<<(x)<<endl
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
//#define  getchar() nc()
inline LL read()
{
	LL x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int N = 1e5 + 5;
const int M = N<<2;
LL n,m,x,y,q,u,t,d,f2,ans,dfs_clock;
LL tot,fir[N],nxt[M],to[M];
LL siz[N],h[N],f[N],top[N],in[N],out[N],son[N];
LL sum[M],delta[M];
char opt[20];
inline void AE(LL x,LL y)
{
	to[++tot]=y;nxt[tot]=fir[x];fir[x]=tot;
	to[++tot]=x;nxt[tot]=fir[y];fir[y]=tot;
} 
inline void dfs1(LL x,LL fa,LL dep)
{
	siz[x]=1;h[x]=dep;f[x]=fa;
	LL maxson=0;
	for(LL i=fir[x];i;i=nxt[i])
	{
		if(to[i]==fa) continue;
		dfs1(to[i],x,dep+1);
		if(siz[to[i]]>maxson)
			maxson=siz[to[i]],son[x]=to[i];
	}
}
inline void dfs2(LL x,LL fa)
{
	if(son[fa]!=x)	top[x]=x;
	else top[x]=top[fa];
	in[x]=++dfs_clock;
	if(son[x])	dfs2(son[x],x);
	for(LL i=fir[x];i;i=nxt[i])
		if(to[i]!=fa&&to[i]!=son[x]) 
			dfs2(to[i],x);	
	out[x]=dfs_clock;
}
inline void update(LL now)
{
	sum[now]=sum[now<<1]+sum[now<<1|1];
}
inline void pushdown(LL now,LL l,LL r,LL mid)
{
	if (delta[now])
    {
        sum[now<<1]+=delta[now]*(LL)(mid-l+1);
        delta[now<<1]+=delta[now];
        sum[now<<1|1]+=delta[now]*(LL)(r-mid);
        delta[now<<1|1]+=delta[now];
        delta[now]=0;
    }
}
inline void modify(LL now,LL l,LL r,LL ls,LL rs,LL v)
{
	LL mid=(l+r)>>1;
	if(ls<=l&&r<=rs)
	{
		sum[now]+=v*(LL)(r-l+1);
		delta[now]+=v;
		return;
	}
	pushdown(now,l,r,mid);
	if(ls<=mid)	modify(now<<1,l,mid,ls,rs,v);
	if(rs>=mid+1) modify(now<<1|1,mid+1,r,ls,rs,v);
	update(now);
}
inline LL query(LL now,LL l,LL r,LL ls,LL rs)
{
	LL mid=(l+r)>>1;	LL ans=0;
	if(ls<=l&&r<=rs)	return sum[now];
	pushdown(now,l,r,mid);
	if(ls<=mid)	ans+=query(now<<1,l,mid,ls,rs);
	if(rs>=mid+1) ans+=query(now<<1|1,mid+1,r,ls,rs);
	return ans;
}
int main()
{
	n=read();
	for(int i=1;i<n;i++)	
	{
		x=read()+1,y=read()+1;
		AE(x,y);
	}
	dfs1(1,0,1);
	dfs2(1,0);
	q=read();
	while(q--)
	{
		scanf("%s",opt);
		if(opt[0]=='A')
		{
			u=read()+1,t=read()+1,d=read();
			LL f1=top[u],f2=top[t];
			while(f1!=f2)
			{
				if(h[f1]<h[f2])	swap(f1,f2),swap(u,t);
				modify(1,1,dfs_clock,in[f1],in[u],d);
				u=f[f1];	f1=top[u];
			}
			if(in[u]>in[t]) swap(u,t);
			modify(1,1,dfs_clock,in[u],in[t],d);
		}
		else
		{
			u=read()+1;
			ans=query(1,1,dfs_clock,in[u],out[u]);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
