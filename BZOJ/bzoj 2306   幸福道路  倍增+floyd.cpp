#include<iostream>  
#include<cstdio>  
#include<cstring>  
#define N 105  
using namespace std;  
  
int n,m; double a[N],f[N][N],g[N][N];  
int main(){  
    scanf("%d%d",&n,&m); int i,j,k;  
    for (i=1; i<=n; i++) scanf("%lf",&a[i]);  
    int sta; scanf("%d",&sta);  
    for (i=1; i<=n; i++)  
        for (j=1; j<=n; j++) if (i!=j) f[i][j]=-1e100;  
    int x,y; double p,ans=0; scanf("%lf",&p);  
    while (m--){  
        scanf("%d%d",&x,&y); f[x][y]=a[y]*p;  
    }  
    for (; p>1e-10; p*=p){  
        for (i=1; i<=n; i++) for (j=1; j<=n; j++) g[i][j]=-1e100;  
        for (k=1; k<=n; k++)  
            for (i=1; i<=n; i++)  
                for (j=1; j<=n; j++)  
                    g[i][j]=max(g[i][j],f[i][k]+f[k][j]*p);  
        memcpy(f,g,sizeof(g));  
    }  
    for (i=1; i<=n; i++) ans=max(ans,f[sta][i]);  
    printf("%.1f\n",ans+a[sta]);  
    return 0;  
}  
