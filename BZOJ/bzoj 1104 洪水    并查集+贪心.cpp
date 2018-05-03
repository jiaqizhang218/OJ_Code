#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000 + 5; 
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int n,m,h[MAXN][MAXN],fa[MAXN*MAXN],cnt,ans,mv[4][2]={1,0,-1,0,0,1,0,-1},have[MAXN*MAXN];
struct M{
	int x,y,hei;
	bool operator <(const M &b) const
	{
		return hei < b.hei;
	}
}s[MAXN*MAXN],l[MAXN*MAXN];
inline int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main()
{
	n = read() , m = read();
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
		{
			h[i][j] = read();
			if(h[i][j] > 0)
				s[++cnt].x=i,s[cnt].y=j,s[cnt].hei=h[i][j];
			else 
				h[i][j] = -h[i][j];
			l[(i-1)*m+j].x = i , l[(i-1)*m+j].y = j , l[(i-1)*m+j].hei = h[i][j];
		}
	for(int i = 1; i <= n * m ; i++)
		fa[i] = i;
	for(int i = 1 ; i <= n + 1; ++i)
		h[i][0] = h[i][m+1] = INF;
	for(int i = 0 ; i <= m + 1; ++i)
		h[0][i] = h[n+1][i] = INF;
	sort(l+1,l+n*m+1);
	sort(s+1,s+cnt+1);
	for(int i=1,k=1;i<=cnt;i++){
        for(;k<=m*n&&l[k].hei<=s[i].hei;k++){
            int x=l[k].x,y=l[k].y;
            for(int j=0;j<=3;j++){
                int xx=x+mv[j][0],yy=y+mv[j][1];
                if(h[xx][yy]<=h[x][y])
                    have[find((x-1)*m+y)]|=have[find((xx-1)*m+yy)],fa[find((xx-1)*m+yy)]=find((x-1)*m+y);
            }
        }
        if(!have[find((s[i].x-1)*m+s[i].y)])
            ans++,have[find((s[i].x-1)*m+s[i].y)]=1;
    }
	cout<<ans;
	return 0;
}
