#include<iostream>  
#include<cstdio>  
#include<cstring>  
#define N 250005  
using namespace std;  
  
int n,m,tot,dfsclk,c[N],bg[N],ed[N],fst[N],pnt[N],nxt[N];  
int read(){  
    int x=0; char ch=getchar();  
    while (ch<'0' || ch>'9') ch=getchar();  
    while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }  
    return x;  
}  
void add(int x,int y){  
    pnt[++tot]=y; nxt[tot]=fst[x]; fst[x]=tot;  
}  
void ins(int x,int t){  
    for (; x<=n; x+=x&-x) c[x]+=t;  
}  
int getsum(int x){  
    int t=0; for (; x; x-=x&-x) t+=c[x]; return t;  
}  
void dfs(int x){  
    bg[x]=++dfsclk; int p;  
    for (p=fst[x]; p; p=nxt[p]) dfs(pnt[p]);  
    ed[x]=dfsclk;  
}  
int main(){  
    n=read(); int i,x,y;  
    for (i=1; i<n; i++){  
        x=read(); y=read(); add(x,y);  
    }  
    dfs(1); m=read()+n-1; char ch;  
    for (i=2; i<=n; i++){ ins(bg[i],1); ins(ed[i]+1,-1); }  
    while (m--){  
        ch=getchar(); while (ch<'A' || ch>'Z') ch=getchar();  
        if (ch=='W') printf("%d\n",getsum(bg[read()])); else{  
            x=read(); y=read();  
            ins(bg[y],-1); ins(ed[y]+1,1);  
        }  
    }  
    return 0;  
} 
