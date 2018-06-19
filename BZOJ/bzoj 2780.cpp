#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define For(i,a,b) for(register int i=(a),i##_end=(b);i<i##_end;++i)
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define SZ(x) (x.size())
#define bin(i) (1<<i)
#define cls(x,y) memset(x,y,sizeof x)
typedef pair<int,int> PII;
typedef long long LL;
const int INF = 0x7fffffff;
/*const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc() //*/
template <typename T> inline void rd(T &x) {
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 4e5 + 5;
string str[MXN>>1];
int n,Q;
struct SAM {
	int cnt,last,rt,np,nq,p,q,l[MXN],sz[MXN],fail[MXN],c[MXN][26],col[MXN],cur[MXN];
 	SAM(){cnt=0;last=rt=++cnt;}
	inline void extend(int x){
		p = last; np = last = ++cnt; l[np] = l[p] + 1; sz[np]=1;
		while(!c[p][x] && p) c[p][x] = np ,p = fail[p];
		if(!p) fail[np] = rt;
		else {
			q = c[p][x];
			if(l[q] == l[p] + 1) fail[np] = q;
			else {
				nq = ++cnt; l[nq] = l[p] + 1;
				memcpy(c[nq],c[q],sizeof c[q]);
				fail[nq] = fail[q] , fail[q] = fail[np] = nq;
				while(c[p][x] == q && p) c[p][x] = nq , p = fail[p];
			}
		}
	}
	inline void pre() {
		rep(i,1,n) {
			string s=str[i]; int len=s.size(),now=rt;
			For(j,0,len) {
				now=c[now][s[j]-'a'];
				int tmp=now;
				for(;tmp&&cur[tmp]!=i;tmp=fail[tmp]) col[tmp]++,cur[tmp]=i;
			}
		}
	}
	char s[MXN];
	inline void solve() {
		scanf("%s",s);
		int len=strlen(s),now=rt;
		For(i,0,len) {
			if(c[now][s[i]-'a']) now=c[now][s[i]-'a'];
			else {puts("0");return;}
		}
		printf("%d\n",col[now]);
	}
}sam;

int main() {
#ifdef iloi
	FO(1);
#endif
	rd(n),rd(Q);
	rep(i,1,n) {
//		scanf("%s",str[i][0]); 
		cin>>str[i]; 
		sam.last=sam.rt;
		int len=str[i].size();
		For(j,0,len) sam.extend(str[i][j]-'a');
	}
	sam.pre();
	while(Q--) sam.solve();
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
