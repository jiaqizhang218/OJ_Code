#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100005
using namespace std;
int n,k,num,i,j,p,x[N][6],C[7][7],status,flag,pre,cnt,t;
typedef long long ll;
ll ans,h,Time,del;
const ll hash=99997;const ll base=97;
struct arr{int num,s,next;}a[100005];
int end[hash],temp[7],f[100005][7],data[100005];
ll doit(int k)
{
  int j;
  for (int i=end[k];i;i=a[i].next)
  {
    j=0;
    if (a[i].num==t)
    for (j=1;j<=t;j++)
      if (temp[j]!=f[i][j]) break;
    if (j==t+1) return ++a[i].s;
  }
  if (!end[k]) data[++pre]=k;
  cnt++;a[cnt].num=t;a[cnt].s=0;a[cnt].next=end[k];end[k]=cnt;
  for (j=1;j<=t;j++) f[cnt][j]=temp[j];return 0;
}
inline int Read()
{
  int x=0;char ch=getchar();bool positive=1;
  for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') positive=0;
  for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
  return positive?x:-x;
}
int main()
{
  scanf("%d%d",&n,&k);
  for (i=1;i<=n;i++)
    for (j=0;j<6;j++)
      x[i][j]=Read();
  C[0][0]=1;  
  for (i=1;i<=6;i++)  
  {  
    C[i][0]=1;  
    for (j=1;j<=i;j++) C[i][j]=C[i-1][j]+C[i-1][j-1];  
  }  
  for (status=0;status<64;status++)
  {
    flag=0;pre=0;
    for (j=0;j<6;j++)
      flag+=(status&(1<<j))?1:0;
    if (flag<k) continue;
    Time=0ll;
    for (i=1;i<=n;i++)
    {
      h=0ll;t=0;
      for (j=0;j<6;j++)
        if (status&(1<<j))
          h=(h*base+ll(x[i][j]))%hash,temp[++t]=x[i][j];
      Time+=doit(h);
    }
    cnt=0;for (i=1;i<=pre;i++) end[data[i]]=0;
    del=((flag-k)&1)?-1ll:1ll;
    ans+=(ll)(Time*del*C[flag][k]);
  }
  printf("%lld",ans);
  return 0;
}
