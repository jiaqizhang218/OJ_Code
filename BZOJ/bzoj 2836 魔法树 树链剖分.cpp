#include<bits/stdc++.h>  
#define ll long long  
using namespace std;  
const int N=150005;  
int n,Ecnt,cnt;  
struct Edge{  
    int next,to;  
}E[N<<1];int head[N];  
struct Tree{  
    int pre,top,tid,deep,sz,son,maxid;  
}tree[N];  
struct Segment{  
    ll mark,sum;  
}seg[N<<2];  
template <typename T>
inline void rd(T &x) {
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}
void add(int u,int v){  
    E[++Ecnt].next=head[u];  
    E[Ecnt].to=v;  
    head[u]=Ecnt;  
}  
void up(int u){  
    seg[u].sum=seg[u<<1].sum+seg[u<<1|1].sum;  
}  
void down(int u,int L,int R){  
    if (u && seg[u].mark){  
        int l=u<<1,r=u<<1|1;  
        int mid=(L+R)>>1;  
        seg[l].mark+=seg[u].mark;  
        seg[r].mark+=seg[u].mark;  
        seg[l].sum+=seg[u].mark*(ll)(mid-L+1);  
        seg[r].sum+=seg[u].mark*(ll)(R-mid);  
        seg[u].mark=0LL;  
    }  
}  
void dfs1(int u,int pre,int depth){  
    tree[u].pre=pre;  
    tree[u].sz=1;  
    tree[u].deep=depth;  
    tree[u].son=0;  
    int maxs=0;  
    for (int i=head[u];i;i=E[i].next){  
        int j=E[i].to;  
        if (j==pre) continue;  
        dfs1(j,u,depth+1);  
        tree[u].sz+=tree[j].sz;  
        if (maxs<tree[j].sz)  
            maxs=tree[j].sz,tree[u].son=j;  
    }  
}  
void dfs2(int u,int ancestor){  
    tree[u].maxid=tree[u].tid=++cnt;  
    tree[u].top=ancestor;  
    if (tree[u].son) dfs2(tree[u].son,ancestor);  
    tree[u].maxid=max(tree[u].maxid,tree[tree[u].son].maxid);  
    for (int i=head[u];i;i=E[i].next){  
        int j=E[i].to;  
        if (j==tree[u].pre || j==tree[u].son) continue;  
        dfs2(j,j);  
        tree[u].maxid=max(tree[u].maxid,tree[j].maxid);  
    }  
}  
void update(int id,int l,int r,int gl,int gr,ll num){  
    down(id,l,r);  
    if (l>=gl && r<=gr){  
        seg[id].mark+=num;  
        seg[id].sum+=(ll)(r-l+1)*num;  
        return;  
    }  
    int mid=(l+r)>>1;  
    if (gl<=mid) update(id<<1,l,mid,gl,gr,num);  
    if (gr>mid) update(id<<1|1,mid+1,r,gl,gr,num);  
    up(id);  
}  
ll query(int id,int l,int r,int gl,int gr){  
    down(id,l,r);  
    if (l>=gl && r<=gr) return seg[id].sum;  
    int mid=(l+r)>>1;  
    ll t=0LL;  
    if (gl<=mid) t+=query(id<<1,l,mid,gl,gr);  
    if (gr>mid) t+=query(id<<1|1,mid+1,r,gl,gr);  
    return t;  
}  
void change(int u,int v,ll d){  
    while (tree[u].top!=tree[v].top){  
        if (tree[tree[u].top].deep<tree[tree[v].top].deep) swap(u,v);  
        update(1,1,n,tree[tree[u].top].tid,tree[u].tid,d);  
        u=tree[tree[u].top].pre;  
    }  
    if (tree[u].deep<tree[v].deep) swap(u,v);  
    update(1,1,n,tree[v].tid,tree[u].tid,d);  
}  
ll querysum(int u){  
    return query(1,1,n,tree[u].tid,tree[u].maxid);  
}  
int main(){
#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
    rd(n);
    int x,y;Ecnt=0;  
    for (int i=1;i<n;i++){  
        rd(x),rd(y); 
        x++,y++;  
        add(x,y),add(y,x);  
    }  
    dfs1(1,-1,0);  
    cnt=0,dfs2(1,1);  
    int m;cin>>m;  
    ll d;char s[10];  
    while (m--){  
        scanf("%s",s);  
        if (s[0]=='A'){  
            rd(x),rd(y),rd(d);  
            x++,y++;  
            change(x,y,d);  
        } else{  
           	rd(x);x++;
            printf("%lld\n",querysum(x));  
        }  
    }  
    return 0;  
} 
