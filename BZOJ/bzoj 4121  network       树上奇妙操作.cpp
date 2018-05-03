#include<bits/stdc++.h>
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
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int N = 500050;
const int M = N<<1;
bool odw[N];
int leaves[N],numleaves,subtree,n;
int cnt,fir[N],nxt[M],to[M],cd[N],w[M];
vector<int> S[N],W;
inline void AE(int u,int v)
{
	to[++cnt]=v;nxt[cnt]=fir[u];fir[u]=cnt;cd[u]++;
}
inline int dfs1(int x)
{
	odw[x]=true;
	if(cd[x]==1)
		leaves[x]=1;
	for(int i=fir[x];i;i=nxt[i])
		if(!odw[to[i]])
		{
			dfs1(to[i]);
			leaves[x]+=leaves[to[i]];
		}
}
inline int findcut(int x)
{
	  odw[x] = true;
	  for(int i=fir[x];i;i=nxt[i])
	    if(!odw[to[i]])
	      if(leaves[to[i]] > numleaves/2)
	       return findcut(to[i]);
		return x;
}
inline void dfs2(int x,int tree)
{
	  odw[x] = true;
	  if(cd[x]==1)
	    S[tree].push_back(x);
	  for(int i=fir[x];i;i=nxt[i])
	    if(!odw[to[i]])
	      	dfs2(to[i],tree);
}
inline int cut(int n)
{
	  dfs1(1);
	  for(int i=1;i<=n;i++)
			odw[i]=false;
	  int w=findcut(1);
	  for(int i=1;i<=n;i++)
	    	odw[i]=false;
	  	odw[w]=true;
	  for(int i=fir[w];i;i=nxt[i])
	    dfs2(to[i],++subtree);
	  return w;
}
inline int calc(int e,int w)
{
	e+=2;
	return e==w?1:e;
}
int main()
{
	n=read();int x,y;
	for(int i=1;i<n;i++)
	{
		x=read(),y=read();
		AE(x,y);AE(y,x);
	}
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	else if(n==2)
	{
		cout<<1<<endl;
		cout<<x<<" "<<y;
		return 0;
	}
	for(int i=1;i<=n;i++)
	if(cd[i]==1)	++numleaves;
	int res=(numleaves+1)>>1;
	printf("%d\n",res);
	cut(n);
	int e=0;W.resize(res<<1);
	for(int i=1;i<=subtree;i++)
		for(int j=0;j<S[i].size();j++)
		{
			W[e]=S[i][j];
			e=calc(e,res<<1);
		}
	if((!W.empty())&W.back()==0)
    	W.back()=S[1][0];
  	for(int i=0;i<(int)W.size();i+=2)
    	printf("%d %d\n",W[i],W[i+1]);
}
