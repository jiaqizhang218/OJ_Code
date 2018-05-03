#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
#define pa pair<int,int>
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
#define  getchar() nc()
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int ans;
int n,m,cnt;
int a[200005],pre[200005],nxt[200005];
bool mark[200005];
priority_queue<pa,vector<pa> >q;
inline void del(int x)
{
	mark[x]=1;
	int l=pre[x],r=nxt[x];
	nxt[x]=pre[x]=0;
	nxt[l]=r;pre[r]=l;
}
inline void get()
{
	while(mark[q.top().second])q.pop();
	int x=q.top().second;ans+=a[x];
	q.pop();
	a[x]=a[pre[x]]+a[nxt[x]]-a[x];
	del(pre[x]);del(nxt[x]);
	q.push(make_pair(a[x],x));
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(m>n/2){puts("Error!");return 0;}
	for(int i=1;i<=n;i++)pre[i]=i-1;pre[1]=n;
	for(int i=1;i<=n;i++)nxt[i]=i+1;nxt[n]=1;
	for(int i=1;i<=n;i++)
		q.push(make_pair(a[i],i));
	for(int i=1;i<=m;i++)
		get();
	printf("%d",ans);
	return 0;
}
