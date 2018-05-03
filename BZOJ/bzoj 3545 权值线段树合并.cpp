#include<iostream>  
#include<cstdlib>  
#include<cstdio>  
#include<cstring>  
#include<cmath>  
#include<ctime>  
#include<algorithm>  
#include<iomanip>  
#include<vector>  
#include<stack>  
#include<queue>  
#include<map>  
#include<set>  
#include<bitset>  
using namespace std;  
#define MAXN 500010  
#define MAXM 4000010  
#define ll long long  
#define INF 1000000000  
#define MOD 1000000007  
#define eps 1e-8  
struct edg{  
    int v1;  
    int v2;  
    int v;  
    friend bool operator <(edg x,edg y){  
        return x.v<y.v;  
    };  
};  
struct que{  
    int I;  
    int v;  
    int x;  
    int k;  
    friend bool operator <(que x,que y){  
        return x.v<y.v;  
    }  
};  
edg e[MAXN];  
int f[MAXN];  
int rt[MAXN];  
int son[MAXM][2],siz[MAXM];  
int tot;  
int n,m,Q;  
que q[MAXN];  
int ans[MAXN];  
int fa(int x){  
    return f[x]==x?x:f[x]=fa(f[x]);  
}  
int merge(int x,int y){  
    if(!(x*y)){  
        return x+y;  
    }  
    siz[x]+=siz[y];  
    son[x][0]=merge(son[x][0],son[y][0]);  
    son[x][1]=merge(son[x][1],son[y][1]);  
    return x;  
}  
void change(int &x,int y,int z,int p){  
    if(!x){  
        x=++tot;  
    }  
    siz[x]++;  
    if(y==z){  
        return ;  
    }  
    int mid=y+z>>1;  
    if(p<=mid){  
        change(son[x][0],y,mid,p);  
    }else{  
        change(son[x][1],mid+1,z,p);  
    }  
}  
int ask(int x,int y,int z,int k){  
    if(siz[x]<k){  
        return -1;  
    }  
    if(y==z){  
        return y;  
    }  
    int t=siz[son[x][1]];  
    int mid=y+z>>1;  
    if(k<=t){  
        return ask(son[x][1],mid+1,z,k);  
    }else{  
        return ask(son[x][0],y,mid,k-t);  
    }  
}  
int main(){  
    int i,x,y;  
    scanf("%d%d%d",&n,&m,&Q);  
    for(i=1;i<=n;i++){  
        f[i]=i;  
        scanf("%d",&x);  
        change(rt[i],1,INF,x);  
    }  
    for(i=1;i<=m;i++){  
        scanf("%d%d%d",&e[i].v1,&e[i].v2,&e[i].v);  
    }  
    sort(e+1,e+m+1);  
    for(i=1;i<=Q;i++){  
        q[i].I=i;  
        scanf("%d%d%d",&q[i].x,&q[i].v,&q[i].k);  
    }  
    sort(q+1,q+Q+1);  
    int wzh=1;  
    for(i=1;i<=Q;i++){  
        while(e[wzh].v<=q[i].v&&wzh<=m){  
            x=e[wzh].v1,y=e[wzh].v2;  
            x=fa(x);  
            y=fa(y);  
            wzh++;  
            if(x==y){  
                continue ;  
            }  
            rt[x]=merge(rt[x],rt[y]);  
            f[fa(y)]=fa(x);  
        }  
        ans[q[i].I]=ask(rt[fa(q[i].x)],1,INF,q[i].k);  
    }  
    for(i=1;i<=Q;i++){  
        printf("%d\n",ans[i]);  
    }  
    return 0;  
}  
