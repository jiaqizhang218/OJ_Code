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
const int N = 100010, H = 110;
int n,c,h,a[N];
int P,Q,A,B,C[H],D[H];
int f[N][H];
int main()
{
#ifdef	iloi
	freopen("test.txt","r",stdin);
#endif
	n=rd(),c=rd();
	rep(i,1,n)	a[i]=rd();
	h=a[1];
	rep(i,1,n) h=h>a[i]?h:a[i];
	h=min(h,100);
	cls(f,0x3f);
	rep(i,1,n) {
		if(i==1) rep(j,a[1],h) f[1][j]=(j-a[i])*(j-a[i]);
		else {
				rep(j,a[i],h) {
						Q=(j-a[i])*(j-a[i]);
						A=C[j]+j*c;
						B=D[j+1]-j*c;
						P=min(A,B);
						f[i][j]=P+Q;
					}
		}
		C[0]=D[h+1]=INF;
		rep(j,1,h) C[j]=min(C[j-1],f[i][j]-j*c);
		per(j,h,1) D[j]=min(D[j+1],f[i][j]+j*c);
	}
	int ans=INF;
	rep(i,1,h)	ans=min(ans,f[n][i]);
	printf("%d",ans);
	return 0; 	
}
