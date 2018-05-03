#include<bits/stdc++.h>
#define N 60003
using namespace std;
int n,m,sz;
int fail[N],ch[N][30],isend[N],pos[N];
int f[120][6003];
const int p=10007;
char s[N];
void insert(int k)
{
 int len=strlen(s);
 int now=0;
 for(int i=0;i<len;i++)
 {
  int x=s[i]-'A';
  if (!ch[now][x]) ch[now][x]=++sz;
  now=ch[now][x]; 
 }
 isend[now]=1; pos[k]=now;
}
void makefail()
{
 queue<int> p;
 for (int i=0;i<26;i++)
 if (ch[0][i]) p.push(ch[0][i]);
 while (!p.empty())
 {
   int now=p.front(); p.pop();
   for (int i=0;i<26;i++)
   {
   	if (!ch[now][i])
   	{
   	 ch[now][i]=ch[fail[now]][i];
   	 continue;
    }
    int x=ch[now][i];
    fail[x]=ch[fail[now]][i];
    if (isend[fail[x]])   isend[x]=1;
    p.push(x);
   }
 }
}
int main()
{
 scanf("%d%d",&n,&m);
 for (int i=1;i<=n;i++)
 {
  scanf("%s",s);
  insert(i);
 }
 for (int i=0;i<26;i++) if (!ch[0][i]) ch[0][i]=++sz;//这里需要注意，因为在构造文本时‘A'-'Z'都可以选，所以在构造trie树时需要加上单词中不包含的字母，这样转移才是正确的
 makefail();
 f[0][0]=1;
 for (int i=1;i<=m;i++)
 {
   for (int j=0;j<=sz;j++)
    {
      if (isend[j]||!f[i-1][j]) continue;
      for (int k=0;k<26;k++)
       f[i][ch[j][k]]=(f[i][ch[j][k]]+f[i-1][j])%p;
    }
 }
 int ans=0; int ans1=1;
 for (int i=1;i<=m;i++)
  ans1=(ans1*26)%p;
 for (int i=1;i<=sz;i++)
  if (!isend[i])
   ans=(ans+f[m][i])%p;
 printf("%d\n",(ans1-ans+p)%p);
}
