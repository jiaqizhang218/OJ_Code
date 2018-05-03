#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
int a[21],sum,i,j,ans,n,x;
int main()
{  
  scanf("%d",&n);  
  for (i=1;i<=n;i++)
    a[i]=a[i-1]+read();  
  sum=a[n]/2;//ÖÜ³¤Ò»°ë 
  for (i=1;i<=n;i++)  
  {  
    if (a[i-1]>=sum) break;  
    for (j=i+1;j<=n;j++)  
      if (a[j-1]-a[i-1]==sum) 
	  {
	  	ans++;break;
	  }
  }  
  printf("%d",ans*(ans-1)/2);  
  return 0;  
}
