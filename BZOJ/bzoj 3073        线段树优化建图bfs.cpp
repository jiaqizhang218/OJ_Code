#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int N = 500010;
const int M = 9000050;
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
int n,m,s,x,y,i,h,t,e,X,Y,tp,tot,L[M],R[M],fir[1048577],pos[N],ne[M],q[N],d[N];
set<int>st; set<int>::iterator it,w[N];
inline void ins(int k,int l,int r)
{
	if(x<=l&&r<=y)
	{
		L[++tot]=X;R[tot]=Y;ne[tot]=fir[k];fir[k]=tot;
		return;
	}
	int mid=l+r>>1;	if(x<=mid)	ins(k<<1,l,mid);
	if(y>mid)	ins(k<<1|1,mid+1,r);
}
inline void buildtree(int k,int l,int r)
{
	if(l==r)	{pos[l]=k;return;}
	int mid=l+r>>1;
	buildtree(k<<1,l,mid); buildtree(k<<1|1,mid+1,r);
}
int main()
{
	for(n=read(),m=read(),s=read(),buildtree(1,1,n);m--;)
	{
		x=read(),y=read(),X=read(),Y=read();
		ins(1,1,n);
		swap(x,X),swap(y,Y);
		ins(1,1,n);
	}
	for(i=1;i<=n+1;i++)	if(i!=s)	st.insert(i);
	for(q[t=1]=s;h^t;)for(e=d[x=q[++h]]+1,x=pos[x];x;fir[x]=0,x>>=1)
            for(i=fir[x];i;i=ne[i]){
                for(tp=0,it=st.lower_bound(L[i]);*it<=R[i];it++)d[q[++t]=*it]=e,w[++tp]=it;
                for(;tp;)st.erase(w[tp--]);
            }
	for(int i=1;i<=n;i++)	printf("%d\n",d[i]);
	return 0;
}
