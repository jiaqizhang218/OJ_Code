#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#define M 1010  
#define MOD 2011  
using namespace std;  
struct abcd{  
    int height,key;  
    bool operator < (const abcd &x) const  
    {  
        if( height != x.height )  
            return height > x.height;  
        return key < x.key;  
    }  
}a[M];  
int n,ans1=1,ans2=1;  
int main()  
{  
    int i,j,k;  
    cin>>n;  
    for(i=1;i<=n;i++)  
    {  
        scanf("%d%d",&a[i].height,&a[i].key);  
        a[i].key--;  
    }  
    sort(a+1,a+n+1);  
    for(i=1;i<=n;i=j)  
    {  
        static int f[M];  
        memset(f,0,sizeof f);  
        f[0]=1;  
        for(j=i;j<=n&&a[i].height==a[j].height;j++)  
        {  
            (ans1*=min(i-1,a[j].key)+j-i+1)%=MOD;  
            for(k=1;k<=i-1&&k<=a[j].key;k++)  
                (f[k]+=f[k-1])%=MOD;  
        }  
        int temp=0;  
        for(k=0;k<=i-1&&k<=a[j-1].key;k++)  
            (temp+=f[k])%=MOD;  
        (ans2*=temp)%=MOD;  
    }  
    cout<<ans1<<' '<<ans2<<endl;  
    return 0;  
}  
