#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
int n,ans;
int f[2][4][4][4][4];
char str[100010];
inline int calc(int x,int a,int b)
{
	if(!a)	return 1;
	if(!b)	return 1+(x!=a);
	return (1+(x!=a||x!=b)+(x!=a&&x!=b&&a!=b));
 } 
int main()
{
	scanf("%d%s",&n,str+1);
	memset(f,0x80,sizeof f);
	f[0][0][0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		int j=i&1,x;
		memset(f[j],0x80,sizeof f[j]);
		if(str[i]=='M')	x=1;
		if(str[i]=='F') x=2;
		if(str[i]=='B') x=3;
		for(int a=0;a<=3;a++)	for(int b=0;b<=3;b++)	for(int c=0;c<=3;c++)	for(int d=0;d<=3;d++)
		{
			f[j][x][a][c][d]=max(f[j][x][a][c][d],f[j^1][a][b][c][d]+calc(x,a,b));
			f[j][a][b][x][c]=max(f[j][a][b][x][c],f[j^1][a][b][c][d]+calc(x,c,d));
		}
	}
	for(int a=0;a<=3;++a) for(int b=0;b<=3;b++) for(int c=0;c<=3;c++) for(int d=0;d<=3;d++)
		ans=max(ans,f[n&1][a][b][c][d]);
	cout<<ans;
	return 0;
}
