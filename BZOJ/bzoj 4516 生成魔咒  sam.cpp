#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
typedef long long LL;
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
const int MXN = 231072;
int n; LL ans;
struct SAM{
	int p,q,np,nq,last,rt,cnt,l[MXN],f[MXN]; map<int,int> ch[MXN];
	SAM(){cnt=0;last=rt=++cnt;}
	inline void ins (int x) {
		p=last; np=last=++cnt; l[np]=l[p]+1;
		while(!ch[p][x]&&p) ch[p][x]=np,p=f[p];
		if(!p) f[np]=1;
		else {
			int q=ch[p][x];
			if(l[q]==l[p]+1) f[np]=q;
			else {
				nq=++cnt; l[nq]=l[p]+1;
				ch[nq]=ch[q],f[nq]=f[q],f[q]=f[np]=nq;
				while(p&&ch[p][x]==q) ch[p][x]=nq,p=f[p];
			}
		}
		ans+=l[np]-l[f[np]];
		printf("%lld\n",ans);
	}
	inline void solve() {
		rd(n); for(register int x,i=1;i<=n;++i) rd(x),ins(x);
	}
}sam;
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	sam.solve();
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
