#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<algorithm>  
#define LL long long  
using namespace std;  
const int maxn=1000010;  
int n,m,mn,pos,root=0,cnt=0;  
LL ans=1e16,a[maxn],ans2;  
  
struct Nodes{  
    int c[2],fa,size;  
    LL s,val;  
};  
  
struct splay_tree{  
    Nodes t[maxn];   
    void push_up(int x){  
        t[x].size=t[t[x].c[0]].size+t[t[x].c[1]].size+1;  
        t[x].s=t[t[x].c[0]].s+t[t[x].c[1]].s+t[x].val;  
    }  
    void rotate(int p,int x){  
        int mark= p==t[x].c[1];  
        int y=t[p].c[mark^1],z=t[x].fa;  
        if (t[z].c[0]==x) t[z].c[0]=p;  
        if (t[z].c[1]==x) t[z].c[1]=p;  
        if (y) t[y].fa=x;t[x].c[mark]=y;  
        t[x].fa=p; t[p].fa=z; t[p].c[mark^1]=x;  
        push_up(x);  
    }  
    void splay(int p,int k){  
        while (t[p].fa!=k){  
            int x=t[p].fa,y=t[x].fa;  
            if (y==k) rotate(p,x);  
            else if (p==t[x].c[0]^x==t[y].c[0]) rotate(p,x),rotate(p,y);  
            else rotate(x,y),rotate(p,x);  
        } push_up(p);  
        if (!k) root=p; return;  
    }  
    void new_splay(int v,int f){  
        t[++cnt].fa=f; t[cnt].val=v;  
        t[cnt].size=1; t[cnt].s=v;  
        if (f) t[f].c[t[f].val>v]=cnt;  
    }  
    void ins(int p,LL v){  
        if(!p){new_splay(v,0),splay(cnt,0);return;}  
        int fat=p;  
        while (p){  
            fat=p;  
            if (t[p].val>v) p=t[p].c[1];  
            else p=t[p].c[0];  
        }  
        new_splay(v,fat);  
        splay(cnt,0);  
    }  
    void del(int p){  
        splay(p,0); int tmp=t[p].c[0];  
        t[t[p].c[0]].fa=0; t[t[p].c[1]].fa=0;  
        if (!t[p].c[1]){root=t[p].c[0];return;}  
        if (!t[p].c[0]){root=t[p].c[1];return;}  
        while (t[tmp].c[1]) tmp=t[tmp].c[1];  
        splay(tmp,0);  
        t[t[p].c[1]].fa=tmp;  
        t[tmp].c[1]=t[p].c[1];  
        push_up(tmp);  
    }  
    int findkth(int p,int k){  
        if (t[t[p].c[0]].size+1==k) return p;  
        if (t[t[p].c[0]].size+1<k)  
            return findkth(t[p].c[1],k-t[t[p].c[0]].size-1);  
        else return findkth(t[p].c[0],k);  
    }  
    void getans(int i){  
        splay(findkth(root,mn),0);  
        LL mid=t[root].val; int tmp=root;  
        LL ret=mid*t[t[tmp].c[0]].size-t[t[tmp].c[0]].s;  
        ret=ret+t[t[tmp].c[1]].s-mid*t[t[tmp].c[1]].size;  
        ret=-ret;  
        if (ret<ans){ans=ret;pos=i;ans2=mid;}  
    }  
}s;  
  
int main(){  
    scanf("%d%d",&n,&m); mn=(m+1)/2;  
    for (int i=1;i<=n;++i) scanf("%lld",&a[i]);  
    for (int i=1;i<=m;++i) s.ins(root,a[i]);  
    s.getans(1);  
    for (int i=m+1;i<=n;++i){  
        s.del(i-m); s.ins(root,a[i]);  
        s.getans(i-m+1);  
    }  
    printf("%lld\n",ans);  
//    for (int i=pos;i<=pos+m-1;++i) a[i]=ans2;  
//    for (int i=1;i<=n;++i) printf("%lld\n",a[i]);  
} 
