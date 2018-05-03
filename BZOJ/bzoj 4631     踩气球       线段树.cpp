#include<bits/stdc++.h> 
using namespace std;  
typedef long long LL;  
const int maxn = 100005, maxm = 5000005;  
  
int n, m, head[maxn << 2], cnt, tot[maxn], ans;  
LL tr[maxn << 2], sum[maxn];  
  
struct data {  
    int v, next;  
} g[maxm];  
  
inline int iread() {  
    int f = 1, x = 0; char ch = getchar();  
    for(; ch < '0' || ch > '9'; ch = getchar()) f = ch == '-' ? -1 : 1;  
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';  
    return f * x;  
}  
  
inline void add(int u, int v) {  
    g[cnt] = (data){v, head[u]};  
    head[u] = cnt++;  
}  
  
inline void update(int p) {  
    for(int i = head[p]; ~i; i = g[i].next) {  
        tot[g[i].v]--;  
        if(!tot[g[i].v]) ans++;  
    }  
}  
  
inline void build(int p, int l, int r) {  
    tr[p] = sum[r] - sum[l - 1];  
    head[p] = -1;  
    if(l == r) return;  
    int mid = l + r >> 1;  
    build(p << 1, l, mid); build(p << 1 | 1, mid + 1, r);  
}  
  
inline void insert(int p, int l, int r, int x, int y, int c) {  
    if(x <= l && r <= y) {  
        add(p, c); tot[c]++;  
        return;  
    }  
    int mid = l + r >> 1;  
    if(x <= mid) insert(p << 1, l, mid, x, y, c);  
    if(y > mid) insert(p << 1 | 1, mid + 1, r, x, y, c);  
}  
  
inline void change(int p, int l, int r, int x) {  
    tr[p]--;  
    if(!tr[p]) update(p);  
    if(l == r) return;  
    int mid = l + r >> 1;  
    if(x <= mid) change(p << 1, l, mid, x);  
    else change(p << 1 | 1, mid + 1, r, x);  
}  
  
int main() {  
    n = iread(); m = iread();  
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + iread();  
    build(1, 1, n);  
    for(int i = 1; i <= m; i++) {  
        int l = iread(), r = iread();  
        insert(1, 1, n, l, r, i);  
    }  
    for(m = iread(); m; m--) {  
        int x = (iread() + ans - 1) % n + 1;  
        change(1, 1, n, x);  
        printf("%d\n", ans);  
    }  
    return 0;  
}
