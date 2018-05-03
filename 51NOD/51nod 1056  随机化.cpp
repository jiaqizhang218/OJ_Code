#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int mxn=100007;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct hstb{
    int v,nxt;
}e[mxn];
int hd[mxn],mct=0;
void insert(int x){
    int u=x%mxn;
    for(int i=hd[u];i;i=e[i].nxt){
        if(e[i].v==x)return;
    }
    e[++mct].v=x;e[mct].nxt=hd[u];hd[u]=mct;
    return;
}
int find(int x){
    int u=x%mxn;
    for(int i=hd[u];i;i=e[i].nxt){
        if(e[i].v==x)return 1;
    }
    return 0;
}
int n,a[mxn],b[mxn];
int ans=0;
int main(){
    int i,j;
    srand(19260817);
    n=read();
    for(i=1;i<=n;i++)a[i]=read(),b[i]=a[i];
    sort(a+1,a+n+1);
    for(int i=1,cnt=0;i<=n;i++){
        if(a[i]==a[i-1])cnt++;
        else cnt=1;
        ans=max(ans,cnt);
    }
    for(i=1;i<=n;i++) insert(a[i]);
    random_shuffle(b+1,b+n+1);
    int T=32000000; 
    while(T--){
        int x=rand()%(n-1)+1,y=rand()%(n-1)+1;
        x=b[x];y=b[y];if(x>y)swap(x,y);
        if(x==y)continue;
        int tmp=y-x;
        int res=2;
        for(i=y+tmp;i<=a[n];i+=tmp){
            if(find(i)){
                res++;
            }
            else break;
        }
        for(i=x-tmp;i>=a[1];i-=tmp){
            if(find(i)){
                res++;
            }
            else break;
        }
        ans=max(ans,res);
    }
    if(ans>=200)printf("%d\n",ans);
    else printf("No Solution\n");
    return 0;
}
