#include<bits/stdc++.h>
#define N 500010
#define lson l , mid , a[x].ls
#define rson mid + 1 , r , a[x].rs
using namespace std;
struct data
{
    int ls , rs , si;
}a[N * 60];
int w[N] , root[N] , tot;
inline int read()
{
    int ret = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0' , ch = getchar();
    return ret;
}
void update(int p , int v  , int l , int r , int &x)
{
    if(!x) x = ++tot;
    a[x].si += v;
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(p <= mid) update(p , v , lson);
    else update(p , v , rson);
}
int query(int b , int e , int l , int r , int x)
{
    if(!x) return 0;
    if(b <= l && r <= e) return a[x].si;
    int mid = (l + r) >> 1 , ans = 0;
    if(b <= mid) ans += query(b , e , lson);
    if(e > mid) ans += query(b , e , rson);
    return ans;
}
int main()
{
    srand(19260817);
    int n , m , i , l , r , s , k , x , p , t;
    n = read() , m = read();
    for(i = 1 ; i <= n ; i ++ ) w[i] = read() , update(i , 1 , 1 , n , root[w[i]]);
    while(m -- )
    {
        l = read() , r = read() , s = read() , k = read() , p = 0;
        for(i = 1 ; i <= 15 ; i ++ )
        {
            t = w[rand() % (r - l + 1) + l];
            if(query(l , r , 1 , n , root[t]) > (r - l + 1) >> 1)
            {
                p = t;
                break;
            }
        }
        if(!p) p = s;
        printf("%d\n" , p);
        for(i = 1 ; i <= k ; i ++ ) x = read() , update(x , -1 , 1 , n , root[w[x]]) , update(x , 1 , 1 , n , root[p]) , w[x] = p;
    }
    p = -1;
    for(i = 1 ; i <= 15 ; i ++ )
    {
        t = w[rand() % n + 1];
        if(a[root[t]].si > n >> 1)
        {
            p = t;
            break;
        }
    }
    printf("%d\n" , p);
    return 0;
}
