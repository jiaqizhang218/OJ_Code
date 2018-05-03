#include<bits/stdc++.h>
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
typedef long long ll;
struct matrix  
{  
  ll p[4][4];int n,m;  
  matrix(){memset(p,0,sizeof(p));}  
}res,a;  
ll MOD,n,chen,i,ans;  
matrix operator * (matrix a,matrix b)  
  {  
    matrix c;c.n=a.n;c.m=a.m;  
    for (int i=1;i<=a.n;i++)  
      for (int j=1;j<=b.m;j++)  
        for (int k=1;k<=a.m;k++)    
          c.p[i][j]=(c.p[i][j]+1ll*a.p[i][k]*b.p[k][j])%MOD;  
    return c;  
  }  
void make_matrix()  
{  
  a.p[1][2]=a.p[1][3]=a.p[2][3]=0ll;  
  a.p[2][1]=a.p[2][2]=a.p[3][1]=a.p[3][2]=a.p[3][3]=1ll;  
  a.p[1][1]=chen%MOD;a.n=3;a.m=3;  
  res.p[1][2]=(chen/10-1ll)%MOD;res.p[1][3]=1ll;  
  res.n=1;res.m=3;  
}  
void quick(ll b)  
{  
  bool flag=true;
  for(;b;b>>=1,a=a*a) if(b&1) res=res*a;
}  
int main()  
{  
  scanf("%lld%lld",&n,&MOD);  
  res.p[1][1]=0ll;chen=1ll;  
  for (i=1;i<=18;i++)  
  {  
    chen*=10ll;  
    make_matrix();  
    quick((chen<=n)?(chen/10*9ll):(n-chen/10+1ll));  
    if (chen>n) break;  
  }  
  printf("%lld",res.p[1][1]);  
  return 0;  
} 
