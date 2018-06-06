#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rpg(i,x) for(register int i=fir[x];i;i=e[i].nxt)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
template <typename T> inline void rd(T &x) {
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 5e3 + 5 , MXM = 2e5 + 5;
int fir[MXN],edge_cnt;
struct edge {
	int to,nxt,from,d;
}e[MXM<<1];
inline void AE(int u,int v) {
	e[++edge_cnt].to=v;e[edge_cnt].from=u;e[edge_cnt].nxt=fir[u];fir[u]=edge_cnt;
}
int fa[MXN];
inline int getfa(int x) {
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
int x[MXM],y[MXM];
struct que {
	int opt,x,y;
}q[MXN<<1];
int mp[MXN][MXN];
int cnt,v[MXN],flag,bel[MXN];
void dfs(int x,int ed,int fro) {
	if(x==ed) flag=1;
	if(flag) return;
	rpg(i,x) {
		int y=e[i].to;
		if(v[y]!=fro&&e[i].d>0) {
			v[y]=fro;
			dfs(y,ed,fro);
			if(flag) return;
		}
	}
}
int main()
{
#ifdef iloi
	   freopen("test.in","r",stdin);
#endif
	int n,m;
	rd(n),rd(m);
	rep(i,1,m) rd(x[i]),rd(y[i]);
	int Q;
	rd(Q);
	rep(i,1,Q) {
		char fk[2]; scanf("%s",fk);
		if(fk[0]=='A') {
			rd(q[i].x),rd(q[i].y);
			q[i].opt=1;
		} else if(fk[0]=='D') {
			rd(q[i].x),rd(q[i].y);
			q[i].opt=2; mp[q[i].x][q[i].y]=mp[q[i].y][q[i].x]=1;
		} else {
			q[i].opt=3;
		}
	}
	rep(i,1,n) fa[i]=i;
	rep(i,1,m) {
		if(mp[x[i]][y[i]]==0&&getfa(x[i])!=getfa(y[i])) fa[x[i]]=y[i];
		else mp[x[i]][y[i]]=mp[y[i]][x[i]]=0;
	}
	rep(i,1,n) if(fa[i]==i) cnt++,bel[i]=cnt;
	rep(i,1,n) {
		fa[i]=getfa(i);
		bel[i]=bel[fa[i]];
	}
	rep(i,1,m) {
		int X=bel[x[i]],Y=bel[y[i]];
		if(X!=Y) {
			flag=0;
			v[X]=i; dfs(X,Y,i);
			if(!flag) cnt--;
			if(mp[X][Y]==0) AE(X,Y),mp[X][Y]=edge_cnt;
			if(mp[Y][X]==0) AE(Y,X),mp[Y][X]=edge_cnt;
			e[mp[X][Y]].d++;
			e[mp[Y][X]].d++;
		}
	}
	memset(v,0,sizeof v);
	rep(i,1,Q) {
		int X=bel[q[i].x],Y=bel[q[i].y];
		if(q[i].opt==3) printf("%d\n",cnt);
		else if(q[i].opt==1) {
			flag=0;
			v[X]=i; dfs(X,Y,i);
			if(!flag) cnt--;
			if(mp[X][Y]==0) AE(X,Y),mp[X][Y]=edge_cnt;
			if(mp[Y][X]==0) AE(Y,X),mp[Y][X]=edge_cnt;
			e[mp[X][Y]].d++;
			e[mp[Y][X]].d++;
		} else {
			flag=0;
			e[mp[X][Y]].d--;
			e[mp[Y][X]].d--;
			v[X]=i; dfs(X,Y,i);
			if(!flag) cnt++;
		}
	}
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
