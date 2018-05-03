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
const int _L = 1e6+5;
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
const int MXN = 200000 + 15;
int block,n,m,op,pos[MXN],l[MXN],r[MXN],k[MXN],d[MXN],nxt[MXN];
inline int cal(int x) {for(int ret=0;;x=nxt[x]){ret+=d[x];if(!nxt[x])return ret;}}
int main()
{
#ifdef iloi
//	   freopen("test.txt","r",stdin);
#endif
	rd(n); block=(int)sqrt(n+0.5);
	rep(i,1,n) rd(k[i]);
	if(n%block) m=n/block+1; else m=n/block;
	rep(i,1,m) l[i]=(i-1)*block+1,r[i]=i*block; r[m]=n;
	rep(i,1,n) pos[i]=(i-1)/block+1;
	per(i,n,1) {
		if(i+k[i]>n) d[i]=1;
		else if(pos[i]==pos[i+k[i]]) d[i]=d[i+k[i]]+1,nxt[i]=nxt[i+k[i]];
		else d[i]=1,nxt[i]=i+k[i];
	}
	rd(op);
	while(op--) {
		int u,x,y;
		rd(u),rd(x);	x++;
		if(u==1) printf("%d\n",cal(x));
		else {
			rd(y); k[x]=y;
			per(i,x,l[pos[x]]) if(pos[i]==pos[k[i]+i]) {
				d[i]=d[i+k[i]]+1,nxt[i]=nxt[i+k[i]];
			}	else {
				d[i]=1,nxt[i]=i+k[i];
			}
		}
	}	
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

