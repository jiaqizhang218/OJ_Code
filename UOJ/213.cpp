#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_end=(b);i>=i##_end;--i)
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ull;
template <typename T> inline void rd(T &x) {
    x=0;int f=1;char CH=getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;return;
}
const int MXN = 1e6 + 6 , Mod = 998244353;
int p,q,n,stk[MXN],top,ls[MXN],rs[MXN];
LL ans,a[MXN],s[MXN],ss[MXN];
template <typename T> inline void Add(T &x,T y) {
	x+=y; if(x>=Mod) x%=Mod; if(x<0) x+=Mod;
}

int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
#endif
	rd(n); rep(i,1,n) rd(a[i]);	
	rep(i,1,n) {
		while(top&&a[i]>a[stk[top]]) top--;
		ls[i]=stk[top]; stk[++top]=i;
	}
	top=0; stk[0]=n+1;
	per(i,n,1) {
		while(top && a[i] >= a[stk[top]]) top--;
		rs[i]=stk[top] , stk[++top]=i;
		p=i-ls[i],q=rs[i]-i;
		if(p>q) swap(p,q);
		Add(ss[1],a[i]),Add(ss[p],-a[i]),
		Add(s[p],p*a[i]%Mod),Add(s[q],-p*a[i]%Mod),
		Add(ss[q],-a[i]),Add(ss[p+q],a[i]),
		Add(s[q],(p+q)*a[i]%Mod),Add(s[p+q],-(p+q)*a[i]%Mod);
	}
	rep(i,1,n) Add(s[i],s[i-1]),Add(ss[i],ss[i-1]),ans^=(s[i]+ss[i]*i)%Mod;
	cout<<ans;
}
