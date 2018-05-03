#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=200010;
int n,m,tag,pre,ans;
int p[maxn],v[maxn],sm[maxn],sn[maxn];
inline int rd()
{
    int ret=0,f=1;  char gc=getchar();
    while(gc<'0'||gc>'9') {if(gc=='-')f=-f;   gc=getchar();}
    while(gc>='0'&&gc<='9')   ret=ret*10+gc-'0',gc=getchar();
    return ret*f;
}
bool cmp(int a,int b)
{
    return (v[a]==v[b])?(a<b):(v[a]<v[b]);
}
int main()
{
    n=rd();
    int i;
    for(i=1;i<=n;i++)    v[i]=rd(),p[i]=i;
    sort(p+1,p+n+1,cmp);
    for(v[0]=-1,i=1;i<=n;i++)
    {
        if(v[p[i]]!=v[p[i-1]])  m++,sm[m]=sn[m]=p[i];
        sm[m]=max(sm[m],p[i]),sn[m]=min(sn[m],p[i]);
    }
    for(i=1;i<=m;i++)
    {
        if(i==1||(tag&&sn[i]<pre))   ans++,tag=0,pre=sn[i];
        else    if(!tag&&sm[i]>pre)  tag=1,pre=sm[i];
        else    if(!tag&&sm[i]<pre)  pre=sn[i];
        else    if(tag&&sn[i]>pre)   pre=sm[i];
    }
    printf("%d",ans);
    return 0;
}
