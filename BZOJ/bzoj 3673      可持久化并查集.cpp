#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define F(i,j,n) for(int i=j;i<=n;++i)
#define D(i,j,n) for(int i=j;i>=n;--i)
#define pb push_back
using namespace std;
typedef long long LL;
inline int getint(){
    int r=1,v=0; char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if (ch=='-') r=-1;
    for(; isdigit(ch);ch=getchar()) v=v*10-'0'+ch;
    return r*v;
}
const int N=2e4+10;
 
int n,m,cnt,rt[N];
 
struct node{
    int l,r,v,size;
}t[N*20];
#define L t[o].l
#define R t[o].r
#define mid (l+r>>1)
#define lch L,l,mid
#define rch R,mid+1,r
 
void build(int &o,int l,int r){
    o=++cnt;
    if (l==r) {t[o].v=l;t[o].size=1;return;}
    build(lch);
    build(rch);
}
void update(int &o,int l,int r,int pos,int v){
    t[++cnt]=t[o], o=cnt;
    if (l==r) {t[o].v=v; return;}
    if (pos<=mid) update(lch,pos,v);
    else update(rch,pos,v);
}
void modify(int &o,int l,int r,int pos,int v){
    t[++cnt]=t[o], o=cnt;
    if (l==r) {t[o].size+=v; return;}
    if (pos<=mid) modify(lch,pos,v);
    else modify(rch,pos,v);
}
int queryv(int o,int l,int r,int pos){
    if (l==r) return t[o].v;
    if (pos<=mid) return queryv(lch,pos);
    else return queryv(rch,pos);
}
int querysz(int o,int l,int r,int pos){
    if (l==r) return t[o].size;
    if (pos<=mid) return querysz(lch,pos);
    else return querysz(rch,pos);
}
int getfa(int x,int y){
    int now=y,nxt=queryv(rt[x],1,n,y);
    while(now!=nxt){
        now=nxt;
        nxt=queryv(rt[x],1,n,now);
    }
    return now;
}
 
int main(){
    n=getint(); m=getint();
    build(rt[0],1,n);
    int cmd,x,y,ans=0;
    F(i,1,m){
        rt[i]=rt[i-1];
        cmd=getint();
        if (cmd==1){
            x=getint(); y=getint();
            int f1=getfa(i,x),f2=getfa(i,y),
                s1=querysz(rt[i],1,n,f1),s2=querysz(rt[i],1,n,f2);
            if (s1<s2) swap(f1,f2);
            modify(rt[i],1,n,f1,s2);
            update(rt[i],1,n,f2,f1);
        }else if (cmd==2){
            rt[i]=rt[getint()];
        }else if (cmd==3){
            x=getint(); y=getint();
            int f1=getfa(i,x),f2=getfa(i,y);
            printf("%d\n",ans=(f1==f2));
        }
    }       
    return 0;
}
