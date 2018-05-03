#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const double eps = 1e-5;
const int maxn = 1010;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
LL ans;  
int n,k,c[maxn];  
bool cmp(int a,int b)  
{  
    return a>b;  
}  
  
int main()  
{  
    scanf("%d%d",&n,&k);  
    for (int i=1;i<=k;i++) scanf("%d",&c[i]);  
    sort(c+1,c+k+1,cmp);  
    for (int i=1;i<=min(k,n/2);i++) ans+=(long long)(n-1-2*(i-1))*c[i];  
    printf("%lld\n",ans);  
    return 0;  
} 


