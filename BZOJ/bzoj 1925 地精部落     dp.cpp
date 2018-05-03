#include<bits/stdc++.h>
#define debug(x) cerr<<#x" = "<<x<<endl
#define rep(i,j,k) for((i)=(j);(i)<=(k);++i)
#define per(i,j,k) for((i)=(j);(i)>=(k);--i)
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
//#define  getchar() nc()
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int n,mod,f[2][5005],g[2][5005]; 
int main()
{
//#ifdef	iloi 
//	freopen("test.txt","r",stdin);
//#endif
	int i,j,flag=0;
	n=read(),mod=read();
	f[flag][1]=g[flag][1]=1;
	for(int i=2;i<=n;++i){
    flag^=1;
    for(int j=1;j<=i;++j){
      f[flag][j]=g[flag^1][j-1];
      g[flag][j]=(f[flag^1][i-1]-f[flag^1][j-1]+mod)%mod;
    }
    for(int j=1;j<=i;++j){
      f[flag][j]=(f[flag][j]+f[flag][j-1])%mod;
      g[flag][j]=(g[flag][j]+g[flag][j-1])%mod;
    	}
  	}
  	debug(f[flag][n]);
  	debug(g[flag][n]);
	printf("%d\n",(f[flag][n]+g[flag][n])%mod);
	return 0;
}
