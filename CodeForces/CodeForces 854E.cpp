#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;

const int N=2e5+7;
struct Node{int l,r,sum;}T[N*40];
int n,q,cnt,x,root[N];
ll pre[N];

void update(int &x,int y,int pos,int l=1,int r=n)
{
    T[x=++cnt]=T[y],T[x].sum++;
    if(l==r)return;
    int mid=l+r>>1;
    if(pos<=mid)update(T[x].l,T[y].l,pos,l,mid);
    else update(T[x].r,T[y].r,pos,mid+1,r);
}

int ask(int x,int y,int L,int R,int l=1,int r=n)
{
    if(L<=l&&r<=R)return T[y].sum-T[x].sum;
    int mid=l+r>>1,an=0;
    if(L<=mid)an+=ask(T[x].l,T[y].l,L,R,l,mid);
    if(R>mid)an+=ask(T[x].r,T[y].r,L,R,mid+1,r);
    return an;
}

inline int query(int x1,int x2,int y1,int y2)
{
    if(x1>x2||y1>y2)return 0;
    return ask(root[x1-1],root[x2],y1,y2);
}

int main(){
    scanf("%d%d",&n,&q);
    F(i,1,n)
    {
        scanf("%d",&x);
        update(root[i],root[i-1],x);
    }
    F(i,1,q)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        ll sum=0,tmp=query(a,c,b,d);
        sum+=1ll*query(1,a-1,1,b-1)*(query(a,n,b,n)+tmp);
        sum+=1ll*query(a,c,1,b-1)*(query(1,n,b,n)+tmp);
        sum+=1ll*query(c+1,n,1,b-1)*(query(1,c,b,n)+tmp);
        sum+=1ll*query(c+1,n,b,d)*(query(1,c,1,n)+tmp);
        sum+=1ll*query(1,a-1,b,d)*(query(a,n,1,n)+tmp);
        sum+=1ll*query(1,a-1,d+1,n)*(query(a,n,1,d)+tmp);
        sum+=1ll*query(a,c,d+1,n)*(query(1,n,1,d)+tmp);
        sum+=1ll*query(c+1,n,d+1,n)*(query(1,c,1,d)+tmp);
        sum+=tmp*(tmp-1);
        sum/=2;
        printf("%lld\n",sum);
    }
    return 0;
}
