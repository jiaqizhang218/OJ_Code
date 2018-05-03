#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int _L = 1e5+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define getchar() gc()
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x*=10;x+=ch-'0';ch=getchar();}
    return x*f;
}
int n,m,tot,cnt;
int d[155],num[155],pri[155];
ll s[25],ans=1;
bool jud(int x){for(int i=2;i<=sqrt(x);i++)if(x%i==0)return 0;return 1;}
void getpri(){for(int i=2;i<=150;i++)if(jud(i))pri[++cnt]=i;}
void solve(ll x,int f)
{
     for(int i=1;i<=cnt;i++)
     {
         if(x<=1)return;
         while(x%pri[i]==0)
         {num[i]+=f;x/=pri[i];}
     }
}
int main()
{
     s[1]=1;
     for(int i=2;i<=22;i++)s[i]=s[i-1]*i;
     getpri();n=read();
     if(n==1)
     {
         int x=read();
         if(!x)	printf("1");
         else printf("0");
         return 0;
     }
     for(int i=1;i<=n;i++)
     {
         d[i]=read();
         if(!d[i])	{puts("0");return 0;}
         d[i]--;	tot+=d[i];
     }
     if(tot!=n-2){printf("0");return 0;}
     solve(s[n-2],1);
     for(int i=1;i<=n;i++)
         solve(s[d[i]],-1);
     for(int i=1;i<=cnt;i++)while(num[i]--)ans*=pri[i];
     printf("%lld",ans);
     return 0;
}
