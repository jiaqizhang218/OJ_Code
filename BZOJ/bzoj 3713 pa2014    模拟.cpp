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
int seq[1000],cnt;
const int N = 1e9 + 7;
int main()
{
	seq[0]=0,seq[1]=1;
	for(cnt=2;seq[cnt-1]<N;cnt++) {
		seq[cnt]=seq[cnt-1]+seq[cnt-2];
	}
	int t = read();
	while(t--) {
		LL x;
		bool flag = false;
		scanf("%lld",&x);
		for(int i=1;i<=cnt;i++) {
			if(seq[i]<=x) {
				for(int j=i;j<=cnt;j++)	
					if(1LL * seq[i] * seq[j] == x) flag=true;
			}
		}
		printf(flag?"TAK":"NIE");
		putchar('\n');
	}
	return 0;
}
