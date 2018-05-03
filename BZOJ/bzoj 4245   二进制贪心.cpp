#include "iostream"  
#include "stdio.h"  
using namespace std;  
typedef long long ll;  
ll read(){  
    ll v=0,f=1; char ch=getchar();  
    while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=getchar(); }  
    while(ch>='0'&&ch<='9'){ v=v*10+ch-'0'; ch=getchar(); }  
    return v;  
}  
const int N=500005;  
ll num[N],l,m,mx=1,len,cnt,ans,xnum[N];  
   
int main(){  
    l=read(); m=read(); int i;  
    for (i=1;i<=l;i++){  
        num[i]=read();  
        if(num[i]>=mx<<1)  
            mx<<=1;    
    }  
    for (i=1;i<=l;i++) xnum[i]=num[i]^xnum[i-1];  
    while (l>=m&&mx){   
        cnt=len=0;  
        for (i=1;i<=l;i++){  
            if ((xnum[i]/mx)%2==0) ++cnt;
        }  
        if (cnt<m||(xnum[l]/mx)%2){  
            ans+=mx; mx>>=2; continue;  
        }  
        for (i=1;i<=l;i++){  
            if ((xnum[i]/mx)%2==0){  
                xnum[++len]=xnum[i];
            }  
        }  
        mx>>=2; l=len;  
    }  
    cout<<ans<<endl;  
    return 0;  
}
