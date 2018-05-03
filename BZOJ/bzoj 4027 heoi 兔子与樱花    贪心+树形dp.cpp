#include<bits/stdc++.h>
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,ans;
int c[2000005];
vector<int> e[2000005];
bool cmp(int a,int b)
{
	return c[a]<c[b];
}
void dfs(int x)
{
	for(int i=0;i<e[x].size();i++)
		dfs(e[x][i]);
	sort(e[x].begin(),e[x].end(),cmp);
	c[x]+=e[x].size();
	for(int i=0;i<e[x].size();i++)
	{
		int t=c[e[x][i]];
		if(c[x]+t-1<=m)
		{
			c[x]+=t-1;
			ans++;
		}
		else break;
	}		
}
int main()
{
	n=read();m=read();
	for(int i=0;i<n;i++)c[i]=read();
	int x,y;
	for(int i=0;i<n;i++)
	{
		x=read();
	    while(x--)
		{
			y=read();
			e[i].push_back(y);
		}
	}
	dfs(0);
	printf("%d\n",ans);
	return 0;
}
