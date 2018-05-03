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
const int maxn = 3000100;
int a[maxn],q1[maxn],q2[maxn];
int n,m,k,ans;
int main()
{
	k=read(),n=read();
	int l1=1,r1=0,l2=1,r2=0,t=1;
	for(int i=1;i<=n;i++)	a[i]=read();
	for(int i=1;i<=n;i++)
	{
		while(l1<=r1&&a[i]>=a[q1[r1]]) r1--;
		while(l2<=r2&&a[i]<=a[q2[r2]]) r2--;
		q1[++r1]=i; q2[++r2]=i;
		while(a[q1[l1]]-a[q2[l2]]>k)
			if(q1[l1]<q2[l2])	t=q1[r1]+1,l1++;
			else t=q2[l2]+1,l2++;
		ans=max(ans,i-t+1);
	}
	cout<<ans;
	return 0;
}
