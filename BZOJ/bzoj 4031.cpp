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
const int Mod = 1e9 ;
int n,m,S;
int s[11][11],a[82][82];
char z[11][11];
inline int guess() {
	S--;	//消去一行一列
	rep(i,1,S) rep(j,1,S) a[i][j]=(a[i][j]+Mod)%Mod;
	LL ans = 1;
	rep(j,1,S) {
		rep(i,j+1,S) 
			while(a[i][j]) {
				LL t = a[j][j] / a[i][j];
				rep(k,j,S) a[j][k]=(a[j][k]-t*a[i][k]%Mod + Mod)%Mod,swap(a[j][k],a[i][k]);
				ans*=-1;
			}
			ans = ans * a[j][j] % Mod;
		}
	return (ans+Mod)%Mod;
}
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(n);rd(m);
	rep(i,1,n)	scanf("%s",z[i]+1);
	rep(i,0,n+1) rep(j,0,m+1) if(i==0||j==0||i==n+1||j==m+1) z[i][j]='*';
	rep(i,1,n)	rep(j,1,m) {
		if(z[i][j]=='.') {
			s[i][j]=++S;
			if(z[i-1][j]=='.') a[s[i-1][j]][s[i][j]]=1,a[s[i][j]][s[i-1][j]]=1;
			if(z[i][j-1]=='.') a[s[i][j-1]][s[i][j]]=1,a[s[i][j]][s[i][j-1]]=1;
		}	
	}
	rep(i,1,S) rep(j,1,S) if(a[i][j]&&i!=j) a[i][i]++;
//	dbg(n), dbg(m); dbg(S);
	cout<<guess()<<endl;
}
