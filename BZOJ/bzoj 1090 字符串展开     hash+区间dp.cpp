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
char S[110];
int f[110][110],N;
const int base = 13;
typedef  unsigned long long ULL;
ULL bin[110],hsh[110];
inline void hshtable()
{
	bin[0]=1;for(int i=1;i<=N;i++)	bin[i]=bin[i-1]*base;
	for(int i=1;i<=N;i++)	hsh[i]=hsh[i-1]*base+S[i];
}
inline ULL Gethsh(int l,int r)	{
	return hsh[r]-hsh[l-1]*bin[r-l+1];
}
inline int size(int x)
{
	int re=0;while(x)	x/=10,re++;	return re;
}
inline bool judge(int l,int m,int r)
{
	if((r-l+1)%m)	return false;
	int tl=(r-l+1)/m; ULL t=Gethsh(l,l+tl-1);
	for(int i=l;i<=r;i+=tl)
		if(Gethsh(i,i+tl-1)!=t)	return false;
	return true;
}
int main()
{
	scanf("%s",S+1);	N=strlen(S+1);
	hshtable();
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
		{
			if(j+i-1<=N)
			{
				int l=j,r=j+i-1;
				f[l][r]=r-l+1;
				for(int k=1;k<=i;k++)
				{
					f[l][r]=min(f[l][r],f[l][l+k-1]+f[l+k][r]);
					if(judge(l,k,r))	f[l][r]=min(f[l][r],2+size(k)+f[l][l+(r-l+1)/k-1]);
				}
			}
		}
	cout<<f[1][N];
	return 0;
}

