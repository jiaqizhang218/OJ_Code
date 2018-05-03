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
int n,m,cnt=1,ans1,ans2,dis[501],from[501],head[501],q[501],S,T;
bool inq[501];
struct data {
	int from,to,next,v,c;
}e[100001];
inline void ins(int u,int v,int w,int c) {
	e[++cnt].from=u,e[cnt].to=v,e[cnt].v=w,e[cnt].c=c,e[cnt].next=head[u],head[u]=cnt;
}
inline void insert(int u,int v,int w,int c) {
	ins(u,v,w,c);ins(v,u,0,-c);
}
inline bool spfa() {
	int t=0,w=1,i,now;
	for(int i=S;i<=T;i++)	dis[i]=INF;
	q[0]=S;dis[S]=0;inq[S]=1;
	while(t!=w){
		now=q[t++];
		if(t==500)	t=0;
		for(int i=head[now];i;i=e[i].next) {
			if(e[i].v&&e[i].c+dis[now]<dis[e[i].to]) {
				dis[e[i].to]=dis[now]+e[i].c;
				from[e[i].to]=i;
				if(!inq[e[i].to]) {
					inq[e[i].to]=true;
					q[w++]=e[i].to;
					if(w==500) w=0;
				}
			}
		}
		inq[now]=false;
	}
	if(dis[T]==INF)	return false;
	return true;
}
inline void mcf() {
	int x=INF,i;
	for(i=from[T];i;i=from[e[i].from]) {
		x=min(x,e[i].v);
	}
	ans1++;
	for(i=from[T];i;i=from[e[i].from]) {
		ans2+=x*e[i].c;
		e[i].v-=x;
		e[i^1].v+=x;
	}
}
int main()
{
	n=read(),m=read();
	S=1,T=n<<1;
	for(int i=1;i<=m;i++) {
		int u=read(),v=read(),w=read();
		insert(u+n,v,1,w);
	}
	for(int i=2;i<n;i++) {
		insert(i,i+n,1,0);
	}
	insert(1,S+n,INF,0);
	insert(n,T,INF,0);
	while(spfa()) mcf();
	printf("%d %d",ans1,ans2);
	return 0;
}
