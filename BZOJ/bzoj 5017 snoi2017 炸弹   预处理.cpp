#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
inline char tc(){
    static char fl[10000],*A=fl,*B=fl;
    return A==B&&(B=(A=fl)+fread(fl,1,10000,stdin),A==B)?EOF:*A++;
}
inline ll read(){
    ll a=0,f=1;static char c;
    while((c=tc())<'0'||c>'9')c=='-'?f=-1:0;
    while(c>='0'&&c<='9')a=a*10+c-'0',c=tc();
    return a*f;
}
const int Mod=1000000007;
ll ans,n,x[500001],y[500001],l[500001],r[500001];
int main(){
    register int i,a;
    n=read();
    for(i=1;i<=n;++i)
        x[i]=read(),y[i]=read();
    for(i=1;i<=n;++i){
        l[i]=i;
        while(l[i]>1&&x[i]-x[l[i]-1]<=y[i])
            l[i]=l[l[i]-1],y[i]=max(y[i],y[l[i]]-x[i]+x[l[i]-1]);
    }
    for(i=n;i;--i){
        r[i]=i;
        while(r[i]<n&&x[r[i]+1]-x[i]<=y[i])
            r[i]=r[r[i]+1],l[i]=min(l[i],l[r[i]]);
    }
    for(i=1;i<=n;++i)
        ans=(ans+(r[i]-l[i]+1)*i)%Mod;
    printf("%d",ans);
    return 0;
}
