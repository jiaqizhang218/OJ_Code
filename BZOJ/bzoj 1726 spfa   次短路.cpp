#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rpg(i,x) for(register int i=fir[x];i;i=e[i].nxt)
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define bin(i) (1<<i)
#define cla(x) memset(x,0,sizeof x)
#define meminf(x) memset(x,127,sizeof x)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
const int oo = 0x3f3f3f3f;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
//#define  getchar() nc()
inline int rd()
{
    int x = 0 , f = 1; char CH = getchar();
    while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
    while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    return f ? x : -x;
}
const int N = 5050,M=100050;
struct edge{
	int from,to,nxt,w;
}e[M<<1];
int fir[N],cnt,m,n,dis[2][N],vis[N],minrd=INF,cminrd=INF;
inline void AE(int u,int v,int w){e[++cnt].to=v;e[cnt].nxt=fir[u];fir[u]=cnt;e[cnt].w=w;e[cnt].from=u;}
inline void spfa(int kind,int s){
	memset(dis[kind],0x3f,sizeof dis[kind]);queue<int> q; 
	q.push(s);dis[kind][s]=0;
	while(!q.empty()){
		int now=q.front(); q.pop();
		rpg(i,now) {
			int v=e[i].to,w=e[i].w;
			if(dis[kind][v]>dis[kind][now]+w) { 
				q.push(v); dis[kind][v]=dis[kind][now]+w; vis[v]=true;
			}
		}
		vis[now]=false;
	}
} 
int main()
{
#ifdef	iloi
	freopen("test.txt","r",stdin);
#endif
	n=rd();m=rd();
	for(int i=1,a,b,c;i<=m;i++) a=rd(),b=rd(),c=rd(),AE(a,b,c),AE(b,a,c);
	spfa(0,1); spfa(1,n);
	minrd=dis[0][n];
	for(int i=1;i<=cnt;i+=2) {
		int u=e[i].from,v=e[i].to,w=e[i].w;
		if(dis[0][u]+w+dis[1][v]<cminrd&&dis[0][u]+w+dis[1][v]!=minrd) cminrd=dis[0][u]+w+dis[1][v];
		if(dis[0][v]+w+dis[1][u]<cminrd&&dis[0][v]+w+dis[1][u]!=minrd) cminrd=dis[0][v]+w+dis[1][u];
	}
	cout<<cminrd<<endl;
}
