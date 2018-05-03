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
#define cls(x,y) memset(x,y,sizeof x)
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
    x = 0; int f = 1; char CH = getchar();
    while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
    while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    return;
}
const int maxn = 1e6+10;  
struct Node{  
    LL v, base;  
    Node(LL v = 0, LL base = 0):v(v), base(base){}  
    bool operator < (const Node& rhs) const {  
        return v > rhs.v;  
    }  
};
int ks, T, L, n, m;  
LL c[maxn],x;  
priority_queue<Node>q1,q2;   
int main()
{
		rd(L),rd(n),rd(m); 
        for (int i = 0; i < n; ++i){  
  
            rd(x); 
            q1.push(Node(x,x));  
        }  
  
        for (int i = 0; i < m; ++i){  
  
            rd(x);  
            q2.push(Node(x,x));  
        }  
  
        for (int i = 0; i < L; ++i){  
            Node u = q1.top(); q1.pop();  
            c[i] = u.v;  
            u.v += u.base;  
            q1.push(u);  
        }  
        LL ans = 0;  
        for (int i = L-1; i >= 0; --i){  
            Node u = q2.top(); q2.pop();  
            ans = max(ans, u.v + c[i]);  
            u.v += u.base;  
            q2.push(u);  
        }  
  
        printf("%lld",ans);  
}
