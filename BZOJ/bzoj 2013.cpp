#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
using namespace std;
template<class K> inline void read(K& x) {
  register char c = getchar();
  for(x = 0;!isdigit(c); c = getchar());
  for(;isdigit(c); c = getchar())
    x = x * 10 + c - '0';
}

template<class K> inline void write(K x) {
  static int fout[20], top;
  do fout[top++] = x % 10, x /= 10; while(x);
  while(top) putchar(fout[--top] + '0');
}
const int maxn=700005;
const int mod=1000000009;
int a[maxn];
int main(){
  int n,d;read(n),read(d);
  for(int i=1;i<=n;++i)read(a[i]);
  sort(a+1,a+n+1);
  int ans=1;
  int pt=1;
  for(int i=1;i<=n;++i){
    while(pt<=n&&a[pt]<a[i]-d)++pt;
    ans=ans*1ll*(i-pt+1)%mod;
  }
  write(ans); 
  return 0;
}
