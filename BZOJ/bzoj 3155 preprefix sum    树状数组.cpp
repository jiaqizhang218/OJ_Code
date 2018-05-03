#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int n,m,a[100005];
LL t[2][100005];
inline int lowbit(int x){
	return x&(-x);
} 
inline void update(int f,int x,LL val)
{
	for(;x<=n;x+=lowbit(x))	t[f][x] += val;
}
inline LL ask(int f,int x)
{
	LL tmp=0;
	for(;x;x-=lowbit(x))
		tmp+=t[f][x];
	return tmp;
}
int main()
{
	n=read(),m=read();
	int x,y;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		update(0,i,a[i]);
		update(1,i,(LL)(n-i+1)*a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		char ch[10];
		scanf("%s",ch);
		if(ch[0]=='Q')
		{
			x=read();
			printf("%lld\n",ask(1,x)-ask(0,x)*(n-x));
		}
		else 
		{
			x=read(),y=read();
			update(0,x,y-a[x]);
			update(1,x,(LL)(n-x+1)*(y-a[x]));
			a[x]=y;
		}
	}
	return 0;
}

