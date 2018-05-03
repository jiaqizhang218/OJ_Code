#include<cmath>  
#include<cstdio>  
#include<iostream>
#include<algorithm>  
using namespace std;  
typedef long long LL;  
const int maxn=(1<<16)+5;  
int p[17],a[17];  
LL f[17][maxn],ans;  
int main()  
{  
    int n,m,i,j,x;  
    p[1]=1; for(i=2;i<17;i++)	p[i]=p[i-1]<<1;  
    scanf("%d%d",&n,&m);  
    for(i=1;i<=n;i++)	scanf("%d",&a[i]),f[i][p[i]]=1;  
    
    int k=(1<<n)-1; 
	 
    for(x=1;x<=k;x++)  
      	for(i=1;i<=n;i++)  
       		if(x&p[i])  
        		for(j=1;j<=n;j++)  
         			if( (x&p[j])==0 && abs(a[i]-a[j])>m)  //表示加进去的牛没被算过且编号差大于m 
           				f[j][x+p[j]]+=f[i][x];  
           		
    for(i=1;i<=n;i++)	ans+=f[i][k];  
    printf("%lld\n",ans);  
    return 0;  
}  
