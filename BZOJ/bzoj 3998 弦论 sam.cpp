#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 1130192;
char s[MXN>>1]; int lens,T,K;
struct SAM{
	int p,q,nq,np,cnt,last,root,l[MXN],sum[MXN],a[MXN],b[MXN],val[MXN],f[MXN],ch[MXN][26];
	SAM(){cnt=0;last=root=++cnt;}
	inline void ins(int x) {
		p=last; last=np=++cnt; l[np]=l[p]+1;val[np]=1;
		while(p&&!ch[p][x]) ch[p][x]=np,p=f[p];
		if(!p) f[np]=1;
		else {
			q=ch[p][x];
			if(l[q]==l[p]+1) f[np]=q;
			else {
				nq=++cnt; l[nq]=l[p]+1;
				memcpy(ch[nq],ch[q],sizeof ch[q]);
				f[nq]=f[q]; f[q]=f[np]=nq;
				while(ch[p][x]==q) ch[p][x]=nq,p=f[p];
			}
		}
	}
	inline void read(){scanf("%s",s+1),lens=strlen(s+1); rd(T),rd(K);}
	inline void build(){rep(i,1,lens) ins(s[i]-'a');}
	inline void rdsort(){
		rep(i,1,cnt) ++b[l[i]];
		rep(i,1,lens) b[i]+=b[i-1];
		per(i,cnt,1) a[b[l[i]]--]=i;
	}
	inline void solve() {
		read();build();rdsort();
		per(i,cnt,1) 
			if(T==1) val[f[a[i]]]+=val[a[i]];
			else val[a[i]]=1;
		val[1]=0;
		per(i,cnt,1) {
			sum[a[i]]=val[a[i]];
			rep(j,0,25) sum[a[i]]+=sum[ch[a[i]][j]];
		}	
	}
	inline void dfs(int x,int K) {
		if(K<=val[x])	return;
		K-=val[x];
		rep(i,0,25) {
			if(ch[x][i]) {
				if(K<=sum[ch[x][i]]) {putchar(i+'a');dfs(ch[x][i],K);return;}
				K-=sum[ch[x][i]];
			}
		}
	}
}sam;
int main()
{
	sam.solve();
	if(K>sam.sum[1]) puts("-1");
	else sam.dfs(sam.root,K);
	return 0;
}

