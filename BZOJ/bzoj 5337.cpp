#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define dbg(x) cerr<<#x<<" = "<<x<<endl
char str[10005];
int k,f[10005],g[10005],n,m,num;
char s[10005];
const int Mul = 233 , Mod = 1e9+7;
struct Hash{
	int base,P;
	int bin[10005],hash[10005];
	Hash(){}
	void prepare(int _base,int _P,char *s){
		base=_base;
		P=_P;
		int n=strlen(s+1);
		bin[0]=1;hash[0]=0;
		for (int i=1;i<=n;++i){
			hash[i]=(1LL*hash[i-1]*base%P+s[i])%P;
			bin[i]=1LL*bin[i-1]*base%P;
		}
	}
	int get_hash(int l,int r){
		return (hash[r]-1LL*hash[l-1]*bin[r-l+1]%P+P)%P;
	}
}h;
int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
#endif
	ios::sync_with_stdio(false);
	cin>>k;
	cin>>str+1; n=strlen(str+1);
	h.prepare(Mul,Mod,str);
	dbg(k);
	for(int i=0;i<n;++i) f[i]=1;
	for(int fc=1;fc<=k;++fc) {
		cin>>num; memcpy(g,f,sizeof g);memset(f,0,sizeof f);
		for(int i=1;i<=num;++i) {
			cin>>s+1; m=strlen(s+1);
			int gery=0; for(int j=1;j<=m;++j) gery=(1LL*gery*Mul%Mod+s[j])%Mod;
			for(int j=0;j<=n-m;++j) {
				//debug(" i = %d , h.get_hash(l = %d,r=%d) = %d\n",i,j+1,j+m,h.get_hash(j+1,j+m));
				if(h.get_hash(j+1,j+m)==gery) f[j+m]=(f[j+m]+g[j])%Mod;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i) ans=(ans+f[i])%Mod;
	cout<<ans;
}
