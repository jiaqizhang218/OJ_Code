#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int head[200010] , to[200010] , next[200010] , cnt , root[200010] , l[200010] , r[200010] , d[200010] , si[200010];
ll m , len[200010] , v[200010];
inline void add(int x , int y , ll z)
{
    to[++cnt] = y;
    len[cnt] = z;
    next[cnt] = head[x];
    head[x] = cnt;
}
inline int merge(int x , int y)
{
    if(!x) return y;
    if(!y) return x;
    if(v[x] < v[y]) swap(x , y);
    r[x] = merge(r[x] , y);
    if(d[l[x]] < d[r[x]]) swap(l[x] , r[x]);
    d[x] = d[r[x]] + 1;
    return x;
}
inline void dfs(int x)
{
    int i;
    root[x] = x , si[x] = 1;
    for(i = head[x] ; i ; i = next[i])
        v[to[i]] = v[x] + len[i] , dfs(to[i]) , si[x] += si[to[i]] , root[x] = merge(root[x] , root[to[i]]);
    while(v[root[x]] > m + v[x])
        si[x] --  , root[x] = merge(l[root[x]] , r[root[x]]);
}
int main()
{
    int n , i , x;
    ll z;
    scanf("%d%lld" , &n , &m);
    for(i = 2 ; i <= n ; i ++ )
        scanf("%d%lld" , &x , &z) , add(x , i , z);
    d[0] = -1;
    dfs(1);
    for(i = 1 ; i <= n ; i ++ )
        printf("%d\n" , si[i]);
    return 0;
}
