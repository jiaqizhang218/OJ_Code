#include<bits/stdc++.h>
const int N=5e5+7;
int _(){int x;scanf("%d",&x);return x;}
int n;
int d1[N],dn[N],d1n=1e9,ws[N*4],fa[N],fe[N];
int pp=0;
void mins(int&a,int b){if(a>b)a=b;}
int abs(int x){return x>0?x:-x;}
int main(){
    n=_();
    if(n==2)return puts("TAK\n1 2 1"),0;
    for(int i=2;i<n;++i)d1[i]=_();
    for(int i=2;i<n;++i){
        dn[i]=_();
        mins(d1n,d1[i]+dn[i]);
    }
    int D=abs(d1[2]-dn[2]);
    if(!D)goto o;
    for(int i=3;i<n;++i)if(abs(d1[i]-dn[i])!=D)goto o;
    puts("TAK");
    printf("1 %d %d\n",n,D);
    for(int i=2;i<n;++i){
        if(d1[i]<dn[i])printf("1 %d %d\n",i,d1[i]);
        else printf("%d %d %d\n",n,i,dn[i]);
    }
    return 0;
    o:;
    ws[0]=1;
    ws[d1n]=n;
    for(int i=2;i<n;++i)if(d1[i]+dn[i]==d1n){
        if(ws[d1[i]])return puts("NIE"),0;
        ws[d1[i]]=i;
    }
    for(int i=2;i<n;++i){
        int a=d1[i],c=a+dn[i]-d1n;
        if(!c)continue;
        if(c&1)return puts("NIE"),0;
        a-=c/2;
        if(!ws[a])return puts("NIE"),0;
        fa[i]=ws[a];
        fe[i]=c/2;
    }
    puts("TAK");
    for(int i=1,pv=0;i<=d1n;++i)if(ws[i])printf("%d %d %d\n",ws[i],ws[pv],i-pv),pv=i;
    for(int i=2;i<n;++i)if(fa[i])printf("%d %d %d\n",i,fa[i],fe[i]);
    return 0;
}
