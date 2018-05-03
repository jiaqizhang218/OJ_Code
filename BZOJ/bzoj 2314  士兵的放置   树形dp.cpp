#include<bits/stdc++.h>
#define rep(i,j,k) for((i)=(j);(i)<=(k);++i)
#define per(i,j,k) for((i)=(j);(i)>=(k);--i)
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
const int N = 500000 + 50;
#define mod 1032992941
int to[N<<1],nxt[N<<1],fir[N];
LL g[N][3],f[N][3];
int n,cnt;
inline void AE(int u,int v)
{
	to[++cnt]=v;nxt[cnt]=fir[u];fir[u]=cnt;
	to[++cnt]=u;nxt[cnt]=fir[v];fir[v]=cnt;
}
//0 ¸¸Ç×  1 ¶ù×Ó  2 ×Ô¼º 
inline void dfs(int x,int fa)
{
	int i;
	f[x][2]=1,f[x][1]=N,g[x][0]=g[x][1]=g[x][2]=1;
	for(i=fir[x];i;i=nxt[i])
	{
		if(to[i]==fa)	continue;
		dfs(to[i],x);
		LL t=0,tmp=min(min(f[to[i]][0],f[to[i]][1]),f[to[i]][2]);
		if(f[to[i]][0]==tmp)    t=(t+g[to[i]][0])%mod;
        if(f[to[i]][1]==tmp)    t=(t+g[to[i]][1])%mod;
        if(f[to[i]][2]==tmp)    t=(t+g[to[i]][2])%mod;
        f[x][2]+=tmp;
        g[x][2]=(g[x][2]*t)%mod;
        tmp=min(f[x][1]+min(f[to[i]][1],f[to[i]][2]),f[x][0]+f[to[i]][2]);
        t=0;
        if(f[x][1]+f[to[i]][1]==tmp)    t=(t+g[to[i]][1])%mod;
        if(f[x][1]+f[to[i]][2]==tmp)    t=(t+g[to[i]][2])%mod;
        f[x][1]=tmp;
        g[x][1]=(g[x][1]*t)%mod;
        if(f[x][0]+f[to[i]][2]==tmp)    g[x][1]=(g[x][1]+g[x][0]*g[to[i]][2])%mod;
 
        f[x][0]+=f[to[i]][1];
        g[x][0]=(g[x][0]*g[to[i]][1])%mod;
	}
}
int main()
{
	int i,a,b;
	for(n=read(),i=1;i<n;i++)
	{
		a=read(),b=read();AE(a,b);
	}
	dfs(1,0);
	if(f[1][1]<f[1][2])  printf("%lld\n%lld",f[1][1],g[1][1]);
    if(f[1][1]>f[1][2])  printf("%lld\n%lld",f[1][2],g[1][2]);
    if(f[1][1]==f[1][2])    printf("%lld\n%lld",f[1][1],(g[1][1]+g[1][2])%mod);
    return 0;
}
