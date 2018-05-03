#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int v[N] , a[N] , root[N] , ls[N << 5] , rs[N << 5] , sum[N << 5] , tot;

template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
void insert(int p , int l , int r , int x , int &y)
{
    y = ++tot , sum[y] = sum[x] + a[p];
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(p <= mid) rs[y] = rs[x] , insert(p , l , mid , ls[x] , ls[y]);
    else ls[y] = ls[x] , insert(p , mid + 1 , r , rs[x] , rs[y]);
}
int query(int p , int l , int r , int x , int y)
{
    if(r <= p) return sum[y] - sum[x];
    int mid = (l + r) >> 1;
    if(p <= mid) return query(p , l , mid , ls[x] , ls[y]);
    else return query(p , mid + 1 , r , rs[x] , rs[y]) + sum[ls[y]] - sum[ls[x]];
}
int main()
{
    int n , m , i , x , y , ans , tmp;
    rd(n);
    for(i = 1 ; i <= n ; i ++ ) rd(a[i]), v[i] = a[i];
    sort(a + 1 , a + n + 1);
    for(i = 1 ; i <= n ; i ++ ) v[i] = lower_bound(a + 1 , a + n + 1 , v[i]) - a;
    for(i = 1 ; i <= n ; i ++ ) insert(v[i] , 1 , n , root[i - 1] , root[i]);
    a[n + 1] = 1 << 30;
    rd(m);
    while(m -- )
    {
        rd(x),rd(y) , ans = 1;
        while((tmp = query(upper_bound(a + 1 , a + n + 2 , ans) - a - 1 , 1 , n , root[x - 1] , root[y])) >= ans)
            ans = tmp + 1;
        printf("%d\n" , ans);
    }
    return 0;
}
