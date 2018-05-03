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
#define  getchar() nc()
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int N = 1500001;
int n,m,x[N],y[N],k[N],ans[N],mn[11][N<<1],Log[N<<1],s[N<<1];
inline void premn()
{
	Log[0]=-1;
    for(int i=1;i<=n;i++)Log[i]=Log[i/2]+1;
    for(int i=1;(1<<i)<=n && i<=10;i++)
        for(int j=1;j+(1<<i)-1<=n && j<=n;j++)
            mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
}
int maxnum;
inline void premx()
{
    for(int i=1;i<=n;i++)mn[0][i]=s[i];
    for(int i=1;(1<<i)<=maxnum && i<=10;i++)
        for(int j=1;j+(1<<i)-1<=maxnum && j<=maxnum;j++)
            mn[i][j]=max(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)	mn[0][i]=s[i]=read();
	premn();int tmp=0;maxnum=0;
	for(int i=1;i<=m;i++)
	{
		int op=read(),xx=read(),yy=read();
		if(op==1)
		{
			int kk=Log[yy-xx+1];
			ans[i]=min(mn[kk][xx],mn[kk][yy-(1<<kk)+1]);
		}
		else 
		{
			tmp++;
			x[tmp]=xx;y[tmp]=yy;k[tmp]=i;
			maxnum=max(maxnum,yy);
		}
	}
	premx();
	for(int i=1;i<=tmp;i++)
	{
		int kk=Log[y[i]-x[i]+1];
		ans[k[i]]=max(mn[kk][x[i]],mn[kk][y[i]-(1<<kk)+1]);
	}
	for(int i=1;i<=m;i++)	printf("%d\n",ans[i]);
	return 0;
}
