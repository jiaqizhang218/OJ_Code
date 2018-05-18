#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MXN = 1e5 + 5;
int T,Mod,q,m,opt;
int a[MXN],s[MXN<<2];
inline void Ins(int k,int l,int r,int p,int v) {
    if(l==r) {
        s[k]=v; return;
    }
    int mid=l+r>>1;
    if(p<=mid) Ins(k<<1,l,mid,p,v);
    else Ins(k<<1|1,mid+1,r,p,v);
    s[k]=1LL*s[k<<1]*s[k<<1|1]%Mod;
}
int main() {
#ifdef iloi
    freopen("test.in","r",stdin);
#endif
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&q,&Mod);
        for(int i=1;i<MXN<<2;++i) s[i]=1;
        for(int i=1;i<=q;++i) {
            scanf("%d%d",&opt,&m);
            if(opt==1) {
                a[i]=m; Ins(1,1,q,i,m);
            } else {
                Ins(1,1,q,m,1);
            }
            printf("%d\n",s[1]);
        }
    }
 
}
