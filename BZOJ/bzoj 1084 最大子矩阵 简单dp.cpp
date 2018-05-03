#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN = 150;
int n,m,k;
int dp[MAXN][11],f[MAXN][MAXN][11];
//f[i][j][k]��ʾ��һ�д�����i�����ڶ��д�����j������ѡȡ��k���Ӿ��������ֵ
int a[2][MAXN];
int sum[2][MAXN];
//sum����ǰ׺���Ż� 
inline int getint(){
    int w=0,q=1;char c=getchar();
    while(c!='-' && (c<'0' || c>'9')) c=getchar();
    if(c=='-') q=-1,c=getchar();
    while(c>='0' && c<='9') w=w*10+c-'0',c=getchar();
    return w*q;
}

int main()
{
    n=getint(); m=getint(); k=getint();
    
    if(m==1) 
	{//����ֻ��һ�е����
    for(int i=1;i<=n;i++) a[0][i]=getint(),sum[0][i]=sum[0][i-1]+a[0][i];

    for(int i=1;i<=n;i++)
        for(int l=1;l<=k;l++) { 
        dp[i][l]=dp[i-1][l];
        for(int j=0;j<i;j++)
            dp[i][l]=max(dp[j][l-1]+sum[0][i]-sum[0][j],dp[i][l]);
        }
    printf("%d",dp[n][k]);
	//����Ŀǰ������ 
    } 
	else
	{	
    for(int i=1;i<=n;i++) a[0][i]=getint(),sum[0][i]=sum[0][i-1]+a[0][i],a[1][i]=getint(),sum[1][i]=sum[1][i-1]+a[1][i];
	//ǰ׺���Ż� 
    for(int l=1;l<=k;l++)
        for(int i=1;i<=n;i++)
        	for(int j=1;j<=i;j++) 
			{
            f[i][j][l]=max(f[i-1][j][l],f[i][j-1][l]);
            for(int from=0;from<i;from++) f[i][j][l]=max(f[i][j][l],f[from][j][l-1]+sum[0][i]-sum[0][from]);//ö�ٴ����ת��
            for(int from=0;from<j;from++) f[i][j][l]=max(f[i][j][l],f[i][from][l-1]+sum[1][j]-sum[1][from]);//ö�ٴ��ұ�ת��
            if(i==j)
            for(int from=0;from<i;from++)//ö�ٴ�����ת��
                f[i][j][l]=max(f[i][j][l],f[from][from][l-1]+sum[0][i]-sum[0][from]+sum[1][j]-sum[1][from]);
        }
    printf("%d",f[n][n][k]);
    }

    return 0;
}
