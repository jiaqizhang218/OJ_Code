#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1000000010;

int n,m,mod,nxt[233];

char s[233];

void getnxt(char s[])
{
    int l = strlen(s);
    nxt[0] = nxt[1] = 0;
    for(int i = 1;i < l;i ++)
    {
        int j = nxt[i];
        while(j && s[i] != s[j]) j = nxt[j];
        nxt[i + 1] = s[i] == s[j] ? j + 1 : 0;
    }
}

struct matrix{
    int n,m,num[30][30];
    matrix(int a,int b) : n(a),m(b) {memset(num,0,sizeof(num));}
};

matrix operator *(const matrix &a,const matrix &b)
{
    matrix ans(a.n,b.m);
    for(int i = 0;i < ans.n;i ++)
        for(int j = 0;j < ans.m;j ++)
            for(int k = 0;k < a.m;k ++)
                ans.num[i][j] = (ans.num[i][j] + (LL)a.num[i][k] * b.num[k][j] % mod) % mod;
    return ans;
}

matrix ksm(matrix a,int b)
{
    matrix ans(a.n,a.m);
    for(int i = 0;i < ans.n;i ++)
        ans.num[i][i] = 1;
    while(b)
    {
        if(b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

int main()
{
	#ifdef iloi
	   freopen("test.txt","r",stdin);
#endif
    scanf("%d%d%d%s",&n,&m,&mod,s);

    getnxt(s);

    matrix f(m,m);

    for(int i = 0;i < m;i ++)
    {
        for(char j = '0';j <= '9';j ++)
        {
            int k = i;
            while(k && s[k] != j) k = nxt[k];
            if(s[k] == j) k ++;
            if(k != m) f.num[i][k] ++;
        }
    }
    matrix fn = ksm(f,n),a(1,m);
    a.num[0][0] = 1;
    a = a * fn;
    int ans = 0;
    for(int i = 0;i < m;i ++)
        ans = (ans + a.num[0][i]) % mod;
    printf("%d\n",ans);
    return 0;
}
