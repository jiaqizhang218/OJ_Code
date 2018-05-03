#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rpg(i,x) for(register int i=fir[x];i;i=e[i].nxt)
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define bin(i) (1<<i)
#define cls(x,y) memset(x,y,sizeof x)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
const int oo = 0x3f3f3f3f;
/*
const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc() //*/
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXM = 600010;
int fa[MXM],dis[MXM],q[MXM],ans[MXM];
int N,D,L,R;
struct node {
	int A,B,id;
}a[MXM];
bool cmp1(const node & a,const node &b) {return a.B<b.B;}
bool cmp2(const node & a,const node &b) {return a.A<b.A;}
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int bin1(int l,int r,int x)
{
    if (a[r].A<x) return -1;
    while (l<r)
    {
        int mid=(l+r)>>1;
        if (a[mid].A<x) l=mid+1;
        else r=mid;
    }
    return r;
}
int bin2(int l,int r,int x)
{
    if (a[l].A>x) return -1;
    while (l<r)
    {
        int mid=(l+r+1)>>1;
        if (a[mid].A>x) r=mid-1;
        else l=mid;
    }
    return l;
}
int bin3(int l,int r,int x)
{
    if (a[r].B<x) return -1;
    while (l<r)
    {
        int mid=(l+r)>>1;
        if (a[mid].B<x) l=mid+1;
        else r=mid;
    }
    return r;
}
int bin4(int l,int r,int x)
{
    if (a[l].B>x) return -1;
    while (l<r)
    {
        int mid=(l+r+1)>>1;
        if (a[mid].B>x) r=mid-1;
        else l=mid;
    }
    return l;
}

int main()
{
#ifdef iloi
	 //  freopen("test.txt","r",stdin);
#endif
	L=R=0;
	rd(N),rd(D);
	rep(i,1,N<<1)	rd(a[i].A),rd(a[i].B),a[i].id=i,fa[i]=i;
	sort(a+1,a+1+N,cmp1);
	sort(a+1+N,a+1+N+N,cmp2);
	rep(i,1,MXM-5) dis[i]=INF;
	for(int i=1;i<=N&&!a[i].B;++i) q[R++]=i,dis[i]=1;
	for(int i=N+1;i<=N+N&&!a[i].A;++i)	q[R++]=i,dis[i]=1;
	while(L<R) {
		int now=q[L++],l,r;
		if(now<=N) {
			l=bin1(N+1,N+N,a[now].A-D);
			r=bin2(N+1,N+N,a[now].A);
		}
		else {
			l=bin3(1,N,a[now].B-D);
			r=bin4(1,N,a[now].B);
		}
		if(l==-1||r==-1) continue;
		for(int i=l,father;i<=r;i=father+1) {
			father=find(i);
			fa[i]=r;
			if(dis[i]>dis[now]+1) 
			dis[i]=dis[now]+1,q[R++]=i;
		}
	}
	rep(i,1,N) 	ans[a[i].id]=dis[i];
	rep(i,1,N) if(ans[i]<INF) cout<<ans[i]<<endl;
	else puts("-1");
	return 0;
}
