#include<bits/stdc++.h>
using namespace std;  
typedef long long LL;  
LL s[3],a,m,n,mo,g,ans[3];  
LL Add(LL x,LL y)  
{  
    LL ret = 0;  
    for (; y; y >>= 1) {  
        if (y & 1) ret = (ret + x)%mo;  
        x = (x + x)%mo;   
    }  
    return ret;  
}  
struct data{  
    LL b[3][3];  
    data() {memset(b,0,sizeof(b));}  
      
    data operator * (const data &d) {  
        data c;  
        for (int i = 1; i <= 2; i++)  
            for (int j = 1; j <= 2; j++)  
                for (int l = 1; l <= 2; l++)  
                    c.b[i][j] = (c.b[i][j] + Add(b[i][l],d.b[l][j]))%mo;  
        return c;  
    }  
};  
data ksm(LL y)  
{  
    data ret,now;  
    ret.b[1][1] = ret.b[2][2] = 1;  
    now.b[1][1] = a; now.b[2][1] = now.b[2][2] = 1; now.b[1][2] = 0;  
    for (; y; y >>= 1) {  
        if (y & 1) ret = ret*now;  
        now = now*now;  
    }  
    return ret;  
}  
LL getLL()  
{  
    LL ret = 0;  
    char ch = getchar();  
    while (ch < '0' || '9' < ch) ch = getchar();  
    while ('0' <= ch && ch <= '9') ret = ret*10 + 1LL*(ch - '0'),ch = getchar();  
    return ret;  
}  
int main()  
{
    mo = getLL(); a = getLL(); s[2] = getLL();   
    s[1] = getLL(); n = getLL(); g = getLL();  
    data ret = ksm(n);  
    for (int i = 1; i <= 2; i++)  
        for (int j = 1; j <= 2; j++)  
            ans[i] = (ans[i] + Add(s[j],ret.b[j][i]))%mo;  
    cout << ans[1]%g;  
    return 0;  
}
