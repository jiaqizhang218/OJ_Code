#include<bits/stdc++.h>
#define debug(x) cerr<<#x" = "<<x<<endl
typedef long long LL;
const int INF = 0x3f3f3f3f;
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
const int N = 2e4 + 5;
int T,n,k,l,a[N],f[N],c[N],pos[N],cnt,g[1<<22];
deque<int> q;
int main()
{
#ifdef iloi
	freopen("test.txt","r",stdin);
#endif
	for(T=read();T;T--)
	{
		n=read(),k=read(),l=read();
		for(int i=1;i<=k;i++)a[i]=read();
		cnt=0;
		sort(a+1,a+k+1);
		k=unique(a+1,a+k+1)-(a+1);
		a[k+1]=n+2;
		a[0]=-1;
		for(int i=1;i<=k;i++)	if(a[i]!=a[i-1]+1) pos[cnt++]=a[i];
		for(int i=1;i<=k;i++)	if(a[i]!=a[i+1]-1) pos[cnt++]=a[i]+1;
		sort(pos,pos+cnt);
		for(int i=1;i<=n;i++) f[i]=INF;
		for(int i=1;i<=l;i++) c[i]=read();
		for(int i=1;i<=l;i++) {
			f[c[i]]=min(f[c[i]],1);
			q.push_back(c[i]);
		}
		while(!q.empty()) {
			int o=q.front(); q.pop_front();
			for(int i=1;i<=l;i++) {
				if(o+c[i]<=n&&f[o+c[i]]==INF) {
					f[o+c[i]]=f[o]+1;
					q.push_back(o+c[i]);
				}
				if(o-c[i]>=1&&f[o-c[i]]==INF) {
					f[o-c[i]]=f[o]+1;
					q.push_back(o-c[i]);
				}
			}
		}
		for(int S=1;S<=(1<<(cnt))-1;S++) {
			int o=0;
			g[S]=INF;
			for(int i=0;i<=cnt-1;i++)
				if(S&(1<<i)) 
					{o=i;break;}
			for(int i=o+1;i<=cnt-1;i++)
				if(S&(1<<i))
					g[S]=min(g[S],g[S^(1<<i)^(1<<o)]+f[pos[i]-pos[o]]);
					
		}
		printf("%d\n",g[(1<<cnt)-1]==INF?-1:g[(1<<cnt)-1]);
	}
}
