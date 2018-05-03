#include<bits/stdc++.h>
#define ll long long
#define N 10000005
using namespace std;
int n,p,tot;
int phi[N],pri[1000005];
bool mark[N];
ll ans,sum[N];
void getphi()
{
	phi[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!mark[i]){phi[i]=i-1;pri[++tot]=i;}
		for(int j=1;j<=tot && i * pri[j] <= n;j++)
		{
			mark[i*pri[j]]=1;
			if(i%pri[j]==0) {phi[i*pri[j]]=phi[i]*pri[j];break;}
			else phi[i*pri[j]]=phi[i]*phi[pri[j]];
		}
	}
}
int main()
{
	scanf("%d",&n);
	getphi();
	for(int i=1;i<=n;i++)
	    sum[i]=sum[i-1]+phi[i];
	for(int i=1;i<=tot;i++)
	    ans+=sum[n/pri[i]]*2-1;
	printf("%lld",ans);
	return 0;
}
