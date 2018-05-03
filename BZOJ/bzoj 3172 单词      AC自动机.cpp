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
const int N = 1000010;
struct node{
	int fail,ch[26],sum;
}p[N];
int n,m,tot;
int Q[N],ans[N],pos[N];
char w[N];
queue<int> q;

int main()
{
	n=read();
	int i,j,k,u,t;
	tot=1;
	for(i=1;i<=n;i++) {
		scanf("%s",w);
		u=1;
		k=strlen(w);
		for(j=0;j<k;j++) {
			if(!p[u].ch[w[j]-'a'])	p[u].ch[w[j]-'a']=++tot;
			u=p[u].ch[w[j]-'a'];
			p[u].sum++;
		}
		pos[i]=u;
	}
	q.push(1);
	while(!q.empty()) {
		u=q.front(); q.pop();
		Q[++Q[0]]=u;
		for(i=0;i<26;i++) {
			if(!p[u].ch[i]) continue;
			q.push(p[u].ch[i]);
			if(u==1) {
				p[p[u].ch[i]].fail=1;
				continue;
			}
			t=p[u].fail;
			while(!p[t].ch[i]&&t)	t=p[t].fail;
			if(t)	p[p[u].ch[i]].fail=p[t].ch[i];
			else p[p[u].ch[i]].fail=1;
		}
	}
	for(i=tot;i>=2;i--) {
		p[p[Q[i]].fail].sum+=p[Q[i]].sum;
	}
	for(i=1;i<=n;i++)	printf("%d\n",p[pos[i]].sum);
	return 0;
}
