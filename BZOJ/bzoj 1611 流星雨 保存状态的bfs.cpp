#include<bits/stdc++.h>
#define ll long long
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std;
int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x * f;
}
int n,mp[310][310];
bool mark[310][310];
int sx[4]={0,0,-1,1},sy[4]={1,-1,0,0};
struct data{
	int x,y,t;
}q[90001];
void bfs()
{
	int l = 0 , r = 1;
	mark[0][0] = true;
	if(mp[0][0] > 1000) 
	{
		printf("%d",0);return;
	}
	while(l < r)
	{
		int x = q[l].x , y = q[l].y , time = q[l++].t;
		for(int i = 0 ; i < 4 ; i++)
		{
			int nowx = x + sx[i], nowy = y + sy[i];
			if(mark[nowx][nowy]||nowx<0||nowy<0||time+1>=mp[nowx][nowy])	continue;
			if(mp[nowx][nowy] > 10000)
			{
				printf("%d",time+1);return;
			}
			q[r].x=nowx,q[r].y=nowy,q[r++].t=time+1;
			mark[nowx][nowy] = true;
		}
	}
	printf("-1");
}
int main()
{
	memset(mp,127,sizeof(mp));
	n = read();
	for(int i = 1 ; i <= n ; i++)
	{
		int x = read() , y = read() , t = read();
		mp[x][y] = min(mp[x][y],t); //选择将这块地摧毁的最早时间 下面同这里 
		for(int l = 0 ; l < 4 ; l++)
		{
			int nowx = sx[l]+x , nowy = sy[l]+y;
			if(nowx < 0 || nowy < 0) continue;
			mp[nowx][nowy] = min(mp[nowx][nowy],t);
		 } 
	}
	bfs();
	return 0;
}

