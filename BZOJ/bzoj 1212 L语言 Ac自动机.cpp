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
struct node{
	int fail,len,ch[26];
	void clear() {
		fail=len=0;
		memset(ch,0,sizeof ch);
	} 
}tr[205];
int sz;
inline void ins(char *s) {
	int u=0,n=strlen(s);
	for(int i=0;i<n;i++) {
		int c=s[i]-'a';
		if(!tr[u].ch[c]) {
			tr[u].ch[c]=++sz;
			tr[sz].clear(); 
		}
		u=tr[u].ch[c];
	}
	tr[u].len=n;
}
inline void bfs() {
	queue<int>q;
	q.push(0);
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=0;i<26;i++) {
			if(tr[u].ch[i]) {
				int v=tr[u].ch[i];
				if(u)tr[v].fail=tr[tr[u].fail].ch[i];
				q.push(v);
			}
			else 
				tr[u].ch[i]=tr[tr[u].fail].ch[i]; 
		} 
	} 
}
bool f[1000005];
inline int dfs(char *s) {
	int n=strlen(s+1);
	memset(f,0,sizeof f);
	f[0]=1;
	int p=0;
	for(int i=1;i<=n;i++) {
		int c=s[i]-'a';
		p=tr[p].ch[c];
		if(!p) break;
		for(int q=p;q;q=tr[q].fail)
			f[i] |= f[i-tr[q].len];
	}
	for(int i=n;i>=0;i--)	if(f[i]) return i;
}
char s[1000005];
int main()
{
	int n=read(),m=read();
	tr[sz=0].clear();
	for(int i=1;i<=n;i++) {
		scanf("%s",s);
		ins(s);
	}
	bfs();
	while(m--) {
		scanf("%s",s+1);
		printf("%d\n",dfs(s));
	}
	return 0;
}
