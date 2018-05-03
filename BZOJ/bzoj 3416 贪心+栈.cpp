#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define debug(x) cerr<<#x" = "<<x<<endl
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define per(i,a,b) for(register int i=(a);i>=(b);--i)
#define edeg(x) for(int i=fir[x];i;i=e[i].nxt)
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
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
//#define  getchar() nc()
inline int rd()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int N = 1000010;
int n,m,k,top;
vector<int> p[N];
char str[N];
int st[N];
LL s[N];
int main()
{
#ifdef	iloi
	freopen("test.txt","r",stdin);
#endif
	n=rd(),k=rd(),scanf("%s",str+1);
	rep(i,1,n) {
		int j;
		st[++top]=i,s[top]=s[top-1];
		if(str[i]=='b')	s[top]++;
		else s[top]-=k;
		if(top>=k+1&&s[top-k-1]==s[top])	for(m++,j=0;j<=k;j++) p[m].pb(st[top--]);
	}
	per(i,m,1) {
		per(j,k,0)	printf("%d ",p[i][j]);
		printf("\n");
	}
	return 0;
}
