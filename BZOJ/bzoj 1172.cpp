#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
typedef long long LL;
const int INF = 0x7fffffff;
template <typename T>
inline void rd(T &x) {
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r
#define ql (x[pos])
#define qr (y[pos])
const int MXN = 3e5 + 5 ;
list<int> q[MXN<<2];
int L,tr[MXN<<2],cnt,gery[MXN*2],x[MXN],a[MXN],y[MXN],d[MXN],f[MXN],n;
inline int find(int k) {
	return lower_bound(gery+1,gery+1+cnt,k)-gery;
}
inline int get(int k) {
	return (!q[k].empty())?f[q[k].front()]:INF;
}
void build(int k,int l,int r) {
	tr[k]=INF;  if(l==r) return;
	int mid=l+r>>1;
	build(lson),build(rson);
}
void modify(int k,int l,int r,int pos,int val) {
	int mid = l + r >> 1;
	if(ql<=l&&r<=qr) {
		if(val) while(!q[k].empty()&&q[k].front()<=pos) q[k].pop_front();
		else {
			while(!q[k].empty()&&f[pos]<=f[q[k].back()]) q[k].pop_back();
			q[k].push_back(pos);
		}
	} else {
		if(qr<=mid) modify(lson,pos,val);
		else if(ql>mid) modify(rson,pos,val);
		else modify(lson,pos,val),modify(rson,pos,val);
	} tr[k]=min(get(k) , (l==r) ? INF : min(tr[k<<1],tr[k<<1|1]));
}
int query(int k,int l,int r,int pos) {
	if(qr<l || ql>r) return INF;
	if(ql<=l&&r<=qr) return tr[k];
	int mid=l+r>>1;
	return min(get(k),(l==r)?INF:min(query(lson,pos),query(rson,pos)));
}
int main()
{
	rd(n),rd(L); --n;
	rep(i,1,n) rd(x[i]),rd(y[i]),rd(d[i]),gery[++cnt]=x[i],gery[++cnt]=y[i];
	sort(gery+1,gery+1+cnt); cnt=unique(gery+1,gery+1+cnt)-gery-1;
	build(1,1,cnt); rep(i,1,n) x[i]=find(x[i]),y[i]=find(y[i]);
	int le=f[0]=d[0]=0; x[0]=1,y[0]=cnt; modify(1,1,cnt,0,0);
	rep(i,1,n) {
	while(d[i]-d[le]>L) modify(1,1,cnt,le,1),++le;
	f[i]=query(1,1,cnt,i);
	if(f[i]!=INF) {
		printf("%d\n",++f[i]);
		modify(1,1,cnt,i,0);
	} else puts("-1");
}
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
