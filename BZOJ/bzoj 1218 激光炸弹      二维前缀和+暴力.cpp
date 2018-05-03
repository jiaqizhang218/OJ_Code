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
const int MAXN = 5010;
int mp[MAXN][MAXN],m,n,ans,r;
int main()
{
	n = read() , r = read();
	for(int i = 1 ; i <= n ; i++) {
		int x =read() , y = read();
		mp[x][y] += read();
	}
	for(int i = 0 ; i <= 5000 ; i++) {
		for(int j = 0 ; j <= 5000 ; j++) {
			mp[i][j] += mp[i-1][j];
		}
	}
	for(int i = 0 ; i <= 5000 ; i++) {
		for(int j = 0 ; j <= 5000 ; j++) {
			mp[i][j] += mp[i][j-1];
		}
	}
	for(int i = r ; i <= 5000 ; i++) {
		for(int j = r ; j <= 5000 ; j++) {
			int tmp = mp[i][j] - mp[i-r][j] - mp[i][j-r] + mp[i-r][j-r];
			ans = ans > tmp ? ans : tmp;
		}
	}
	cout<<ans;
}

