#include<bits/stdc++.h>
typedef long long LL;
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
const int N = 300005;
int n,m,tp,w,i,ans;
struct data{
	int x,y;
}p[N],q[N]; 
bool cmp(data a,data b)
{
	return a.x<b.x||a.x==b.x&&a.y>b.y;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		p[i].x=read(),p[i].y=read();
	sort(p+1,p+1+n,cmp);
	for(int i=1;i<=n;i++)
		if(p[i].y<p[i].x) q[tp++]=data{p[i].x,p[i].y};
	for(int my=2e9,w=i=tp;i;i--)
	{
		my=min(q[i].y,my);
		if(my>q[i-1].x)	ans+=2ll*(q[w].x-my),my=2e9,w=i-1;
	}
	cout<<ans+m;
}
