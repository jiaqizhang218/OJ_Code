#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#define mp(A,B) make_pair(A,B)
using namespace std;
const int maxn=40010;
const int maxm=400010;
int n,m,cnt,ans;
queue<int> q;
int pre[maxn],inq[maxn],dis[maxn],pa[maxm],pb[maxm],pc[maxm];
int to[maxm],next[maxm],val[maxm],head[maxn];
void add(int a,int b,int c)
{
    to[cnt]=b,val[cnt]=c,next[cnt]=head[a],head[a]=cnt++;
}
void spfa()
{
    int u,i;
    while(!q.empty())
    {
        u=q.front(),q.pop(),inq[u]=0;
        for(i=head[u];i!=-1;i=next[i])  if(dis[to[i]]>dis[u]+val[i])
        {
            dis[to[i]]=dis[u]+val[i],pre[to[i]]=pre[u];
            if(!inq[to[i]]) inq[to[i]]=1,q.push(to[i]);
        }
    }
}
inline int rd()
{
    int ret=0,f=1;  char gc=getchar();
    while(gc<'0'||gc>'9') {if(gc=='-')f=-f;   gc=getchar();}
    while(gc>='0'&&gc<='9')   ret=ret*10+gc-'0',gc=getchar();
    return ret*f;
}
int main()
{
    n=rd(),m=rd();
    int i,a,b,c,d;
    memset(head,-1,sizeof(head));
    for(i=1;i<=m;i++)
        a=rd(),b=rd(),c=rd(),d=rd(),add(a,b,c),pa[cnt]=a,pb[cnt]=b,pc[cnt]=c,add(b,a,d),pa[cnt]=b,pb[cnt]=a,pc[cnt]=d;
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    for(i=head[1];i!=-1;i=next[i])  dis[to[i]]=val[i],q.push(to[i]),inq[to[i]]=1,pre[to[i]]=to[i];
    spfa();
    memset(head,-1,sizeof(head)),cnt=0;
    ans=1<<30;
    for(i=1;i<=2*m;i++)
    {
        if(pa[i]==1)
        {
            if(pre[pb[i]]!=pb[i])   add(1,pb[i],pc[i]);
        }
        else    if(pb[i]==1)
        {
            if(pre[pa[i]]==pa[i])   add(pa[i],n+1,pc[i]);
            else    ans=min(ans,dis[pa[i]]+pc[i]);
        }
        else
        {
            if(pre[pa[i]]==pre[pb[i]])  add(pa[i],pb[i],pc[i]);
            else    add(1,pb[i],dis[pa[i]]+pc[i]);
        }
    }
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0,q.push(1);
    spfa(),ans=min(ans,dis[n+1]);
    if(ans==1<<30||ans==0x3f3f3f3f)   printf("-1");
    else    printf("%d",ans);
    return 0;
}
