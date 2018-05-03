#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define pa pair<int,int>
#define inf 1000000000
#define eps 1e-8
#define ll long long
using namespace std;
ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
priority_queue<int,vector<int>,greater<int> >q;
int n,K,ans;
ll m,sum;
struct data{
	int p,c;
}a[50005];
bool cmpc(data a,data b)
{
	return a.c<b.c;
}
bool cmpp(data a,data b)
{
	return a.p<b.p;
}
int main()
{
	n=read();K=read();m=read();
	for(int i=1;i<=n;i++)
		a[i].p=read(),a[i].c=read();
	sort(a+1,a+n+1,cmpc);
	for(int i=1;i<=K;i++)
	{
		sum+=a[i].c;
		q.push(a[i].p-a[i].c);
		if(sum>m){printf("%d\n",i-1);return 0;}
		if(i==n){printf("%d\n",n);return 0;}
	}
	sort(a+K+1,a+n+1,cmpp);
	ans=K;
	for(int i=K+1;i<=n;i++)
	{
		int t=inf;
		if(!q.empty())t=q.top();
		if(t<a[i].p-a[i].c)
		{
			sum+=t;q.pop();
			q.push(a[i].p-a[i].c);
			sum+=a[i].c;
		}
		else sum+=a[i].p;
		if(sum>m)break;
		else ans++;
	}
	printf("%d\n",ans);
	return 0;
}
