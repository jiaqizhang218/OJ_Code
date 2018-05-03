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
inline int rd()
{
    int x = 0 , f = 1; char CH = getchar();
    while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
    while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    return f ? x : -x;
}
bool a[1005][1005];  
int h[1005],s[1005],l[1005],r[1005],n,m,t,ans=0;  
int main()
{
	n=rd(),m=rd(); char ch;
	rep(i,1,n)rep(j,1,m) {for(ch=getchar();ch!='F'&&ch!='R';ch=getchar()); a[i][j]=(ch=='F');}
	rep(i,1,n) {
		rep(j,1,m) if(a[i][j]) h[j]++;	else h[j]=0; 
		t=0,s[0]=0;
		rep(j,1,m) {
			while(t&&h[s[t]]>=h[j]) t--;
			l[j]=s[t]+1; s[++t]=j;
		}
		t=0,s[0]=m+1;
		per(j,m,1) {
			while(t&&h[s[t]]>=h[j]) t--;
			r[j]=s[t]-1; s[++t]=j;
		}
		rep(j,1,m)ans=max(ans,h[j]*(r[j]-l[j]+1));
	}
	cout<<ans*3<<endl;
}
