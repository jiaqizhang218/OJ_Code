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
    return;
}
const int N = 500050;
namespace Trie {	
	struct node {
		int s,son[2];
	}t[N];
	int ans,nt,n,m,sum[N];
	inline void insert(int len) 
	{
		int x,ansm=0,p=0;
		rep(i,1,len) {
			rd(x);
			int zz=x;
			if(!t[p].son[zz]) t[p].son[zz]=++nt;
			p=t[p].son[zz]; sum[p]++;
		}
		t[p].s++;
	}
	inline int query(int len) 
	{
		int x,ans=0,p=0;
		rep(i,1,len) {
			rd(x);
			int zz=x;
			if(!t[p].son[zz]) {
				for(i=i+1;i<=len;i++)
					rd(x);
				return ans;
			}
			p=t[p].son[x];
			ans+=t[p].s;
		}
		return ans-t[p].s+sum[p];
	}
}
using namespace Trie;
	
int main()
{
#ifdef iloi
	freopen("test.txt","r",stdin);
#endif 
	rd(n),rd(m);
	for(int i=1,x;i<=n;i++) {
		rd(x); insert(x);
	}
	for(int i=1,x;i<=m;i++) {
		rd(x); printf("%d\n",query(x));
	}
}
