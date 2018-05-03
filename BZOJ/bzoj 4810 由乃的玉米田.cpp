#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
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
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 1e5 + 5 , MXM = 1e5;
int n,m;
int a[MXN],bel[MXN],block,ans[MXN],cnt[MXN];
struct dog_fc{
	int l,r,id,opt,x;
}q[MXN];
inline bool cmp(dog_fc a,dog_fc b) {
	return bel[a.l]<bel[b.l]||(bel[a.l]==bel[b.l]&&a.r<b.r);
}
bitset<MXN> F,G;
inline void del(int x) {
	cnt[a[x]]--; if(!cnt[a[x]]) F.reset(a[x]),G.reset(MXM-a[x]);
}
inline void add(int x) {
	cnt[a[x]]++; F.set(a[x]),G.set(MXM-a[x]);
}
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(n),rd(m); block=(int)sqrt(n+0.5);
	rep(i,1,n) rd(a[i]),bel[i]=(i-1)/block+1;
	rep(i,1,m) q[i].id=i,rd(q[i].opt),rd(q[i].l),rd(q[i].r),rd(q[i].x);
	sort(q+1,q+1+m,cmp);
	int l=1,r=0;
	rep(i,1,m) {
		for(;r<q[i].r;r++) add(r+1);
		for(;l<q[i].l;l++) del(l);
		for(;l>q[i].l;l--) add(l-1);
		for(;r>q[i].r;r--) del(r);
		if(q[i].opt==1) {if((F&F>>q[i].x).any()) ans[q[i].id]=1;}
		else if(q[i].opt==2) {if((F&G>>(MXM-q[i].x)).any()) ans[q[i].id]=1;}
		else {
			rep(j,1,sqrt(q[i].x)+1) if(q[i].x%j==0) 
				if(F[j]&F[q[i].x/j]) {
					ans[q[i].id]=1;break;
				}
		}
	}
	rep(i,1,m) puts(ans[i]?"yuno":"yumi");
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

