#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
using namespace std;
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
    return *p1++;
}
//#define  getchar() nc()
inline int read()
{
	int x = 0 , f = 1; char CH = getchar();
	while(CH<'0'||CH>'9') {if(CH=='-')f=0;CH=getchar();}
	while(CH>='0'&&CH<='9') {x=(x<<3)+(x<<1)+(CH-48);CH=getchar();}
	return f ? x : -x;
}
const int N = 16;  
const int M = (1 << N);  
   
int n,c,a[N],b[N],d[233],f[M];  
   
int main()  
{      
    n=read(),c=read();
    for (int i = 0; i < n; i++) a[i]=read(),b[i]=read();
    for (int o = 1; o < (1 << n); o++)  
    {  
        int tp = 0;  
        for (int x = o,now = 0; x; x >>= 1,now++)  
            if (x & 1) d[++tp] = a[now],d[++tp] = b[now];  
        bool pass = 1; sort(d + 1,d + tp + 1);  
        for (int i = 1; i < tp; i += 2)  
            if (d[i + 1] - d[i] > c) pass = 0;  
        f[o] = pass ? (tp / 2 - 1) : M;  
        for (int op = o - 1 & o; op; op = op - 1 & o)  
            f[o] = min(f[o],f[op] + f[o ^ op]);  
    }  
    cout << (f[(1 << n) - 1] == M ? -1 : f[(1 << n) - 1]) << endl;  
    return 0;  
}
