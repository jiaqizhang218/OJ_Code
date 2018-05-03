#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 55;
const ll MOD = 1e9 + 7;
vector<pair<int, int> > G[MAXN];
queue<int> Q;
int n, dis[MAXN], ind[MAXN];
char s[MAXN];
int main() {
  	scanf("%d", &n);
    for(int i = 0; i < n; i++) G[i].clear();
    for(int i = 0; i < n; i++) {
      scanf("%s", s);
      for(int j = 0; j < n; j++) {
        if(s[j] == '0') continue;
        G[i].push_back(make_pair(j, s[j] - '0'));
      }
    }
    memset(dis, 127 / 2, sizeof(dis));
    memset(ind, 0, sizeof(ind));
    dis[0] = 0; Q.push(0);
    while(!Q.empty()) {
      int cur = Q.front(); Q.pop();
      for(int i = 0; i < G[cur].size(); i++) {
        int nx = G[cur][i].first;
        if(dis[cur] + G[cur][i].second < dis[nx]) {
          dis[nx] = dis[cur] + G[cur][i].second;
          Q.push(nx);
        }
      }
    }
    ll ans = 1;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < G[i].size(); j++) {
        int nx = G[i][j].first;
        if(dis[i] + G[i][j].second == dis[nx]) {
          ind[nx]++;
        }
      }
    }
    for(int i = 1; i < n; i++) {
      ans = ans * ind[i] % MOD;
    }
    printf("%lld\n", ans);
  return 0;
}
