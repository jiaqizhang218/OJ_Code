#include<bits/stdc++.h>
typedef long long LL;
const int N = 300300;
const int INF = 0x7fffffff;
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
//#define  getchar() nc()
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int n,i,l,r,a[N],b[N],ans[N];LL sum;
int main()
{
	for(n=read(),i=1;i<=n;i++)	a[i]=read();
	for(i=1;i<=n;i++)	b[i]=read();
	for(sort(b+1,b+n+1),l=1,i=2,r=n;i<n;i++)
	{
		if(a[i]>a[i-1]&&a[i]>a[i+1])	ans[i]=b[r--];
		if(a[i]<a[i-1]&&a[i]<a[i+1])	ans[i]=b[l++];
	}
	ans[1]=a[1]<a[2]?b[l++]:b[r--]; ans[n]=a[n]<a[n-1]?b[l++]:b[r--];
	for(i=2;i<n;i++)
	{
		if(a[i]>a[i-1]&&a[i]<a[i+1])	ans[i]=b[l++];
		if(a[i]<a[i-1]&&a[i]>a[i+1])	ans[i]=b[r--];
	}
	for(i=1;i<n;i++)	sum+=abs(ans[i]-ans[i+1]);
	for(cout<<sum<<endl,i=1;i<=n;i++)	printf("%d ",ans[i]);
	return 0;
}
