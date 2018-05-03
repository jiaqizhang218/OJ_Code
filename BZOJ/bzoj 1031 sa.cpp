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
/*
const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc() //*/
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
const int MXN = 7e5+5;
char s[MXN],ans[MXN];
int n,sa[MXN],t[MXN],t2[MXN],rk[MXN],c[MXN];
inline void build_sa(char str[],int m) {
	int i, *x = t , *y = t2;
	for(i=0;i<m;++i) c[i]=0;
	for(i=0;i<n;++i) c[x[i]=str[i]]++;
	for(i=1;i<m;++i) c[i]+=c[i-1];
	for(i=n-1;i>=0;--i)sa[--c[x[i]]]=i;
	
	for(int k=1;k<=n;k<<=1) {
		int p=0;
		for(i=n-k;i<n;++i) y[p++]=i;
		for(i=0;i<n;++i) if(sa[i]>=k) y[p++]=sa[i]-k;
		
		for(i=0;i<m;++i) c[i]=0;
		for(i=0;i<n;++i) c[x[y[i]]]++;
		for(i=0;i<m;++i) c[i]+=c[i-1];
		for(i=n-1;i>=0;--i) sa[--c[x[y[i]]]]=y[i];
		
		swap(x,y);
		p=1;x[sa[0]]=0;
		#define cmpy (y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k])
		for(i=1;i<n;++i) 
			x[sa[i]]=cmpy?p-1:p++;
		if(p>=n) break;
		m=p;
	}
}
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++) s[i+n]=s[i];
	n<<=1;
	s[n++]=0;
	build_sa(s,257);
	for(int i=0;i<n;++i) rk[sa[i]]=i;
	for(int i=0;i<n/2;++i) ans[rk[i]]=s[i+n/2-1];
	for(int i=0;i<n;++i) if(ans[i]>0) printf("%c",ans[i]);
	return 0;	
#ifdef iloi
	debug("\nMy Time: %.4lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}
