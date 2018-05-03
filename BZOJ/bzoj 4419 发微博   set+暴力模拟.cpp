#include<bits/stdc++.h>
#define N 200005
#define L x<<1
#define R x<<1|1
using namespace std;
inline int sc()
{
    int i=0; char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')i=i*10+c-'0',c=getchar();
    return i;
}
set<int>st[N];
int get[N],give[N],n,m;
int main()
{
    n=sc(),m=sc();
    for(int i=1;i<=m;i++)
    {
        char s[5];scanf("%s",s);
        if(s[0]=='!')give[sc()]++;
        else if(s[0]=='+')
        {
            int x=sc(),y=sc();
            get[x]-=give[y];
            get[y]-=give[x];
            st[x].insert(y);
            st[y].insert(x);
        }
        else
        {
            int x=sc(),y=sc();
            get[x]+=give[y];
            get[y]+=give[x];
            st[x].erase(y);
            st[y].erase(x);
        }
    }
    for(int i=1;i<=n;i++)
        for(set<int>::iterator it=st[i].begin();it!=st[i].end();it++)
            get[*it]+=give[i];
    for(int i=1;i<=n;i++)
    {
        printf("%d",get[i]);
        if(i!=n)printf(" ");
    }
    return 0;
}
