#include<bits/stdc++.h>
using namespace std;
const int MXN = 5e5 + 5;
#define debug(...) fprintf(stderr,__VA_ARGS__) 
typedef long long LL;
int tot,now,n,m,typ,sum[MXN<<2];
int ls[MXN*80],rs[MXN*80],tr[MXN*80],rt[MXN],la,tag[MXN<<2];
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

struct data {
    int v,fro,t;
    data(int _v=0,int _fro=0,int _t=0) {
        v=_v;fro=_fro,t=_t;
    }
    bool operator < (const data &rhs) const {
        return t > rhs.t;
    }
}v[MXN*80];

void update(int &y,int x,int l,int r,int ql,int qr,data val) {
    y=++tot; ls[y]=ls[x]; rs[y]=rs[x]; v[y]=v[x];
    if(l>=ql&&r<=qr) {
        v[y]=min(v[y],val);
        return;
    }
    int mid=l+r>>1; 
    if(qr<=mid) update(ls[y],ls[x],l,mid,ql,qr,val);
    else if(ql>mid) update(rs[y],rs[x],mid+1,r,ql,qr,val);
    else update(ls[y],ls[x],l,mid,ql,mid,val),update(rs[y],rs[x],mid+1,r,mid+1,qr,val);
}

data query(int k,int l,int r,int x) {
    data ret=v[k];
    if(r==l||!k) {
        return ret;
    }
    int mid=l+r>>1;
    if(x<=mid) ret=min(ret,query(ls[k],l,mid,x));
    else ret=min(ret,query(rs[k],mid+1,r,x));
    return ret;
}

inline void pushdown(int k,int l,int r) {
    if(tag[k]) {
        int mid=l+r>>1;
        sum[k<<1]=(tag[k]*(mid-l+1));
        tag[k<<1]=tag[k];
        sum[k<<1|1]=(tag[k]*(r-mid));
        tag[k<<1|1]=tag[k];
        tag[k]=0;
    }
}
inline void toch(int k,int y,int l,int r) {
    sum[k]=(r-l+1)*y;
    tag[k]=y;
}
void change(int k,int l,int r,int ql,int qr,int x) {
    if(l>=ql&&r<=qr) {
        toch(k,x,l,r);
        return;
    }
    int mid=l+r>>1;
    pushdown(k,l,r);
    if(qr<=mid) change(lson,ql,qr,x);
    else if(ql>mid) change(rson,ql,qr,x);
    else change(lson,ql,mid,x),change(rson,mid+1,qr,x);
	sum[k]=sum[k<<1]+sum[k<<1|1];
}
inline int query(int k,int l,int r,int ql,int qr) {
    if(l>=ql&&r<=qr) {
        return sum[k];
    }
//    debug("l=%d,r=%d,ql=%d,qr=%d\n",l,r,ql,qr);
    pushdown(k,l,r);
    int mid=l+r>>1;
    if(qr<=mid) return query(lson,ql,qr);
    else if(ql>mid) return query(rson,ql,qr);
    else return query(lson,ql,mid)+query(rson,mid+1,qr);
}

int main() {
#ifdef iloi
    freopen("test.in","r",stdin);
#endif
    ios::sync_with_stdio(0);
    cin>>n>>m>>typ;
    while(m--) {
        now++; rt[now]=rt[now-1];
        int opt,l,r,x; cin>>opt;
        if(opt==1) {
            cin>>l>>r;
            l=((LL)typ*la+l)%n+1; r=((LL)typ*la+r)%n+1;
            if(l>r) swap(l,r);
            la=query(1,1,n,l,r);
            cout<<la<<endl;
        } else if(opt==2) {
            cin>>l;
            l=((LL)typ*la+l)%n+1;
            data t=query(rt[now],1,n,l);
            t=query(rt[t.fro],1,n,l);
            t.t=now;
            update(rt[now],rt[now],1,n,l,l,t);
            change(1,1,n,l,l,t.v);        
        } else {
            cin>>l>>r>>x;
            l=((LL)typ*la+l)%n+1,r=((LL)typ*la+r)%n+1;
            if(l>r) swap(l,r);
            update(rt[now],rt[now],1,n,l,r,data(x,now-1,now));
            change(1,1,n,l,r,x);
        }
    }
}
