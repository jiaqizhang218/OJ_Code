#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int N = 5005;
int n,m;
double f[2][N];
int main()
{
	scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++) 
	 {
        int now=i&1;
        if (i==0){f[now][j]=0;continue;}
        if (j==0){f[now][j]=f[now^1][j]+1;continue;}
        f[now][j]=max(0.0,(f[now^1][j]+1)*i/double(i+j)+(f[now][j-1]-1)*j/double(i+j));
     }
    printf("%.6f\n",f[n&1][m]-0.0000005);
    return 0;
}
