#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const int maxn=100010,maxb=320;  
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
int n,c,m,sum[maxb][maxn],f[maxb][maxb],a[maxn],sz,cnt,bel[maxn],l[maxn],r[maxn],tsum[maxn],ans,tmp[maxn];  
void work(){  
    int x,y,L,R;scanf("%d%d",&x,&y);  
    x=(x+ans)%n+1,y=(y+ans)%n+1,ans=0;  
    if (x>y) swap(x,y);   
    L=bel[x],R=bel[y];  
    if (L==R){  
        for (int i=x;i<=y;i++) tsum[a[i]]=0;  
        for (int i=x;i<=y;i++)  
            if ((++tsum[a[i]])!=1)  
                ans+=(tsum[a[i]]&1)?-1:1;  
    }  
    else{  
        ans=f[L+1][R-1];  
        for (int i=x;i<=r[L];i++) tsum[a[i]]=sum[R-1][a[i]]-sum[L][a[i]];  
        for (int i=l[R];i<=y;i++) tsum[a[i]]=sum[R-1][a[i]]-sum[L][a[i]];  
        for (int i=x;i<=r[L];i++)  
            if (++tsum[a[i]]!=1)  
                ans+=(tsum[a[i]]&1)?-1:1;  
        for (int i=l[R];i<=y;i++)  
            if (++tsum[a[i]]!=1)  
                ans+=(tsum[a[i]]&1)?-1:1;  
    }  
    printf("%d\n",ans);  
} 
int main()
{
	n = read() , c = read() , m = read();
	sz = sqrt(n) , cnt = n/sz + (n%sz!=0);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);  
    for (int i=1;i<=n;i++) bel[i]=(i-1)/sz+1;  
    for (int i=1;i<=n;i++){r[bel[i]]=i;if (!l[bel[i]]) l[bel[i]]=i;} 
    for (int i=1;i<=cnt;i++){  
        for (int j=1;j<=c;j++) sum[i][j]=sum[i-1][j];  
        for (int j=l[i];j<=r[i];j++) sum[i][a[j]]++;  
    } 
	 for (int i=1;i<=cnt;i++){  
        for (int j=1;j<=c;j++) tsum[j]=0;int tmp=0;  
        for (int j=i;j<=cnt;j++){  
            for (int k=l[j];k<=r[j];k++)  
                if (tsum[a[k]]++) tmp+=(tsum[a[k]]&1)?-1:1;  
            f[i][j]=tmp;  
        }  
    }
	for(int i = 1 ; i <= m ; i++)	work();
	return 0;
}
