#include<bits/stdc++.h>
#define N 1001000
int i,j,n,p[N];char s[N];long long ans;
int main(){
    for(scanf("%d%s",&n,s+1),i=2;i<=n;i++){
        for(;j&&s[j+1]^s[i];j=p[j]);
        if(s[i]==s[j+1])j++;
        p[i]=j;
    }
    for(i=1;i<=n;i++)if(p[p[i]])p[i]=p[p[i]];
    for(i=1;i<=n;i++)if(p[i])ans+=i-p[i];
    printf("%lld",ans);
}
