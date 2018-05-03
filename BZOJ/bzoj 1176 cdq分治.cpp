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
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
//#define  getchar() nc()
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
    while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;
    return;
}
const int M = 2002002;
struct node{
	int x,y,num,pos,ans;
	node(){}
	node(int X,int Y,int Num);
	bool operator < (const node &rhs) const {
		return x<rhs.x;
	}
}q[200200],nq[200200];
int num,w,n,ans;
int c[M],tim[M],T;
inline void update(int x,int y){for(;x<=w;x+=(x&(-x))){if(tim[x]!=T)c[x]=0;tim[x]=T;c[x]+=y;}}
inline int get(int x){int re=0;for(;x;x-=(x&(-x))) if(tim[x]==T) re+=c[x]; return re;}
inline bool cmp(const node& x,const node& y){return x.pos<y.pos;}
node :: node(int X,int Y,int Num) {x=X,y=Y,num=Num;pos=n,ans=0;}
void cdq(int l,int r)
{
	int i,j,mid=l+r>>1;
	int x=l,y=mid+1;
	if(l==r)return;
	for(i=l;i<=r;i++) if(q[i].pos<=mid) nq[x++]=q[i]; else nq[y++]=q[i];
	memcpy(q+l,nq+l,sizeof(q[0])*(r-l+1));
	cdq(l,mid);	cdq(mid+1,r);
	j=l;++T;
	for(i=mid+1;i<=r;++i)
	{
		for(;q[j].x<=q[i].x&&j<=mid;j++) 
			if(q[j].num!=20010821)
				update(q[j].y,q[j].num);
		if(q[i].num==20010821)
			q[i].ans+=get(q[i].y);
	}

	x=l;y=mid+1;
	for(i=l;i<=r;++i) 
	{
		if(q[x]<q[y]&&x<=mid||y>r)
			nq[i]=q[x++];
		else	nq[i]=q[y++];
	}
	memcpy(q+l,nq+l,sizeof(q[0])*(r-l+1));
}
int main()
{
#ifdef	iloi
	freopen("test.txt","r",stdin);
#endif
	int i,p,x,y,z,x1,y1,x2,y2;
	rd(num),rd(w);
	while(rd(p),p^3) {
		if(p==1) rd(x),rd(y),rd(z),q[++n]=node(x,y,z);
		else {rd(x1),rd(y1),rd(x2),rd(y2),q[++n]=node(x1-1,y1-1,20010821);
			q[++n]=node(x1-1,y2,20010821);
			q[++n]=node(x2,y1-1,20010821);
			q[++n]=node(x2,y2,20010821);
		}
	}
	sort(q+1,q+n+1);
	cdq(1,n);
	sort(q+1,q+n+1,cmp);
    for(i=1;i<=n;i++)  
        if(q[i].num==20010821)  
        {  
            ans=0;  
            ans+=q[i++].ans;  
            ans-=q[i++].ans;  
            ans-=q[i++].ans;  
            ans+=q[i  ].ans;  
            printf("%d\n",ans);  
        }  	
}
