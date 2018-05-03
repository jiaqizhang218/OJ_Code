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
    x=(f==1)?x:-x;  return;
}
const int N = 100005;
int Q,n,a[N],rt[N],ls[N*20],rs[N*20],sum[N*20],ncnt;
int sx[N],icnt;
inline int Search(int x){return lower_bound(sx+1,sx+icnt+1,x)-sx;}
inline void pushup(int x){sum[x]=sum[ls[x]]+sum[rs[x]];} 
inline void Modify(int x,int &y,int l,int r,int t)
{
	sum[y=++ncnt]=sum[x]+1; ls[y]=ls[x],rs[y]=rs[x]; int mid=l+r>>1;
	if(l==r) return;
	if(t<=mid) Modify(ls[x],ls[y],l,mid,t);
	else Modify(rs[x],rs[y],mid+1,r,t);
	pushup(y);
}
inline int query(int x,int y,int l,int r,int k)
{
	if(l==r) return sx[l];
	int mid=(l+r)>>1,tmp=sum[ls[y]]-sum[ls[x]];
	if(k<=tmp) return query(ls[x],ls[y],l,mid,k);
	else return query(rs[x],rs[y],mid+1,r,k-tmp);
}
struct edge{
	int to,nxt;
}e[N<<1];
int fir[N],inum;
inline void AE(int u,int v){e[++inum].to=v,e[inum].nxt=fir[u];fir[u]=inum;}
inline void ins(int u,int v){AE(u,v),AE(v,u);}
int dfs_clock,in[N],out[N],siz[N];
inline void dfs(int x,int fa)
{
	in[x]=++dfs_clock; Modify(rt[dfs_clock-1],rt[dfs_clock],1,icnt,Search(a[x]));
	siz[x]=1; rpg(i,x) 
		if(e[i].to!=fa) 
			dfs(e[i].to,x),siz[x]+=siz[e[i].to];
	out[x]=dfs_clock;
}
map<int,int> Map;
int main()
{
#ifdef	iloi
	freopen("test.txt","r",stdin);
#endif
	rd(n); rep(i,1,n) rd(a[i]),sx[i]=a[i],Map[a[i]]=i;
	sort(sx+1,sx+1+n);
	icnt=unique(sx+1,sx+n+1)-sx-1;
	for(int u,v,i=1;i<n;++i) rd(u),rd(v),ins(u,v);
	dfs(1,0); rd(Q);
	for(int u,v;Q;--Q) {
		rd(u),rd(v); 	
		printf("%d\n",Map[query(rt[in[u]-1],rt[out[u]],1,icnt,v)]);
	}
}
