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
#define cla(x) memset(x,0,sizeof x)
#define meminf(x) memset(x,127,sizeof x)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
const int oo = 0x3f3f3f3f;
const int N = 500050;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
#define  getchar() nc()
inline int rd()
{
    int x = 0 , f = 1; char CH = getchar();
    while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
    while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    return f ? x : -x;
}
int n,a[N],m; 
struct segment{
	int ls,rs,sum,f;
}t[N<<2];
inline void push_up(int k){
	t[k].sum=t[k<<1|1].sum+t[k<<1].sum;
	t[k].f=max(max(t[k<<1].f,t[k<<1|1].f),t[k<<1].rs+t[k<<1|1].ls);
	t[k].ls=max(t[k<<1].ls,t[k<<1].sum+t[k<<1|1].ls);
	t[k].rs=max(t[k<<1|1].rs,t[k<<1].rs+t[k<<1|1].sum); 
}
inline void build(int k,int l,int r){
	if(l==r) {t[k].ls=t[k].rs=t[k].sum=t[k].f=a[l];	return;}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	push_up(k);
}
inline void modify(int k,int l,int r,int x,int v){
	int mid=(l+r)>>1;
	if(l==r) {
		t[k].ls=t[k].rs=t[k].sum=t[k].f=v;	return;
	}
	if(x<=mid) modify(k<<1,l,mid,x,v );
	else modify(k<<1|1,mid+1,r,x,v );
	push_up(k); 
}
struct Node{int f,l,r,tot;};
inline Node query(int o,int L,int R,int l,int r){
	int mid=L+R>>1;
	if(L==l&&R==r)return (Node){t[o].f,t[o].ls,t[o].rs,t[o].sum};
	if(r<=mid)return query(o<<1,L,mid,l,r);else if(l>mid)return query(o<<1|1,mid+1,R,l,r);
	else {
		Node a=query(o<<1,L,mid,l,mid ),b=query(o<<1|1,mid+1,R,mid+1,r );
		Node r;r.f=max(max(a.f,b.f),a.r+b.l),r.l=max(a.l,a.tot+b.l),r.r=max(b.r,b.tot+a.r);
		r.tot=a.tot+b.tot;
		return r;
	}
}
int main()
{
#ifdef iloi
	freopen("test.txt","r",stdin);
#endif
	n=rd(); m=rd();
	rep(i,1,n) a[i]=rd();
	build(1,1,n);
	while(m--){
		int op=rd(),x=rd(),y=rd();
		if(op==1){
			if(x>y)swap(x,y);
			printf("%d\n",query(1,1,n,x,y).f);}
		else {
			modify(1,1,n,x,y);
		}
	}
}
