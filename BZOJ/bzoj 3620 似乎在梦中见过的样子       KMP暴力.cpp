#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int MAXN = 20010;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int next[MAXN],n,k,ans;
char s[MAXN];
inline void KMP(int p)
{
	for(int i = 1 ; i <= n ; i++)	next[i] = p - 1;
	for(int i = p + 1 ; i <= n ; i++)
	{
		int j = next[i-1];
		while(j != p-1 && s[j+1] != s[i])	j = next[j];
		if(s[j+1] == s[i])	j++;
		next[i] = j; 
	}
	int j = next[p];
	for(int i = p + 1; i <= n ; i++)
	{
		while(j != p-1 && s[j+1] != s[i])	j=next[j];
		if(s[j+1] == s[i])	j++;
		while((j-p+1)*2>=(i-p+1))	j=next[j];
		if(j-p+1>=k)	ans++;
	}
}
int main()
{
		scanf("%s",s+1);
		scanf("%d",&k);
		n = strlen(s+1);
		for(int i = 1 ; i <= n ; i++)
			KMP(i);
		printf("%d\n",ans);
		return 0;
}
