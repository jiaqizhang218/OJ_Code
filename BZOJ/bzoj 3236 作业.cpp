#include<bits/stdc++.h>
typedef long long LL;
#define lowbit(x) x&(-x)
const int INF = 0x7fffffff;
const int N = 100005;
const int M = 1000005;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int n,m,t[2][N],app[N],num[N],a1[M],a2[M];
struct Q{  
    int l,r,a,b,pos,x;  
    bool operator < (const Q &b) const{  
        if (pos < b.pos) return 1;  
        if (pos > b.pos) return 0;  
        return r < b.r;  
    }  
}q[M];  
  
void Add(int x,int y,int z)  
{  
    for (int j = y; j <= n; j += lowbit(j))  
        t[x][j] += z;  
}  
  
int sum(int y,int x)  
{  
    int ret = 0;  
    for (int j = y; j; j -= lowbit(j))  
        ret += t[x][j];  
    return ret;  
}  
  
int main()  
{  
    cin >> n >> m;  
    for (int i = 1; i <= n; i++) num[i]=read();  
    int p = sqrt(n);  
    for (int i = 1; i <= m; i++) {  
        int l,r,a,b;  
        scanf("%d%d%d%d",&l,&r,&a,&b);  
        int pos = l/p;  
        q[i] = (Q){l,r,a,b,pos,i};  
    }  
      
    sort(q+1,q+m+1);  
    int L,R;  
    L = 1;  
    R = 0;  
    for (int i = 1; i <= m; i++) {  
        if (R < q[i].r)   
            for (int j = R+1; j <= q[i].r; j++) {  
                Add(0,num[j],1);  
                if (!app[num[j]]) Add(1,num[j],1);  
                ++app[num[j]];  
            }  
        if (R > q[i].r)   
            for (int j = R; j > q[i].r; j--) {  
                Add(0,num[j],-1);  
                --app[num[j]];  
                if (!app[num[j]]) Add(1,num[j],-1);  
            }  
        R = q[i].r;  
          
        if (L < q[i].l)  
            for (int j = L; j < q[i].l; j++) {  
                Add(0,num[j],-1);  
                --app[num[j]];  
                if (!app[num[j]]) Add(1,num[j],-1);  
            }  
        if (L > q[i].l)   
            for (int j = L-1; j >= q[i].l; j--) {  
                Add(0,num[j],1);  
                if (!app[num[j]]) Add(1,num[j],1);  
                ++app[num[j]];  
            }  
        L = q[i].l;  
          
        a1[q[i].x] = sum(q[i].b,0) - sum(q[i].a-1,0);  
        a2[q[i].x] = sum(q[i].b,1) - sum(q[i].a-1,1);  
    }  
      
    for (int i = 1; i <= m; i++) printf("%d %d\n",a1[i],a2[i]);  
    return 0;  
}  
