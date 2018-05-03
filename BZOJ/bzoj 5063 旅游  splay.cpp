#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
#define N 100010
struct data
{
    int fa , c[2] , si , rev;
}a[N];
int root , ans[N] , tot;
inline void rever(int x)
{
    swap(a[x].c[0] , a[x].c[1]) , a[x].rev ^= 1;
}
inline void pushup(int x)
{
    a[x].si = a[a[x].c[0]].si + a[a[x].c[1]].si + 1;
}
inline void pushdown(int x)
{
    if(a[x].rev) rever(a[x].c[0]) , rever(a[x].c[1]) , a[x].rev = 0;
}
inline void rotate(int &k , int x)
{
    int y = a[x].fa , z = a[y].fa , l = (a[y].c[1] == x) , r = l ^ 1;
    if(y == k) k = x;
    else a[z].c[a[z].c[1] == y] = x;
    a[x].fa = z , a[y].fa = x , a[a[x].c[r]].fa = y , a[y].c[l] = a[x].c[r] , a[x].c[r] = y;
    pushup(y) , pushup(x);
}
inline void splay(int &k , int x)
{
    int y , z;
    while(x != k)
    {
        y = a[x].fa , z = a[y].fa;
        if(y != k)
        {
            if((a[y].c[0] == x) ^ (a[z].c[0] == y)) rotate(k , x);
            else rotate(k , y);
        }
        rotate(k , x);
    }
}
int find(int k , int x)
{
    pushdown(k);
    if(x <= a[a[k].c[0]].si) return find(a[k].c[0] , x);
    else if(x > a[a[k].c[0]].si + 1) return find(a[k].c[1] , x - a[a[k].c[0]].si - 1);
    else return k;
}
inline int split(int l , int r)
{
    int x = find(root , l) , y = find(root , r + 2);
    splay(root , x) , splay(a[root].c[1] , y);
    return a[a[root].c[1]].c[0];
}
inline int build(int l , int r)
{
    if(l > r) return 0;
    int mid = (l + r) >> 1;
    a[mid].c[0] = build(l , mid - 1) , a[a[mid].c[0]].fa = mid;
    a[mid].c[1] = build(mid + 1 , r) , a[a[mid].c[1]].fa = mid;
    pushup(mid);
    return mid;
}
inline void dfs(int x)
{
    if(!x) return;
    pushdown(x) , dfs(a[x].c[0]) , ans[++tot] = x , dfs(a[x].c[1]);
}
inline char nc()
{
    static char buf[100000] , *p1 , *p2;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf , 1 , 100000 , stdin) , p1 == p2) ? EOF : *p1 ++ ;
}
inline int read()
{
    int ret = 0; char ch = nc();
    while(!isdigit(ch)) ch = nc();
    while(isdigit(ch)) ret = ((ret + (ret << 2)) << 1) + (ch ^ '0') , ch = nc();
    return ret;
}
int main()
{
    int n = read() , m = read() , i , A , B , C , x;
    root = build(1 , n + 2);
    for(i = 1 ; i <= m ; i ++ )
    {
        A = read() , B = read() , C = read();
        x = split(A + 1 , A + B) , a[a[x].fa].c[0] = 0 , pushup(a[x].fa) , pushup(root) , rever(x);
        split(C + 1 , C) , a[x].fa = a[root].c[1] , a[a[x].fa].c[0] = x , pushup(a[x].fa) , pushup(root);
    }
    dfs(root);
    for(i = 2 ; i <= n + 1 ; i ++ ) printf("%d " , ans[i] - 1);
    return 0;
}
