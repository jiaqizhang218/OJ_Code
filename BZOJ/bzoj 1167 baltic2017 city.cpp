#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(register int i=(a),i##_st=(b);i>=i##_st;--i)
#define rvc(i,S) for(register int i=0;i<S.size();++i)
#define fi first
#define se second
#define pb push_back

typedef tuple<int,int,int> pqe;
typedef long long LL;
const int INF = 0x7fffffff;
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
inline bool cmp(pqe A1,pqe A2) {
	int b1,d1,p1,b2,d2,p2;
    tie(b1,d1,p1)=A1;
    tie(b2,d2,p2)=A2;
    if(b1<b2)return true;
    if(b1>b2)return false;
    if(d1>d2)return true;
    if(d1<d2)return false;
    return p1<=p2;
}
const int MXN = 300000 + 5;
int n,m,period,x,y,a[MXN],dest[MXN][2],solved,timp[MXN],vec;
LL k;
vector<int> v[MXN];

priority_queue< pqe , vector<pqe> , function<bool(pqe,pqe) >  > Q(cmp);

int main()
{
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
	rd(n) , rd(k) ;
	rep(i,1,n) {
		rd(a[i]) , Q.push(make_tuple(a[i],i,i));
	}
	rep(i,1,n-1) {
		rd(x),rd(y);
		v[x].pb(y),v[y].pb(x);
	}
	while(Q.size()) {
		pqe P = Q.top(); Q.pop();
		int fru,des,poz;
		tie(fru,des,poz) = P;
		rvc(i,v[poz]) {
			if(des == vec || dest[vec][1] || des == dest[vec][0] ) continue;
			if(dest[vec][0]) dest[vec][1] = des;
			else {dest[0][vec] = des; solved++;}
			if(solved == n) break;
			Q.push(make_tuple(fru-1,des,vec));
		}
		if(solved==n) break;
	}
	
#ifdef iloi
	debug("\nMy Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}

