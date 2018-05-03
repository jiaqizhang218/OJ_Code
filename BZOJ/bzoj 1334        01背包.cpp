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
const int MAXN = 100010;
bool f[MAXN];
int n,s,a[MAXN];
int main()
{
	n=read();
	for(int i=1;i<=n;i++) {
		a[i]=read();
		s+=a[i];
	}
	sort(a+1,a+1+n);
	f[0]=1;
	for(int i=n;i;i--) {
		for(int j=min(s,s/2+a[i]);j>=a[i];j--) {
			f[j] |= f[j-a[i]];
		}
	}
	for(int i=s;i>(s>>1);i--) {
		if(f[i]) {
			printf("%d\n",i);
			return 0;
		}
	}
}
