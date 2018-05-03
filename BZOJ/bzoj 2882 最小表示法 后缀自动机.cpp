#include<bits/stdc++.h>
#define N 600003
using namespace std;
int n,m,cnt,nq,np,p,q,last,root;
map<int,int> ch[N*2];
int fa[N*2],l[N*2],a[N];
void extend(int x)
{
    int c=a[x];
    p=last; np=++cnt; last=np;
    l[np]=x;
    for (;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
    if (!p) fa[np]=root;
    else {
        q=ch[p][c];
        if (l[q]==l[p]+1) fa[np]=q;
        else {
            nq=++cnt; l[nq]=l[q]+1;
            ch[nq]=ch[q];
            fa[nq]=fa[q];
            fa[q]=fa[np]=nq;
            for (;ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) a[n+i]=a[i];
    m=2*n;
    last=root=++cnt; ch[N].clear();
    for (int i=1;i<=m;i++) extend(i);
    p=1;
    map<int,int>::iterator t;
    for (int i=1;i<=n;i++) {
        t=ch[p].begin();
        p=t->second;
        if (i!=n) printf("%d ",t->first);
        else printf("%d\n",t->first);
    }
}
