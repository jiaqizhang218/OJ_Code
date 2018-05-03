#include<bits/stdc++.h>
typedef long long LL;
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x * f;
}
inline int get_phi(int x)
{
    int res=x;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            res=res/i*(i-1);
            while(x%i==0)x/=i;
        }
    }
    if(x!=1)res=res/x*(x-1);
    return res;
}

int main()
{
	int n = read(),ans;
	for(int i = 1 ; i < n ; i++)
		ans += get_phi(i);
	printf("%d",(ans<<1)+1);	
}
