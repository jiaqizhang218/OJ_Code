#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int dx[] = {1, 1, -1, -1}, dy[] = {1, -1, 1, -1};
int n, m, a[752][752], l[752][752], ix[4], iy[4], fx[4], fy[4];
ll s[4][752][752], ts[752][752], ans, mts;

void calc(int d){
	for(int i = ix[d]; i != fx[d]; i += dx[d]){
		int cs = 0;
		stack<int> st;
		st.push(iy[d] - dy[d]);
		for(int j = iy[d]; j != fy[d]; j += dy[d]){
			l[i][j] = a[i][j] * (l[i - dx[d]][j] + 1);
			while(!st.empty()){
				if(l[i][st.top()] < l[i][j]) break;
				int tx = st.top(), tv = l[i][st.top()];
				st.pop();
				if(!st.empty()) cs -= abs(tx - st.top()) * tv;
			}
			if(!st.empty()) cs += abs(j - st.top()) * l[i][j];
			st.push(j);
			s[d][i][j] = cs;
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	ix[0] = ix[1] = 1;		ix[2] = ix[3] = n;
	fx[0] = fx[1] = n + 1;	fx[2] = fx[3] = 0;
	iy[0] = iy[2] = 1;		iy[1] = iy[3] = m;
	fy[0] = fy[2] = m + 1;	fy[1] = fy[3] = 0;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) scanf("%1d", a[i] + j);
	for(int i = 0; i < 4; i++) calc(i);
	for(int i = n; i >= 1; i--){
		for(int j = m; j >= 1; j--){
			ans += s[0][i][j];
			ts[i][j] = ts[i + 1][j] + ts[i][j + 1] - ts[i + 1][j + 1] + s[0][i][j] - s[1][i][j + 1] - s[2][i + 1][j] + s[3][i + 1][j + 1];
			mts = max(mts, ts[i][j]);
		}
	}
	printf("%lld\n", ans - mts);
}
