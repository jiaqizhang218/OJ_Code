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
typedef pair<int,bool> pa;
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
const int MXN = 5000000;
const int Mod = 1e5 + 7;
map<LL,pa> mp[Mod];
bool check[MXN];
int prime[MXN],mu[MXN];
inline void Moblius() {
	memset(check,0,sizeof check);
	mu[1]=1; int tot=0;
	for(int i=2;i<MXN;++i) {
		if(!check[i]) {
			prime[tot++]=i;
			mu[i]=-1;
		}
		for(int j=0;j<tot&&i*prime[j]<MXN;++j) {
			int num=i*prime[j];
			check[num]=true;
			if(i%prime[j]==0) {
				mu[num]=0; break;
			}
			else mu[num]=-mu[i];
		}
	}
	for(int i=2;i<MXN;++i) mu[i]+=mu[i-1];
}
inline int calc(LL x) {
	if(x<MXN) return mu[x];
	pa p=mp[x%Mod][x];
	if(p.second)	return p.first;
	int ans=1;
	for(LL i=2,la=0;i<=x;i=la+1) {
		la=x/(x/i);
		ans-=(la-i+1)*calc(x/i);
	}
	mp[x%Mod][x]=Pa(ans,true);
	return ans;
}
int main()
{
	Mobius();
	LL a,b;
	while(cin>>a>>b)	cout<<calc(b)-calc(a-1)<<endl;
	return 0;
}
