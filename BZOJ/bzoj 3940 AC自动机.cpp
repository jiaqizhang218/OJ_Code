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
const int N = 1e5 + 5;
int n,m,len[N],val[N],ch[N][30],nxt[N],lst[N],fail[N],sz,pos[N];
char str[N],s[N];
queue<int> q;
inline void ins(){
	int now=0,l=strlen(str);
	for(int i=0;i<l;i++)
		if(ch[now][str[i]-'a']) now=ch[now][str[i]-'a'];
		else now=ch[now][str[i]-'a']=++sz;
	val[now]=1;len[now]=l;
}
inline void get_fail() {
	rep(i,0,25) if(ch[0][i]) q.push(ch[0][i]);
	while(!q.empty()) {
		int u=q.front(); q.pop();
		rep(i,0,25) {
				int v=ch[u][i],k=ch[fail[u]][i];
				if(v) {fail[v]=k,q.push(v);}	
				else ch[u][i]=k;
		}
	}
}
int main()
{
#ifdef	iloi
	freopen("test.txt","r",stdin);
#endif
	scanf("%s",s+1);
	n=strlen(s+1);
	rd(m);
	rep(i,1,m) scanf("%s",str),ins();
	get_fail();
	rep(i,0,n)	nxt[i]=i+1;
	rep(i,1,n+1) lst[i]=i-1;
	int p=0;
	rep(i,1,n) {
		pos[i]=p=ch[p][s[i]-'a'];
		if(val[p]) {
			int now=i;
			for(int j=1;j<=len[p];++j)	lst[nxt[now]]=lst[now],nxt[lst[now]]=nxt[now],now=lst[now];
			p=pos[now];
		}
	}
	for(int i=nxt[0];i!=n+1;i=nxt[i])	putchar(s[i]);
	return 0; 
}
