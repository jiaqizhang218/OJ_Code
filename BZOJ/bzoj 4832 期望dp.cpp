#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
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
double f[55][10][10][10];
int main()
{
	int T,K,A,B,C;
	for(rd(T);T--;) {
		rd(K),rd(A),rd(B),rd(C);
		cls(f,0);
		f[0][C][B][A]=1.0; double ans = 0.0;
		rep(i,0,K-1) {
			rep(j,0,7) {
				rep(l,0,7-j) {
					rep(k,0,7-j-l) {
					#define tmp (1+j+l+k)
					#define cc f[i][j][l][k]
						f[i+1][j][l][k]+=cc/tmp;
						ans += cc/tmp;
						if(k) f[i+1][j][l][k-1]+=cc*k/tmp;
						if(j+l+k<7) {
							if(l) f[i+1][j+1][l-1][k+1]+=cc*l/tmp;
							if(j) f[i+1][j][l+1][k]+=cc*j/tmp;
						}
						else {
							if(l) f[i+1][j][l-1][k+1]+=cc*l/tmp;
							if(j) f[i+1][j-1][l+1][k]+=cc*j/tmp;
						}
					#undef tmp
					#undef cc
					}
				}
			}
		}
		printf("%.2lf\n",ans);
	}
}
