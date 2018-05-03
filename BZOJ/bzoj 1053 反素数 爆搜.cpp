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
int prime[101]={1,2,3,5,7,11,13,17,19,23,29,31,41,43};  
LL num,has;  
int n;  
void DFS(int k,LL now,int cnt,int last)  
{  
    if(k==12){  
        if(now>num&&cnt>has)has=cnt,num=now;  
        if(now<=num&&cnt>=has)num=now,has=cnt;  
        return ;  
    }  
    DFS(k+1,now,cnt,0);  
    int tp=prime[k];  
    if(tp*now>n)return;  
    for(int i=1;i<=last;i++)  
     {  
        DFS(k+1,now*tp,cnt*(i+1),i);  
        tp*=prime[k];  
         if(now*tp>n)break;  
     }  
}  
int main()  
{  
  
    scanf("%d",&n);  
    DFS(1,1,1,20);  
    cout<<num;  
    return 0;  
} 


