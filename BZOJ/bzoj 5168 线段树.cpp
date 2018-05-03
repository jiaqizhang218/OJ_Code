#include <bits/stdc++.h>

using namespace std;
const int N=10000000+1;
const int M=1000+10;
int Cover[N<<2];
int n,m;
int ans;
int a[M],b[M];
const int _L = 1e6+5;
char ibuf[_L],*ih=ibuf+_L;
inline char gc(){return (ih==ibuf+_L?fread(ibuf,1,_L,stdin),ih=ibuf:0),*ih++;}
#define  getchar() gc() //*/
template <typename T>
inline void rd(T &x)
{
    x = 0; int f = 1; char CH = getchar();
    while(!isdigit(CH)) {if(CH=='-')f=0;CH=getchar();}
    while(isdigit(CH)) {x=((x+(x<<2))<<1)+(CH-48);CH=getchar();}
    x=(f==1)?x:-x;  return;
}

#define lc(o) (o<<1)
#define rc(o) ((o<<1)|1)
void pushup(int o){
  Cover[o]=(Cover[lc(o)]&Cover[rc(o)]);
}
int beCovered=1;
void insert(int o,int l,int r,int L,int R){
  if(Cover[o]) return ;
  if(l<=L&&R<=r&&(!Cover[o])){
    Cover[o]=1;
    beCovered=0;
    return ;
  }
  int mid=(L+R)>>1;
  if(l<=mid)
    insert(lc(o),l,r,L,mid);
  if(r>mid)
    insert(rc(o),l,r,mid+1,R);

  pushup(o);
}
int main(){
  rd(n),rd(m);
  for(int i=0;i<m;i++)	rd(a[i]),rd(b[i]);

  for(int i=m-1;i>=0;i--){
    beCovered=1;
    insert(1,a[i],b[i],1,n);
    if(!beCovered) ans++;
  }
  cout<<ans<<endl;

  return 0;
}
