#include<bits/stdc++.h> 
#define mp(a,b,c,d) (data){a,b,c,d}
#define inf 1000000000
#define ll long long
#define N 500005
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
//三元组(i, l, r)表示右端点为i，左端点在[l, r]之间和最大的区间 
struct data{int i,l,r,t;};
int bin[20],Log[N];
int n,K,L,R;
int a[N],mx[N][20];
ll ans;
void pre()
{ 
	Log[0]=-1;for(int i=1;i<=n;i++)	Log[i]=Log[i>>1]+1; //log[i]的值是i是2的几次方  本来可以用自带函数 或许这个比较快 
	
	for(int i=1;i<=n;i++)	mx[i][0]=i; //mx[i][j]表示第i个向后数2的j次方个的最大数的序号 
	
	for(int i=n;i;i--)
		for(int j=1;j<=18;j++)
			if(i+bin[j]-1<=n)
			{
				int t1=mx[i][j-1],t2=mx[i+bin[j-1]][j-1]; //求出两段最大序号 
				mx[i][j]= a[t1]>a[t2] ? t1 : t2 ;	//合并判断 
			}
			else break; //  就是个小小的优化 
}
inline int query(int l,int r)
{
	if(l==r)return l;
	int t=Log[r-l+1];
	int t1=mx[l][t] , t2=mx[r-bin[t]+1][t];
	return a[t1] > a[t2] ? t1 : t2; 
}

inline bool operator<(data x,data y)
{
	return a[x.t]-a[x.i-1]<a[y.t]-a[y.i-1];
} // 比大小 实质是比区间和的大小 

void solve()
{
	priority_queue<data,vector<data> >q;  //优先队列 按区间和从大到小维护 
	for(int i=1;i<=n;i++)
		if(i+L-1<=n)
		{
			int t=min(n,i+R-1);
			
			q.push(mp( i , i+L-1 , t , query(i+L-1,t) ) );
			
		}
	for(int i=1;i<=K;i++)
	{
		data t=q.top();	q.pop();
		ans += a[t.t] - a[t.i-1]; //加上 i 到 t 的和  perfect！ 
		// data( i , l , r , t ) 
		// 从 i 到 l~r 中 最大的序号是t  
	    if(t.t-1>=t.l)	q.push(mp(t.i , t.l , t.t-1 , query(t.l,t.t-1) ) );  //左端点在i 右端点在l~~t-1 之间 
		if(t.t+1<=t.r)	q.push(mp(t.i , t.t+1 , t.r , query(t.t+1,t.r) ) );  //左端点在i 右端点在t+1~~r 之间 
	}
}
int main()
{
	bin[0]=1;for(int i=1;i<20;i++)	bin[i]=bin[i-1]<<1; //bin[i]表示表示把1往左移i位。或许用数组存起来比较快？ 
	 
	n=read();K=read();L=read();R=read(); 
	//n为音符的个数，k为乐曲所包含的超级和弦个数，L和R分别是超级和弦所包含音符个数的下限和上限 
	
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)a[i]+=a[i-1];  //前缀和优化
	 
	pre();
	solve();
	
	printf("%lld",ans);
	return 0;
}
