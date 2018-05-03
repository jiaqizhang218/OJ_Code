#include <cmath>
#include <cstdio>
inline double squ(double x)
{
    return x * x;
}
double qpow(double a,int x){
      double ans=1;
      for(;x;x>>=1,a=a*a){
        if(x&1)ans=ans*a;
      }
      return ans;
}
int main()
{
    int k , n , m , i , j;
    double ans = 0;
    scanf("%d%d%d" , &k , &n , &m);
    for(i = 1 ; i <= n ; i ++ )
        for(j = 1 ; j <= m ; j ++ )
            ans += 1 - qpow((squ((i - 1) * m) + squ((j - 1) * n) + squ((n - i) * m) + squ((m - j) * n)
    -squ((i - 1) * (j - 1)) - squ((i - 1) * (m - j)) - squ((n - i) * (j - 1)) - squ((n - i) * (m - j))) / squ(n * m) , k);
    printf("%.0lf\n" , ans);
    return 0;
}
