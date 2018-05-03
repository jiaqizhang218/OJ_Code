#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#define pa pair<int,int>
#define inf 1000000000
#define ll long long 
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
int a[55],f[55];
int cal(int x,int y)
{
    for(int k=1;k<=y-x+1;k++)
    {
        for(int i=k;i<=y-x;i++)
			if(abs(a[i+x]-a[i+x-k])>1)return k-1;
        if(abs(a[x+k-1]-a[y-k+1])<=1)return k-1;
    }
    return y-x+1;
}
void dp()
{
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			f[i]=max(f[i],f[j]+cal(j+1,i));
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
		for(int i=1;i<=n;i++)a[i]=read();
		cal(1,n);
		sort(a+1,a+n+1);
		dp();
		printf("%d\n",f[n]);
    }
    return 0;
}
