#include<bits/stdc++.h>
#define N 100010
using namespace std;
typedef long long ll;
ll a[N] , pos[N] , val[N];
int tot;
ll gcd(ll x,ll y){ll t; while(y) t=x,x=y,y=t%x; return x;}
int main()
{
    int T;
    scanf("%d" , &T);
    while(T -- )
    {
        tot = 0;
        int n , i , j , last;
        ll t , ans = 0;
        scanf("%d" , &n);
        for(i = 1 ; i <= n ; i ++ ) scanf("%lld" , &a[i]);
        for(i = 1 ; i <= n ; i ++ )
        {
            last = tot , tot = 0;
            for(j = 1 ; j <= last ; j ++ )
            {
                t = gcd(val[j] , a[i]);
                if(t != val[tot]) pos[++tot] = pos[j] , val[tot] = t , ans = max(ans , t * (i - pos[j] + 1));
            }
            if(a[i] != val[tot]) pos[++tot] = i , val[tot] = a[i] , ans = max(ans , a[i]);
        }
        printf("%lld\n" , ans);
    }
    return 0;
}
