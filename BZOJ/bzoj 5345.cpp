#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e5 + 5;
int fa[MXN],l[MXN],r[MXN],opt[MXN],nod[MXN<<1],tot,num,fc[MXN],n;
vector<int> gery[MXN<<2];
int getfa(int x) {
    return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
inline void merge(int x,int y) {
    int fx=getfa(x),fy=getfa(y);
    if(fx==fy) return;
    fa[fx]=fy;
    l[fy]=min(l[fy],l[fx]);
    r[fy]=max(r[fy],r[fx]);
    return;
}
void Insert(int k,int l,int r,int pos,int id) {
    for(vector<int>::iterator it=gery[k].begin();it!=gery[k].end();++it) merge(*it,id);
    if(!gery[k].empty()) gery[k].clear(),gery[k].push_back(getfa(id));
    if(l==r) return;
    int mid=l+r>>1;
    if(pos<=mid) Insert(k<<1,l,mid,pos,id);
    else Insert(k<<1|1,mid+1,r,pos,id);
}
void Ins(int k,int l,int r,int L,int R,int id) {
    if(l>=L&&r<=R) {
        gery[k].push_back(id); return;
    }
    int mid=l+r>>1;
    if(L<=mid) Ins(k<<1,l,mid,L,R,id);
    if(R>mid) Ins(k<<1|1,mid+1,r,L,R,id);
}
int main() {
#ifdef iloi
    freopen("test.in","r",stdin);
#endif
    scanf("%d",&n);
    for(register int i=1;i<=n;++i) {
        scanf("%d%d%d",&opt[i],&l[i],&r[i]);
        if(opt[i]==1) nod[++tot]=l[i],nod[++tot]=r[i];
    }
    sort(nod+1,nod+1+tot);
    for(register int i=1;i<=n;++i) {
        if(opt[i]==1) {
            fc[++num]=i; fa[i]=i;
            int L=lower_bound(nod+1,nod+1+tot,l[i])-nod,R=lower_bound(nod+1,nod+1+tot,r[i])-nod;
            Insert(1,1,tot,L,i);Insert(1,1,tot,R,i);
            if(L+1<=R-1) Ins(1,1,tot,L+1,R-1,i);
        } else {
            int fx=getfa(fc[l[i]]),fy=getfa(fc[r[i]]);
            //fprintf(stderr,"fx = %d , fy=%d\n",fx,fy);
            if(fx==fy) puts("YES");
            else if(l[fy]<l[fx]&&l[fx]<r[fy]) puts("YES");
            else if(l[fy]<r[fx]&&r[fx]<r[fy]) puts("YES");
            else puts("NO");
        }
    }
}
