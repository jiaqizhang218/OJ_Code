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
int nedge=0,p[400001],nex[400001],head[400001],n,m;
bool b[200001];
int sum=0;
inline void addedge(int a,int b){
    p[++nedge]=b;nex[nedge]=head[a];head[a]=nedge;
}
void dfs(int x)
{
	for(int k = head[x]; k; k = nex[k])
	{
		++sum;
		if(!b[p[k]])	b[p[k]]=true,dfs(p[k]);
	}
} 
int main()
{
	n = read() , m = read();
	for(int i = 1 ; i <= n ; i++)
	{
		int x = read() , y = read();
		addedge(x,y),addedge(y,x);	//把第i个球能投进的两个框连起来 
	}
	int ans = 0;
	for(int i = 1 ; i <= m ; i++)
		if(!b[i])
		{
			b[i]=true;	sum=0; dfs(i);
			sum>>=1;
			if(sum&1) ans++;
		}
	printf("%d",ans); 	
}

