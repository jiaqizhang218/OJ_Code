#include<bits/stdc++.h>
typedef long long LL;
const int MAXN = 303;
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int n,m,k;
bool vis[MAXN][MAXN][2][2][2][2];
LL f[MAXN][MAXN][2][2][2][2];
inline LL DFS(int N,int M,int l,int r,int u,int d)
{
	if(N>M)	swap(N,M),swap(u,l),swap(d,r);
	if(u && !d)	swap(u,d);	if(l && !r)	swap(l,r);
	if(vis[N][M][l][r][u][d])	return f[N][M][l][r][u][d];
	f[N][M][l][r][u][d] = 1LL * (N * M - k) * (N * M - k);
	if(u || d || (l && r))	
		for(int i=1;i<M;i++)
			f[N][M][l][r][u][d] = min(f[N][M][l][r][u][d],DFS(N,i,l,0,u,d)+DFS(N,M-i,0,r,u,d));
	if(l || r || (u && d))
		for(int i=1;i<N;i++)
			f[N][M][l][r][u][d] = min(f[N][M][l][r][u][d],DFS(i,M,l,r,u,0)+DFS(N-i,M,l,r,0,d));
	vis[N][M][l][r][u][d]=1;
	return f[N][M][l][r][u][d];
}
int main()
{
	cin>>n>>m>>k;
	cout<<DFS(n,m,1,1,1,1)<<endl;	
}
