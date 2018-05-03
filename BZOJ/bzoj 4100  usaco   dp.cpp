#include<cstdio>  
#include<iostream>  
using namespace std;  
int n,x;  
char a[2],s[10];  
long long ans,f[10][20],c[10],b[10];  
void dfs(int k,long long sum)  
{  
    if(k>7)   
    {  
        int s1=(b[1]+b[2]*2+b[3]*2+b[4])%7;  
        int s2=(b[5]+b[6]+b[2]+b[3])%7;  
        int s3=(b[7]+2*b[6])%7;  
        if(s1==0||s2==0||s3==0) ans=ans+sum;  
        return;  
    }  
    for(int i=0;i<=6;i++)   
    {  
        b[k]=i-7;  
        c[k]=f[k][i];  
        if(c[k]==0) continue;  
        dfs(k+1,sum*c[k]);  
    }  
}  
int main()  
{  
    s[1]='B';s[2]='E';s[3]='S';s[4]='I';s[5]='G';s[6]='O';s[7]='M';  
    cin>>n;  
    for(int i=1;i<=n;i++)   
    {  
        scanf("%s%d",a,&x);  
        for(int j=1;j<=7;j++)   
        if(a[0]==s[j]) f[j][(x%7+7)%7]++; //负数取模   
    }  
    dfs(1,1);     
    cout<<ans;      
    return 0;  
}  
