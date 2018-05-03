#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rpg(i,x) for(register int i=fir[x];i;i=e[i].nxt)
#define ull unsigned long long
#define fi first
#define se second
#define pb push_back
#define bin(i) (1<<i)
#define cls(x,y) memset(x,y,sizeof x)
typedef pair<int,int> pa;
typedef long long LL;
const int INF = 0x7fffffff;
const int oo = 0x3f3f3f3f;
/*const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc() //*/
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 4e5 + 5;
int dig[MXN],sum[MXN];
string s[MXN<<1];
int n,k,len[MXN];
struct SAM {
	int p,nq,np,q,last,rt,f[MXN],cnt,ch[MXN][30],l[MXN],b[MXN],c[MXN],vis[MXN]; LL ans[MXN];int tmpt=0,tmp[MXN];
	 SAM(){rt=last=cnt=1;}
	 inline void ins(int x) {
	 	p=last; np=last=++cnt; l[np]=l[p]+1;
	 	while(!ch[p][x]&&p) ch[p][x]=np,p=f[p];
	 	if(!p) f[np]=rt;
	 	else {
	 		q=ch[p][x];
	 		if(l[p]+1==l[q]) f[np]=q;
	 		else {
	 			nq=++cnt; l[nq]=l[p]+1;
	 			memcpy(ch[nq],ch[q],sizeof ch[q]);
	 			f[nq]=f[q],f[np]=f[q]=nq;
	 			while(ch[p][x]==q) ch[p][x]=nq,p=f[p];
	 		}
	 	}
	 }
	 inline void topo() {
	 	queue<int> q; 
	 	rep(i,1,cnt) if(!dig[i]) q.push(i),tmp[++tmpt]=i;
	 	while(!q.empty()) {
	 		int x=q.front(); q.pop();
	 		if(!--dig[f[x]]) 
	 			q.push(f[x]),tmp[++tmpt]=f[x];
	 	}
	 	per(i,tmpt,1) sum[tmp[i]]+=sum[f[tmp[i]]];
	 }
	 inline void solve() {
	 	rep(i,1,n) {
	 		p=1;
	 		rep(j,0,len[i]-1) {
	 			p=ch[p][s[i][j]-'a'];
	 			int x=p;
	 			while(x&&vis[x]!=i) {
	 				c[x]++,vis[x]=i,x=f[x];
	 			}
	 		}
	 	}
	 	rep(i,1,cnt) dig[f[i]]++,sum[i]=(c[i]>=k)?(l[i]-l[f[i]]):0;
	 	topo();
	 	rep(i,1,n) {
	 		p=1;
	 		rep(j,0,len[i]-1) {
	 			p=ch[p][s[i][j]-'a'];
	 			ans[i]+=sum[p];
	 		}
	 		printf("%lld\n",ans[i]);
	 	}
	 }
	 	
}sam;
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(n),rd(k);
	rep(i,1,n) {
		cin>>s[i]; len[i]=s[i].size();
		sam.last=sam.rt; 
		rep(j,0,len[i]-1) sam.ins(s[i][j]-'a');
	}
	sam.solve();
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

