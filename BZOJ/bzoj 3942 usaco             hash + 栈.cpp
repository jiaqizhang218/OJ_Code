#include<stdio.h>
#include<string.h>
unsigned long long hs[1000010],ht;
unsigned long long seed[1000010];
int n,m;
int top;
char S[1000010],stack[1000010],T[1000010];
void BKDR()
{
    seed[1]=131;
    ht=T[0];
    int i;
    for(i=1;i<m;i++)
    {
        ht=ht*seed[1]+T[i];
        seed[i+1]=seed[i]*seed[1];
    }
}
int main()
{
    scanf("%s%s",S,T);
    n=strlen(S);
    m=strlen(T);
    BKDR();
    int i,j;
    for(i=0;i<m;i++)
    {
        stack[top++]=S[i];
        hs[top]=hs[top-1]*seed[1]+S[i];
    }
    for(i=m;i<n;i++)
    {
        while(top>=m&&hs[top]-hs[top-m]*seed[m]==ht)
            for(j=0;j<m;j++)
                stack[--top]='\0';
        stack[top++]=S[i];
        hs[top]=hs[top-1]*seed[1]+S[i];
    }
    while(top>=m&&hs[top]-hs[top-m]*seed[m]==ht)
        for(j=0;j<m;j++)
            stack[--top]='\0';
    printf("%s",stack);
    return 0;
}
