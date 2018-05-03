#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=10010;
int n,m,cnt;
int to[maxn<<1],next[maxn<<1],head[maxn],val[maxn<<1],dis[maxn],inq[maxn],len[maxn];
queue<int> q;
void add(int a,int b,int c)
{
    to[cnt]=b,val[cnt]=c,next[cnt]=head[a],head[a]=cnt++;
}
int main()
{
    scanf("%d%d",&n,&m);
    int i,a,b,c,d,u;
    memset(head,-1,sizeof(head));
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&d,&a,&b);
        switch(d)
        {
            case 1:scanf("%d",&c),add(a,b,-c);  break;
            case 2:scanf("%d",&c),add(b,a,c);   break;
            case 3:add(a,b,0),add(b,a,0);   break;
        }
    }
    for(i=1;i<=n;i++)    q.push(i),inq[i]=1,len[i]=1;
    while(!q.empty())
    {
        u=q.front(),q.pop(),inq[u]=0;
        for(i=head[u];i!=-1;i=next[i])
        {
            if(dis[to[i]]>dis[u]+val[i])
            {
                dis[to[i]]=dis[u]+val[i];
                len[to[i]]=len[u]+1;
                if(len[to[i]]>n)
                {
                    printf("No");
                    return 0;
                }
                if(!inq[to[i]]) inq[to[i]]=1,q.push(to[i]);
            }
        }
    }
    printf("Yes");
    return 0;
}
