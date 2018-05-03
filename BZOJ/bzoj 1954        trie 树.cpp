#include<bits/stdc++.h> 
#define ll long long 
#define inf 2000000000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int bin[35];
int n,ans,cnt,val[100005],last[100005];
struct edge{
	int to,next,v;
}e[200005];
struct trie{
	int cnt;
	int ch[3000005][2];
	void insert(int x){
		int now=0;
		for(int i=30;i>=0;i--)
		{
			int t=x&bin[i];t>>=i;
			if(!ch[now][t])ch[now][t]=++cnt;
			now=ch[now][t];
		}
	}
	void query(int x){
		int tmp=0,now=0;
		for(int i=30;i>=0;i--)
		{
			int t=x&bin[i];t>>=i;
			if(ch[now][t^1])now=ch[now][t^1],tmp+=bin[i];
			else now=ch[now][t];
		}
		ans=max(tmp,ans);
	}
}trie;
void insert(int u,int v,int w)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;e[cnt].v=w;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;e[cnt].v=w;
}
void dfs(int x,int fa)
{
	for(int i=last[x];i;i=e[i].next)
		if(e[i].to!=fa)
		{
			val[e[i].to]=val[x]^e[i].v;
			dfs(e[i].to,x);
		}
}
int main()
{
	bin[0]=1;for(int i=1;i<=30;i++)bin[i]=bin[i-1]<<1;
	n=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		insert(u,v,w);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		trie.insert(val[i]);
	for(int i=1;i<=n;i++)
		trie.query(val[i]);
	printf("%d",ans);
	return 0;
}
