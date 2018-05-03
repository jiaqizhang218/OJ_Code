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
const int N = 500005;
char str[N],nxt[N];
inline int getnext() 
{
	int i=1,j=0;nxt[0]=nxt[1]=0;
	for(;str[i]!='\0';++i)
	{
		while(j&&str[i]!=str[j]) j=nxt[j];
		if(str[i]==str[j]) ++j;
		nxt[i+1]=j;
	}
	return i;
}
int len=1,pre[N],suc[N],fir[N];
struct edge{
	int to,nxt;
}lst[N];
inline void AE(int a,int b){lst[len].to=b;lst[len].nxt=fir[a],fir[a]=len++;}
int maybe[N],tot=0,maxgap=1;
inline void del(int x)
{
	if(suc[x]) pre[suc[x]]=pre[x];
	if(pre[x]) suc[pre[x]]=suc[x];
	if(pre[x]!=0&&suc[x]!=0&&suc[x]-pre[x]>maxgap)
		maxgap=suc[x]-pre[x];
	pre[x]=suc[x]=0;
}
int q[N],head,tail;
inline void bfs(int s,int avoid) 
{
	head=tail=0;
	q[tail++]=s;
	while(head!=tail)
	{
		int x=q[head++];
		if(x==avoid) continue;
		del(x);
		for(int pt=fir[x];pt;pt=lst[pt].nxt)
			q[tail++]=lst[pt].to;
	}
}
int main()
{
	scanf("%s",str);
	int n=getnext();
	rep(i,1,n) AE(nxt[i],i);
	for(int i=n;i;i=nxt[i]) maybe[++tot]=i;
	rep(i,1,n) pre[i]=i-1,suc[i]=i+1;
	suc[n]=0;
	for(int i=tot;i>=1;--i) {
		bfs(maybe[i+1],maybe[i]);
		if(maxgap<=maybe[i]) {
			printf("%d\n",maybe[i]);
			break;
		}
	}
	return 0;
}
