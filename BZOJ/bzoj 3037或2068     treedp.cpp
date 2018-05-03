#include<bits/stdc++.h>  
using namespace std;  
#define maxn 1000020  
long long b[maxn],in[maxn],q[maxn];  
bool flag[maxn];  
int n;  
int main()  
{  
    int x,y,cnt;  
    int t=0;  
    int h=1;  
    scanf("%d",&n);  
    for(int i=1;i<=n;i++)  
    {  
        scanf("%d",&b[i]);  
        in[b[i]]++;  
    }  
    for(int i=1;i<=n;i++)  
        if(!in[i])  
     	   q[++t]=i;
    int tmp;  
    int ans=0;  
    while(h<=t)  
    {  
        tmp=q[h];  
        h++;  
        if(!flag[tmp]&&!flag[b[tmp]])  
        {  
            ans++;  
            flag[b[tmp]]=1;  
            in[b[b[tmp]]]--;  
            if (!in[b[b[tmp]]])  
            {  
                t++;  
                q[t]=b[b[tmp]];  
            }  
        }  
        flag[tmp]=1;  
    }  
  
    for (int i=1,j ; i<=n ; i++ )  
        if ( !flag[i] )  
        {  
            cnt=1;  
            flag[i]=true;  
            j=i;  
            while ( b[j]!=i )  
            {  
                flag[b[j]]=true;  
                cnt++;  
                j=b[j];  
            }  
            ans+=cnt/2;  
        }  
    printf("%d",ans);  
    return 0;  
}
