#include<bits/stdc++.h>
using namespace std;
const int MXN = 2e5 + 5,Mod = 1e9 + 7,Mul = 27;
struct Hash{
	int base,P;
	int bin[MXN],hash[MXN][26];
	Hash(){}
	void prepare(int _base,int _P,char *s){
		base=_base; P=_P;
		int n=strlen(s+1);
		bin[0]=1;
		for (int i=1;i<=n;++i){
			for(int j=0;j<26;++j)
				hash[i][j]=(1LL*hash[i-1][j]*base%P+(s[i]=='a'+j))%P;
				bin[i]=1LL*bin[i-1]*base%P;
		}
	}
	int get_hash(int l,int r,int i){
		return (hash[r][i]-1LL*hash[l-1][i]*bin[r-l+1]%P+P)%P;
	}
}h;
int n,m,val1[30],val2[30];
char str[MXN];
int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
#endif
	cin>>n>>m;
	cin>>str+1;
	h.prepare(Mul,Mod,str);
	while(m--) {
		int x,y,l; cin>>x>>y>>l;
		for(int i=0;i<26;++i) {
			val1[i]=h.get_hash(x,x+l-1,i),val2[i]=h.get_hash(y,y+l-1,i);
		}
		sort(val1,val1+26);sort(val2,val2+26);
		for(int i=0;i<26;++i) {
			if(val1[i]!=val2[i]) {
				puts("NO"); goto gery;
			}
		}
		puts("YES");
		gery: 250;
	}
}
