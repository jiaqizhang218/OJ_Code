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
#define cls(x,y) memset(x,y,sizeof x)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
const int oo = 0x3f3f3f3f;
/*
const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc() //*/
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 1e5 + 5;
int fir[MXN],cnt,n,k,val[MXN]; LL f[MXN][3];
struct edge{
	int to,nxt;
}e[MXN<<1];
inline void AE(int u,int v){e[++cnt].to=v;e[cnt].nxt=fir[u];fir[u]=cnt;}
inline void ins(int u,int v){AE(u,v),AE(v,u);}
const int Mod = 1e9 + 7;
inline void dfs(int x,int fa) {
	bool flg=0;
	rpg(i,x) {
		int v=e[i].to;
		if(v==fa) continue;	flg=1;
		dfs(v,x);
		if(val[x]) {
			LL tmp = f[x][val[x]];
			if(val[v]==val[x])	{
				cout<<0<<endl; exit(0);
			}
			if(val[v]) (tmp+=f[v][val[v]])%=Mod;
			else rep(j,0,2) if(j!=val[x]) (tmp+=f[v][j])%=Mod;
			f[x][val[x]]=tmp%Mod;
		}
		else {
			if(val[v]==0) (f[x][1]+=f[v][val[v]])%=Mod,(f[x][2]+=f[v][val[v]])%=Mod;
			else if(val[v]==1) (f[x][0]+=f[v][val[v]])%=Mod,(f[x][2]+=f[v][val[v]])%=Mod;
			else if(val[v]==2) (f[x][1]+=f[v][val[v]])%=Mod,(f[x][0]+=f[v][val[v]])%=Mod;
			else {
				rep(j,0,2) rep(k,0,2) if(j!=k) (f[x][j]+=f[v][k])%=Mod;
			}
		}
	}
	if(!flg) {
		if(val[x]) f[x][val[x]]=1;
		else f[x][0]=f[x][1]=f[x][2]=1;
	}
}
int main()
{
#ifdef iloi
	//   freopen("test.txt","r",stdin);
#endif
	rd(n);	rd(k); for(int x,y,i=1;i<n;++i) rd(x),rd(y),ins(x,y);
	for(int x,y,i=1;i<=k;++i) rd(x),rd(y),val[x]=y-1;
	dfs(1,0);
	if(val[1]) cout<<f[1][val[1]]%Mod<<endl;
	else cout<<((f[1][0]+f[1][1])%Mod+f[1][2]%Mod)<<endl;
}
/*
4 1
1 2
1 3
1 4
4 3
*/
