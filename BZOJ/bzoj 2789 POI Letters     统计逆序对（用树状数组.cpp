#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
#define N 1000003  
using namespace std;  
int n,ch[30][100000],len[N],pd[30];  
long long tr[N],ans;  
char s[N],s1[N];  
int lowbit(int x)  
{  
    return x&(-x);  
}  
void change(int x,long long v)  
{  
    for (;x<=n;x+=lowbit(x))  
     tr[x]+=v;  
}  
long long  sum(int x)  
{  
    int ans=0; 
    for (;x;x-=lowbit(x))  
     ans+=tr[x];  
    return ans;  
}  
int main()  
{  
    scanf("%d\n",&n);  
    scanf("%s",s+1);  
    scanf("%s",s1+1);  
    for (int i=1;i<=n;i++)  
     {  
        int x=s[i]-'A';  
        ch[x][++ch[x][0]]=i;  
     }  
    for (int i=1;i<=n;i++)  
     {  
        int x=s1[i]-'A';  
        pd[x]++;  
        len[i]=ch[x][pd[x]];  
     }  
    for (int i=n;i>=1;i--)  
     {  
        ans+=sum(len[i]);  
        change(len[i],1);  
     }  
    printf("%lld\n",ans);  
}  
