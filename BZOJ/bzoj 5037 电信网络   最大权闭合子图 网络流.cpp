#include<bits/stdc++.h>
using namespace std;
int n,cnt,ans,S,T;
int x[510],y[510],r[510],s[510];
int to[1000000],nxt[1000000],val[1000000],fir[510],d[510];
queue<int> q;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
#define  getchar() nc()
inline int rd()
{
    int ret=0,f=1;  char gc=getchar();
    while(gc<'0'||gc>'9') {if(gc=='-')f=-f;   gc=getchar();}
    while(gc>='0'&&gc<='9')   ret=ret*10+gc-'0',gc=getchar();
    return ret*f;
}
void add(int a,int b,int c)
{
    to[cnt]=b,val[cnt]=c,nxt[cnt]=fir[a],fir[a]=cnt++;
    to[cnt]=a,val[cnt]=0,nxt[cnt]=fir[b],fir[b]=cnt++;
}
int dfs(int x,int mf)
{
    if(x==T)    return mf;
    int i,k,temp=mf;
    for(i=fir[x];i!=-1;i=nxt[i])
    {
        if(d[to[i]]==d[x]+1&&val[i])
        {
            k=dfs(to[i],min(val[i],temp));
            if(!k)  d[to[i]]=0;
            val[i]-=k,val[i^1]+=k,temp-=k;
            if(!temp)   break;
        }
    }
    return mf-temp;
}
int bfs()
{
    while(!q.empty())   q.pop();
    memset(d,0,sizeof(d));
    q.push(S),d[S]=1;
    int i,u;
    while(!q.empty())
    {
        u=q.front(),q.pop();
        for(i=fir[u];i!=-1;i=nxt[i])
        {
            if(!d[to[i]]&&val[i])
            {
                d[to[i]]=d[u]+1;
                if(to[i]==T)    return 1;
                q.push(to[i]);
            }
        }
    }
    return 0;
}
int main()
{
    n=rd(),S=0,T=n+1;
    int i,j;
    memset(fir,-1,sizeof(fir));
    for(i=1;i<=n;i++)
    {
        x[i]=rd(),y[i]=rd(),r[i]=rd(),s[i]=rd();
        if(s[i]>0)   ans+=s[i],add(S,i,s[i]);
        else    add(i,T,-s[i]);
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)    
			if(i!=j&&(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=r[i]*r[i]) 
				add(i,j,1<<30);
    while(bfs())    ans-=dfs(S,1<<30);
    printf("%d",ans);
    return 0;
}
