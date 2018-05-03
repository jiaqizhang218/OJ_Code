#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
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
/*const int _L = 1e6+5;
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
const int MXN = 3e5 + 5;
int siz,n,k,cnt;
int ls[MXN],d[MXN]; 
LL ans[MXN];
char s1[10],s2[10];
struct data{
	int x[3];
}a[MXN];
struct Segtree{
	int siz; LL sum;
}t[MXN<<2];
int z[10];
inline bool cmp(data a,data b){return a.x[1]+a.x[2]<b.x[1]+b.x[2];}
inline void update(int x){t[x].sum=t[x<<1].sum+t[x<<1|1].sum;t[x].siz=t[x<<1].siz+t[x<<1|1].siz;}
inline void build(int x,int l,int r) {
	if(l==r) {
		t[x].sum=t[x].siz=0;return;
	}
	int m=l+r>>1;
	build(x<<1,l,m);
	build(x<<1|1,m+1,r);
	update(x);
}
inline void insert(int x,int l,int r,int k) {
	if(l==r) {
		t[x].sum+=d[l]; t[x].siz++;
		return ;
	}
	int mid=l+r>>1;
	if(k<=mid) insert(x<<1,l,mid,k);
	else insert(x<<1|1,mid+1,r,k);
	update(x);
}
inline LL getsum(int x,int l,int r,int cnt) {
	if(t[x].siz<=cnt) return t[x].sum;
	if(l==r) return 1LL*cnt*d[l];
	int mid=l+r>>1;
	if(t[x<<1].siz>=cnt) return getsum(x<<1,l,mid,cnt);
	else return t[x<<1].sum+getsum(x<<1|1,mid+1,r,cnt-t[x<<1].siz);
}
inline LL query(LL k) {
	LL s=getsum(1,1,siz,k);
	return t[1].sum-2LL*s;
}
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(k),rd(n); LL pre=0;	int tot=0;	
	rep(i,1,n) {
		int x1,x2;
		scanf("%s%d%s%d",s1,&x1,s2,&x2);
		if(s1[0]==s2[0]) {
			pre+=abs(x1-x2);
			continue;
		}
		pre++;
		a[++tot].x[1]=x1,a[tot].x[2]=x2;
		ls[++cnt]=x1,ls[++cnt]=x2;
	}
	if(cnt) {
		sort(ls+1,ls+1+cnt);
		siz=unique(ls+1,ls+1+cnt)-ls-1;
		n=tot;
		rep(i,1,n) {
			int tmp=lower_bound(ls+1,ls+1+siz,a[i].x[1])-ls,tmp2=lower_bound(ls+1,ls+1+siz,a[i].x[2])-ls;
			d[tmp]=a[i].x[1],d[tmp2]=a[i].x[2];
		}
		build(1,1,siz);
		sort(a+1,a+1+n,cmp);
		rep(i,1,n) {
			insert(1,1,siz,(lower_bound(ls+1,ls+1+siz,a[i].x[1])-ls));
			insert(1,1,siz,(lower_bound(ls+1,ls+1+siz,a[i].x[2])-ls));
			ans[i]=query(i);
		}
	}
	if(k==1) return cout<<ans[n]+pre<<endl,0;
	else {
		LL Ans=ans[n];
		if(siz) {
			build(1,1,siz);
			per(i,n,2) {
				insert(1,1,siz,lower_bound(ls+1,ls+1+siz,a[i].x[1])-ls);
				insert(1,1,siz,lower_bound(ls+1,ls+1+siz,a[i].x[2])-ls);
				Ans=min(Ans,ans[i-1]+query(n-i+1));
			}
		}
		cout<<Ans+pre<<endl;
	}
	return 0;
#ifdef iloi
	debug("\nMy Time: %.4lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

