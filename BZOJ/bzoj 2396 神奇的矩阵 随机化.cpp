#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 1000 + 5;
const int INF = 0x7fffffff;
int n,m;
int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];
int rnd[maxn],ans1[maxn],ans2[maxn];
bool jud()
{
	for(int i = 1 ; i <= n ; i++)
		if(ans1[i]!=ans2[i]) return false;
	return true;
}
void mix(int a[maxn],int b[maxn][maxn],int s[maxn])
{
	int tmp[maxn];
	for(int j=1;j<=n;j++)
    {
    	tmp[j]=0;
    	for(int k=1;k<=n;k++)
    	   tmp[j]+=a[k]*b[k][j];
    }
    for(int i=1;i<=n;i++)	s[i]=tmp[i];
}
int main()
{	
	for(int i = 1 ;i <= 1000 ; i++) rnd[i]=rand();
	while(scanf("%d",&n)!=EOF)
	{	
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= n ; j++)
				scanf("%d",&a[i][j]);
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= n ; j++)
				scanf("%d",&b[i][j]);
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= n ; j++)
				scanf("%d",&c[i][j]);
		mix(rnd,a,ans1);
		mix(ans1,b,ans1);
		mix(rnd,c,ans2);
		if(jud()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
 } 
