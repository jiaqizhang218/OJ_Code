#include<bits/stdc++.h>
#define ll long long
const int INF = 0x7fffffff;
const double eps = 1e-5;
#define N 40005
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
struct arr{int s,go,next;}a[N<<1];
int end[N],son[N],f[N],d[N],data[N];
int cnt,L,All,ans,i,x,y,z,n,root,K;
bool Can[N];
void add(int u,int v,int w)
{
	a[++cnt].go = v; a[cnt].next = end[u] ; end[u] = cnt ; a[cnt].s = w;
}
void Get_root(int k,int fa)
{
	son[k] = 1; f[k] = 0;
	for(int i = end[k]; i; i = a[i].next)
	{
		int go = a[i].go;
		if(go == fa || Can[go])	continue;
		Get_root(go,k); son[k] += son[go];
		if(son[go] > f[k]) f[k] = son[go];
	}
	if(All-son[k]>f[k])	f[k] = All - son[x];
	if(f[k] < f[root]) root = k;
}
void Get_array(int k,int fa)
{
	data[++L] = d[k];
	for(int i = end[k];i;i=a[i].next)
	{
		int go = a[i].go;
		if(go != fa && !Can[go])
			d[go] = d[k] + a[i].s, Get_array(go,k);
	}
}
int calc(int k,int now)
{
	d[k] = now; L = 0; Get_array(k,-1);
	int A = 0,l,r;
	sort(data+1,data+L+1);
	for(l = 1 , r = L ;  l < r ;)
		if(data[r] + data[l] <= K) A += r-l,l++;	else r--;
	return A;zaml
	
}
void work(int k)
{
	ans += calc(k,0) ; Can[k] = 1;
	for(int i = end[k];i;i=a[i].next)
	{
		int go = a[i].go;
		if(Can[go]) continue;
		ans -= calc(go,a[i].s);f[root = 0] = n + 1;
		All = son[go]; Get_root(go,-1);
		work(root); 
	}
}
int main()
{
	n = read();
	for(int i = 1 ; i < n ; i++)
		x = read() , y =  read() , z = read() , add(x,y,z) , add(y,x,z);
	K = read(); All = n;
	f[root=0] = n+1;Get_root(1,-1);
	work(root);
	printf("%d",ans); 
	return 0;	
}

