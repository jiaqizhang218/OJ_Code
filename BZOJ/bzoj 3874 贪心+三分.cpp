#include<cstdio>
#include<algorithm>
#define N 333
using namespace std;
typedef long long LL;
LL m,f,n,i,top,midl,midr,l,r,ans,ansl,ansr;
struct EG{LL x,y;}eg[N],q[N];
bool cmp(EG a,EG b){return a.x<b.x;}
LL calc(LL x){
    LL xm,ans=0,days=0,la,i;
    xm=m-x*f;if(xm<0)return 0;
    for(i=1;i<=top;i++){
        if(days<=q[i].y){
            la=min(q[i].y-days+(LL)1,xm/q[i].x/x);
            ans+=la*x;xm-=q[i].x*x*la;
            days+=la;
        }
        if(days<=q[i].y){
            la=min(x,xm/q[i].x);
            ans+=la;xm-=q[i].x*la;days++;
        }
    }
    return ans;
}
int main(){
    scanf("%lld%lld%lld",&m,&f,&n);
    for(i=1;i<=n;i++)scanf("%lld%lld",&eg[i].x,&eg[i].y);
    sort(eg+1,eg+n+1,cmp);
    q[++top]=eg[1];
    for(i=2;i<=n;i++)if(eg[i].y>q[top].y)q[++top]=eg[i];
    l=1;r=m/(f+q[1].x);
    ans=max(calc(l),calc(r));
    while(l<=r){
        midl=l+(r-l)/(LL)3;midr=r-(r-l)/(LL)3;
        ansl=calc(midl);ansr=calc(midr);
        ans=max(ans,max(ansl,ansr));
        if(ansl<ansr)l=midl+1;else r=midr-1;
    }
    printf("%lld\n",ans);
}
