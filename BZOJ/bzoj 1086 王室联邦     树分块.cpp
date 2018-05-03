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
int n,B,cnt,top,pro;
int last[1005],q[1005],size[1005],cap[1005],belong[1005];
struct data {
	int to,next;
}e[2005];
inline void insert(int u,int v) {
	e[++cnt].to = v , e[cnt].next = last[u] , last[u] = cnt;
	e[++cnt].to = u , e[cnt].next = last[v] , last[v] = cnt; 
} 
inline void dfs(int x,int fa) {
	q[++top] = x;
	for(int i=last[x];i;i=e[i].next) {
		if(e[i].to!=fa) {
			dfs(e[i].to,x);
			if(size[x]+size[e[i].to] >= B) {
				size[x] = 0;
				cap[++pro] = x;
				while(q[top] != x) {
					belong[q[top--]] = pro;
				}
			}
			else size[x]+=size[e[i].to];
		}
	}
	size[x]++;
} 
inline void paint(int x,int fa,int c) {
	if(belong[x])	c=belong[x];
	else belong[x]=c;
	for(int i=last[x];i;i=e[i].next) 
		if(e[i].to!=fa) 
			paint(e[i].to,x,c);
}
int main()
{
	n=read(),B=read();
	if(n<B)	{
		puts("0");
		return 0;
	}
	for(int i=1;i<n;i++) {
		int u=read(),v=read();
		insert(u,v);
	}
	dfs(1,0);
	if(!pro)	cap[++pro]=1;
	paint(1,0,pro);
	printf("%d\n",pro);
	for(int i=1;i<=n;i++)	printf("%d ",belong[i]);
	cout<<endl;
	for(int i=1;i<=pro;i++)	printf("%d ",cap[i]);
	return 0;
}
