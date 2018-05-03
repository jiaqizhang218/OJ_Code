#include<bits/stdc++.h>
#define N 200003  
using namespace std;  
int n,m;  
struct data1{  
    int pos,color,pre;  
}w[N];  
struct data{  
    int l,r,id,time;  
}q[N];  
int belong[N],last[N],color[1000003],cnt,sz,vis[N],num[1000003],ans[N],ans1;  
int cmp(data a,data b)  
{  
    if (belong[a.l]==belong[b.l])  
     return a.r<b.r;  
    return belong[a.l]<belong[b.l];  
}  
void calc(int x)  
{  
    if (vis[x])  
    {  
     if (!--num[color[x]])  ans1--;  
    }  
    else  
    {  
     if (++num[color[x]]==1)  ans1++;  
    }  
    vis[x]^=1;  
}  
void change(int x,int c)  
{  
    if (vis[x])  
     {  
        calc(x);  
        color[x]=c;  
        calc(x);  
     }  
    else color[x]=c;  
}  
int main()  
{  
    scanf("%d%d",&n,&m);  
    for (int i=1;i<=n;i++)  
     scanf("%d",&color[i]),last[i]=color[i];  
    for (int i=1;i<=m;i++)  
     {  
        char s[10]; scanf("%s",s);  
        int x,y; scanf("%d%d",&x,&y);  
        if (s[0]=='R')  
         {  
            w[++cnt].pos=x; w[cnt].color=y; w[cnt].pre=last[x];//记录更改之前的颜色  
            last[x]=y;  
         }  
        else  
         {  
            q[++sz].l=x; q[sz].r=y; q[sz].id=sz; q[sz].time=cnt;//记录他之前的离他最近的操作  
         }  
     }  
    int block=sqrt(n);  
    for (int i=1;i<=n;i++)  
     belong[i]=(i-1)/block+1;  
    sort(q+1,q+sz+1,cmp);  
    int l,r;  
    l=r=1; calc(l);  
    for (int i=1;i<=sz;i++)  
     {  
        for (int j=q[i-1].time+1;j<=q[i].time;j++)  
         change(w[j].pos,w[j].color);  
        for (int j=q[i-1].time;j>q[i].time;j--)  
         change(w[j].pos,w[j].pre);  
        while (l<q[i].l)  calc(l++);  
        while (l>q[i].l)  calc(--l);  
        while (r<q[i].r)  calc(++r);  
        while (r>q[i].r)  calc(r--);  
        ans[q[i].id]=ans1;  
     }  
    for (int i=1;i<=sz;i++)  
     printf("%d\n",ans[i]);  
}
