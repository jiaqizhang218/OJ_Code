#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rpg(i,x) for(register int i=fir[x];i;i=e[i].nxt)
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define bin(i) (1<<i)
#define cla(x) memset(x,0,sizeof x)
#define meminf(x) memset(x,127,sizeof x)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
const int oo = 0x3f3f3f3f;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
//#define  getchar() nc()
template <typename T>
inline void rd(T &x)
{
    x = 0 ;int f = 1; char CH = getchar();
    while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
    while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    x = f ? x : -x;
}
const int N = 100005;
int n,m,fa[N],c[N][2],st[N];
bool rev[N];
inline bool isroot(int x){return c[fa[x]][1]!=x&&c[fa[x]][0]!=x;}
inline void pushdown(int x){
    int l=c[x][0],r=c[x][1];
    if(rev[x]){rev[x]^=1,rev[l]^=1,rev[r]^=1;swap(c[x][0],c[x][1]);}
}
inline void rotate(int x){
    int y=fa[x],z=fa[y],which=(c[y][1]==x),which1 = which ^ 1;
    if(!isroot(y))  {if(c[z][0]==y) c[z][0]=x; else c[z][1]=x;}
    fa[x]=z;fa[y]=x;fa[c[x][which1]]=y; c[y][which]=c[x][which1]; c[x][which1]=y;
}
inline void splay(int x) {
    int top=0;st[++top]=x;
    for(int i=x;!isroot(i);i=fa[i]) st[++top]=fa[i];
    for(int i=top;i;i--)    pushdown(st[i]);
    for(int y=fa[x],z=fa[y];!isroot(x);rotate(x),y=fa[x],z=fa[y])
        if(!isroot(y)) {if(c[y][0]==x^c[z][0]==y) rotate(x); else rotate(y);}
}
inline void access(int x) {for(int t=0;x;splay(x),c[x][1]=t,t=x,x=fa[x]);}
inline void makeroot(int x) {access(x);splay(x);rev[x]^=1;}
inline void link(int x,int y) {makeroot(x),fa[x]=y;splay(x);}
inline void cut(int x,int y) {makeroot(x),access(y),splay(y);c[y][0]=fa[x]=0;}
inline int findd(int x) {access(x);splay(x);int y=x;while(c[y][0])y=c[y][0]; return y;}
int main()
{
    char ch[10];
    int x,y;
    rd(n),rd(m);
    rep(i,1,m){
        scanf("%s",ch);
        rd(x),rd(y);
        if(ch[0]=='C') link(x,y);
        else if(ch[0]=='D') cut(x,y);
        else {
            if(findd(x)==findd(y)) printf("Yes\n");
            else printf("No\n");
        }
    }
}
