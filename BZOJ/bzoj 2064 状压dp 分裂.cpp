#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
const int INF = 0x7fffffff;
int ed,n,m,sum[1<<22],f[1<<22];
inline int read()
{
	int f = 1 , x = 0 ; char ch = getchar();
	while(ch<'0'||ch>'9'){f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int lowbit(int x){return x&(-x);}
void init()
{
	n = read();
	for(int i = 1 ; i <= n ; i++)
		sum[1<<i>>1] = read();  //第i块地的面积保存在i上. 
	m = read();
	for(int j = 1 ; j <= m ; j++)
	{
		sum[1<<(n+j)>>1] = -1 * read();  //变化后的土地取负值 
	}
	n = n + m;
	ed = (1<<n)-1;	//ed表示了所有状态 
}
#include<iostream>  
#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<cmath>  
#include<algorithm>  
#define F(i,j,n) for(int i=j;i<=n;i++)  
#define D(i,j,n) for(int i=j;i>=n;i--)  
#define ll long long  
#define maxn 2000000  
using namespace std;  
int n,m,f[maxn],sum[maxn];  
inline int read()  
{  
    int x=0,f=1;char ch=getchar();  
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}  
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  
    return x*f;  
}  
int main()  
{  
    n=read();F(i,1,n) sum[1<<(i-1)]=read();  
    m=read();F(i,1,m) sum[1<<(n+i-1)]=-read();  
    int num=(1<<(n+m))-1;  
    F(i,1,num)  
    {  
        int tmp=i&(-i);  
        sum[i]=sum[tmp]+sum[i-tmp];  
        F(j,1,n+m) if (i&(1<<(j-1))) f[i]=max(f[i],f[i-(1<<(j-1))]);  
        if (!sum[i]) f[i]++;  
    }  
    printf("%d\n",n+m-2*f[num]);  
    return 0;  
}  int main()
{
	init();
	for(int i = 1 ; i <= ed ; i++)
	{
		int t = lowbit(i) ;  ///取最低位 
		sum[i] = sum[t] + sum [i-t];
		for(int j = 1 ; j <= n ; j++)
			if( ( i & ( 1<<j>>1 ) ) > 1)
			{
				int k = i - (1<<j>>1);
				f[i] = max(f[k],f[i]);
			}
		if(!sum[i]) f[i]++;	
	}
	printf("%d",n-2*f[ed]);
	return 0;
}
