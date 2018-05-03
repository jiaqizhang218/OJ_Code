#include<cstdio>
#include<algorithm>
#include<iostream>
#define P 31
#define R register
#define ull unsigned long long
using namespace std;
int read(){
    R int x=0;bool f=1;
    R char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=0;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f?x:-x;
}
const int N=5e5+10;
ull hash[N],base[N];
int n,m,vgcd,ans,c[N][26];;
char s[N];
void get_hash(){
    base[0]=1;
    for(int i=1;i<=n;i++){
        hash[i]=hash[i-1]*P+s[i]-'a';
        base[i]=base[i-1]*P;
    }
}
void check(int x,int y,int t){
    ull has1=hash[y-t]-hash[x-1]*base[y-x+1-t];
    ull has2=hash[y]-hash[x+t-1]*base[y-x+1-t];
    if(has1==has2) ans=min(ans,t);
}
int main(){
    n=read();gets(s+1);m=read();
    get_hash();
    for(int i=0;i<=25;i++)
        for(int j=1;j<=n;j++)
            c[j][i]=c[j-1][i]+(s[j]-'a'==i);

    for(int i=1,x,y;i<=m;i++){
        x=read();y=read();ans=N;vgcd=y-x+1;
        for(int j=0;j<=25;j++) vgcd=__gcd(vgcd,c[y][j]-c[x-1][j]);
        for(int j=1;j*j<=vgcd;j++){
            if(vgcd%j) continue;
            check(x,y,(y-x+1)/j);
            check(x,y,(y-x+1)/(vgcd/j));
        }
        printf("%d\n",ans);
    }
    return 0;
}
