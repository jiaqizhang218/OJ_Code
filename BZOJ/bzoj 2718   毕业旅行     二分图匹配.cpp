#include<bits/stdc++.h>
#define N 205
using namespace std;
int n,m,G[N+1][N+1],lk[N+1],x,y;
int cnt;
bool used[N+1];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline bool find(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(!G[x][i])continue;
        if(used[i])continue;
        used[i]=true;
        if(!lk[i]||find(lk[i]))
        {
            lk[i]=x;
            return true;
        }
    }
    return false;
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        x=read(),y=read();
        G[x][y]=true;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                G[i][j]=G[i][j]||(G[i][k]&&G[k][j]);
    for(int i=1;i<=n;i++)
    {
        memset(used,false,sizeof(used));
        if(find(i))cnt++;
    }
    cout<<n-cnt;
    return 0;
}
