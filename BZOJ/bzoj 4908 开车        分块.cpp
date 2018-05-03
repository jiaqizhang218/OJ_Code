#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define getchar() (*S++)
#define pa pair<int,int>
#define ll long long
#define MN 50000
#define MB 400
char B[1<<26],*S=B;
using namespace std;
inline int read()
{
    int x = 0 , f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return x * f;
}
long long Ans,ans[MB+5],F[MB+5][MB*2+5],f[MB+5][MB*2+5];
int n,m,l[MN*3+5],cnt=0,pos[MB+5],a[MN+5],block[MN*3+5],v[MN*3+5];
int s[MN*3+5],b[MN+5],tot=1,size;
struct ques{int x,y;}q[MN+5];
inline int abs(int x){return x<0?-x:x;}
void Move(int x,int y)
{
    Ans-=ans[x];
    if(abs(y)<=MB) Ans+=(ans[x]=F[x][MB+y]);
    else
    {
        if(y>MB) Ans+=(ans[x]=F[x][MB<<1]+1LL*(y-MB)*f[x][MB<<1]);
        if(y<MB) Ans+=(ans[x]=F[x][0]+1LL*(MB-y)*f[x][0]);
    }
}

void Build(int x)
{
    int W=0;
    for(int i=0;i<=MB<<1;++i) f[x][i]=F[x][i]=0;
    for(int i=(x-1)*size+1;block[i]==x;++i)
    {
        F[x][MB]+=1LL*v[i]*abs(W+=s[i]);
        if(!W)  f[x][1+MB]+=v[i],f[x][MB-1]+=v[i];
        if(W>0) f[x][MB+1]+=v[i],W<MB?(f[x][MB-W-1]+=v[i]<<1):0,f[x][MB-1]-=v[i];
        if(W<0) f[x][MB+1]-=v[i],f[x][MB-W+1]+=v[i]<<1,f[x][MB-1]+=v[i];
    }
    for(int i=1;i<=MB;++i) 
        F[x][MB+i]=F[x][MB+i-1]+(f[x][MB+i]+=f[x][MB+i-1]),
        F[x][MB-i]=F[x][MB-i+1]+(f[x][MB-i]+=f[x][MB-i+1]);                
    Move(x,pos[x]);
}

int main()
{
    fread(B,1,1<<26,stdin);
    n=read();
    for(int i=1;i<=n;++i) a[i]=l[++cnt]=read();
    for(int i=1;i<=n;++i) b[i]=l[++cnt]=read();
    m=read();
    for(int i=1;i<=m;++i) q[i].x=read(),q[i].y=l[++cnt]=read();
    sort(l+1,l+cnt+1);
    for(int i=2;i<=cnt;++i)    if(l[i]!=l[i-1]) l[++tot]=l[i];
    for(int i=1;i<tot;++i) v[i]=l[i+1]-l[i];
    size=sqrt(tot);
    for(int i=1;i<=n;++i) 
        a[i]=lower_bound(l+1,l+tot+1,a[i])-l,
        b[i]=lower_bound(l+1,l+tot+1,b[i])-l,
        ++s[a[i]],--s[b[i]];
    for(int i=1;i<=tot;++i) block[i]=(i-1)/size+1;
    for(int i=1,w=0;i<=block[tot];++i) 
    {
        pos[i]=w;Build(i);
        for(int j=(i-1)*size+1;block[j]==i;++j) w+=s[j];
    }
    printf("%lld\n",Ans);
    for(int i=1;i<=m;++i)
    {
        q[i].y=lower_bound(l+1,l+tot+1,q[i].y)-l; 
        if(q[i].y!=a[q[i].x])
        {                
            --s[a[q[i].x]];++s[q[i].y];
            if(block[q[i].y]==block[a[q[i].x]])
                Build(block[q[i].y]);
            else
            {
                int From=min(block[a[q[i].x]],block[q[i].y]),
                      To=max(block[a[q[i].x]],block[q[i].y]);
                for(int j=From+1;j<To;++j) 
                    Move(j,pos[j]+=(q[i].y>a[q[i].x]?-1:1));
                if(a[q[i].x]>q[i].y) ++pos[block[a[q[i].x]]];
                else --pos[block[q[i].y]];
                Build(block[q[i].y]);Build(block[a[q[i].x]]);
            }
        }
        a[q[i].x]=q[i].y;printf("%lld\n",Ans);
    }
    return 0;
}
