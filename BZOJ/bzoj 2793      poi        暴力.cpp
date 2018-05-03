#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1000010
using namespace std;
int tag[N] , vis[N] , pos[N] , tot;
long long sta[N];
int main()
{
    int n = 0 , m , k , i , x;
    long long now = 0;
    scanf("%d" , &m);
    for(i = 1 ; i <= m ; i ++ ) scanf("%d" , &x) , tag[x] = 1 , n = max(n , x);
    for(i = 1 ; i <= n ; i ++ ) pos[i] = i;
    scanf("%d" , &k);
    while(k -- )
    {
        scanf("%d" , &x);
        for(i = 1 ; i <= x ; i ++ )
        {
            while(pos[x] <= n && vis[pos[x]]) pos[x] += x;
            if(pos[x] > n) break;
            if(tag[pos[x]]) sta[++tot] = now + i;
            vis[pos[x]] = 1;
        }
        now += x;
    }
    printf("%d\n" , tot);
    for(i = 1 ; i <= tot ; i ++ ) printf("%lld\n" , sta[i]);
    return 0;
}
