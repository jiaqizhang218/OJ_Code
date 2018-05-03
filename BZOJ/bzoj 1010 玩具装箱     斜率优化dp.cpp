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
int n,L,l,r;
int c[50005],q[50005];
LL s[50005],f[50005],C;
inline double slop(int j,int k)
{
	return (f[k]-f[j] + (s[k]+C) * (s[k]+C) - (s[j]+C) * (s[j]+C)) / (2.0 * (s[k] - s[j]));
}
inline void dp()
{
	l = 1 , r = 0 ; q[++r] = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		while(l < r && slop(q[l],q[l+1]) <= s[i]) ++l;
		int t = q[l];
		f[i] = f[t] + (s[i] - s[t] - C) * (s[i] - s[t] - C);
		while(l < r && slop(q[r],i) < slop(q[r-1],q[r])) --r;
		q[++r] = i;
	}
}
int main()
{
	n = read() , L = read(); C = L + 1;
	for(int i = 1 ; i <= n ; i++) c[i] = read(),s[i] = s[i-1] + c[i] + i;
	dp();
	printf("%lld\n",f[n]);
	return 0;
}
