#include<bits/stdc++.h>
using namespace std;
const int N=1010;
const int LOGN=11;
int a,b,n,ans=2147483647;
int lg2[N],st[LOGN]={1};
int M[N][N];
int fmi[N][N][LOGN],fmx[N][N][LOGN];
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int main(){
    a=read(),b=read(),n=read();
    for(int i=1;i<=n;i++) lg2[i]=(int)log2(i);
    for(int i=1;i<LOGN;i++) st[i]=st[i-1]<<1;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            M[i][j]=read();
            fmi[i][j][0]=fmx[i][j][0]=M[i][j];
        }
    }
    for(int i=1;i<LOGN;i++){
        for(int j=1;j+st[i-1]<=a;j++){
            for(int k=1;k+st[i-1]<=b;k++){
                fmi[j][k][i]=fmi[j][k][i-1];
                fmi[j][k][i]=min(fmi[j][k][i],fmi[j+st[i-1]][k][i-1]);
                fmi[j][k][i]=min(fmi[j][k][i],fmi[j][k+st[i-1]][i-1]);
                fmi[j][k][i]=min(fmi[j][k][i],fmi[j+st[i-1]][k+st[i-1]][i-1]);
                fmx[j][k][i]=fmx[j][k][i-1];
                fmx[j][k][i]=max(fmx[j][k][i],fmx[j+st[i-1]][k][i-1]);
                fmx[j][k][i]=max(fmx[j][k][i],fmx[j][k+st[i-1]][i-1]);
                fmx[j][k][i]=max(fmx[j][k][i],fmx[j+st[i-1]][k+st[i-1]][i-1]);
            }
        }
    }
    int d=st[lg2[n]];
    for(int i=1;i+n-1<=a;i++){
        for(int j=1;j+n-1<=b;j++){
            int mi=fmi[i][j][lg2[n]],mx=fmx[i][j][lg2[n]];
            mi=min(mi,min(fmi[i+n-d][j][lg2[n]],min(fmi[i][j+n-d][lg2[n]],fmi[i+n-d][j+n-d][lg2[n]])));
            mx=max(mx,max(fmx[i+n-d][j][lg2[n]],max(fmx[i][j+n-d][lg2[n]],fmx[i+n-d][j+n-d][lg2[n]])));
            ans=min(ans,mx-mi);
        }
    }
    printf("%d\n",ans);

    return 0;
}
