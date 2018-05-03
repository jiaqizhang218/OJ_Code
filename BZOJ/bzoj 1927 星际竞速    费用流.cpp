#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int maxm = 15050;
const int maxn = 809;
const int T = 5; 
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
struct E{
	int to,flow,cap,w;	E(){}
	E(int to,int flow,int cap,int w): to(to),flow(flow),cap(cap),w(w){}
}edges[maxm*T];
int n,m,s,t,cnt,tot,ans,A[maxn],B[maxn],from[maxn*T],dis[maxn*T],a[maxn*T];
bool vis[maxn*T];
queue<int> Q;
vector<int> v[maxn*T];
inline bool spfa()
{
	for(int i=s;i<=t;i++)
		dis[i]=INF,vis[i]=a[i]=0;
	dis[s]=0; vis[s]=1;
	Q.push(s);	a[s]=INF;
	while(!Q.empty())
	{
		int k=Q.front(); Q.pop();
		vis[k]=0;
		for(int i=0;i<v[k].size();i++)
		{
			E e=edges[v[k][i]];
			if(e.cap == e.flow)	continue;
			if(dis[e.to]>dis[k]+e.w)	
			{
				dis[e.to]=dis[k]+e.w;
				a[e.to]=min(a[k],e.cap-e.flow);
				from[e.to]=v[k][i];
				if(!vis[e.to])	vis[e.to]=1,Q.push(e.to);
			}
		}
	}
	return dis[t]!=INF;
}
inline void Add(int x,int y,int cap,int w)
{
	v[x].push_back(cnt);
	edges[cnt++]=E(y,0,cap,w);
	v[y].push_back(cnt);
	edges[cnt++]=E(x,0,0,-w);	
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		A[i]=++tot,B[i]=++tot;
	t = ++ tot;
	for(int i=1;i<=n;i++)
	{
		int x=read();
		Add(s,A[i],1,0);
		Add(B[i],t,1,0);
		Add(s,B[i],1,x);
	}
	while(m--)
	{
		int x=read(),y=read(),w=read();
		if(x>y)	swap(x,y);
		Add(A[x],B[y],1,w);
	}
	while(spfa())
	{
		ans+=a[t]*dis[t];
		for(int now=t;now!=s;now=edges[from[now]^1].to)
		{
			edges[from[now]].flow += a[t];
			edges[from[now]^1].flow -= a[t];
		}
	}
	cout<<ans;
	return 0;
}
