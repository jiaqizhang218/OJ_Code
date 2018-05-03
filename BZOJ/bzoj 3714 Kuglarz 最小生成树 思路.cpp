#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const double eps = 1e-5;
const int MAXN = 2000 + 5;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
LL ans;
struct edg{  
    int x;  
    int y;  
    int v;  
    friend bool operator <(edg x,edg y){  
        return x.v<y.v;  
    }  
};  
int f[MAXN];  
edg e[MAXN*MAXN];  
int tot;   
int n; 
int fa(int x){  
    return f[x]==x?x:f[x]=fa(f[x]);  
}  
void kruskal(){  
    int i;  
    for(i=0;i<=n;i++){  
        f[i]=i;  
    }  
    sort(e+1,e+tot+1);  
    for(i=1;i<=tot;i++){  
        if(fa(e[i].x)!=fa(e[i].y)){  
            ans+=e[i].v;  
            f[fa(e[i].x)]=fa(e[i].y);  
        }  
    }  
}  
int main(){  
    int i,j;  
    scanf("%d",&n);  
    for(i=0;i<n;i++){  
        for(j=i+1;j<=n;j++){  
            scanf("%d",&e[++tot].v);  
            e[tot].x=i;  
            e[tot].y=j;  
        }  
    }  
    kruskal();  
    printf("%lld\n",ans);  
    return 0;  
}
