#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
long long w,h,n,ans[maxn];
bool X[maxn],Y[maxn];
struct node{
    char ch[3];long long x;
}op[maxn];
struct Node{
    long long pre,nxt,v;
}hang[maxn],lie[maxn];
int main(){
    scanf("%lld%lld%lld",&w,&h,&n);
    X[0]=X[h]=Y[0]=Y[w]=1;
    for(long long i=1;i<=n;i++){
        scanf("%s%d",op[i].ch,&op[i].x);
        if(op[i].ch[0]=='H')X[op[i].x]=1;
        if(op[i].ch[0]=='V')Y[op[i].x]=1;
    }
    ans[0]=w*h;
    long long dx=0,dy=0;
    for(long long i=0,p=0;i<=w;i++){
        if(Y[i]==1)
        lie[i].pre=p,lie[p].nxt=i,lie[i].v=i-p,dy=max(dy,i-p),p=i;
    }
    lie[w].nxt=w;
    for(long long i=0,p=0;i<=h;i++){
        if(X[i]==1)
        hang[i].pre=p,hang[p].nxt=i,hang[i].v=i-p,dx=max(dx,i-p),p=i;
    }
    hang[h].nxt=h;
    ans[n]=dx*dy;
    for(long long i=n;i>=2;i--){
        if(op[i].ch[0]=='H'){
            long long u=op[i].x;
            hang[hang[u].nxt].v+=hang[u].v;
            hang[hang[u].pre].nxt=hang[u].nxt;
            hang[hang[u].nxt].pre=hang[u].pre;
            dx=max(dx,hang[hang[u].nxt].v);
        }
        else{
            long long u=op[i].x;
            lie[lie[u].nxt].v+=lie[u].v;
            lie[lie[u].pre].nxt=lie[u].nxt;
            lie[lie[u].nxt].pre=lie[u].pre;
            dy=max(dy,lie[lie[u].nxt].v);
        }
        ans[i-1]=dx*dy;
    }
    for(long long i=1;i<=n;i++){
        printf("%lld\n",ans[i]);
    }
}
