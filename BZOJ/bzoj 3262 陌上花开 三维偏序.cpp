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
const int M = 5000005;
int n,m,sz,tmp;
int rt[200005],ans[100005],sum[100005];
int s[M],ls[M],rs[M],v[M],w[M],rnd[M];
struct data{int a,b,c;}a[100005];
inline int getrand(){
	static int fuck = 2333;
	return fuck = (int)(fuck*48271LL%2147483647);
}
inline bool cmp(data a,data b){
	if(a.a==b.a&&a.b==b.b)	return a.c<b.c;
	else if(a.a==b.a)	return a.b<b.b;
	else return a.a<b.a;
}
inline int lowbit(int x) 
{return x&(-x);}
inline void update(int x) 
{s[x]=s[ls[x]]+s[rs[x]]+w[x];}
inline void rturn(int &k) 
{int t=ls[k];ls[k]=rs[t];rs[t]=k;update(k);update(t);k=t;}
inline void lturn(int &k)
{int t=rs[k];rs[k]=ls[t];ls[t]=k;update(k);update(t);k=t;}
inline void ins(int &k,int num)
{
	if(!k) { k=++sz;rnd[k]=getrand();v[k]=num;s[k]=w[k]=1;return;}
	s[k]++;
	if(num==v[k]){w[k]++;return;}
	else if(num<v[k]){ins(ls[k],num);if(rnd[ls[k]]<rnd[k])rturn(k);}
	else {ins(rs[k],num);if(rnd[rs[k]]<rnd[k])lturn(k);}
}
inline void getrank(int k,int num)
{
	if(!k)	return;
	if(num==v[k]) {tmp+=s[ls[k]]+w[k];return;}
	else if(num<v[k]) { getrank(ls[k],num);}
	else {tmp+=s[ls[k]]+w[k];getrank(rs[k],num);}
}
inline void ask(int x,int num)
{for(int i=x;i;i-=lowbit(i))	getrank(rt[i],num);}
inline void insert(int x,int num)
{for(int i=x;i<=m;i+=lowbit(i)) ins(rt[i],num);}
int main()
{
	rd(n),rd(m);
	rep(i,1,n) rd(a[i].a),rd(a[i].b),rd(a[i].c);
	sort(a+1,a+1+n,cmp);
	rep(i,1,n) {
		if(a[i].a==a[i+1].a&&a[i].b==a[i+1].b&&a[i].c==a[i+1].c&&i!=n)
			sum[i+1]+=sum[i]+1;
		else 
		{
			tmp=0;
			ask(a[i].b,a[i].c);
			ans[tmp]+=sum[i]+1;
		}
		insert(a[i].b,a[i].c);
	}
	rep(i,0,n-1) printf("%d\n",ans[i]);
	return 0;
}
