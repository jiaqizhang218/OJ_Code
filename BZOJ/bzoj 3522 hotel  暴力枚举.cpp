#include<bits/stdc++.h>
#define cle(a) memset(a,0,sizeof a)
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
int next[10005],to[10005],head[5005],num[5005];
LL sum,t1[5005],t2[5005];
int tot,n,x,y,mx;
inline void insert(int x,int y) {
	next[++tot]=head[x];
	head[x]=tot;
	to[tot]=y;
}
inline void dfs(int x,int fa,int deep) {
	mx=max(mx,deep);
	num[deep]++;
	for(int i=head[x];i;i=next[i])
		if(to[i]!=fa)	dfs(to[i],x,deep+1);
}
int main()
{
	n=read();
	for(int i=1;i<n;i++) {
		int x=read(),y=read();
		insert(x,y);
		insert(y,x);
	}
	for(int i=1;i<=n;i++) {
		cle(t1),cle(t2);
		for(int j=head[i];j;j=next[j]) {
			cle(num);
			dfs(to[j],i,1);
			for(int k=1;k<=mx;k++) {
				sum+=t2[k]*num[k];
				t2[k]+=num[k]*t1[k];
				t1[k]+=num[k];
			}
		}
	}
	cout<<sum;
}
