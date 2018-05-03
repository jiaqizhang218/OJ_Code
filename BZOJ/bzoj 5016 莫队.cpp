#include<stdio.h>  
#include<math.h>  
#include<algorithm>  
using namespace std;  
#define LL long long  
int pos[50005];  
typedef struct Que  
{  
    int l, r;  
    int c, id;  
    bool operator < (const Que &b) const  
    {  
        if(pos[l]<pos[b.l] || pos[l]==pos[b.l] && r<b.r)  
            return 1;  
        return 0;  
    }  
}Que;  
Que s[200005];  
int a[50005];  
LL ans[50005], sl[50005], sr[50005];  
int main(void)  
{  
    LL val;  
    int B, cnt, n, q, i, l1, l2, r1, r2, L, R;  
    scanf("%d", &n);  
    for(i=1;i<=n;i++)  
        scanf("%d", &a[i]);  
    B = sqrt(1.0*n)+1, cnt = 0;  
    scanf("%d", &q);  
    for(i=1;i<=q;i++)  
    {  
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);  
        s[++cnt].id = i, s[cnt].c = 1, s[cnt].l = r1, s[cnt].r = r2;  
        s[++cnt].id = i, s[cnt].c = 1, s[cnt].l = l1-1, s[cnt].r = l2-1;  
        s[++cnt].id = i, s[cnt].c = -1, s[cnt].l = l1-1, s[cnt].r = r2;  
        s[++cnt].id = i, s[cnt].c = -1, s[cnt].l = l2-1, s[cnt].r = r1;  
    }  
    R = 1, L = 0;  
    for(i=1;i<=n;i++)  
    {  
        L++;  
        pos[i] = R;  
        if(L==B)  
            R++, L = 0;  
    }  
    val = L = R = 0;  
    sort(s+1, s+cnt+1);  
    for(i=1;i<=cnt;i++)  
    {  
        while(L<s[i].l)  
            val += sr[a[++L]], sl[a[L]]++;  
        while(L>s[i].l)  
            val -= sr[a[L]], sl[a[L--]]--;  
        while(R<s[i].r)  
            val += sl[a[++R]], sr[a[R]]++;  
        while(R>s[i].r)  
            val -= sl[a[R]], sr[a[R--]]--;  
        ans[s[i].id] += val*s[i].c;  
    }  
    for(i=1;i<=q;i++)  
        printf("%lld\n", ans[i]);  
    return 0;  
}  
