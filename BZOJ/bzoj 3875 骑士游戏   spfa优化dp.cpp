#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int M = 2010000;
const int N = 201000;
using namespace std;
inline LL read()
{
	LL x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
struct KSD {
	int v,next;
}e[M],E[M];
int head[N],HEAD[N],cnt;
inline void add(int u,int v) {
	e[++cnt].v = v; E[cnt].v = u; e[cnt].next = head[u] ; E[cnt].next = HEAD[v]; HEAD[v]=head[u]=cnt;
}
LL A[N],dist[N];
bool in[N];
int n;
queue <int> q;
inline void spfa() {
	while(!q.empty()) q.pop();
	int i,u,v;
	for(i=1;i<=n;i++) q.push(i),in[i]=1;
	while(!q.empty()) {
		u=q.front(),q.pop(),in[u]=0;
		LL temp=A[u];
		for(i=head[u];i;i=e[i].next) {
			temp += dist[e[i].v];
		}
		if(temp >= dist[u])	continue;
		dist[u] = temp;
		for(i=HEAD[u];i;i=E[i].next) {
			if(!in[v=E[i].v])	q.push(v),in[v]=1;
		}
	}
}
int main()
{
	int i,j,k,a,b,c;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		A[i]=read(),dist[i]=read();scanf("%d",&c);
		while(c--) {
			scanf("%d",&a);
			add(i,a);
		}
	} 
	spfa();
	cout<<dist[1];
	return 0;
}
