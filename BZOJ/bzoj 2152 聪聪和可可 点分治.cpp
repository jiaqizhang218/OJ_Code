#include<bits/stdc++.h>
#define ll long long
const int INF = 0x7fffffff;
const double eps = 1e-5;
const int N = 50005;
using namespace std;
int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
void put(int x)
{
    int num = 0; char c[15];
    while(x) c[++num] = (x%10)+48, x /= 10;
    while(num) putchar(c[num--]);
}
struct arr{
	int go,next,s;
}a[N];
int son[N],f[N],end[N],F[N][4];
int root,n,i,All,ans,Mon,Son,c,cnt,x,y,z;
bool Can[N];
inline void add(int u,int v,int w)
{
	a[++cnt].go = v , a[cnt].next = end[u] , end[u] = cnt , a[cnt].s = w;
}
inline void Get(int k,int fa)
{
	son[k] = 1,f[k] = 0;
	for(int i = end[k];i;i=a[i].next)
	{
		int go = a[i].go;
		if(fa == go || Can[go]) continue;
		Get(go,k);	son[k] += son[go];
		if(son[go] > f[k]) f[k] = son[go];
	}
	if(All-son[k] > f[k]) f[k] = All - son[k];
	if(f[k] < f[root]) root = k;
}
inline void dfs(int k,int fa,int P,int now)
{
	F[P][now]++;
	for(int i = end[k];i;i=a[i].next)
	{
		int go = a[i].go;
		if(go == fa|| Can[go]) continue;
		dfs(go,k,P,(now+a[i].s)%3);
	}
}
inline void work(int k)
{
	Can[k] = true;
	for(int i = end[k];i;i=a[i].next)
	{
		int go = a[i].go;
		if(Can[go]) continue;
		int N0 = F[k][0],N1 = F[k][1],N2 = F[k][2];
		dfs(go,k,k,a[i].s);
		ans += (N0+1) * (F[k][0]-N0)+N2*(F[k][1]-N1)+N1*(F[k][2]-N2);
		f[root=0]=n+1; All = son[go];
		Get(go,-1);	work(root);
	}
}
inline int gcd(int a,int b)
{
	return (a%b)?gcd(b,a%b):b;
}
int main()
{
	n = read();
	if(!n) 	
	{
		printf("0/1");
		return 0;
	}
	for(int i = 1 ; i < n ; i++)
		x=read(),y=read(),z=read(),add(x,y,z%3),add(y,x,z%3);
		f[root=0]=n+1;All=n;
		Get(1,-1);
		work(root);
		Mon = n * n; Son = ans*2+n; c = gcd(Mon,Son); Mon/=c , Son/=c;
		printf("%d/%d",Son,Mon);
		return 0;
}

