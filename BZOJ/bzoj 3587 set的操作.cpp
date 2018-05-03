#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define debug(x) cerr<<#x" = "<<x<<endl
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define per(i,a,b) for(register int i=(a);i>=(b);--i)
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
const int N = 100010;
set<int> s;
map<LL,bool> mp;
LL num[N],p[N*10],b[N*10],h[N*10];
int n,q,m;
int main()
{
	srand(19260817);
	n=rd(),m=rd(),q=rd();
	rep(i,1,n)	num[i]=1LL*rand()*rand()%1000000000*(rand()*rand()%2000000000);
	s.insert(1);
	rep(i,1,n) h[1]^=num[i],p[1]++,b[i]=1;
	////h存当前房间的异或值；p存当前房间的人数；b存当前每个人在哪个房间   
	rep(i,1,q) {
		char c; int x,y;
		c=getchar();
		x=rd(),y=rd();
		if(c=='C') {
			if(b[x]==y)	continue;
			s.erase(b[x]); s.erase(y);
			h[b[x]]^=num[x];
			p[b[x]]--;
			if(!mp[h[b[x]]])	s.insert(b[x]);
			h[y]^=num[x];
			p[y]++;
			if(!mp[h[y]])	s.insert(y);
			b[x]=y;
		}
		else
			if(c=='W') {
				int ans=0;
				set<int>::iterator it=s.lower_bound(x);
				for(;it!=s.end()&&*it<=y;it=s.lower_bound(x)) {
					mp[h[*it]]=1;
					ans+=p[*it];
					s.erase(it);
				}	
				printf("%d\n",ans);
			}
	}
	return 0; 
}
