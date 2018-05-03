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
const int mod = 1000000007;
const int N = 100010;
#define eps 1e-8
int fa[20][N];
inline int find(int j,int i) {
	return fa[j][i] == i ? i : fa[j][i] = find(j,fa[j][i]);
}
inline void merge(int j,int x,int y) {
	int f1=find(j,x),f2=find(j,y);
	if(f1==f2) 	return;
	fa[j][f2]=f1;
	if(!j)	return;
	merge(j-1,x,y);
	merge(j-1,x+(1<<(j-1)),y+(1<<(j-1)));
}
int main()
{
	int n=read(),m=read();
	if(n==1)	{
		cout<<10<<endl;
		return 0;
	}
	for(int j=0;j<18;j++)
		for(int i=1;i<n;i++)
			fa[j][i]=i;
	for(int i=1;i<=m;i++) {
		int l1=read(),r1=read(),l2=read(),r2=read();
		if(l1>l2) {
			swap(l1,l2);swap(r1,r2);
		}
		int j=log2(r1-l1+1+eps);
		merge(j,l1,l2); merge(j,r1-(1<<j)+1,r2-(1<<j)+1);
	}
	int ans=0;
	for(int i=1;i<=n;i++) {
		if(find(0,i)==i)	ans++;
	}
	LL ret=9;
	for(int i=2;i<=ans;i++) {
		ret=ret*10%mod;
	}
	printf("%lld\n",ret);
	return 0;
}

