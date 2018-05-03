#include <map>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1010
#define L 110
#define M 100100
#define base 131
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ull hash[N][L];
ull power[L];
int ans[N];
char s[N][L];
map<ull,int>root;
int n,l,m;
int tot;
struct node
{
    int l,r,siz,v,rnd,col;
}tr[(N+M)<<4];
void pushup(int &rt)
{
    tr[rt].siz=tr[tr[rt].l].siz+tr[tr[rt].r].siz+1;
}
void down(int &rt,int x)
{
    ans[tr[rt].v]=max(ans[tr[rt].v],x);
    tr[rt].col=max(tr[rt].col,x);
}
void pushdown(int &rt)
{
    if(tr[rt].col!=0)
    {
        if(tr[rt].l!=0)
            down(tr[rt].l,tr[rt].col);
        if(tr[rt].r!=0)
            down(tr[rt].r,tr[rt].col);
        tr[rt].col=0;
    }
}
void lturn(int &rt)
{
    int t=tr[rt].r;
    pushdown(rt),pushdown(t);
    tr[rt].r=tr[t].l;
    tr[t].l=rt;
    rt=t;
    pushup(rt),pushup(tr[rt].l);
}
void rturn(int &rt)
{
    int t=tr[rt].l;
    pushdown(rt),pushdown(t);
    tr[rt].l=tr[t].r;
    tr[t].r=rt;
    rt=t;
    pushup(rt),pushup(tr[rt].r);
}
void insert(int &rt,int v)
{
    if(!rt)
    {
        rt=++tot;
        tr[rt].l=tr[rt].r=0;
        tr[rt].siz=1,tr[rt].col=0;
        tr[rt].v=v,tr[rt].rnd=rand();
        return ;
    }
    pushdown(rt);
    tr[rt].siz++;
    if(v<=tr[rt].v)
    {
        insert(tr[rt].l,v);
        if(tr[tr[rt].l].rnd<tr[rt].rnd)rturn(rt);
    }else
    {
        insert(tr[rt].r,v);
        if(tr[tr[rt].r].rnd<tr[rt].rnd)lturn(rt);
    }
    pushup(rt);
}
void del(int &rt,int v)
{
    if(!rt)return;
    pushdown(rt);
    tr[rt].siz--;
    if(v==tr[rt].v)
    {
        if(tr[rt].l*tr[rt].r==0){rt=tr[rt].l+tr[rt].r;return;}
        if(tr[tr[rt].l].rnd<tr[tr[rt].r].rnd)rturn(rt),del(tr[rt].r,v);
        else lturn(rt),del(tr[rt].l,v);
    }else if(v<tr[rt].v)del(tr[rt].l,v);
    else del(tr[rt].r,v);
    if(rt)pushup(rt);
}
void insert(int x)
{
    insert(root[hash[x][l]],x);
    int tmp=root[hash[x][l]];
    down(tmp,tr[tmp].siz);
}
void del(int x)
{
    del(root[hash[x][l]],x);
}
int main()
{
    scanf("%d%d%d",&n,&l,&m);
    power[0]=1;
    for(int i=1;i<=l;i++)power[i]=power[i-1]*base;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
        for(int j=1;j<=l;j++)
        {
            hash[i][j]=hash[i][j-1]*base+s[i][j];
        }
        insert(i);
    }
    for(int i=1;i<=m;i++)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        del(a);
        if(a!=c)del(c);
        hash[a][l]-=s[a][b]*power[l-b];
        hash[c][l]-=s[c][d]*power[l-d];
        swap(s[a][b],s[c][d]);
        hash[a][l]+=s[a][b]*power[l-b];
        hash[c][l]+=s[c][d]*power[l-d];
        insert(a);
        if(a!=c)insert(c);
    }
    for(int i=1;i<=n;i++)del(i);
    for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
}
