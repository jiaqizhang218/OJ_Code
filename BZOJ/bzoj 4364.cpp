#include "bits/stdc++.h"
#define lson rt<<1,l,m
#define rson rt<<1|1,m+1,r
using namespace std;
typedef long long LL;
const int MAX=2e6+5;
int n,m;
int mn[MAX<<2],mx[MAX<<2];
inline int read(){
    int an=0,x=1;char c=getchar();
    while (c<'0' || c>'9') {if (c=='-') x=-1;c=getchar();}
    while (c>='0' && c<='9') {an=an*10+c-'0';c=getchar();}
    return an*x;
}
void PushUp(int rt){
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
    mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
}
void PushDown(int rt){
    if (mn[rt]>mx[rt<<1]) mx[rt<<1]=mn[rt<<1]=mn[rt];
    else if (mn[rt]>mn[rt<<1]) mn[rt<<1]=mn[rt];
    if (mn[rt]>mx[rt<<1|1]) mx[rt<<1|1]=mn[rt<<1|1]=mn[rt];
    else if (mn[rt]>mn[rt<<1|1]) mn[rt<<1|1]=mn[rt];
    
    if (mx[rt]<mn[rt<<1]) mx[rt<<1]=mn[rt<<1]=mx[rt];
    else if (mx[rt]<mx[rt<<1]) mx[rt<<1]=mx[rt];
    if (mx[rt]<mn[rt<<1|1]) mx[rt<<1|1]=mn[rt<<1|1]=mx[rt];
    else if (mx[rt]<mx[rt<<1|1]) mx[rt<<1|1]=mx[rt];
}
void update1(int rt,int l,int r,int x,int y,int z){//µ÷¸ß
    if (x<=l && r<=y){
        mx[rt]=max(mx[rt],z);
        mn[rt]=max(mn[rt],z);
        return;
    }
    int m=(l+r)>>1;
    PushDown(rt);
    if (x<=m) update1(lson,x,y,z);
    if (y>m) update1(rson,x,y,z);
    PushUp(rt);
}
void update2(int rt,int l,int r,int x,int y,int z){//µ÷µÍ
    if (x<=l && r<=y){
        mx[rt]=min(mx[rt],z);
        mn[rt]=min(mn[rt],z);
        return;
    }
    int m=(l+r)>>1;
    PushDown(rt);
    if (x<=m) update2(lson,x,y,z);
    if (y>m) update2(rson,x,y,z);
    PushUp(rt);
}
int out(int rt,int l,int r){
    if (l==r) return printf("%d\n",mx[rt]),0;
    int m=(l+r)>>1;
    PushDown(rt);
    out(lson);
    out(rson);
}
int main(){
    int i,j,x,y,z,w;
    n=read(),m=read();
    for (i=1;i<=m;i++){
        w=read(),x=read(),y=read(),z=read();++x,++y;
        if (w==1) update1(1,1,n,x,y,z);
        if (w==2) update2(1,1,n,x,y,z);
    }
    out(1,1,n);
    return 0;
}
