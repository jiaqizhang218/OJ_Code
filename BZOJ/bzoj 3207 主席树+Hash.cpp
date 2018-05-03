#include <bits/stdc++.h>
#define INF 18446744073709551615UL
using namespace std;

const int N = 200100;
const int Size = 8000100;
typedef unsigned long long ll;
ll a[N]; ll hash[N]; ll val[N];
int sum[Size]; int tr[Size][2];
int root[N];
int n,m,k,cnt=0;

inline int read()
{
    int t=1,x=0; char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') t=-1;
		ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return t*x;
}

void Insert(int x,int &y,ll l,ll r,ll v)
{
    y=++cnt; sum[y]=sum[x]+1;
    tr[y][0]=tr[x][0]; tr[y][1]=tr[x][1];
    if(l==r) return;
    ll mid=(l>>1)+(r>>1)+(l&r&1);
    if(v<=mid) Insert(tr[x][0],tr[y][0],l,mid,v);
    else Insert(tr[x][1],tr[y][1],mid+1,r,v);
}

int Query(int x,int y,ll l,ll r,ll v)
{
    if(l==r) return sum[y]-sum[x];
    ll mid=(l>>1)+(r>>1)+(l&r&1);
    if(v<=mid) return Query(tr[x][0],tr[y][0],l,mid,v);
    else Query(tr[x][1],tr[y][1],mid+1,r,v);
}

int main()
{
    int l,r;
    n=read(); m=read(); k=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++) hash[i]=hash[i-1]*233+a[i];
    ll t=1; for(int i=1;i<=k;i++) t*=233; 
    for(int i=k;i<=n;i++) val[i]=hash[i]-hash[i-k]*t;
    for(int i=k;i<=n;i++) Insert(root[i-1],root[i],0,INF,val[i]);
    while(m--){
        ll h=0; l=read(); r=read();
        for(int i=1;i<=k;i++) h=h*233+read();
        if(Query(root[l+k-2],root[r],0,INF,h)) puts("No");
        else puts("Yes");
    }
    return 0;
}
