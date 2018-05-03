#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const double eps = 1e-5;
const int N = 1000005;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
int n,ans,fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main()
{
    n=read();	
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=n;i++)
	{
		int x=read();
		int p=find(i),q=find(x);
		if(p!=q)fa[q]=i;
    }
	for(int i=1;i<=n;i++)
	    if(fa[i]==i)ans++;
	printf("%d",ans);
	return 0;
}	


