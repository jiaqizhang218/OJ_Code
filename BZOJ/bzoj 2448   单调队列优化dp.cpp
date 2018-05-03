#include<cstdio>
#include<iostream>
//https://www.cnblogs.com/beiyuoi/p/5974574.html 
using namespace std;
 
const int N = 2005;
 
int n,t[N];
int f[N][N];
int q1[N],h1,t1;// [i,g]
int q2[N],h2,t2;// (g,j]
 
inline int in(int x=0,char ch=getchar(),int v=1){
    while(ch!='-' && (ch>'9'||ch<'0')) ch=getchar();if(ch=='-') v=-1,ch=getchar();
    while(ch>='0' && ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();return x*v; }
 
int main(){
//  freopen("in.in","r",stdin);
    n=in();
    for(int i=1;i<=n;i++) t[i]=in();
     
    for(int i=n;i;i--){
        f[i][i]=t[i],f[i][i-1]=0;
        h1=h2=1,t1=t2=0;
        q1[++t1]=i;
         
        int g=i;
//      int tmpm=i;
        for(int j=i+1;j<=n;j++){
            //q1 - 加入t[j]
            while(h1<=t1 && f[i][q1[t1]-1]+t[q1[t1]] > f[i][j-1]+t[j]) t1--;
            q1[++t1]=j;
             
            //分割点
            for(;g<j && f[i][g-1] < f[g+1][j];g++){
                //q1 del g
                if(q1[h1] == g) h1++;
                //q2 add g
                while(h2<=t2 && f[q2[t2]+1][j]+t[q2[t2]] > f[g+1][j]+t[g]) t2--;
                q2[++t2]=g;
//              if(f[tmpm][j]+t[tmpm] > f[g+1][j]+t[g]) tmpm=g;
            }
             
            //计算f[i][j]
            f[i][j]=min(f[i][q1[h1]-1]+t[q1[h1]],f[q2[h2]+1][j]+t[q2[h2]]);
//          f[i][j]=min(f[i][j],f[tmpm][j]+t[tmpm]);
        }
//      for(;h2<=t2;h2++) f[i][n]=min(f[i][n],f[q2[h2]+1][n]+t[q2[h2]]);
    }
     
//  for(int i=1;i<=n;i++) for(int j=1;j<=n-i+1;j++) printf("%d%c",f[j][j+i-1]," \n"[j==n-i+1]);
     
    cout<<f[1][n]<<endl;
    return 0;
}
