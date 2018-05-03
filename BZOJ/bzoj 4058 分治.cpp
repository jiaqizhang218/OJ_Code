#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define maxn 200007

inline int rd() {
    char c = getchar();
    while (!isdigit(c)) c = getchar() ; int x = c - '0';
    while (isdigit(c = getchar())) x = x * 10 + c - '0';
    return x;
}

char a[maxn];

int s[maxn] , tmp[maxn] , n;

void input() {
    scanf("%s" , a + 1);
    for (n = 1;a[n];n ++) s[n] = a[n] - '0';
    s[0] = s[n] = 0;
    n --;
}

bool work(int l , int r) {
    int p = 0;
    rep (i , l , r) if (s[i]) {
        p = 1;
        break;
    }
    if (!p) return 0;
    if ((r - l) & 1) return 1;
    int t = 0;
    for (int i = l + 1;i <= r;i += 2)
        tmp[++ t] = s[i];
    int m = l + t - 1;
    for (int i = l + 1;i <= r;i += 2)
        tmp[++ t] = s[i + 1] ^ s[i - 1];
    rep (i , 1 , t)
        s[i + l - 1] = tmp[i];
    r = l + t - 1;
    return work(l , m) || work(m + 1 , r);
}

void solve() {
    puts(work(1 , n) ? "LIVES" : "DIES");
}

int main() {
    per (T , rd() , 1) {
        input();
        solve();
    }
    return 0;
}
