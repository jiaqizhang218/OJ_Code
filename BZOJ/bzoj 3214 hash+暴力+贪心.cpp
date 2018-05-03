#include<bits/stdc++.h>

using namespace std;

const int N=50005;

int n,t1,t2,t3,s[N],a[N],b[N],c[N];
char str[N*10];

void init()
{
    gets(str);int len=strlen(str);
    for (int k=0,i=0;i<len;i++)
    {
        if (str[i]>='a'&&str[i]<='z') k=k*27+str[i]-'a'+1;
        else s[++n]=k,k=0;
    }
    gets(str);len=strlen(str);
    for (int k=0,i=0;i<len;i++)
    {
        if (str[i]>='a'&&str[i]<='z') k=k*27+str[i]-'a'+1;
        else a[++t1]=k,k=0;
    }
    gets(str);len=strlen(str);
    for (int k=0,i=0;i<len;i++)
    {
        if (str[i]>='a'&&str[i]<='z') k=k*27+str[i]-'a'+1;
        else b[++t2]=k,k=0;
    }
    gets(str);len=strlen(str);
    for (int k=0,i=0;i<len;i++)
    {
        if (str[i]>='a'&&str[i]<='z') k=k*27+str[i]-'a'+1;
        else c[++t3]=k,k=0;
    }
}

int main()
{
    init();
    int l=1,r=n,tot=0;
    for (int i=1;i<=t1;i++,l++) while (s[l]!=a[i]) l++,tot++;
    for (int i=t3;i>=1;i--,r--) while (s[r]!=c[i]) r--,tot++;
    int ans=n;
    for (int i=l;i<=r;i++)
        if (s[i]==b[1])
        {
            int p=i,flag=0;
            for (int j=1;j<=t2;j++,p++)
            {
                while (p<=r&&s[p]!=b[j]) p++;
                if (p>r) {flag=1;break;}
            }
            if (!flag) ans=min(ans,p-i-t2);
        }
    printf("%d",ans+tot);
    return 0;
}
