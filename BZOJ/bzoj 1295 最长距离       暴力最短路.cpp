#include<bits/stdc++.h>
typedef long long LL;
const int inf = 0x7fffffff;
const int maxn = 910; 
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int dx[4]={0,1,0,-1};  
int dy[4]={1,0,-1,0};  
int a[31][31];  
int q1[maxn],q2[maxn],dis[31][31];  
bool vis[31][31];  
char s[50];  
int n,m,T;  
double ans;  
  
void bfs(int x,int y)  
{  
    for (int i=1;i<=n;i++)  
      for (int j=1;j<=m;j++)  
        dis[i][j]=inf;  
    int l=0,r=1;  
    q1[1]=x;q2[1]=y;vis[x][y]=1;dis[x][y]=0;  
    while (l!=r)  
    {  
        l++;if (l==maxn) l=0;  
        int x=q1[l],y=q2[l];  
        for (int i=0;i<4;i++)  
        {  
            int xx=x+dx[i],yy=y+dy[i];  
            if (xx<1 || xx>n || yy<1 || yy>n) continue;  
            if (dis[x][y]+a[x][y]<dis[xx][yy])  
            {  
                dis[xx][yy]=dis[x][y]+a[x][y];  
                if (!vis[xx][yy])  
                {  
                    r++;if (r==maxn) r=0;  
                    q1[r]=xx;q2[r]=yy;vis[xx][yy]=1;  
                }  
            }  
        }  
        vis[x][y]=0;  
    }  
}  
  
int main()  
{  
    scanf("%d%d%d",&n,&m,&T);  
    for (int i=1;i<=n;i++)  
    {  
        scanf("%s",s+1);  
        for (int j=1;j<=m;j++) a[i][j]=s[j]-'0';  
    }  
    ans=0.0;  
    for (int i=1;i<=n;i++)  
      for (int j=1;j<=m;j++)  
      {  
        bfs(i,j);  
        for (int k=1;k<=n;k++)  
          for (int p=1;p<=m;p++)  
            if (dis[k][p]+a[k][p]<=T) ans=max(ans,sqrt((double)(k-i)*(k-i)+(p-j)*(p-j)));  
      }  
    printf("%.6lf\n",ans);  
    return 0;  
}

