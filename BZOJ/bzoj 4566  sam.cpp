#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rpg(i,x) for(register int i=fir[x];i;i=e[i].nxt)
typedef long long LL;
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 400005;
int fir[MXN],tot; LL dp[MXN];
char s1[MXN>>1];
struct edge{
	int to,nxt;
}e[MXN<<1];
inline void AE(int u,int v){e[++tot].to=v;e[tot].nxt=fir[u];fir[u]=tot;}
struct SAM {
	int p,q,lens,nq,np,last,root,ch[MXN][26],a[MXN],b[MXN],sz[MXN],f[MXN],l[MXN],cnt;
	SAM(){cnt=0;root=last=++cnt;}
	inline void ins(int x) {
		p=last; np=last=++cnt; l[np]=l[p]+1;sz[np]=1;
		while(!ch[p][x]&&p) ch[p][x]=np,p=f[p];
		if(!p) f[np]=1;
		else {
			q=ch[p][x];
			if(l[q]==l[p]+1) f[np]=q;
			else {
				nq=++cnt; l[nq]=l[p]+1;
				memcpy(ch[nq],ch[q],sizeof ch[q]);
				f[nq]=f[q],f[q]=f[np]=nq;
				while(ch[p][x]==q&&p) ch[p][x]=nq,p=f[p];
			}
		}
	}
	inline void pre() {
		rep(i,1,cnt) b[l[i]]++;
		rep(i,1,lens) b[i]+=b[i-1];
		per(i,cnt,1) a[b[l[i]]--]=i;
		per(i,cnt,1) sz[f[a[i]]]+=sz[a[i]];
	}
	inline void dfs(int x) {
		dp[x]+=(LL)sz[x]*(l[x]-l[f[x]]);
		rpg(i,x) dp[e[i].to] += dp[x], dfs(e[i].to);
	}
	inline void read() {
		scanf("%s",s1+1); lens=strlen(s1+1);
		rep(i,1,lens) ins(s1[i]-'a');
		pre(); rep(i,1,cnt) if(f[i]) AE(f[i],i); dfs(1);
		scanf("%s",s1+1); lens=strlen(s1+1);
	}
	inline void solve() {
		read();
		LL ans=0; int t,len=0; p=1;
		rep(i,1,lens) {
			t=s1[i]-'a';
			while(p&&!ch[p][t]) p=f[p];
			if(!p) p=1,len=0;
			else len=min(len,l[p])+1,p=ch[p][t];
			ans+=dp[f[p]],ans+=(LL)(len-l[f[p]])*sz[p];
		}
		cout<<ans<<endl;
	}
}sam;
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	sam.solve(); 
}

