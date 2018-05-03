#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<queue>
#include<cmath>
#include<algorithm>
#define inf 1000000000
#define ll long long
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,head=1,tail,ans;
int l[1000005],r[1000005],q[1000005];
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
        l[i]=read(),r[i]=read();
    for(int i=1;i<=n;i++)
    {
        while(l[q[head]]>r[i]&&head<=tail)head++;
        if(head<=tail)
            ans=max(ans,i-q[head]+1);
        int t=i;while(l[i]>l[q[tail]]&&head<=tail)t=q[tail],tail--;
        l[t]=l[i];q[++tail]=t;
    }
    printf("%d\n",ans);
    return 0;
}
