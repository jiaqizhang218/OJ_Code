#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int maxn = 200000 + 20;
int n,m,bo[maxn]; 
int main()
{
	n=read(),m=read();
	while(m--)
	{
		int x=read(),y=read();
		bo[x]=bo[y]=1;
	}
	for(int i=1;i<=n;i++)
		if(!bo[i])	{
			puts("NIE");	return 0;
		}
	puts("TAK");
	return 0;
}
