#include<bits/stdc++.h>
using namespace std;
const int M=2e3+7;
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
int n,m,k,s[M][M],cnt,sum,ans;
struct pos{
    int x,y,w;
    bool operator <(const pos& h)const{return w>h.w;}
}q[M*M];
int main(){
    n=read(); m=read(); k=min(4*n,n*m);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) 
    s[i][j]=read(),q[cnt++]=(pos){i,j,s[i][j]};
    nth_element(q,q+k,q+cnt);
    for(int i=0;i<k;i++){
        for(int j=0;j<i;j++)if(q[i].x!=q[j].x&&q[i].y!=q[j].y){
            sum=min(s[q[i].x][q[i].y],s[q[j].x][q[j].y]);
            sum=min(sum,s[q[i].x][q[j].y]);
            sum=min(sum,s[q[j].x][q[i].y]);
            ans=max(ans,sum);
        }
    }printf("%d\n",ans);
    return 0;
}
