#include<bits/stdc++.h> 
#define M 5505
#define N 505
using namespace std;
int t[N][M],n,k,a[10005];
int lowbit(int x)
{
    return x&(-x);
}
int Getmax(int x,int y)
{
    int ans=0;
    for (int i=x;i;i-=lowbit(i))
        for (int j=y;j;j-=lowbit(j))
            ans=max(ans,t[i][j]);
    return ans;
}
void Update(int x,int y,int k)
{
    for (int i=x;i<=N-3;i+=lowbit(i))
       for (int j=y;j<=M-3;j+=lowbit(j))
           t[i][j]=max(t[i][j],k);
}
int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    k++;
    int ans=1;
    for (int i=1;i<=n;i++)
        for (int j=k;j;j--)
        {
            int x=Getmax(j,a[i]+j)+1;
            ans=max(ans,x);
            Update(j,a[i]+j,x);
        }
    printf("%d\n",ans);
    return 0;
}
