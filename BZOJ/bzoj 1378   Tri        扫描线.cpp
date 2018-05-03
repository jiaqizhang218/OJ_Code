#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 2005000
using namespace std;
struct tri{int x,y,m;}a[2005];
int b[N],c[N],e[N];
int n,m,l,r,d,cnt,ans;
bool cmp(tri x,tri y){
    return x.x<y.x;
}
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
    	a[i].x=read(),a[i].y=read(),a[i].m=read();
        b[++cnt]=a[i].y;
        b[++cnt]=a[i].y+a[i].m;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i!=j)
                if (a[i].x<=a[j].x&&a[i].x+a[i].m>=a[j].x){
                    int y=a[i].y+(a[i].x+a[i].m-a[j].x);
                    if (y>=a[j].y&&y<=a[j].y+a[j].m) b[++cnt]=y;
                }
    sort(b+1,b+cnt+1);
    sort(a+1,a+n+1,cmp);
    m=1;
    for (int i=2;i<=cnt;i++)
        if (b[i]!=b[i-1])
            b[++m]=b[i];
    for (int i=1;i<=m;i++){
        l=r=-1e9;
        for (int j=1;j<=n;j++){
            d=a[j].m-(b[i]-a[j].y);
            if (d<0||d>a[j].m) continue;
            if (a[j].x>r){
                c[i]+=r-l;
                r=a[j].x+d;
                l=a[j].x;
            }
            else if (a[j].x+d>r)
                r=a[j].x+d;
        }
        c[i]+=r-l;
        l=r=-1e9;
        for (int j=1;j<=n;j++){
            d=a[j].m-(b[i]-a[j].y);
            if (d<0||d>=a[j].m) continue;
            if (a[j].x>r){
                e[i]+=r-l;
                r=a[j].x+d;
                l=a[j].x;
            }
            else if (a[j].x+d>r)
                r=a[j].x+d;
        }
        e[i]+=r-l;
    }
    for (int i=1;i<m;i++)
        ans+=(b[i+1]-b[i])*(c[i]+e[i+1]);
    printf("%d.%d",ans/2,(ans&1)?5:0);
}
