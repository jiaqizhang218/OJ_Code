#include<bits/stdc++.h>  
#define N 200003  
using namespace std;  
int fa[N],sum[N],n,m;  
int find(int x)  
{  
    if (x==fa[x]) return x;  
    int t=find(fa[x]);  
    sum[x]+=sum[fa[x]];  
    fa[x]=t;  
    return fa[x];  
}  
int main()  
{  
    while(true) 
	{  
        scanf("%d%d",&n,&m);  
        if (n==0&&m==0) break;  
        for (int i=1;i<=n;i++) fa[i]=i,sum[i]=0;  
        for (int i=1;i<=m;i++) 
		{  
            char s[10]; int x,y; scanf("%s%d%d",s,&x,&y);  
            if (s[0]=='!') 
			{  
                int k; scanf("%d",&k);  
                int r1=find(x); int r2=find(y);  
                fa[r2]=r1;  
                sum[r2]=sum[x]-sum[y]-k;  
            }  
            else 
			{  
                int r1=find(x); int r2=find(y);  
                if (r1!=r2) printf("UNKNOWN\n");  
                else printf("%d\n",sum[x]-sum[y]);  
            }  
        }  
    }  
}  
