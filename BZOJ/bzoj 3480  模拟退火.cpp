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
    ansx/=(double)n;ansy/=(double)n;T=100000;//�仯����
    nowx=ansx=nowy=ansy;//��ʼλ��
    dis=dist(ansx,ansy);//��ǰ���Ž�
    while(T>0.001){
        nx=nowx;ny=nowy;
        nx=nx+T*(Rand()*2-1);
        ny=ny+T*(Rand()*2-1);//�ڵ�ǰλ�õı仯���������ȡһ��
        now=dist(nowx,nowy)-dist(nx,ny);//���㵱ǰ��
        if(now>0||exp(now/T)>rand()){//�����ǰ������Ž����ôȡΪ��ǰ�⣬������exp|��ǰ��-���Ž�|/T�ĸ��ʽ��ܵ�ǰ��
            nowx=nx;
            nowy=ny;
        }
        T*=0.98;//����������Χ�����£�
    }
    printf("%.3lf %.3lf",ansx,ansy);
}
