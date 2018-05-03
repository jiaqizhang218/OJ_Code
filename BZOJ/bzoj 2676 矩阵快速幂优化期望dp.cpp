#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define rint register int
#define dd double
#define esp 0.00000001
using namespace std;
inline void read(int &x)
{
    x=0; char q=getchar();
    while(q<'0'||q>'9') q=getchar();
    while(q>='0'&&q<='9') x=x*10+q-'0',q=getchar();
}
inline void readll(ll &x)
{
    x=0; char q=getchar();
    while(q<'0'||q>'9') q=getchar();
    while(q>='0'&&q<='9') x=x*10+q-'0',q=getchar();
}

int all,dui[10][31];
struct QTQ
{
    dd b[155][155];
    void clear()
    {
        mem(b,0);
    }
    void out()
    {
        printf("\n");
        for(int i=1;i<=all;++i)
        {
            for(int j=1;j<=all;++j)
                printf("%lf ",b[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    QTQ operator * (const QTQ &c) const
    {
        QTQ x=*this,t; rint i,j,k;
        for(i=1;i<=all;++i)
            for(j=1;j<=all;++j)
            {
                t.b[i][j]=0;
                for(k=1;k<=all;++k)
                    t.b[i][j]+=x.b[i][k]*c.b[k][j];
            }
        return t;
    }
}f,a,a1,a2;

int n,R,Q;
ll S;

dd dp(dd p)
{
    rint i,j;
    f.clear(); a1.clear(); a2.clear();
    for(i=1;i<=Q;++i)
        for(j=0;j<=R;++j)
            if(i>=j||i==Q)
            {
                a1.b[dui[i][j]][dui[min(i+1,Q)][min(j+1,R)]]=p;
                a1.b[dui[i][j]][dui[i-1][0]]=(1.0-p);
            }
    a1.b[all][all]=1;
    for(i=0;i<=Q;++i)
        for(j=0;j<=R;++j)
            if(i>=j||i==Q)
                a2.b[dui[i][j]][all]=j;
    for(i=1;i<=all;++i) a2.b[i][i]=1;
    a=a1*a2;
    f.b[1][dui[Q][0]]=1;
    int ci=n;
    while(ci)
    {
        if(ci&1)
            f=f*a;
        a=a*a;
        ci>>=1;
    }
    return f.b[1][all];
}

dd work()
{
    dd l=0,r=1,mid;
    while(l<r-esp)
    {
        mid=(l+r)/2.0;
        if(dp(mid)>=S) r=mid;
        else l=mid;
    }
    return l;
}

int main(){
    rint i,j;
    
    read(n); read(R); read(Q); readll(S);
    all=0;
    for(i=0;i<=Q;++i)
        for(j=0;j<=R;++j)
            if(i>=j||i==Q)
                dui[i][j]=++all;
    ++all;
    if(dp(1.0)<=S)// ... 必须是<=，不然第一个点... 
    {
        printf("Impossible.\n");
        return 0;
    }
    printf("%lf",work());
}
