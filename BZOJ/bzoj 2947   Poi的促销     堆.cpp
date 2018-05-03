#include <set>  
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
int n,m;  
long long ans;  
multiset<int> s;  
int main()  
{  
    int i,j,x;  
    cin>>n;  
    for(i=1;i<=n;i++)  
    {  
        scanf("%d",&m);  
        for(j=1;j<=m;j++)  
            scanf("%d",&x),s.insert(x);  
        multiset<int>::iterator it=s.begin();  
        ans-=*it;s.erase(it);  
        it=s.end();it--;  
        ans+=*it;s.erase(it);  
    }  
    cout<<ans<<endl;  
    return 0;  
}  
