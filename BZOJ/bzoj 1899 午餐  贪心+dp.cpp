#include<bits/stdc++.h> 
using namespace std;
const int maxn=200,maxm=40000,MAXINT=((1<<30)-1)*2+1;

int n,f[maxn+5][maxm+5],sum[maxn+5],ans;
struct Student
{
    int a,b;
    bool operator < (const Student &a) const {return b>a.b;}
};
Student s[maxn+5];

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d%d",&s[i].a,&s[i].b);
    sort(s+1,s+1+n);
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+s[i].a;
    memset(f,63,sizeof(f));
    f[0][0]=0;
    for (int i=1;i<=n;i++)
    for (int j=0;j<=sum[i];j++)
    {
        f[i][j]=min(f[i][j],max(f[i-1][j],sum[i-1]-j+s[i].a+s[i].b));
        if (s[i].a<=j) f[i][j]=min(f[i][j],max(f[i-1][j-s[i].a],j+s[i].b));
    }
    ans=MAXINT;
    for (int j=0;j<=sum[n];j++) ans=min(ans,f[n][j]);
    printf("%d\n",ans);
    return 0;
}
