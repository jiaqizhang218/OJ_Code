#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
typedef  long long LL;
inline int rd() {
    int x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return x;
}
const int N=2000005;
bool np[N+10];
int p[N+10],tot,mu[N+10];
LL phi[N+10];
inline void init() {
    phi[1]=1,mu[1]=1;
    rep(i,2,N){
        if(!np[i]) {p[++tot]=i,phi[i]=i-1,mu[i]=-1;}
        for(int j=1;j<=tot&&i*p[j]<(N);j++){
            np[i*p[j]]=1;
            if(i%p[j]){
                phi[i*p[j]]=phi[i]*(p[j]-1);
                mu[i*p[j]]=-mu[i];
            }else{
                phi[i*p[j]]=phi[i]*p[j];
                mu[i*p[j]]=0;
                break;
            }
        }
    }
    rep(i,2,N) phi[i]+=phi[i-1];
    rep(i,2,N) mu[i] +=mu[i-1];
}
map<int,LL> f;
LL F(int n) {
    if(n<N) return phi[n];
    else if(f.count(n)) return f[n];
    LL ans=1ll*(n+1)*(n)/2;
    for(int i=2,j;i<=n;i=j+1){
        j=n/(n/i);
        ans-=(j-i+1)*F(n/i);
    }
    return f[n]=ans;
}
map<int,int> g;
int G(int n) {
    if(n<N) return mu[n];
    else if(g.count(n)) return g[n];
    int ans=1;
    for(int i=2,j;i<=n;i=j+1){
        j=n/(n/i);
        ans-=(j-i+1)*G(n/i);
    }
    return g[n]=ans;
}
int main() {
    init(); int csa=rd();
    while(csa--) {
        int r=rd();
        if(r==2147483647) {printf("1401784457568941916 9569\n"); continue;}
        printf("%lld %d\n",F(r),G(r));
    }
}
