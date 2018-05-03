#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define cls(x,y) memset(x,y,sizeof x)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
const int MXN = 1310721;
char s[MXN>>1]; int lens; LL ans;
struct SAM{
	int p,q,np,nq,cnt,root,last,ch[MXN][30],l[MXN],f[MXN],w[MXN],a[MXN],b[MXN],v[MXN];
	SAM(){cnt=0;root=last=++cnt;}
	inline void ins(int x) {
		p=last; np=last=++cnt; l[np]=l[p]+1; w[np]=v[np]=1;
		while(!ch[p][x]&&p) ch[p][x]=np,p=f[p];
		if(!p) f[np]=1;
		else {
			q=ch[p][x];
			if(l[p]+1==l[q]) f[np]=q;
			else {
				nq=++cnt; l[nq]=l[p]+1;
				memcpy(ch[nq],ch[q],sizeof ch[q]);
				f[nq]=f[q],f[np]=f[q]=nq;
				while(ch[p][x]==q&&p) ch[p][x]=nq,p=f[p];
			}
		}
	}
	inline void read() {char c;for(c=getchar();c!=EOF;c=getchar())s[++lens]=c;}
	inline void build() {rep(i,1,lens) ins(s[i]-'a');}
	inline void solve() {
		read(); build();
		rep(i,1,cnt) ++b[l[i]];
		rep(i,1,lens) b[i]+=b[i-1];
		rep(i,1,cnt) a[b[l[i]]--]=i;
		per(i,cnt,1) v[f[a[i]]]+=v[a[i]];
		ans=1LL*lens*(lens-1)/2*(lens+1);
		rep(i,1,cnt) ans-=1LL*w[f[i]]*v[i]*l[f[i]]*2,w[f[i]]+=v[i];
		printf("%lld\n",ans);
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

