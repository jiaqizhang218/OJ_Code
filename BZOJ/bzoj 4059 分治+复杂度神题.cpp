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
const int MXN = 200010;
map<int,int> mp;
int n,m,tot,T;
int a[MXN],pre[MXN],nxt[MXN];
inline bool solve(int l,int r) {
	if(l>=r) return 1;
	int i=l,j=r;
	rep(k,l,r) {
			if(pre[i]<l && nxt[i]>r) return (solve(l,i-1)&solve(i+1,r));
			++i;
			if(pre[j]<l && nxt[j]>r) return (solve(l,j-1)&solve(j+1,r));
			--j;
	}
	return false;
}
int main()
{
	rd(T);
	while(T--) {
		rd(n); mp.clear();
		rep(i,1,n) rd(a[i]),nxt[mp[a[i]]]=i,pre[i]=mp[a[i]],mp[a[i]]=i;
		rep(i,1,n) nxt[mp[a[i]]]=n+1;
		if(solve(1,n)) puts("non-boring");
		else puts("boring");
	}
}
