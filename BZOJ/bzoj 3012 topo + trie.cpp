#include<cstdio>  
#include<cstring>  
#include<cstdlib>  
#include<cmath>  
#include<iostream>  
#include<algorithm>  
#define maxn 300010   
  
using namespace std;  
  
int ch[maxn][26];  
bool tag[maxn];  
char s[30010][310];  
int q[26],head[26],next[2010],to[2010],d[26];  
int a[26][26];  
int ans[30010];  
int n,m,tot,num,cnt;  
bool w;  
  
void insert(char s[])  
{  
    int n=strlen(s+1),x=0;  
    for (int i=1;i<=n;i++)  
    {  
        if (!ch[x][s[i]-'a']) ch[x][s[i]-'a']=++tot;  
        x=ch[x][s[i]-'a'];  
    }  
    tag[x]=1;  
}  
  
void addedge(int x,int y)  
{  
    if (a[x][y]) return;  
    num++;to[num]=y;next[num]=head[x];head[x]=num;  
    d[y]++;a[x][y]=1;  
}  
  
void query(char s[])  
{  
    int n=strlen(s+1),x=0;  
    for (int i=1;i<=n;i++)  
    {  
        if (tag[x]) {w=1;return;}  
        for (int j=0;j<26;j++)  
          if (j!=s[i]-'a' && ch[x][j]) addedge(s[i]-'a',j);  
        x=ch[x][s[i]-'a'];  
    }  
}  
  
bool check()  
{  
    int l=0,r=0;  
    for (int i=0;i<26;i++) if (!d[i]) q[++r]=i;  
    while (l<r)  
    {  
        int x=q[++l];  
        for (int p=head[x];p;p=next[p])  
          if (d[to[p]])  
          {  
            d[to[p]]--;  
            if (!d[to[p]]) q[++r]=to[p];  
          }  
    }  
    return (r==26);  
}  
  
int main()  
{  
    scanf("%d",&n);  
    for (int i=1;i<=n;i++)  
    {  
        scanf("%s",s[i]+1);  
        insert(s[i]);  
    }  
    for (int i=1;i<=n;i++)  
    {  
        num=0;w=0;  
        memset(head,0,sizeof(head));  
        memset(d,0,sizeof(d));  
        memset(a,0,sizeof(a));  
        query(s[i]);  
        if (!w && check()) ans[++cnt]=i;  
    }  
    printf("%d\n",cnt);  
    for (int i=1;i<=cnt;i++) printf("%s\n",s[ans[i]]+1);  
    return 0;  
}  
