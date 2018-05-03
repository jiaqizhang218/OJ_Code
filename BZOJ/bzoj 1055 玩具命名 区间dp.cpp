#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAXN 205
int W,I,N,G,n,cnt;
char s[MAXN];
struct hp{char x,y,z;}ch[MAXN];
bool f[MAXN][MAXN][100];
int main()
{
    scanf("%d%d%d%d\n",&W,&I,&N,&G);
    for (int i=1;i<=W;++i) gets(s),ch[++cnt].x=s[0],ch[cnt].y=s[1],ch[cnt].z='W';
    for (int i=1;i<=I;++i) gets(s),ch[++cnt].x=s[0],ch[cnt].y=s[1],ch[cnt].z='I';
    for (int i=1;i<=N;++i) gets(s),ch[++cnt].x=s[0],ch[cnt].y=s[1],ch[cnt].z='N';
    for (int i=1;i<=G;++i) gets(s),ch[++cnt].x=s[0],ch[cnt].y=s[1],ch[cnt].z='G';
    gets(s);n=strlen(s);
    for (int i=n;i>=1;--i) s[i]=s[i-1];

    for (int i=1;i<=n;++i) f[i][i][s[i]]=true;
    for (int len=2;len<=n;++len)
        for (int l=1;l<=n-len+1;++l)
        {
            int r=l+len-1;
            for (int k=l;k<=r;++k)
                for (int i=1;i<=cnt;++i)
                    f[l][r][ch[i].z] |= f[l][k][ch[i].x]&&f[k+1][r][ch[i].y];
        }
    bool flag=false;
    if (f[1][n]['W']) putchar('W'),flag=true;
    if (f[1][n]['I']) putchar('I'),flag=true;
    if (f[1][n]['N']) putchar('N'),flag=true;
    if (f[1][n]['G']) putchar('G'),flag=true;
    if (!flag) puts("The name is wrong!");
    else putchar('\n');
}
