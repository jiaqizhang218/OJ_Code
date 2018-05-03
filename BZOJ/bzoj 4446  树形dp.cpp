#include<bits/stdc++.h>
#define debug(x) cout<<(#x)<<" "<<(x)<<endl
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
const int N = 2000500;
LL n,g[N][20],f[N][20],a[N],b[N],dep[N],dis[N];
int main()
{
	n=read();	dep[1]=1;
	for(int i=1;i<=n;i++)	a[i]=read();
	for(int i=2;i<=n;i++)	b[i]=read(),dep[i]=dep[i>>1]+1,dis[i]=dis[i>>1]+b[i];
	for(int x=n;x;x--) {
		if((x<<1)>n) {
			for(int j=0;j<=dep[x];j++)
			{
				int fa=(x>>(dep[x]-j+1)),y=(x>>(dep[x]-j)^1);
				f[x][j]=(dis[x]+dis[y]-2*dis[fa])*a[y];
			}
		}
		else if((x<<1)==n) {
			for(int j=0;j<=dep[x];j++)
			{
				int y=(x<<1);
				f[x][j]=a[y]*b[y]+f[y][j];
			}
		}
		else {
			for(int j=0;j<=dep[x];j++) {
	        int lson=(x<<1),rson=(x<<1|1);
	        f[x][j]=min(a[lson]*b[lson]+f[lson][dep[lson]]+f[rson][j],a[rson]*b[rson]+f[rson][dep[rson]]+f[lson][j]);
		}
	}
	for(int x=n;x;x--){
    if((x<<1)>n){
        for(int j=0;j<=dep[x];j++){
        int y=(x>>(dep[x]-j));
        g[x][j]=(dis[x]-dis[y])*a[y];
        }
    }
    else if((x<<1)==n){
        for(int j=1;j<=dep[x];j++){
        int y=(x<<1);
        g[x][j]=a[y]*b[y]+g[y][j];
        }
    }
    else{
        for(int j=0;j<=dep[x];j++){
        int lson=(x<<1),rson=(x<<1|1);
        g[x][j]=min(a[lson]*b[lson]+f[lson][dep[lson]]+g[rson][j],a[rson]*b[rson]+f[rson][dep[rson]]+g[lson][j]);
        }
    }
    }
    LL ans=g[1][0];
    for(int i=2;i<=n;i++){
    LL ret=g[i][dep[i]-1];
        for(int x=i;x>1;x>>=1){
        int y=x^1;
        if(y>n) ret+=a[x>>2]*b[x>>1];
        else ret+=a[y]*b[y]+g[y][dep[y]-2];
    }
    ans=min(ans,ret);
    }
    printf("%lld\n",ans);
    return 0;
}
}
