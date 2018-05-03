#include<bits/stdc++.h>
using namespace std;
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define dbg(x) cerr<<#x" = "<<x<<endl
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
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
//#define  getchar() nc()
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
    while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;
    return;
}
const int N = 50000 + 10;
int val[N],n,m,a,b,c,o;
inline int getrand(){
	static int fkd=21323;
	return fkd=fkd*48271LL%2147483647;
}
struct node {
	node* ch[2];
	int rank,val,siz,ge;
	node(int x){val=x;rank=getrand();siz=ge=1;ch[1]=ch[0]=NULL;}
	void tain(){
		siz=1;
		if(ch[0]) siz+=ch[0]->siz;
		if(ch[1]) siz+=ch[1]->siz;
	}
};
inline int s(node* o){return o?o->siz:0;}
node* rt[N<<2];
inline void rotate(node* &o,int d) 
{
	node* k=o->ch[d^1]; o->ch[d^1]=k->ch[d]; k->ch[d]=o;
	o->tain(); k->tain(); o=k;
}
inline void insert(node* &o,int val)
{
	if(o==NULL) {o=new node(val);return;}
	if(val<o->val) {
		insert(o->ch[0],val);
		if(o->ch[0]->rank > o->rank)
			rotate(o,1);
		}
	else {
		insert(o->ch[1],val);
		if(o->ch[1]->rank > o->rank)
			rotate(o,0);
		}
	o->tain();
}
inline void build(int l,int r,int k)
{
	rep(i,l,r) insert(rt[k],val[i]);
}
inline void treeins(int l,int r,int k)
{
	build(l,r,k);
	if(l==r)	return;
	int mid=(l+r)>>1;
	treeins(l,mid,k<<1); treeins(mid+1,r,k<<1|1);
}
inline void del(node* &o,int val)
{
	if(val==o->val) {
		if(o->ch[0]&&o->ch[1]) {
			int d2=(o->ch[0]->rank > o->ch[1]->rank);
			rotate(o,d2); del(o->ch[d2],val);
		}
		else {
			node* u=NULL;
			if(o->ch[0]!=NULL) u=o->ch[0];
			else u=o->ch[1];
			delete o;
			o=u;
		}
	}
	else {
		if(val < o->val) del(o->ch[0],val);
		else del(o->ch[1],val);
	}
	if(o) o->tain();
}
inline int find_rank(node* o,int val)
{
	int ge=0;
	while(o) {
		if(val > o->val) ge+=s(o->ch[0])+1,o=o->ch[1];
		else o=o->ch[0];
	}
	return ge;
}
inline int tree_rank(int l,int r,int k,int val)
{
	if(a<=l&&r<=b) return find_rank(rt[k],val);
	int mid=(l+r)>>1,ret=0;
	if(b<=mid) return tree_rank(l,mid,k<<1,val);
	if(mid<a) return tree_rank(mid+1,r,k<<1|1,val);
	return tree_rank(l,mid,k<<1,val)+tree_rank(mid+1,r,k<<1|1,val);
}
inline int divide_rank(int val)
{
	int l=0,r=100000000;
	while(l<=r) {
		int mid=(l+r)>>1;
		int ans=tree_rank(1,n,1,mid)+1;
		if(ans<=val) l=mid+1;
		else r=mid-1;
	}
	return r;
}
inline int pre(int l,int r,int val)
{
	int tmp=tree_rank(1,n,1,val);
	return divide_rank(tmp);
}
inline int nxt(int l,int r,int val)
{
	int tmp=tree_rank(1,n,1,val+1)+1;
	return divide_rank(tmp);
}
inline void change(int l,int r,int k,int pos,int pre,int now)
{
	del(rt[k],pre); insert(rt[k],now);
	if(l==r) return;
	int mid=(l+r)>>1;
	if(pos<=mid) change(l,mid,k<<1,pos,pre,now);
	else change(mid+1,r,k<<1|1,pos,pre,now);
}
int main()
{
#ifdef	iloi
	freopen("test.txt","r",stdin);
#endif
	rd(n),rd(m);	rep(i,1,n) rd(val[i]);
	treeins(1,n,1);
	while(m--) {
		rd(o);
		switch(o) {
			case 1: rd(a),rd(b),rd(c);
				printf("%d\n",tree_rank(1,n,1,c)+1);break;
			case 2: rd(a),rd(b),rd(c);
				printf("%d\n",divide_rank(c));break;
			case 3: rd(a),rd(b);
                change(1,n,1,a,val[a],b);val[a]=b;break;
            case 4: rd(a),rd(b),rd(c);
            	printf("%d\n",pre(a,b,c));break;
            case 5: rd(a),rd(b),rd(c);
            	printf("%d\n",nxt(a,b,c));break;
            }
        }
}
