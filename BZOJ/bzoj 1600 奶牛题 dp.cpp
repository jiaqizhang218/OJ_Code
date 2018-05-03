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
int f[5][2555],n,mx;  
int main()  
{  
    n=read();
    mx=(n+1)/2-1;  
    f[0][0]=1;  
    for(int i=1;i<=4;i++)  
        for(int j=1;j<=n;j++)  
            for(int k=1;k<=min(j,mx);k++)  
                f[i][j]+=f[i-1][j-k];  
    cout<<f[4][n];  
    return 0;  
} 
