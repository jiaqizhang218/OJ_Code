#include<bits/stdc++.h> 
#define N 100066
using namespace std;
int sc()
{
    int i=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')i=i*10+c-'0',c=getchar();
    return i;
}
int L,R,D,H,T,n,flag;
int main()
{
    T=sc();
    while(T--)
    {
        n=sc();flag=1;
        L=D=0x7FFFFFFF;
        R=H=-0x7FFFFFFF;
        for(int i=1;i<=n;i++)
        {
            int a=sc(),b=sc(),c=sc(),d=sc();
            if(L>=a&&R<=b&&D>=c&&H<=d)
            {
                flag=1;
                L=a,R=b,D=c,H=d;
            }
            else if(L<=a&&R>=b&&D<=c&&H>=d)continue;
            else
            {
                flag=0;
                L=min(L,a);
                R=max(R,b);
                D=min(D,c);
                H=max(H,d);
            }
        }
        flag?puts("TAK"):puts("NIE");
    }
    return 0;
}
