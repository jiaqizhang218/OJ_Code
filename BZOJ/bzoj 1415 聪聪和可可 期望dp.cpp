#include <bits/stdc++.h>
using namespace std;
int N, E, C, M;
#define maxn 1010
vector <int> mp[maxn];
int p[maxn][maxn];
double dp[maxn][maxn];
int dist[maxn];
int t[maxn];
void bfs(int s)
{
    queue <int> q;
    q.push(s);
    int vis[maxn];
    memset(vis, 0, sizeof(vis));
    memset(dist, -1, sizeof(dist));
    dist[s] = 0;
    vis[s] = 1;    
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i = 0; i < mp[u].size(); i++)
        {
            if(dist[mp[u][i]] == -1)
            {
                dist[mp[u][i]] = dist[u]+1;
                p[mp[u][i]][s] = u;
                q.push(mp[u][i]);
            }
            else if(dist[mp[u][i]] == dist[u]+1) p[mp[u][i]][s] = min(p[mp[u][i]][s], u);
        }
    }
}
double dfs(int from, int to)
{
    if(dp[from][to] != -1) return dp[from][to];
 
    if(from == to) return dp[from][to] = 0;
    if(p[from][to] == to || p[p[from][to]][to] == to) return dp[from][to] = 1.0;
 
    double sum = dfs(p[p[from][to]][to], to); //ÁôÔÚÔ­µØ
    for(int i = 0; i < mp[to].size(); i++)
    {
        sum += dfs(p[p[from][to]][to], mp[to][i]);
    }
    sum /= (t[to]+1.0); sum += 1;
    return dp[from][to] = sum;
 
 
}
int main() 
{
    while(~scanf("%d%d", &N, &E))
    {
        scanf("%d%d", &C, &M);
        for(int i = 1; i <= N; i++) mp[i].clear();
        memset(t, 0, sizeof(t));
        for(int i = 1; i <= E; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            t[a]++; t[b]++;
            mp[a].push_back(b);
            mp[b].push_back(a);  
        }
        memset(p, -1, sizeof(p));
        for(int i = 1; i <= N; i++) bfs(i);
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++) dp[i][j] = -1;
        }
        double ans = dfs(C, M);
        printf("%.3lf\n", ans);
          
    }
    return 0;
}
