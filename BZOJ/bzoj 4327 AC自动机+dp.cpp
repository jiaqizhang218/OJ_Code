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
const int N = 10000010;
queue<int> q;
int nxt[N][4],fail[N],len[N],tot=1,pos[100010][110];
bool vis[N]; char str[N],w[N];
inline int tra(char ch) {return ch=='E'?0:ch=='S'?1:ch=='W'?2:3;}
inline void build()
{
	rep(i,0,3) nxt[0][i]=1;
	q.push(1);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		rep(i,0,3) {
			if(nxt[x][i]) fail[nxt[x][i]]=nxt[fail[x]][i],q.push(nxt[x][i]);
			else nxt[x][i]=nxt[fail[x]][i];
		}
	}
}
int main()
{
#ifdef	iloi
	freopen("test.txt","r",stdin);
#endif
	int n,m,t;
	rd(n),rd(m),scanf("%s",str+1);
	rep(i,1,m) 
	{
		scanf("%s",w+1),len[i]=strlen(w+1);
		for(int j=t=1;j<=len[i];++j)
		{
			if(!nxt[t][tra(w[j])]) nxt[t][tra(w[j])]=++tot;
			t=nxt[t][tra(w[j])],pos[i][j]=t;
		}
	}
	build();
	vis[1]=1,t=1;
	rep(i,1,n) 
	{
		t=nxt[t][tra(str[i])];
		for(int j=t;!vis[j];j=fail[j]) vis[j]=true;
	}
	rep(i,1,m)
	{
		int j;
		for(j=len[i];j;--j) if(vis[pos[i][j]]) break;
		printf("%d\n",j);
	}
	return 0;
}
