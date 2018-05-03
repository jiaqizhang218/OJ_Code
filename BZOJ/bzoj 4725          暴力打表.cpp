#include<bits/stdc++.h>  
   
using namespace std;  
   
map <int ,pair<int ,int > > s;  
   
typedef map<int ,pair<int ,int > >::iterator it;  
   
int Q,n;  
   
int a[100],b[10000],cnt;  
   
int main()  
{  
    a[1]=1,a[2]=2;  
    s[1]=make_pair(2,1);  
    for(n=3;;n++)  
    {  
        if(n&1) a[n]=a[n-1]*2;  
        else for(int j=1;;j++) if(!s.count(j)) { a[n]=a[n-1]+j; break; }  
        for(int j=1;j<n;j++) s[a[n]-a[j]]=make_pair(n,j);  
        if((!(n&1))&&a[n]>1e9) break;  
    }  
    for(it l=s.begin();l!=s.end();l++)  
        b[++cnt]=l->first;
    scanf("%d",&Q);  
    while(Q--)  
    {  
        int x;  
        scanf("%d",&x);  
        it l=s.find(x);  
        if(l!=s.end())  
            printf("%d %d\n",l->second.first,l->second.second);  
        else  
        {  
            int y=lower_bound(b+1,b+cnt+1,x)-b-1;  
            printf("%d %d\n",n+(x-y)*2,n+(x-y)*2-1);  
        }  
    }  
}  
