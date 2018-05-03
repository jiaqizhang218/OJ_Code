#include<bits/stdc++.h>
using namespace std; 
const int N=1000000;
int n,m,S,T;
int mx[64],my[64],nx[64],ny[64];
int to[N],nxt[N],fir[N],cnt,h[N],q[N],ev[N];
double t1,t2,v;
inline bool bfs(){
    for(int i=1;i<=T;i++)h[i]=0;
    int ql=0,qr=0;
    h[q[qr++]=S]=1;
    while(ql!=qr){
        int w=q[ql++];
        for(int i=fir[w];i;i=nxt[i])if(ev[i]){
            int u=to[i];
            if(!h[u])h[q[qr++]=u]=h[w]+1;
        }
    }
    return h[T];
}
inline int dfs(int w,int f){
    if(w==T)return f;
    int c,used=0;
    for(int i=fir[w];i;i=nxt[i])
	if(ev[i]&&h[to[i]]==h[w]+1){
        int u=to[i];
        c=dfs(u,min(ev[i],f-used));
        ev[i]-=c;	ev[i^1]+=c;
        used+=c;
        if(f==used)return f;
    }
    h[w]=0;
    return used;
}
inline void adde(int a,int b){
    to[cnt]=b;nxt[cnt]=fir[a];ev[cnt]=1;fir[a]=cnt++;
    to[cnt]=a;nxt[cnt]=fir[b];ev[cnt]=0;fir[b]=cnt++;
}
bool chk(double t){
    cnt=2;
    S=n*m+m+1;T=S+1;
    for(int i=1;i<=T;i++)fir[i]=0;
    for(int i=1;i<=n;i++){
        for(int k=0;k<m;k++){
            adde(S,(i-1)*m+k+1);
        }
    }
    for(int i=1;i<=m;i++)adde(n*m+i,T);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            double x=mx[j]-nx[i],y=my[j]-ny[i];
            double tm=sqrt(x*x+y*y)/v;
            if(tm>t)continue;
            for(int k=0;k<m;k++)if(tm+t1+(t1+t2)*k<=t){
                adde((i-1)*m+k+1,n*m+j);
            }
        }
    }
    int ans=0;
    while(bfs())ans+=dfs(S,0x3f3f3f3f);
    return ans==m;
}
int main(){
    scanf("%d%d%lf%lf%lf",&n,&m,&t1,&t2,&v);
    for(int i=1;i<=m;i++)scanf("%d%d",mx+i,my+i);
    for(int i=1;i<=n;i++)scanf("%d%d",nx+i,ny+i);
    t1/=60.;
    double L=0,R=1e5;
    for(int i=0;i<44;i++){
        double M=(L+R)*.5;
        if(chk(M))R=M;
        else L=M;
    }
    printf("%.6f\n",L);
    return 0;
}
