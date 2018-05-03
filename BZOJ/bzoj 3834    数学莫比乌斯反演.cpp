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
inline void work() {
	int a=read()-1,b=read(),c=read()-1,d=read();
	int i,j,x,y,ans;
	int aa,bb,cc,dd;
	if(d>b)	swap(b,d),swap(a,c);
	for(i=1;i<=d;i=j+1) {
		j=min(b/(b/i),d/(d/i));
		if(i<=a)	j=min(j,a/(a/i));
		if(i<=c)	j=min(j,c/(c/i));
		if(b/i>a&&d/i>c/i) ans=j;
	}
	printf("%d\n",ans);
}
int main()
{
	int T=read();
	while(T--) work();
	return 0;
}

