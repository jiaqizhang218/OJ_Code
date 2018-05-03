#include<bits/stdc++.h>  
using namespace std;  
const int maxn=2e5+10;  
int n,m,l,r;  
int x[maxn<<1];  
int a[maxn],b[maxn];  
int sum[maxn<<1],s[maxn<<1];  
int main(){  
    scanf("%d%d",&n,&m);  
    for(int i=1;i<=n;i++){  
        scanf("%d%d",&a[i],&b[i]);b[i]+=a[i]-1;  
        x[++x[0]]=a[i];x[++x[0]]=b[i];  
    }sort(x+1,x+1+x[0]);  
    x[0]=unique(x+1,x+1+x[0])-x-1;  
    for(int i=1;i<=n;i++){  
        l=lower_bound(x+1,x+1+x[0],a[i])-x;  
        r=upper_bound(x+1,x+1+x[0],b[i])-x;  
        sum[l]++;sum[r]--;s[l]++;  
    }for(int i=1;i<=x[0]+1;i++)sum[i]+=sum[i-1],s[i]+=s[i-1];  
    while(m--){  
        scanf("%d%d",&l,&r);r+=l-1;  
        l=lower_bound(x+1,x+1+x[0],l)-x;  
        r=upper_bound(x+1,x+1+x[0],r)-x;  
        printf("%d\n",sum[l]+s[r-1]-s[l]);  
    }  
    return 0;  
}
