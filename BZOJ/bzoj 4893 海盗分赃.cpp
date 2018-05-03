#include<bits/stdc++.h>
#define ll long long
const int INF = 0x7fffffff;
const double eps = 1e-5;
using namespace std;
const int maxn = 1E5 + 10;

int n,A[maxn],cnt[3],pre[maxn][3],suf[maxn][3];
int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f*=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x * f;
}
void put(int x)  
{  
    int num = 0; char c[15];
    while(x) c[++num] = (x%10)+48, x /= 10;
    while(num) putchar(c[num--]);
    putchar('\n'); 
}
int main()
{
	n = read();
	for(int i = 1 ; i <= n ; i++)
		A[i] = read();
	for(int i = 1 ; i <= n ; i++)
	{
		++cnt[A[i]];
		for(int j = 0 ; j < 3 ; j++)
			pre[i][j] = cnt[j];		//前i个j颜色的珠宝有多少个 
	}
	for(int i = n ; i ; i--)
	{
		for(int j = 0 ; j < 3 ; j++)
			suf[i][j] = suf[i+1][j];
		++suf[i][A[i]];
	}
	bool flag = true;
	for(int j = 0 ; j < 3 ; j++)
		if(pre[n>>1][j] != cnt[j]/2)	flag = 0;	//都各能切成两个 
	if(flag)
	{
		cout<<1<<endl; return 0;
	}
	for(int i = 1; i < n>>1; i++)
	{
		int tmp;flag=1;
		for(int j = 0; j < 3; j++)
		{
			tmp = pre[i][j] + suf[n-(n/2-i)+1][j];
			if(tmp!=cnt[j]/2)
			{
				flag=0;break;
			}	
		}
		if(flag)
			{
				cout<<2<<endl;return 0;
			}
	}
	cout<<3;
	return 0;
}

