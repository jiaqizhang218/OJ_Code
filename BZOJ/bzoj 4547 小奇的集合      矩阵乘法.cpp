#include<bits/stdc++.h>
using namespace std;  
#define MAXN 1010
#define ll long long  
#define INF 1000000000  
#define MOD 10000007
ll n,m;  
struct mt{  
    ll x[4][4];  
    mt(){  
        memset(x,0,sizeof(x));  
    }  
    friend mt operator *(mt x,mt y){  
        ll i,j,k;  
        mt z;  
        for(i=1;i<=3;i++){  
            for(j=1;j<=3;j++){  
                for(k=1;k<=3;k++){  
                    (z.x[i][j]+=(ll)x.x[i][k]*y.x[k][j]%MOD)%=MOD;  
                }  
            }  
        }  
        return z;  
    }  
    void pt(){  
        ll i,j;  
        for(i=1;i<=3;i++){  
            for(j=1;j<=3;j++){  
                printf("%lld ",x[i][j]);  
            }  
            printf("\n");  
        }  
    }  
}a,b,c;  
ll mx=-INF,mx2=-INF;  
ll ans;
int main(){  
    ll i,x;
    scanf("%lld%lld",&n,&m);
    for(i=1;i<=n;i++){  
        scanf("%lld",&x);  
        ans+=x;  
        ans+=MOD;
        ans%=MOD;
        if(x>mx){
            mx2=mx;  
            mx=x;  
        }else if(x>mx2){  
            mx2=x;  
        }  
    }  
    if(mx<0){  
        ans+=((ll)(mx+mx2)*m%MOD+MOD)%MOD;  
        ans%=MOD;  
        printf("%lld\n",ans);  
        return 0;  
    }  
    while(m&&mx2<0){  
        ans+=mx+mx2;  
        ans+=MOD;  
        ans%=MOD;  
        mx2=mx+mx2;  
        mx2+=MOD;  
        mx2%=MOD;  
        m--;  
    }  
    a.x[1][1]=a.x[2][1]=a.x[1][2]=a.x[1][3]=a.x[3][3]=a.x[2][3]=1;  
    b.x[1][1]=b.x[2][2]=b.x[3][3]=1;  
    c.x[1][1]=mx;  c.x[1][2]=mx2;  c.x[1][3]=0;  
    for(;m;m>>=1,a=a*a) if(m&1) b=b*a;
    c=c*b;  
    (ans+=c.x[1][3]+MOD)%=MOD;  
    printf("%lld\n",ans);  
    return 0;  
} 
