#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
const int MAXN = 200010;
const int MAXM = 800010;
int n,ecnt,first[MAXN],nxt[MAXM],to[MAXM],w[MAXM];
LL dis[MAXN];
struct node {
	int x,y,id;
}a[MAXN];
inline bool cmpx(node q,node qq) {
	return q.x<qq.x;
}
inline bool cmpy(node q,node qq) {
	return q.y<qq.y;
}
struct Val {
	LL dis;
	int x;
	bool operator < (const Val &a) const {
		return a.dis < dis;
	}
}tmp;
priority_queue <Val> Q;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
inline void link(int x,int y,int z) {
	nxt[++ecnt] = first[x] ; first[x] = ecnt ; to[ecnt] = y ; w[ecnt] = z;
	nxt[++ecnt] = first[y] ; first[y] = ecnt ; to[ecnt] = x ; w[ecnt] = z;
}
inline void work() {
	n = read() ;
	for(int i=1;i<=n;i++) {
		a[i].x=read(),a[i].y=read(),a[i].id=i;
	}
	for(int i=1;i<=n;i++) 
		dis[i]=INF;		dis[1]=0;
	sort(a+1,a+n+1,cmpx);	for(int i=1;i<n;i++)	link(a[i].id,a[i+1].id,a[i+1].x-a[i].x);
	sort(a+1,a+n+1,cmpy);	for(int i=1;i<n;i++)	link(a[i].id,a[i+1].id,a[i+1].y-a[i].y);
	tmp.dis = 0, tmp.x = 1;
	Q.push(tmp); int x;
	while(!Q.empty()) {
		tmp = Q.top(); Q.pop();
		x = tmp.x;	if(dis[x] != tmp.dis)	continue;
		for(int i=first[x];i;i=nxt[i]) {
			int v = to[i];
			if(dis[v] > dis[x] + w[i]) {
				dis[v] = dis[x] + w[i];
				tmp.x=v;tmp.dis=dis[v];
				Q.push(tmp);
			}
		}
	}
	cout<<dis[n];
}
int main()
{
	work();
}
