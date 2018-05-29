#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_end=(b);i>=i##_end;--i)
template <typename T> inline void rd(T &x) {
    x=0;int f=1;char CH=getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;return;
}
const int MXN = 1e5 + 5;
int ans=0,trie_cnt=1,rt=1,len,ch[MXN*60][11],cnt[MXN*60];
char str[62];
vector<int> v[MXN*60];
inline void Ins(int id,int val) {
	scanf("%s",str+1); len=strlen(str+1);
	int now = rt;
	rep(i,1,len) {
		if(!ch[now][str[i]-'a']) ch[now][str[i]-'a']=++trie_cnt;
		now=ch[now][str[i]-'a']; cnt[now]+=val;
		if(cnt[now]>v[now].size()) v[now].push_back(id);
	}
}
inline void Query() {
	int t,a,b,c;scanf("%s",str+1);len=strlen(str+1); rd(a),rd(b),rd(c);
	t=(1LL*a*abs(ans)+b)%c; int now=rt;
	rep(i,1,len) {
		if(!ch[now][str[i]-'a']) {ans=-1;break;}
		now=ch[now][str[i]-'a'];
		if(i==len) ans=(v[now].size()-1)>=t?v[now][t]:-1;
	}
	printf("%d\n",ans);
}
int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
#endif
	int n,k;
	rd(n);
	rep(owo,1,n) {
		rd(k);
		if(k==1) Ins(owo,1);
		else if(k==2) Ins(owo,-1);
		else Query();
	}
}
