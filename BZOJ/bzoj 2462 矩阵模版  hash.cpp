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
const int maxn = 1010;

const unsigned int BASE1 = 121;
const unsigned int BASE2 = 131;
const int mod = 99999997;
int n, m, a, b, q;
unsigned int hash1[maxn][maxn], hash2[maxn][maxn];
unsigned int bas1[maxn], bas2[maxn];
bool v[100000000];
unsigned int gethash()
{
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			hash2[i][j]+=hash2[i-1][j]*BASE1;
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			hash2[i][j]+=hash2[i][j-1]*BASE2;
	return hash2[a][b];
}
inline void work()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%1d", &hash1[i][j]);
	bas1[0]=bas2[0]=1;
	for(int i=1;i<=100;i++)	bas1[i]=bas1[i-1]*BASE1,bas2[i]=bas2[i-1]*BASE2;
	for(int i=1;i<=n;i++)	for(int j=1;j<=m;j++)	hash1[i][j]+=hash1[i-1][j]*BASE1;
	for(int i=1;i<=n;i++)	for(int j=1;j<=m;j++)	hash1[i][j]+=hash1[i][j-1]*BASE2;
	for(int i=a;i<=n;i++)	for(int j=b;j<=m;j++)	
	{
		unsigned int h=hash1[i][j];
		h-=hash1[i-a][j]*bas1[a];
		h-=hash1[i][j-b]*bas2[b];
		h+=hash1[i-a][j-b]*bas1[a]*bas2[b];
		v[h%mod]=1;
	}
	scanf("%d",&q);
	while(q--)
	{
		for(int i=1;i<=a;i++)
			for(int j=1;j<=b;j++)
				scanf("%1d", &hash2[i][j]);
		unsigned x = gethash()%mod;
		if(v[x])	puts("1");
		else puts("0");
	}
}

int main()
{
	work();
	return 0;
}

