#include <cstdio>
#include <cstring>
#include <queue>
#define N 10000
#define M 500000
#define inf 0x3f3f3f3f
using namespace std;
queue<int> q;
int head[N] , to[M] , val[M] , cost[M] , next[M] , cnt , s , d , t , dis[N] , from[N] , pre[N];
void add(int x , int y , int v , int c)
{
    to[++cnt] = y , val[cnt] = v , cost[cnt] = c , next[cnt] = head[x] , head[x] = cnt;
    to[++cnt] = x , val[cnt] = 0 , cost[cnt] = -c , next[cnt] = head[y] , head[y] = cnt;
}
bool spfa()
{
    int x , i;
    memset(from , -1 , sizeof(from));
    memset(dis , 0x3f , sizeof(dis));
    dis[s] = 0 , q.push(s);
    while(!q.empty())
    {
        x = q.front() , q.pop();
        for(i = head[x] ; i ; i = next[i])
            if(val[i] && dis[to[i]] > dis[x] + cost[i])
                dis[to[i]] = dis[x] + cost[i] , from[to[i]] = x , pre[to[i]] = i , q.push(to[i]);
    }
    return ~from[t];
}
int main()
{
    int T , Case;
    scanf("%d" , &T);
    for(Case = 1 ; Case <= T ; Case ++ )
    {
        memset(head , 0 , sizeof(head)) , cnt = 1;
        int n , m , k , i , x , y , f = 0 , ans = 0;
        scanf("%d%d%d" , &n , &m , &k) , s = 0 , d = 2 * n + 1 , t = 2 * n + 2;
        for(i = 1 ; i < n ; i ++ ) add(i , i + 1 , inf , 0);
        for(i = 1 ; i <= n ; i ++ ) scanf("%d" , &x) , add(s , i , x , 0) , add(i + n , t , x , 0) , add(d , i + n , inf , 0) , f += x;
        for(i = 1 ; i <= m ; i ++ ) scanf("%d%d" , &x , &y) , add(s , d , x , y);
        while(k -- )
        {
            scanf("%d%d" , &x , &y);
            for(i = 1 ; i <= n - x - 1 ; i ++ ) add(i , i + x + 1 + n , inf , y);
        }
        while(spfa())
        {
            x = inf;
            for(i = t ; i != s ; i = from[i]) x = min(x , val[pre[i]]);
            f -= x , ans += x * dis[t];
            for(i = t ; i != s ; i = from[i]) val[pre[i]] -= x , val[pre[i] ^ 1] += x;
        }
        printf("Case %d: " , Case);
        if(f) printf("impossible\n");
        else printf("%d\n" , ans);
    }
    return 0;
}
