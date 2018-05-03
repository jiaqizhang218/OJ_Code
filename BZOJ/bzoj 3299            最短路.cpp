#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<string>  
#include<queue>  
  
using namespace std;  
  
struct node{  
    int x,y;  
    bool f;  
}a[27][2];  
  
struct node1{  
    int x,y;  
    int num;  
};  
  
node S,T;  
int n,m;  
char c[330][330];  
bool vis[330][330];  
queue<node1>q;  
int tox[4]={-1,0,1,0};  
int toy[4]={0,1,0,-1};  
  
int main(){  
    scanf("%d%d\n",&n,&m);  
    for(int i=1; i<=n; i++){  
        for(int j=1; j<=m; j++){  
            vis[i][j]=false;  
            c[i][j]=getchar();  
            if(c[i][j]>='A' && c[i][j]<='Z'){  
                int x=c[i][j]-'A';  
                if(a[x][0].f)a[x][1].x=i,a[x][1].y=j;  
                else a[x][0].x=i,a[x][0].y=j,a[x][0].f=true;  
            }  
            else if(c[i][j]=='@')S.x=i,S.y=j;  
            else if(c[i][j]=='=')T.x=i,T.y=j;  
        }getchar();  
    }  
    vis[S.x][S.y]=1;  
    node1 t;  t.x=S.x;  t.y=S.y;  t.num=0;  q.push(t);  
    while(!q.empty()){  
        t=q.front();  
        q.pop();  
        for(int i=0; i<4; i++){  
            node1 t1=t;  
            t1.x+=tox[i];  
            t1.y+=toy[i];  
            t1.num++;  
            if(t1.x==T.x && t1.y==T.y){  
                printf("%d\n",t1.num);  
                return 0;  
            }  
            if(c[t1.x][t1.y]=='#')continue;  
            if(c[t1.x][t1.y]>='A' & c[t1.x][t1.y]<='Z'){  
                int x=c[t1.x][t1.y]-'A';  
                if(a[x][0].x==t1.x && a[x][0].y==t1.y)t1.x=a[x][1].x,t1.y=a[x][1].y;  
                else t1.x=a[x][0].x,t1.y=a[x][0].y;  
            }  
            if(vis[t1.x][t1.y])continue;  
            	vis[t1.x][t1.y]=1;  
            q.push(t1);  
        }  
    }  
      
    return 0;  
}
