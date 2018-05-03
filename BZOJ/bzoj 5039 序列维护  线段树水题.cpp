#include<stdio.h>  
#define LL long long  
LL tre[400044], tx[400044], tp[400044];  
int mod;  
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
inline void Create(int l, int r, int x)  
{  
    int m;  
    if(l==r)  
    {  
        scanf("%lld", &tre[x]);  
        return;  
    }  
    tx[x] = 1;  
    m = (l+r)>>1;  
    Create(l, m, x<<1);  
    Create(m+1, r, x<<1|1);  
    tre[x] = (tre[x<<1]+tre[x<<1|1])%mod;  
}  
void Lazy(int l, int r, int x)  
{  
    int m;  
    m = (l+r)>>1;  
    if(tx[x]!=1)  
    {  
        tre[x<<1] = tre[x<<1]*tx[x]%mod;  
        tre[x<<1|1] = tre[x<<1|1]*tx[x]%mod;  
        if(l!=r)  
        {  
            tx[x<<1] = tx[x<<1]*tx[x]%mod;  
            tx[x<<1|1] = tx[x<<1|1]*tx[x]%mod;  
            tp[x<<1] = tp[x<<1]*tx[x]%mod;  
            tp[x<<1|1] = tp[x<<1|1]*tx[x]%mod;  
        }  
        tx[x] = 1;  
    }  
    if(tp[x])  
    {  
        tre[x<<1] = (tre[x<<1]+tp[x]*(m-l+1))%mod;  
        tre[x<<1|1] = (tre[x<<1|1]+tp[x]*(r-m))%mod;  
        if(l!=r)  
        {  
            tp[x<<1] = (tp[x<<1]+tp[x])%mod;  
            tp[x<<1|1] = (tp[x<<1|1]+tp[x])%mod;  
        }  
        tp[x] = 0;  
    }  
}  
void Update(int l, int r, int x, int a, int b, int c, int opt)  
{  
    int m;  
    if(l>=a && r<=b)  
    {  
        if(opt==1)  
        {  
            tre[x] = tre[x]*c%mod;  
            if(l==r)  
                return;  
            tx[x] = tx[x]*c%mod;  
            tp[x] = tp[x]*c%mod;  
        }  
        else  
        {  
            tre[x] = (tre[x]+c*(r-l+1))%mod;  
            if(l==r)  
                return;  
            tp[x] = (tp[x]+c)%mod;  
        }  
        return;  
    }  
    m = (l+r)>>1;  
    Lazy(l, r, x);  
    if(a<=m)  
        Update(l, m, x<<1, a, b, c, opt);  
    if(b>=m+1)  
        Update(m+1, r, x<<1|1, a, b, c, opt);  
    tre[x] = (tre[x<<1]+tre[x<<1|1])%mod;  
}  
LL Query(int l, int r, int x, int a, int b)  
{  
    int m;  
    LL ans = 0;  
    if(l>=a && r<=b)  
        return tre[x];  
    m = (l+r)>>1;  
    Lazy(l, r, x);  
    if(a<=m)  
        ans += Query(l, m, x<<1, a, b);  
    if(b>=m+1)  
        ans += Query(m+1, r, x<<1|1, a, b);  
    return ans%mod;  
}  
int main(void)  
{  
    int n, m, opt, a, b, x;  
    n=read(),mod=read(); 
    Create(1, n, 1);  
    m=read();
    while(m--)  
    {  
        opt=read();
        if(opt<=2)  
        {  
            a=read(),b=read(),x=read();
            Update(1, n, 1, a, b, x, opt);  
        }  
        else  
        {  
            a=read(),b=read();
            printf("%lld\n", Query(1, n, 1, a, b));  
        }  
    }  
    return 0;  
} 
