#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_end=(b);i>=i##_end;--i)
#define rpg(i,x) for(register int i=fir[x];i;i=e[i].nxt)
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ull;
template <typename T> inline void rd(T &x) {
    x=0;int f=1;char CH=getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;return;
}
template <typename T> inline bool chMax(T &a,T &b) {
    return a<b?a=b,true:false;
}
template <typename T> inline bool chMin(T &a,T &b) {
    return a>b?a=b,true:false;
} 
const int MXN = 1e5 + 5;
int n,fir[MXN],edge_cnt,vis[MXN],pri[MXN],pri_cnt;
struct edge {
	int to,nxt,w;
}e[MXN<<1];
inline void AE(int u,int v,int w) {
	e[++edge_cnt].to=v;e[edge_cnt].nxt=fir[u];fir[u]=edge_cnt;e[edge_cnt].w=w;
}
ull _rand() {
	ull ret=0,x=(1<<8)-1;
	rep(i,1,8) ret=ret<<8|(rand()&x);
	return ret;
}
map<int,ull> id; map<ull,int> f;
LL ans;
void dfs(int x,int fa,int val,ull cd) {
	if(val) {
		int m = sqrt(val);
		for(int i=1;pri[i]<=m;++i) {
			while(val%pri[i]==0) {
				if(!id.count(pri[i])) id[pri[i]]=_rand();
				cd ^= id[pri[i]];
				val /= pri[i];
			}
		}
		if(val > 1) {
			if(!id.count(val)) id[val]=_rand();
			cd ^= id[val];
		}
	}
	if(!f.count(cd)) f[cd]=1;
	else ans += f[cd]++;
	rpg(i,x) if(e[i].to!=fa) dfs(e[i].to,x,e[i].w,cd);
}

int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
#endif
	vis[1] = 1;
	for(int i=2;i<MXN;++i) {
		if(!vis[i]) {
			pri[++pri_cnt]=i;
		}
		for(int j=1;j<=pri_cnt&&pri[j]*i<MXN;++j) {
			vis[pri[j]*i]=1;
			if(i%pri[j]==0) break;
		}
	}
	rd(n);	srand(time(0));
	for(int i=1,x,y,z;i<n;++i) {
		rd(x),rd(y),rd(z); AE(x,y,z),AE(y,x,z);
	}
	dfs(1,0,0,0);
	printf("%lld\n",ans*2);
}
