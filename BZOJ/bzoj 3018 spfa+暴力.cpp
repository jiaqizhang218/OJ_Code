#include<bits/stdc++.h>
using namespace std;
#define RG register
#define rep(i,a,b) for(RG int i=a,i##_end=b;i<=i##_end;++i)
#define per(i,a,b) for(RG int i=a,i##_end=b;i>=i##_end;--i)
#define rpg(i,x) for(RG int i=fir[x];i;i=e[i].nxt)
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define pos(x,y) (x-1)*n+y
const int N = 950;
char mp[35][35];
int n,disa,disb,dis[N][N],vis[N],ans;
int cnt,fir[N];
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
struct edge{int to,nxt,val;}e[N<<5];
inline void AE(int u,int v,int w){e[++cnt].to=v;e[cnt].nxt=fir[u];fir[u]=cnt;e[cnt].val=w;}
inline int rd(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();} return x*f;}
inline void add(int x,int y)
{
    rep(i,0,3) {
        int nowx=x+dx[i],nowy=y+dy[i];
        if(nowx<1||nowx>n||nowy<1||nowy>n)    continue;
        if(mp[x][y]==mp[nowx][nowy]) AE(pos(x,y),pos(nowx,nowy),disa);    else AE(pos(x,y),pos(nowx,nowy),disb);
    }    
}
inline void spfa(int x,int y){
    int nowx = pos(x,y),now; memset(vis,0,sizeof vis);
    queue<int> q; q.push(nowx); vis[nowx]=true; dis[nowx][nowx]=0;
    while(!q.empty()) {
        now = q.front(); q.pop();
        rpg(i,now) {
            if(vis[e[i].to]) continue;
            if(dis[nowx][e[i].to]>dis[nowx][now]+e[i].val)    
				dis[nowx][e[i].to]=dis[nowx][now]+e[i].val,q.push(e[i].to);
        }
    }
}
int main(){
#ifdef iloi
	freopen("test.txt","r",stdin);
#endif
    n=rd(),disa=rd();disb=rd();
    rep(i,1,n) scanf("%s",mp[i]+1);
    memset(dis,0x3f,sizeof dis);
    rep(i,1,n)    rep(j,1,n)    add(i,j);
    rep(i,1,n)    rep(j,1,n)    spfa(i,j);
    rep(i,1,n)    rep(j,1,n)    rep(k,1,n)    rep(l,1,n)    if(dis[pos(i,j)][pos(k,l)]>ans) ans=dis[pos(i,j)][pos(k,l)];
    printf("%d\n",ans);
    return 0;
}
