#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<cmath>  
#include<algorithm>  
using namespace std;  
const int N=510;  
char ch;  
bool f[N*N];  
int n,m,map[510][510],point[N*N],next[N*N*10],tot,dis[N*N],l[N*N*10];  
int xi[4]={-1,0,0,1},yi[4]={0,-1,1,0};  
struct S{int st,en,va;}aa[N*N*10];  
inline void add(int x,int  y,int z){  
    tot+=1;next[tot]=point[x];point[x]=tot;  
    aa[tot].st=x;aa[tot].en=y;aa[tot].va=z;  
}  
inline void SPFA(int x){  
    int h,t,u,i;  
    memset(f,1,sizeof(f));  
    memset(dis,127/3,sizeof(dis));  
    h=t=1;l[h]=x;dis[x]=0;  
    while(h<=t){  
        u=l[h]; f[u]=true;  
        for(i=point[u];i;i=next[i])  
          if(dis[aa[i].en]>dis[u]+aa[i].va){  
            dis[aa[i].en]=dis[u]+aa[i].va;  
            if(f[aa[i].en]){  
                f[aa[i].en]=false;  
                l[++t]=aa[i].en;  
            }  
          }  
        h+=1;  
    }  
}  
int main(){  
    while(scanf("%d%d",&n,&m)==2){  
        if(n==m&&n==0) break;  
        int i,j,x1,y1,x2,y2,k;  
        for(i=1;i<=n;++i)  
          for(j=1;j<=m;++j){  
            while(1){  
                scanf("%c",&ch);  
                if(ch=='@'||ch=='#') break;  
            }  
            if(ch=='@') map[i][j]=1;  
            if(ch=='#') map[i][j]=2;  
          }  
        tot=0;  
        memset(point,0,sizeof(point));  
        memset(next,0,sizeof(next));  
        for(i=1;i<=n;++i)  
          for(j=1;j<=m;++j)  
            for(k=0;k<4;++k){  
                int xx=i+xi[k],yy=j+yi[k];  
                if(xx>0&&xx<=n&&yy>0&&yy<=m)  
                  add(m*(i-1)+j,m*(xx-1)+yy,abs(map[i][j]-map[xx][yy]));  
            }  
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);  
        x1+=1;y1+=1;x2+=1;y2+=1;  
        SPFA((x1-1)*m+y1);  
        printf("%d\n",dis[(x2-1)*m+y2]);  
    }  
} 
