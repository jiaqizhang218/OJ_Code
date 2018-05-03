#include<bits/stdc++.h>
#define rep(i,j,k) for((i)=(j);(i)<=(k);++i)
#define per(i,j,k) for((i)=(j);(i)>=(k);--i)
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
#define  getchar() nc()
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
#define N 301000
int n,m;
int a[N],b[N];
int sta[N],top;
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    for(int i=1;i<=m;i++)
        b[i]=read();
    for(int i=2;i<=n;i++)
        if(a[i]>a[i-1])a[i]=a[i-1];
    int l,r,la=n+1;
    for(int i=1;i<=m;i++)
    {
        l=1,r=la-1;
        int ans=r;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(a[mid]<b[i])ans=mid,r=mid-1;
            else l=mid+1;
        }
        la=ans;
        if(a[ans]<b[i])la--;
    }
    printf("%d\n",la);
}
