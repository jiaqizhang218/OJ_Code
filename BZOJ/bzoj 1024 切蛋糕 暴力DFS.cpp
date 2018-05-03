#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
double mins(double &a,double b){
    if(a>b) a=b;
}
double dfs(double x,double y,int cnt){
    if(cnt==1) return max(y/x,x/y);
    double ans=100000.0;
    for(int i = 1 ; i <= (cnt>>1) ; i++)
	{
        mins(ans,max(dfs(x*i/cnt,y,i),dfs(x*(cnt-i)/cnt,y,cnt-i)));
        mins(ans,max(dfs(x,y*i/cnt,i),dfs(x,y*(cnt-i)/cnt,cnt-i)));
    }
    return ans;
}
int main(){
    double x,y;int cnt;
    scanf("%lf%lf%d",&x,&y,&cnt);
    printf("%.6lf\n",dfs(x,y,cnt));
    return 0;
}

