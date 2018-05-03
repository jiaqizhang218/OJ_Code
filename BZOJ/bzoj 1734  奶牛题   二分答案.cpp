#include<cstdio>  
#include<algorithm>  
using namespace std;  
int x[100001];  
int main()  
{  
     int n,c;  
     scanf("%d%d",&n,&c);  
     int i;  
     for(i=1;i<=n;i++)  
          scanf("%d",&x[i]);  
     sort(x+1,x+1+n);  
     int l=1,r=x[n];  
     int ans=0;  
     while(l<=r)  
     {  
          int mid=(l+r)/2;  
          int last=x[1],sum=1;  
          for(i=2;i<=n;i++)  
          {  
               if(x[i]-last>=mid)  
               {  
                    sum++;  
                    last=x[i];  
               }  
          }  
          if(sum>=c)  
          {  
               if(mid>ans)  
                    ans=mid;  
               l=mid+1;  
          }  
          else  
               r=mid-1;  
     }  
     printf("%d\n",ans);  
     return 0;  
}  

