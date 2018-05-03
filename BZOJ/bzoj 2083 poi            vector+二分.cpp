#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#include<vector>   
#define N 1000010  
using namespace std;  
int a[N];  
vector<int>b[N],v[N];  
int t[N],len[N];  
bool ans[N];  
int S[N],T;  
int main()  
{  
    int n,m;  
    scanf("%d",&n);  
    int i,j,x,y;  
    for(i=1;i<=n;i++)  
    scanf("%d",&a[i]);  
    scanf("%d",&m);  
    for(i=1;i<=m;i++)  
    {  
        scanf("%d",&len[i]);  
        for(j=1;j<=len[i];j++)  
        {  
            scanf("%d",&x);  
            b[i].push_back(x);  
        }  
        v[b[i][0]].push_back(i);  
        t[i]=1;  
    }  
    for(i=1;i<=n;i++)  
    {  
        T=0;  
        for(j=0;j<v[a[i]].size();j++)  
        {  
            x=v[a[i]][j];  
            t[x]++;  
            if(t[x]>len[x]) ans[x]=true;  
            else T++,S[T]=x;  
        }  
        v[a[i]].clear();  
        for(j=1;j<=T;j++)  
        v[b[S[j]][t[S[j]]-1]].push_back(S[j]);  
    }  
    for(i=1;i<=m;i++)  
    {  
        if(ans[i]) puts("TAK");  
        else puts("NIE");  
    }  
} 
