#include<cstdio>
#include<cmath>
#include<cstdlib>
#define N 11111
using namespace std;
int n,i;
double ansx,ansy,nowx,nowy,dis,nx,ny,T,now,x[N],y[N],w[N];
double Rand(){return (double)(rand()%20000)/20000.0;}
double dist(double xx,double yy){
    now=0;
    for(int i=1;i<=n;i++)now+=sqrt((xx-x[i])*(xx-x[i])+(yy-y[i])*(yy-y[i]))*w[i];
    if(now<dis)dis=now,ansx=xx,ansy=yy;
    return now;
}
int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%lf%lf%lf",&x[i],&y[i],&w[i]),ansx+=x[i],ansy+=y[i];
    ansx/=(double)n;ansy/=(double)n;T=100000;//变化幅度
    nowx=ansx=nowy=ansy;//初始位置
    dis=dist(ansx,ansy);//当前最优解
    while(T>0.001){
        nx=nowx;ny=nowy;
        nx=nx+T*(Rand()*2-1);
        ny=ny+T*(Rand()*2-1);//在当前位置的变化幅度内随机取一点
        now=dist(nowx,nowy)-dist(nx,ny);//计算当前解
        if(now>0||exp(now/T)>rand()){//如果当前解比最优解好那么取为当前解，否则以exp|当前解-最优解|/T的概率接受当前解
            nowx=nx;
            nowy=ny;
        }
        T*=0.98;//降低搜索范围（降温）
    }
    printf("%.3lf %.3lf",ansx,ansy);
}
