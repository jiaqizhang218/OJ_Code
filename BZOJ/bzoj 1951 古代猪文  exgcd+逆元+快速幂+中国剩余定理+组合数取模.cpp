#include <cstdio>
typedef long long ll;
 
const int MOD = 999911659;
int m[4] = {2, 3, 4679, 35617};
int fac[4][36666], a[4], d[11111];
 
int exgcd(int a, int b, int &x, int &y) {
    if(!b) {
        x = 1; y = 0;
        return a;
    }
    int ret = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return ret;
}
 
int inv(int a, int mod) {
    int x, y, d = exgcd(a, mod, x, y);
    if(x < 0)   x += mod;
    return x;
}
 
int C(int i, int n, int k, int p) {
    return fac[i][n]*inv(fac[i][n-k]*fac[i][k]%p, p)%p;
}
 
int Lucas(int i, int n, int k, int p) {
    int ret = 1;
    while(n && k) {
        ret = ret*C(i, n%p, k%p, p)%p;
        if(ret == 0)    return 0;
        n /= p; k /= p;
    }
    return ret;
}
 
int pow_mod(int x, int n, int mod) {
    int ret = 1;
    while(n) {
        if(n&1) ret = (ll)ret*x%mod;
        x = (ll)x*x%mod;
        n >>= 1;
    }
    return ret;
}
 
int China(int n, int a[], int m[]) {
    int M = 1;
    for(int i = 0;i < n; i++)   M *= m[i];
    int ret = 0;
    for(int i = 0;i < n; i++) {
        int w = M/m[i], x, y;
        int d = exgcd(w, m[i], x, y);
        ret = (ret + (ll)x*w*a[i])%M;
    }
    return (ret+M)%M;
}
 
int main() {
    int n, g;
    scanf("%d%d", &n, &g);
    if(g == MOD)    return puts("0") , 0;
    int tot = 0;
    for(int i = 1;i*i <= n; i++) if(n%i == 0) {
        if(i*i == n)    d[tot++] = i;
        else    d[tot++] = i, d[tot++] = n/i;
    }
    for(int i = 0;i < 4; i++) {
        fac[i][0] = 1;
        for(int j = 1;j <= m[i]; j++)
            fac[i][j] = fac[i][j-1]*j%m[i];
    }
    for(int i = 0;i < tot; i++) {
        for(int j = 0;j < 4; j++) {
            a[j] += Lucas(j, n, d[i], m[j]) % m[j];
            a[j] %= m[j];
        }
    }
    int ans = China(4, a, m);
    printf("%d\n", pow_mod(g, ans, MOD));
    return 0;
}
