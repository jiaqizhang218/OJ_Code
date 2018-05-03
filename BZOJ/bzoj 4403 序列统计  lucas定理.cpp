#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LB;
const int mod = 1000003;
int n,len,L,R,jie[mod+12],nj[mod+12];
inline int fast_pow(int x,int y){ int r=1; while(y>0) { if(y&1) r=1LL*r*x%mod; x=1LL*x*x%mod; y>>=1; } return r; }
inline int C(int n,int m){ if(n<m) return 0; return 1LL*jie[n]*nj[m]%mod*nj[n-m]%mod; }
inline int getint(){
    int w=0,q=0; char c=getchar(); while((c<'0'||c>'9') && c!='-') c=getchar();
    if(c=='-') q=1,c=getchar(); while (c>='0'&&c<='9') w=w*10+c-'0',c=getchar(); return q?-w:w;
}
 
inline void Init(){
    jie[0]=nj[0]=1; for(int i=1;i<mod;i++) jie[i]=1LL*jie[i-1]*i%mod;
    nj[mod-1]=fast_pow(jie[mod-1],mod-2); for(int i=mod-2;i>=1;i--) nj[i]=1LL*nj[i+1]*(i+1)%mod;
}
 
inline int Lucas(int n,int m){
    if(n<m) return 0; if(m==0) return 1;
    if(n<mod && m<mod) return C(n,m);
    return 1LL*Lucas(n/mod,m/mod)*C(n%mod,m%mod)%mod;
}
 
inline void work(){
    Init(); int T=getint();
    while(T--) {
        n=getint(); L=getint(); R=getint();
        len=R-L+1;
        printf("%d\n",(Lucas(len+n,n)-1+mod)%mod);
    }
}

int main()
{
    work();
    return 0;
}
