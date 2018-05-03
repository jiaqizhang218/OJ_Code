#include<bits/stdc++.h>
using namespace std;  
  
const int maxn = 1E5 + 10;  
  
struct data{  
    int pre,nex;  
}a[maxn];  
  
int n,tot,m,ti,pre[maxn],nex[maxn],ans[maxn],vis[maxn],p[maxn];  
  
vector <int> v[maxn];  
queue <int> q;  
  
int main()  
{  
    cin >> n >> m;  
    while (m--) {  
        int x,y; scanf("%d%d",&x,&y);  
        v[x].push_back(y); v[y].push_back(x);  
    }  
  
    for (int i = 1; i <= n; i++) pre[i] = i-1,nex[i] = i+1;  
    nex[0] = 1; pre[n+1] = n;   
    while (nex[0] != n+1) {  
        ++tot; ++ans[tot]; q.push(nex[0]);   
        nex[0] = nex[nex[0]]; pre[nex[0]] = 0;  
        while (!q.empty()) {  
            int k = q.front(); q.pop(); ++ti;  
            for (int i = 0; i < v[k].size(); i++) vis[v[k][i]] = ti;  
            for (int x = nex[0]; x != n+1; x = nex[x])   
                if (vis[x] != ti) {  
                    nex[pre[x]] = nex[x];  
                    pre[nex[x]] = pre[x];  
                    ++ans[tot]; q.push(x);  
                }  
        }  
    }  
      
    printf("%d\n",tot);  
    sort(ans + 1,ans + tot + 1);  
    for (int i = 1; i <= tot; i++) printf("%d ",ans[i]);  
    return 0;  
}
