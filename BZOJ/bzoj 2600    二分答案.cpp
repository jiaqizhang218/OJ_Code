#include<iostream>
#include<cstdio>
using namespace std;
long long f[100010],now,k,ans,a[100010],sum,n,l,b,lef,righ,mid;
bool check(long long x)
{
  int i,l,r,mi;
  for (i=1;i<=n-x+1;++i)
  {
      l=i; r=i+x-1; mi=(l+r)/2;
      now=a[mi];//���ײ����꣩
      sum=now*(mi-l)-(f[mi-1]-f[l-1])+(f[r]-f[mi])-now*(r-mi);
//��ʽ�ӵľ����Ʒ��Ѿ�д�������ˣ�
      if (sum<=b) return true;
  }
  return false;
}
int main()
{
  cin>>n>>l>>b;
 for (int i=1;i<=n;++i) cin>>a[i];
 f[0]=0;
 for (int i=1;i<=n;++i) f[i]=f[i-1]+a[i];//��ǰi�����������֮�ͣ�
 lef=0;
 righ=n+1;
 ans=0;
 while (lef<=righ) //��ö���м��鵾�����ո
 {
     mid=(lef+righ)/2;
     if (check(mid)==true) 
     {
      lef=mid+1;
      if (ans<mid) ans=mid;
     }
        else righ=mid-1;
  } 
  cout<<ans<<endl;
  return 0;
}
