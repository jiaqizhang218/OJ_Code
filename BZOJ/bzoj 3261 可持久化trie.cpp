    #include<cstdio>  
    #include<cstring>  
    #include<cstdlib>  
    #include<cmath>  
    #include<algorithm>  
    #include<iostream>  
    #define maxn 600010  
    #define N maxn*27  
      
    using namespace std;  
      
    int lch[N],rch[N],size[N],root[maxn];  
    int n,m,tot,T,sum;  
    char s[5];  
      
    int modify(int pre,int i,int x)  
    {  
        int now=++tot;  
        if (i==0)  
        {  
            lch[now]=rch[now]=0;size[now]=size[pre]+1;  
        }  
        else  
        {  
            int mid=((x>>(i-1))&1);  
            if (mid==0)  
            {  
                rch[now]=rch[pre];lch[now]=modify(lch[pre],i-1,x);  
            }  
            else  
            {  
                lch[now]=lch[pre];rch[now]=modify(rch[pre],i-1,x);  
            }  
            size[now]=size[lch[now]]+size[rch[now]];  
        }  
        return now;  
    }  
      
    int query(int root1,int root2,int i,int x)  
    {  
        if (i==0) return 0;  
        int mid=((x>>(i-1))&1);  
        if (mid==0)  
        {  
            if (size[rch[root2]]-size[rch[root1]]) return (1<<(i-1))+query(rch[root1],rch[root2],i-1,x);  
            else return query(lch[root1],lch[root2],i-1,x);  
        }  
        else  
        {  
            if (size[lch[root2]]-size[lch[root1]]) return (1<<(i-1))+query(lch[root1],lch[root2],i-1,x);  
            else return query(rch[root1],rch[root2],i-1,x);  
        }  
    }  
      
    int main()  
    {  
        scanf("%d%d",&n,&T);  
        root[0]=lch[0]=rch[0]=size[0]=0;  
        root[0]=modify(root[0],25,0);  
        for (int i=1;i<=n;i++)  
        {  
            int x;  
            scanf("%d",&x);sum^=x;  
            root[i]=modify(root[i-1],25,sum);  
        }  
        while (T--)  
        {  
            int l,r,x;  
            scanf("%s",s+1);  
            if (s[1]=='A')  
            {  
                scanf("%d",&x);  
                sum^=x;  
                n++;root[n]=modify(root[n-1],25,sum);  
            }  
            else  
            {  
                scanf("%d%d%d",&l,&r,&x);  
                l--;r--;  
                printf("%d\n",query(root[l-1],root[r],25,sum^x));  
            }  
        }  
        return 0;  
    }  
