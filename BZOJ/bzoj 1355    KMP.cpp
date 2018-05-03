#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int maxn = 1000005; 
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int n,f[maxn];
char s[maxn];
int main()
{
	scanf("%d%s",&n,s+1);
	int j=0;
	for(int i=2;i<=n;i++) {
		while(s[j+1]!=s[i]&&j)	j=f[j];
		if(s[j+1]==s[i])	j++;
		f[i]=j;
	}
	printf("%d\n",n-f[n]);
	return 0;
}
