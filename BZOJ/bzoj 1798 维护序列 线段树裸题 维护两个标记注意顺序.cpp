/**************************************************************
    Problem: 1798
    User: iloi
    Language: C++
    Result: Accepted
    Time:3920 ms
    Memory:10200 kb
****************************************************************/
 
#include <cstdio>
#include <algorithm>
  
using namespace std;
typedef long long ll;
  
struct sgement_tree{
    ll sum, mul, add;
}seg[400025];
ll mod;
int n, M, L, R, X, oper, Mul, Add;
  
inline ll read(){
    ll x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
          
    while (ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}
  
inline void refresh(int p, int D){
    int l = p << 1, r = p << 1 | 1;
    seg[l].sum = (seg[l].sum * seg[p].mul + (D - (D >> 1)) * seg[p].add) % mod;
    seg[l].mul = seg[l].mul * seg[p].mul % mod;
    seg[l].add = (seg[l].add * seg[p].mul + seg[p].add) % mod;
    seg[r].sum = (seg[r].sum * seg[p].mul + (D >> 1) * seg[p].add) % mod;
    seg[r].mul = seg[r].mul * seg[p].mul % mod;
    seg[r].add = (seg[r].add * seg[p].mul + seg[p].add) % mod;
    seg[p].mul = 1, seg[p].add = 0; 
}
  
inline void fresh(int p){
    seg[p].sum = (seg[p << 1].sum + seg[p << 1 | 1].sum) % mod;
}
  
void build_seg(int p, int l, int r){
    seg[p].mul = 1, seg[p].add = 0;
    if (l == r){
        seg[p].sum = read();
        return;
    }
    int mid = (l + r) >> 1;
    build_seg(p << 1, l, mid);
    build_seg(p << 1 | 1, mid + 1, r);
    fresh(p);
}
  
void update(int p, int l, int r){
    if (R < l || r < L) return;
    if (L <= l && r <= R){
        seg[p].sum = (seg[p].sum * Mul + (r - l + 1) * Add) % mod;
        seg[p].mul = seg[p].mul * Mul % mod;
        seg[p].add = (seg[p].add * Mul + Add) % mod;
        return;
    }
    int mid = (l + r) >> 1;
    refresh(p, r - l + 1);
    update(p << 1, l, mid);
    update(p << 1 | 1, mid + 1, r);
    fresh(p);
}
  
ll query(int p, int l, int r){
    if (R < l || r < L) return 0;
    if (L <= l && r <= R) return seg[p].sum;
    int mid = (l + r) >> 1;
    refresh(p, r - l + 1);
    ll res = (query(p << 1, l, mid) + query(p << 1 | 1, mid + 1, r)) % mod;
    fresh(p);
    return res;
}
  
int main(){
    n = read(), mod = read();
    build_seg(1, 1, n);
    M = read();
     
    while (M--){
        oper = read();
        if (oper == 1){
            L = read(), R = read();
            Mul = read(), Add = 0;
             
            update(1, 1, n);
        }else
        if (oper == 2){
            L = read(), R = read();
            Mul = 1, Add = read();
             
            update(1, 1, n);
        }else{
            L = read(), R = read();
             
            printf("%lld\n", query(1, 1, n));
        }
    }
    return 0;
}
