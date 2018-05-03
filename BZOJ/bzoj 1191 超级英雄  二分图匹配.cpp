#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
int mp[1001][1001],lk[1001],n,m,ans;
bool vis[1001];
bool find(int x)
{
	for(int i=0;i<n;i++)
	{
	   if(!vis[i]&&mp[x][i])
	   {
	   	   vis[i]=1;
	   	   if(!lk[i]||find(lk[i]))
	   	   {
	   	   	  lk[i]=x;
	   	   	  return true;
	   	   }
	   }
    }
    return false;
}
int main()
{
	n = read() , m = read();
	for(int i=1;i<=m;i++)
	{
	   int x = read() , y = read();
	   mp[i][x]=mp[i][y]=1;
}
    for(int i=1;i<=m;i++)
    {
    	memset(vis,0,sizeof vis);
    	if(find(i))ans++;
    	else break;
    }
   	printf("%d\n",ans);
	return 0;
}


