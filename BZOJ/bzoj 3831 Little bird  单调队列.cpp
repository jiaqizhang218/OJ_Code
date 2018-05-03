#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int MAXN = 1100000;
int n,m,H[MAXN],f[MAXN],q[MAXN]; 
int main()
{
	n=read();
	for(int i=1;i<=n;i++) 
		H[i]=read();
	m=read();
	while(m--){
		int K=read();
		int h=0,t=0;
		for(int i=0;i<=n;i++)	f[i]=0;
		q[t++]=1;
		for(int i=2;i<=n;i++) {
			while(h<t&&q[h]+K<i) h++;
			f[i]=f[q[h]]+(H[q[h]]<=H[i]?1:0);
			while(h<t&&(f[q[t-1]]>f[i]||(f[q[t-1]]==f[i]&&H[q[t-1]]<=H[i]))) t--;
			q[t++]=i;
		}
		printf("%d\n",f[n]);
	}
}
