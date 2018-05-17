#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(register int i=(j);i<=(k);++i)
#define per(i,j,k) for(register int i=(j);i>=(k);--i)
#define dbg(x) cerr<<#x<<" = "<<x<<endl
const int MXN = 1200005;
char str[MXN>>1];
int rt[MXN],fa[MXN][21],Q,n,m,pos[MXN>>1];
struct tree {
	struct fc {
		int sum,id;
		fc operator * (const fc &rhs) const {
			if(sum>rhs.sum) return *this;
			if(rhs.sum>sum) return rhs;
			if(id<rhs.id) return *this; else return rhs;
		}
	}gery;	
	struct Tree {
		int ls,rs;fc c;
	}tr[MXN*20];
	int cnt;
	void Ins(int &k,int l,int r,int p) {
		if(!k) k=++cnt;
		if(l==r) {
			tr[k].c.sum++; tr[k].c.id=l; return;
		}
		int mid=l+r>>1;
		if(p<=mid) Ins(tr[k].ls,l,mid,p);
		else Ins(tr[k].rs,mid+1,r,p);
		tr[k].c=tr[tr[k].ls].c * tr[tr[k].rs].c;
	}
	int merge(int x,int y,int l=1,int r=m) {
		if(!(x*y)) return x|y;
//		dbg(tr[187].rs),dbg(tr[181].rs);
//		fprintf(stderr,"x = %d , y = %d , l = %d , r = %d\n",x,y,l,r);
		int z=++cnt;
		if(l==r) {
			tr[z].c=(fc){tr[x].c.sum+tr[y].c.sum,l};
			return z;
		}
		int mid=l+r>>1;
		tr[z].ls=merge(tr[x].ls,tr[y].ls,l,mid);
		tr[z].rs=merge(tr[x].rs,tr[y].rs,mid+1,r);
		tr[z].c=tr[tr[z].ls].c * tr[tr[z].rs].c;
		return z;
	}
	fc query(int k,int l,int r,int L,int R) {
		if(!k) return (fc){0,0};
		if(l<=L&&R<=r) return tr[k].c;
		int mid=L+R>>1;
		if(r<=mid) return query(tr[k].ls,l,r,L,mid);
		else if(l>mid) return query(tr[k].rs,l,r,mid+1,R);
		else return (query(tr[k].ls,l,r,L,mid) * query(tr[k].rs,l,r,mid+1,R));
	}
}T;

struct SAM {
	int p,np,q,nq,root,cnt,last,ch[MXN][27],fail[MXN],l[MXN],a[MXN],b[MXN];
	SAM(){cnt=0;root=last=++cnt;}
	inline void extend(int x) {
		p=last; np=last=++cnt; l[np]=l[p]+1;
		while(p&&!ch[p][x]) ch[p][x]=np,p=fail[p];
		if(!p) fail[np]=root;
		else {
			q=ch[p][x];
			if(l[q]==l[p]+1) fail[np]=q;
			else {
				nq=++cnt; fail[nq]=fail[q];
				memcpy(ch[nq],ch[q],sizeof ch[q]);
				fail[np]=fail[q]=nq; l[nq]=l[p]+1;
				while(ch[p][x]==q&&p) ch[p][x]=nq,p=fail[p];
			}
		}
	}
	inline void rdsort() {
		for(int i=1;i<=cnt;++i) b[l[i]]++;
		for(int i=1;i<=cnt;++i) b[i]+=b[i-1];
		for(int i=1;i<=cnt;++i) a[b[l[i]]--]=i;
	}
	inline void solve() {
		rdsort();
//		rep(i,1,T.cnt) fprintf(stderr,"tr[%d].ls = %d , tr[%d].rs = %d\n",i,T.tr[i].ls,i,T.tr[i].rs);
		per(i,cnt,1) {
			int x=a[i];
			if(fail[x]) rt[fail[x]]=T.merge(rt[fail[x]],rt[x]);
		}
		per(i,cnt,1) {
			fa[i][0]=fail[i];
		}
		rep(j,1,20) rep(i,1,cnt) {
			fa[i][j]=fa[fa[i][j-1]][j-1];
		}
	}
	inline int get(int x,int y) {
		int p=pos[y],len=y-x+1;
		per(i,20,0) {
			if(l[fa[p][i]]>=len) p=fa[p][i];
		}
		return p;
	}		
}sam;


int main() {
#ifdef iloi
	freopen("test.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin>>str+1;
	for(int i=1,len=strlen(str+1);i<=len;++i) sam.extend(str[i]-'a'),pos[i]=sam.last;
	sam.extend(26); cin>>m;
	for(int j=1;j<=m;++j) {
		cin>>str+1;
		for(int i=1,len=strlen(str+1);i<=len;++i) sam.extend(str[i]-'a'),T.Ins(rt[sam.last],1,m,j);
		sam.extend(26);
	} cin>>Q; sam.solve();
	while(Q--) {
		int l,r,L,R;
		cin>>l>>r>>L>>R;
		int nd = sam.get(L,R);// dbg(nd);
		T.gery = T.query(rt[nd],l,r,1,m);
		if(T.gery.sum==0) cout<<l<<" 0"<<endl;
		else cout<<T.gery.id<<" "<<T.gery.sum<<endl;
	}
}
