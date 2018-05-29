#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_end=(b);i>=i##_end;--i)
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ull;
template <typename T> inline void rd(T &x) {
    x=0;int f=1;char CH=getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;return;
}
template <typename T> inline bool chMax(T &a,T b) {
    return a<b?a=b,true:false;
}
template <typename T> inline bool chMin(T &a,T b) {
    return a>b?a=b,true:false;
}
const int MXN = 305;
int n,m,K,a[MXN][MXN],f[MXN][MXN],ans=0x7fffffff;
int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
#endif
	rd(n),rd(m),rd(K);
	rep(i,1,n) rep(j,1,m) rd(a[i][j]);
	memset(f,0x7f,sizeof f);
	rep(i,1,m) rep(j,1,i-1) f[i][j]=a[1][i]+a[1][j];
	rep(i,2,n) {
		rep(j,1,m) {
			rep(k,1,j-1) {
				if(j+1<=m) chMin(f[j+1][k],f[j][k]+K);
				if(k+1<=m) chMin(f[j][k+1],f[j][k]+K);
			}
		}
		per(j,m,1) {
			per(k,j-1,1) {
				if(j-1>=1) chMin(f[j-1][k],f[j][k]+K);
				if(k-1>=1) chMin(f[j][k-1],f[j][k]+K);
			}
		}
		rep(j,1,m)
			rep(k,1,j-1)
				f[j][k]+=a[i][j]+a[i][k];
	}
	rep(i,1,m) rep(j,1,i-1) chMin(ans,f[i][j]);
	printf("%d\n",ans);
}
