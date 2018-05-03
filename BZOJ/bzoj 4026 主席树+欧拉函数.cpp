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
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
//#define  getchar() nc()
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
    while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;
    return;
}
inline int gi(){int x;rd(x);return x;}
inline LL gll(){LL x;rd(x);return x;}
const int N = 1e6+1000;
const int H =5e4 + 5;
const int M = 5e6 + 5;
const int Mod = 1e6 + 777;
int isprime[N],prime[N],prnum[N],cc;
int rev[N],has[N];
struct Node{
	int to,nxt;
}e[N<<1];
int fir[N],eot=0,n,q,a[H],T[H],ls[M],rs[M],v[M],tot,puf[H];
inline void AE(int u,int v) {e[++eot].to=v;e[eot].nxt=fir[u];fir[u]=eot;}
inline int build(int l,int r) {
	int rt=tot++;
	v[rt]=1; if(l==r) return rt;
	int mid=(l+r)>>1;
	ls[rt]=build(l,mid),rs[rt]=build(mid+1,r);
	return rt;
}
inline int update(int pos,int num,int l,int r,int pr) {
	int rt=tot++;
	v[rt]=1LL*v[pr]*num%Mod;
	if(l==r)	return rt;
	int mid=(l+r)>>1;
	if(pos<=mid) {
		ls[rt]=update(pos,num,l,mid,ls[pr]); 
		rs[rt]=rs[pr];
	}else {
		ls[rt]=ls[pr];
		rs[rt]=update(pos,num,mid+1,r,rs[pr]);
	}
	return rt;
}
inline int query(int L,int R,int l,int r,int rt) {
	if(L<=l&&r<=R)	return v[rt];
	int mid=(l+r)>>1,ans=1;
	if(L<=mid) ans=1LL*ans*query(L,R,l,mid,ls[rt])%Mod;
	if(R>mid) ans=1LL*ans*query(L,R,mid+1,r,rs[rt])%Mod;
	return ans;
}
		
int main()
{
#ifdef	iloi
	freopen("test.txt","r",stdin);
#endif
	rep(i,2,N-1) {
		if(!isprime[i]) { 
			prime[++cc]=i;
			for(int j=i;j<N;j+=i) {
				isprime[j]=1;AE(j,i);
			}
		}
	}
	rev[0]=rev[1]=1;
	rep(i,2,N-1) rev[i]=1LL*(Mod-Mod/i)*rev[Mod%i] % Mod;
	rep(i,1,cc) prnum[prime[i]]=1LL*(prime[i])*rev[prime[i]]%Mod;
	rd(n),rd(q);
	rep(i,1,n) a[i]=gi();
	puf[0]=1; T[0]=build(1,n);
	rep(i,1,n) {
		puf[i] = 1LL * puf[i-1] * a[i] % Mod;
		int tmp=T[i-1] , tt=1;
		rpg(j,a[i]) {
			int x=e[j].to;
			if(has[x]) tmp=update(has[x],rev[prnum[x]],1,n,tmp);
			tt = 1LL * tt * prnum[x] % Mod;
			has[x]=i;
		}
		T[i] = update(i,tt,1,n,tmp);
	}
	int ans=0;
	while(q--) {
		int l=gi(),r=gi();
		l^=ans,r^=ans;
		ans=query(l,r,1,n,T[r]);
		ans=1LL * ans * puf[r] % Mod * rev[puf[l-1]] % Mod;
		printf("%d\n",ans);
	}	
}
