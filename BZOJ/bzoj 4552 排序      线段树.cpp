#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int MAXN = 100010;
int n,m,a[MAXN],L[MAXN],R[MAXN],s[MAXN<<2],ch[MAXN<<2],c[MAXN];
int p;
inline void ud(int x)
{
	s[x]=s[x<<1]+s[x<<1|1];
}
inline void toch(int x,int y,int z,int cv) {
	ch[x]=cv;
	s[x]=(z-y+1)*cv;
}
inline void pd(int x,int y,int z) {
	if(ch[x]!=-1) {
		int mid=y+z>>1;
		toch(x<<1,y,mid,ch[x]);
		toch(x<<1|1,mid+1,z,ch[x]);
		ch[x]=-1;
	}
}
inline void build(int x,int y,int z,int l) {
	ch[x]=-1;
	if(y==z) {
		if(a[y]<=l) {
			s[x]=0;
		}
		else {
			s[x]=1;
		}
		return;
	}
	int mid=y+z>>1;
	build(x<<1,y,mid,l);
	build(x<<1|1,mid+1,z,l);
	ud(x);
}
inline int ask(int x,int y,int z,int l,int r) {
	if(y==l&&z==r) {
		return s[x];
	}
	pd(x,y,z);
	int mid=y+z>>1;
	if(r<=mid) {
		return ask(x<<1,y,mid,l,r);
	}
	else if(l>mid) {
		return ask(x<<1|1,mid+1,z,l,r);	
	}
	else {
		return ask(x<<1,y,mid,l,mid)+ask(x<<1|1,mid+1,z,mid+1,r);	               	
	}     	
}
inline void change(int x,int y,int z,int l,int r,int cv) {
	if(l>r)	return;
	if(y==l&&z==r) {
		toch(x,y,z,cv);
		return;
	}	
	pd(x,y,z);
	int mid=y+z>>1;
	if(r<=mid)	{
		change(x<<1,y,mid,l,r,cv);
	}	else if(l>mid) {
		change(x<<1|1,mid+1,z,l,r,cv);
	}	else {
		change(x<<1,y,mid,l,mid,cv);
		change(x<<1|1,mid+1,z,mid+1,r,cv);
	}
	ud(x);
}
bool OK(int x) {
	int i;
	build(1,1,n,x);
	for(i=1;i<=m;i++) {
		int t=ask(1,1,n,L[i],R[i]);
		if(!c[i]) {
			change(1,1,n,L[i],R[i]-t,0);
			change(1,1,n,R[i]-t+1,R[i],1);
		}else {
			change(1,1,n,L[i],L[i]+t-1,1);
			change(1,1,n,L[i]+t,R[i],0);
		}
	}
	return !ask(1,1,n,p,p);
}
int main()                                              
{
	int i;
	n=read(),m=read();
	for(i=1;i<=n;i++) {
		a[i]=read();
	}
	for(i=1;i<=m;i++) {
		c[i]=read();L[i]=read();R[i]=read();
	}
	p=read();
	int l=1,r=n;
	int ans;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(OK(mid))	ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans;
	return 0;
}

/*
/*
This is the code for bzoj4552
(http://www.lydsy.com:808/JudgeOnline/problem.php?id=4552)
The problem is maintaing a permutation of 1~n,
supporting range sorting (increasing or decreasing),
query the value of **one** position **after all sortings**.
This problem can also be solved offline by using binary
search and naive segment tree which is O(nlog^2n).
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define SZ 666666 //length of sequence
#define SG 9999999 //number of segment tree nodes
//merge-split seg begin
int ss[SG],sn=0,ch[SG][2],s[SG];
#define er(x) ss[++sn]=x //erase x for further usage
inline int alc_() //allocate a clean new node
{
    int x=ss[sn--];
    ch[x][0]=ch[x][1]=s[x]=0;
    return x;
}
#define alc alc_()
//make a seg with only node p
void build(int& x,int l,int r,int p)
{
    x=alc; s[x]=1;
    if(l==r) return;
    int m=(l+r)>>1;
    if(p<=m) build(ch[x][0],l,m,p);
    else build(ch[x][1],m+1,r,p);
}
//merge seg t1&t2
int merge(int t1,int t2)
{
    if(t1&&t2);else return t1^t2;
    ch[t1][0]=merge(ch[t1][0],ch[t2][0]);
    ch[t1][1]=merge(ch[t1][1],ch[t2][1]);
    s[t1]+=s[t2]; er(t2); return t1;
}
//split t1 to t1&t2 so that s[t1]=k
void split(int t1,int&t2,int k)
{
    t2=alc;
    int ls=s[ch[t1][0]];
    if(k>ls) split(ch[t1][1],ch[t2][1],k-ls);
    else swap(ch[t1][1],ch[t2][1]);
    if(k<ls) split(ch[t1][0],ch[t2][0],k);
    s[t2]=s[t1]-k; s[t1]=k;
}
//query k-th
int ask(int x,int l,int r,int k)
{
    if(l==r) return l;
    int ls=s[ch[x][0]];
    int m=(l+r)>>1;
    if(k>ls) return ask(ch[x][1],m+1,r,k-ls);
    return ask(ch[x][0],l,m,k);
}
//seg end
bool typ[SZ]; //0 inc   1 dec
//i-th pos store a substr which l=i (if exists)
//rots[] stores the root, rs[] stores the right border
int rots[SZ],rs[SZ];
set<int> sol; //maintain the left borders of ordered substrs
int n,q,a[SZ];
//split x so that rs[x]=s
void sp(int x,int s)
{
    if(s>=rs[x]||s<x) return;
    if(!typ[x]) split(rots[x],rots[s+1],s-x+1);
    else
    {
        rots[s+1]=rots[x];
        split(rots[s+1],rots[x],rs[x]-s);
    }
    rs[s+1]=rs[x]; rs[x]=s;
    sol.insert(s+1); typ[s+1]=typ[x];
}
//merge adjacent substr a&b to a (typ[a] should be edited manually)
void mg(int a,int b)
{
    if(a==b) return;
    sol.erase(b);
    rots[a]=merge(rots[a],rots[b]);
    rs[a]=rs[b];
}
//query the value of k in substr begin with x
int qpos(int x,int k)
{
    k-=x-1;
    if(!typ[x]) return ask(rots[x],1,n,k);
    else return ask(rots[x],1,n,rs[x]-x+2-k);
}
int main()
{
    for(int i=SG-1;i>=1;i--) ss[++sn]=i; //initialize memory pool
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i); //original sequence
        build(rots[i],1,n,a[i]);
        sol.insert(i); rs[i]=i;
    }
    static int tmp[SZ],tn=0;
    while(q--)
    {
        int o,l,r;
        scanf("%d%d%d",&o,&l,&r);
        //sort range [l,r]
		//o: 0 inc  1 dec
        //split out l&r
        set<int>::iterator w=sol.upper_bound(l); sp(*(--w),l-1);
        w=sol.upper_bound(r); sp(*(--w),r);
        //get the range
        set<int>::iterator p1=sol.lower_bound(l),
        p2=sol.upper_bound(r); --p2;
        int tg=*p1;
        if(p1!=p2) //merge them
        {
        	for(set<int>::iterator i=++p1;;++i)
        	{tmp[++tn]=*i; if(i==p2) break;}
        	for(int i=1;i<=tn;i++) mg(tg,tmp[i]); tn=0;
        }
        typ[tg]=o;
    }
    int r; scanf("%d",&r); //query the r-th position of the sequence
    set<int>::iterator w=sol.upper_bound(r);
    int x=*(--w); printf("%d\n",qpos(x,r));
}

*/
