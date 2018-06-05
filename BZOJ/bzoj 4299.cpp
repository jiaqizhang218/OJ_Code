#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
typedef long long LL;
const int INF = 0x7fffffff;
const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc() //*/
template <typename T> inline void rd(T &x) {x = 0; int f = 1; char CH = getchar();while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}x=(f==1)?x:-x;  return;}
const int MXN = 1e5 + 5;
int n,m,a[MXN];
int rt[MXN],ls[MXN*40],rs[MXN*40],cnt=1;
LL sum[MXN*40];
void update(int &y,int x,int l,int r,int val) {
	y=++cnt; ls[y]=ls[x] , rs[y] = rs[x] , sum[y] = sum[x] + val;
	if(l==r) return;
	int mid=l+r>>1;
	if(val<=mid) update(ls[y],ls[x],l,mid,val);
	else update(rs[y],rs[x],mid+1,r,val);
}
LL query(int x,int y,int l,int r,int val) {
	if(l==r) return sum[y]-sum[x];
	int mid=l+r>>1;
	if(val<=mid) return query(ls[x],ls[y],l,mid,val);
	else return sum[ls[y]]-sum[ls[x]]+query(rs[x],rs[y],mid+1,r,val);
}
int main() {
#ifdef iloi
	   freopen("test.in","r",stdin);
#endif
	rd(n);
	rep(i,1,n) {int x;rd(x);update(rt[i],rt[i-1],1,1e9,x);}
	rd(m);
	rep(owo,1,m) {
		LL last=0,mx=0;int l,r;
		rd(l),rd(r);
		while(1) {
			mx=query(rt[l-1],rt[r],1,1e9,mx+1);
			if(mx==last) {printf("%d\n",mx+1);break;}
			last=mx;
		}
	}
	return 0;
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
