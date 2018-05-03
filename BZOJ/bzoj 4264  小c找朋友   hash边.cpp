#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int maxn=1000010;
int n,m;
ll v[maxn],s[maxn],p[maxn],ans,sum;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
#define  getchar() nc()
inline int rd()
{
    int ret=0,f=1;  char gc=getchar();
    while(gc<'0'||gc>'9') {if(gc=='-')f=-f;   gc=getchar();}
    while(gc>='0'&&gc<='9')   ret=ret*10+gc-'0',gc=getchar();
    return ret*f;
}
int main()
{ 
    srand(19260817);
    n=rd(),m=rd();
    int i,a,b;
    for(i=1;i<=n;i++)    v[i]=(ll)rand()*rand()*rand()*rand();
    for(i=1;i<=m;i++)
    {
        a=rd(),b=rd();
        s[a]^=v[b],s[b]^=v[a];
    }
    for(i=1;i<=n;i++)    p[i]=s[i];
    sort(p+1,p+n+1);
    for(sum=0,i=1;i<=n;i++)
    {
        if(p[i]!=p[i-1])    ans+=sum*(sum-1)/2,sum=0;
        sum++;
    }
    ans+=sum*(sum-1)/2;
    for(i=1;i<=n;i++)    p[i]=s[i]^v[i];
    sort(p+1,p+n+1);
    for(sum=0,i=1;i<=n;i++)
    {
        if(p[i]!=p[i-1])    ans+=sum*(sum-1)/2,sum=0;
        sum++;
    }
    ans+=sum*(sum-1)/2;
    printf("%lld",ans);
    return 0;
}
