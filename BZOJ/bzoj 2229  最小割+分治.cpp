#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int N = 205;
const int M = 20005;
queue<int> q;
int n,head[N],to[M],val[M],nxt[M],cnt,s,t,dis[N],ans[N][N],a[N],tmp[N],v[M],tot;
inline void add(int x,int y,int z)
{
	to[++cnt]=y;val[cnt]=z;nxt[cnt]=head[x];head[x]=cnt;
	to[++cnt]=x,val[cnt]=z;nxt[cnt]=head[y];head[y]=cnt;
}
inline bool bfs()
{
    int x , i;
    memset(dis , 0 , sizeof(dis));
    while(!q.empty()) q.pop();
    dis[s] = 1 , q.push(s);
    while(!q.empty())
    {
        x = q.front() , q.pop();
        for(i = head[x] ; i ; i = nxt[i])
        {
            if(val[i] && !dis[to[i]])
            {
                dis[to[i]] = dis[x] + 1;
                if(to[i] == t) return 1;
                q.push(to[i]);
            }
        }
    }
    return 0;
}
inline int dinic(int x , int low)
{
    if(x == t) return low;
    int temp = low , i , k;
    for(i = head[x] ; i ; i = nxt[i])
    {
        if(val[i] && dis[to[i]] == dis[x] + 1)
        {
            k = dinic(to[i] , min(temp , val[i]));
            if(!k) dis[to[i]] = 0;
            val[i] -= k , val[i ^ 1] += k;
            if(!(temp -= k)) break;
        }
    }
    return low - temp;
}
inline void solve(int l , int r)
{
    if(l >= r) return;
    int i , j , sum = 0 , p1 , p2;
    for(i = 2 ; i <= cnt ; i += 2) val[i] = val[i ^ 1] = (val[i] + val[i ^ 1]) >> 1;
    s = a[l] , t = a[r];
    while(bfs()) sum += dinic(s , 1 << 30);
    for(i = 1 ; i <= n ; i ++ )
        if(dis[i])
            for(j = 1 ; j <= n ; j ++ )
                if(!dis[j])
                    ans[i][j] = ans[j][i] = min(ans[i][j] , sum);
    for(p1 = i = l , p2 = r ; i <= r ; i ++ )
    {
        if(dis[a[i]]) tmp[p1 ++ ] = a[i];
        else tmp[p2 -- ] = a[i];
    }
    for(i = l ; i <= r ; i ++ ) a[i] = tmp[i];
    solve(l , p2) , solve(p1 , r);
}
int main()
{
    int T;
    scanf("%d" , &T);
    while(T -- )
    {
        memset(head , 0 , sizeof(head)) , cnt = 1 , memset(ans , 0x7f , sizeof(ans)) , tot = 0;
        int m , i , j , x , y , z , k;
        scanf("%d%d" , &n , &m);
        while(m -- ) scanf("%d%d%d" , &x , &y , &z) , add(x , y , z);
        for(i = 1 ; i <= n ; i ++ ) a[i] = i;
        solve(1 , n);
        for(i = 1 ; i <= n ; i ++ )
            for(j = i + 1 ; j <= n ; j ++ )
                v[++tot] = ans[i][j];
        sort(v + 1 , v + tot + 1);
        scanf("%d" , &k);
        while (k -- )
        {
            scanf("%d" , &x);
            if(x >= v[tot]) printf("%d\n" , tot);
            else printf("%d\n" , upper_bound(v + 1 , v + tot + 1 , x) - v - 1);
        }
        if(T) printf("\n");
    }
    return 0;
}
