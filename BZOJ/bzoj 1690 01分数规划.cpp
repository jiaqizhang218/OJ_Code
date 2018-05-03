#include<bits/stdc++.h> 
#define RG register
#define rep(i,j,k) for(RG int i=j,i##_end=k;i<=i##_end;++i)
#define maxn 1010
#define INF 0x3fffffff
#define eps 1e-4
using namespace std;

inline int read(){
    char ch=getchar(); int f=1,x=0;
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return f*x;
}
struct e{int t; double w; int n;}es[maxn*5]; int g[maxn],ess;
void pe(int f,int t){es[++ess]=(e){t,0,g[f]}; g[f]=ess;}
double v[maxn],w[maxn*5]; int n,m;
void rebuild(double x){rep(i,1,m)es[i].w=w[i]*x-v[es[i].t];}
bool ins[maxn],f; double d[maxn];
void dfs(int x){
    ins[x]=1;
    for(int i=g[x];i;i=es[i].n){
        if(f)return;
        if(d[es[i].t]>d[x]+es[i].w){
            if(ins[es[i].t]){f=1; return;} d[es[i].t]=d[x]+es[i].w; dfs(es[i].t);
        }
    }
    ins[x]=0;
}
bool spfa(){
    memset(ins,0,sizeof(ins)); memset(d,0,sizeof(d)); f=0;
    rep(i,1,n){dfs(i); if(f)return 1;} return 0;
}
int main(){
    n=read(); m=read(); rep(i,1,n) v[i]=read(); rep(i,1,m) {int x=read(),y=read(); w[i]=read(); pe(x,y);}
    double l=1,r=10000;
    while(r-l>eps){
        double mid=(l+r)/2; rebuild(mid); if(spfa())l=mid;else r=mid;
    }
    return printf("%.2lf",l),0;
}
