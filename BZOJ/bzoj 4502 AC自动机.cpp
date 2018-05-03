#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
template <typename T>
inline void rd(T &x) {
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
int n,rt,tot;
char s[35];
queue<int> q;

struct node {
	int fa,siz,f,c[30];
}a[300055];


inline void Ins(char *s) {
	int len = strlen(s+1) , now = rt;
	rep(i,1,len) {
		if(!a[now].c[s[i]-'a']) {
			a[now].c[s[i]-'a'] = ++tot;
			a[tot].fa = now;
		}
		now = a[now].c[s[i]-'a'];
	}
}

inline void build() {
	rep(i,0,25) {
		if(a[rt].c[i]) q.push(a[rt].c[i]),a[a[rt].c[i]].f=rt;
	}
	while(!q.empty()) {
		int now = q.front(); q.pop();
		rep(i,0,25) {
			if(a[now].c[i]) {
				a[a[now].c[i]].f = a[a[now].f].c[i];
				q.push(a[now].c[i]);
			} else {
				a[now].c[i] = a[a[now].f].c[i];
			}
		}
	}
}

LL ans;


int main() {
#ifdef iloi
	   freopen("test.in","r",stdin);
#endif
	rd(n);
	rep(i,1,n) {
		scanf("%s",s+1);	Ins(s);
	}
	a[rt].f = rt;   build();
	rep(i,1,tot) {
		for(int j=a[i].f; j ; j=a[j].f) ++a[j].siz;
	}
	
	ans = 1LL * tot * tot;
	rep(i,1,tot) {
		int j = i , k = a[i].f;
		if(!k) continue;
		while(k) j = a[j].fa , k = a[k].fa;
		ans -= a[j].siz;
	}
	cout<<ans;
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
