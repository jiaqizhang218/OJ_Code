#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define mod 1000000
#define inf 1000000000
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,L,R;
int a[1005],f[2][100005],s[2][100005];
int main()
{
	//n������ mֻ���� ��L~Rֻ���ϳ�ȥʱ ��ͬ�ķ��������� 
	//f[i][j]��ʾǰi�������ȥjֻ���ϵķ������� 
	n=read();m=read();L=read();R=read();
	for(int i=1;i<=m;i++)
	{
		int x=read();a[x]++;
	}
	f[0][0]=1;
	for(int i=0;i<=m;i++)	s[0][i]=1;
	
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)		//n������mֻ 
		{
			f[i&1][j] += s[(i-1)&1][j];
			
			if(j - a[i] - 1 >= 0)		f[i&1][j] -= s[(i-1)&1][j-a[i]-1];
				f[i&1][j] %= mod;
			if(j)	s[i&1][j] = (s[i&1][j-1]+f[i&1][j]) % mod;
			else s[i&1][j] = f[i&1][j];
				f[(i-1)&1][j] = 0;//������Ҫ����һ����� 
		}
	printf("%d\n",(s[n&1][R]-s[n&1][L-1]%mod+mod)%mod);
	return 0;
}
