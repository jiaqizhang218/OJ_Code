    #include<cstdio>  
    #include<cstdlib>  
    #include<cstring>  
    #include<algorithm>  
    #include<cmath>  
    using namespace std;  
    typedef long long ll;  
      
    inline char nc(){  
        static char buf[100000],*p1=buf,*p2=buf;  
        if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }  
        return *p1++;  
    }  
      
    inline void read(ll &x){  
        char c=nc(),b=1;  
        for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;  
        for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;  
    }  
      
    const int maxn=500000;  
    int mobius[maxn+5],sum[maxn+5];  
    int vst[maxn+5],prime[maxn+5],num=0;  
      
    inline void Pre()  
    {  
        mobius[1]=1;  
        for (int i=2;i<=maxn;i++)  
        {  
            if (!vst[i])  
                mobius[i]=-1,prime[++num]=i;  
            for (int j=1;j<=num && prime[j]*i<=maxn;j++)  
            {  
                vst[i*prime[j]]=1;  
                if (i%prime[j]==0)  
                {  
                    mobius[i*prime[j]]=0; break;  
                }  
                else  
                    mobius[i*prime[j]]=-mobius[i];  
            }  
        }  
    }  
      
    ll K;  
      
    inline ll Cal(ll x)  
    {  
        ll ret=0;  
        ll t=sqrt(x);  
        for (ll i=1;i<=t;i++)  
            ret+=x/(i*i)*mobius[i];  
        return x-ret;  
    }  
      
    int main()  
    {  
        ll Q;  
        ll L,R,MID;  
        Pre();  
        Q=1;  
        while (Q--)  
        {  
            read(K);  
            L=0; R=210000000000LL;  
            while (L+1<R)  
                if (Cal(MID=(L+R)>>1)>=K)  
                    R=MID;  
                else  
                    L=MID;  
            printf("%lld\n",R);  
        }  
        return 0;  
    }  
