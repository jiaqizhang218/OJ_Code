// 区间cover & 区间gcd
#include <map>
#include <cstdio>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 100005;
map<PII, int> I;
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
pair<PII, int> make_tuple(int x, int y, int z) {
  return make_pair(make_pair(x, y), z);
}
void split(int p) {
  map<PII, int>::iterator it = I.lower_bound(make_pair(p, p));
  if((*it).first.first != p) {
    it--; // [l, r] -> [l, p - 1] + [p, r]
    int l = (*it).first.first, r = (*it).first.second, v = (*it).second;
    I.erase(it);
    I.insert(make_tuple(l, p - 1, v));
    I.insert(make_tuple(p, r, v));
  }
}
void cover(int l, int r, int v) {
  split(l); split(r + 1);
  map<PII, int>::iterator L = I.lower_bound(make_pair(l, l));
  map<PII, int>::iterator R = I.lower_bound(make_pair(r + 1, r + 1));
  I.erase(L, R);
  I.insert(make_tuple(l, r, v));
}
void gcd(int l, int r, int v) {
  split(l); split(r + 1);
  map<PII, int>::iterator it = I.lower_bound(make_pair(l, l));
  for(; (*it).first.second <= r; it++) 
    if((*it).second > v) (*it).second = gcd((*it).second, v);
}
int main() {
  int T; scanf("%d", &T);
  while(T--) {
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
      int x; scanf("%d", &x);
      I.insert(make_tuple(i, i, x));
    }
    I.insert(make_tuple(n + 1, n + 1, -1));
    int m; scanf("%d", &m);
    while(m--) {
      int t, l, r, x; scanf("%d %d %d %d", &t, &l, &r, &x);
      if(t == 1) cover(l, r, x); else gcd(l, r, x);
    }
    map<PII, int>::iterator it = I.begin();
    for(; it != I.end(); it++) {
      if((*it).first.first == n + 1) break;
      for(int i = (*it).first.first; i <= (*it).first.second; i++) 
        printf("%d ", (*it).second);
    }
    putchar('\n');
  }
  return 0;
}
