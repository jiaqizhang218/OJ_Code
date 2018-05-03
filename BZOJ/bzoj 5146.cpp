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
/*const int _L = 1e6+5;
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
const LL Mod = 1e9 + 7;
void exgcd(LL a,LL b,LL &x,LL &y){
    if(b==0){
        x=1;y=0;return;
    }
    exgcd(b,a%b,x,y);
    LL temp=x;x=y;y=temp-a/b*y;
    return;
}
LL n,tmp,inv;
int main()
{
//141208853
//666973916
#ifdef iloi
//	   freopen("test.txt","r",stdin);
#endif
	rd(n);// LL xx;exgcd(n,Mod,inv,xx);
//	cout<<(inv)<<endl;
//	cout<<141208853*666973916%Mod<<endl;
	for(register long long xx,i=1;i<Mod;++i) {
		exgcd(i,Mod,inv,xx);
		if(inv*n%Mod==423626558) return printf("%I64d",i),0;
//		if(inv==141208853) return printf("%I64d",i),0;
	}
	cout<<"fuck"<<endl;
#ifdef iloi
	debug("\nMy Time: %.4lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

