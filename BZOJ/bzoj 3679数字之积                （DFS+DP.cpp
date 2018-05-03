#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
 
using namespace std;
typedef long long ll;
map<ll,int> mp;
int m;
ll n,l,r,now;
ll pri[]={2,3,5,7},val[6000],f[20][12][6000],v[20];
inline void dfs(int dep)
{
    if(now>n)    return ;
    if(dep==4)
    {
        mp[now]=++m,val[m]=now;
        return ;
    }
    int t=0;
    dfs(dep+1);
    while(now*pri[dep]<=n)   now*=pri[dep],t++,dfs(dep+1);
    while(t--)  now/=pri[dep];
}
ll calc(ll x)
{
    if(!x)  return 0;
    ll ret=0;
    int i,j,k,mx=0;
    ll tmp=1;
    while(x)    v[++mx]=x%10,x/=10;
    for(i=1;i<mx;i++)    for(j=1;j<=9;j++)    for(k=1;k<=m;k++)    ret+=f[i][j][k];
    for(i=mx;i;i--)
    {
        for(j=1;j<v[i];j++)
            for(k=1;k<=m;k++)    if(tmp*val[k]<=n)    ret+=f[i][j][k];
        tmp*=v[i];
        if(!tmp||tmp>n)  break;
    }
    if(!i)  ret++;
    return ret;
}
//先预处理出f(x)所有可能的取值，然后设dp[i][j]表示有i位，f值为j的数的个数
int main()
{
    scanf("%lld%lld%lld",&n,&l,&r);
    int i,j,k,h;
    now=1,dfs(0);
    for(i=1;i<=9;i++)    f[1][i][mp[i]]=1;
    for(i=2;i<=18;i++)
        for(k=1;k<=9;k++)
            for(j=1;j<=m;j++)    if(f[i-1][k][j])
                for(h=1;h<=9;h++)    if(val[j]*h<=n)
                    f[i][h][mp[val[j]*h]]+=f[i-1][k][j];
    printf("%lld",calc(r-1)-calc(l-1));
    return 0;
}
