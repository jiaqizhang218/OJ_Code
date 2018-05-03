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
const int MAXN = 1000010;
int n,fa[MAXN],ans,loc;
bool visit[MAXN];
inline int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
inline void merge(int x,int y)
{
	int f1=find(x),f2=find(y);
	if(f1!=f2)	fa[f1]=f2;
}
int main()
{
	n = read();
	for(int i=1;i<=n;i++)	fa[i]=i; 
	for(int i=1;i<=n;i++)	loc=read(),merge(loc,i);
	for (int i=1; i<=n; i++)
        if (!visit[find(i)])
            ans++,visit[find(i)]=1;
    printf("%d\n",ans);
    return 0;
}

