#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 105

int n,m,r,c,cnt,ans,a[N][N];
char s[N];
int tot,point[N*N*2],nxt[N*N*10],v[N*N*10];
int belong[N*N*2],vis[N*N*2];

void add(int x,int y)
{
    ++tot; nxt[tot]=point[x]; point[x]=tot; v[tot]=y;
}
bool find(int x,int k)
{
    for (int i=point[x];i;i=nxt[i])
        if (vis[v[i]]!=k)
        {
            vis[v[i]]=k;
            if (!belong[v[i]]||find(belong[v[i]],k))
            {
                belong[v[i]]=x;
                return true;
            }
        }
    return false;
}
int main()
{
#ifdef iloi
	freopen("test.txt","r",stdin);
#endif
    scanf("%d%d%d%d\n",&n,&m,&r,&c);
    for (int i=1;i<=n;++i)
    {
        gets(s);
        for (int j=1;j<=m;++j)
            if (s[j-1]=='x') a[i][j]=1;
            else cnt++;
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
        {
            if (a[i][j]) continue;
            int x=(i-1)*m+j,y;
            if (i+r<=n&&j-c>=1&&!a[i+r][j-c])
            {
                y=(i+r-1)*m+j-c;
                add(x,n*m+y);
            }
            if (i+r<=n&&j+c<=m&&!a[i+r][j+c])
            {
                y=(i+r-1)*m+j+c;
                add(x,n*m+y);
            }
            if (i+c<=n&&j-r>=1&&!a[i+c][j-r])
            {
                y=(i+c-1)*m+j-r;
                add(x,n*m+y);
            }
            if (i+c<=n&&j+r<=m&&!a[i+c][j+r])
            {
                y=(i+c-1)*m+j+r;
                add(x,n*m+y);
            }
        }
    for (int i=1;i<=n*m;++i)
        if (find(i,i)) ans++;
    printf("%d\n",cnt-ans);
}
