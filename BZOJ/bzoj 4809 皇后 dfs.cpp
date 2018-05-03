#include<cstdio>  
#include<cstring>  
const int Q=18;  
int n,a[Q][Q],ans=0;  
bool r[Q],x1[Q*2],x2[Q*2];  
void dfs(int x)  
{  
    if(x==n+1)  
    {  
        ans++;  
        return;  
    }  
    for(int i=1;i<=n;i++)  
    if(a[x][i]==0 && r[i]==false && x1[x-i+n]==false && x2[x+i]==false)  
    {  
        r[i]=true;x1[x-i+n]=true;x2[x+i]=true;  
        dfs(x+1);  
        r[i]=false;x1[x-i+n]=false;x2[x+i]=false;  
    }  
}  
int main()  
{  
    memset(r,false,sizeof(r));  
    memset(x1,false,sizeof(x1));  
    memset(x2,false,sizeof(x2));  
    scanf("%d",&n);  
    for(int i=1;i<=n;i++)  
    for(int j=1;j<=n;j++)  
    scanf("%d",&a[i][j]);  
    dfs(1);  
    printf("%d",ans);  
}  
