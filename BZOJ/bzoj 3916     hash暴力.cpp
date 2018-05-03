#include<bits/stdc++.h>
typedef long long ll;
#define MAXN 4000010  
#define MAXM 1010  
#define INF 1000000000  
#define MOD 1000000007 
using namespace std;
int n;  
char s[MAXN];  
ll h[MAXN],mi[MAXN];  
ll bas=233;  
int ans;  
ll ansh;  
int main(){  
    int i;  
    scanf("%d%s",&n,s+1);  
    if(!(n&1)){  
        printf("NOT POSSIBLE\n");  
        return 0;  
    }  
    mi[0]=1;  
    for(i=1;i<=n;i++){  
        mi[i]=mi[i-1]*bas%MOD;  
        h[i]=(h[i-1]*bas+s[i])%MOD;  
    }  
    for(i=1;i<=n/2+1;i++){  
        if((h[n/2+1]-h[i]*mi[n/2+1-i]%MOD+h[i-1]*mi[n/2+1-i]%MOD+MOD)%MOD  
            ==  
            (h[n]-h[n/2+1]*mi[n-n/2-1]%MOD+MOD)%MOD){  
            if(ans&&ansh!=(h[n]-h[n/2+1]*mi[n-n/2-1]%MOD+MOD)%MOD){  
                printf("NOT UNIQUE\n");  
                return 0;  
            }  
            ans=i;  
            ansh=(h[n]-h[n/2+1]*mi[n-n/2-1]%MOD+MOD)%MOD;  
        }  
    }  
    for(;i<=n;i++){  
        if(((h[n]-h[i]*mi[n-i]%MOD+MOD)+(h[i-1]-h[n/2]*mi[i-1-n/2]%MOD+MOD)%MOD*mi[n-i]%MOD)%MOD  
            ==  
            h[n/2]){  
              
            if(ans&&ansh!=h[n/2]){  
                printf("NOT UNIQUE\n");  
                return 0;  
            }  
            ans=i;  
            ansh=h[n/2];  
        }  
    }  
    if(!ans){  
        printf("NOT POSSIBLE\n");  
        return 0;  
    }  
    for(i=1;i<=n/2+(ans<=n/2);i++){  
        if(i!=ans){  
            printf("%c",s[i]);  
        }  
    }  
    printf("\n");  
    return 0;  
}  
