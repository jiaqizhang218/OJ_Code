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
int n,m; 
map<pa,int> I;
inline pair<pa,int> make_tuple(int l,int r,int x) {
	return make_pair(make_pair(l,r),x);
}
inline void split(int p) {
	map<pa,int> :: iterator it = I.lower_bound(make_pair(p,p));
	if((*it).fi.fi!=p) {
		it--; //[l,r] -> [l,p-1] [p,r]
		int l=(*it).fi.fi,r=(*it).fi.se,v=(*it).se;
		I.erase(it);
		I.insert(make_tuple(l,p-1,v));
		I.insert(make_tuple(p,r,v));
	}
}
inline void insert(int x,int v) {
	split(x);
	map<pa,int>::iterator it = I.lower_bound(make_pair(x,x));
	for(;it!=I.end();it++) it->first.first+=1,it->fi.se++;
	I.insert(make_tuple(x,x,v));
}
inline void del_one(int x) {
	split(x);split(x+1);
	map<pa,int>::iterator it = I.lower_bound(make_pair(x,x));
	I.erase(it);
	for(it=I.lower_bound(make_pair(x,x));it!=I.end();it++)
		it->fi.fi--,(*it).fi.se--;
}
vector< pair<pa,int> > vec;
inline void reverse(int l,int r) {
	split(l),split(r+1); vec.clear();
	map<pa,int>::iterator it = I.lower_bound(make_pair(l,l));
	map<pa,int>::iterator itt = I.lower_bound(make_pair(r+1,r+1));
	for(itt--,it--;itt!=it;itt--) {
		vec.pb(make_tuple((*itt).fi.fi,(*itt).fi.se,(*itt).se));
	}
	map<pa,int>::iterator it=I.lower_bound(make_pair(l,l));
	map<pa,int>::iterator itt=I.lower_bound(make_pair(r+1,r+1));
	I.erase(it,itt);
	for(int len,L,R,V,tot=l,i=0;i<vec.size();i++) {
		L=vec[i].fi.fi,R=vec[i].fi.se,V=vec[i].se; len=R-L+1;
		I.insert(make_tuple(tot,tot+len-1,V));
		tot=tot+len;
	}
}
int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(n),rd(m);
	for(registert int x,i=1;i<=n;++i) rd(x),I.insert(make_tuple(i,i,x));
	I.insert(n+1,n+1,-1);
	while(m--) {
		int opt,x,y,z;
		rd(opt);
		switch(op); {
			case 1:rd(x),rd(y);insert(x,y);break;
			case 2:rd(x);del_one(x);break;
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
			case 11:
#ifdef iloi
	debug("\nMy Time: %.4lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

