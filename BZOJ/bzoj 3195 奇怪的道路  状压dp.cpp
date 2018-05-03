#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int F[32][32][1<<9][9];
int n,m,K;
int main()
{
    scanf("%d%d%d",&n,&m,&K);
    F[2][0][0][0]=1;
    for(int i=2;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<(1<<(K+1));k++)
            {
                for(int c=0;c<K;c++)
                {
                    if(!F[i][j][k][c])  continue;
                    (F[i][j][k][c+1]+=F[i][j][k][c])%=mod;
                    if(i-K+c>=1 && j<m)
                        (F[i][j+1][k^(1<<c)^(1<<K)][c]+=F[i][j][k][c])%=mod;
                }   
                if(!(k&1)) (F[i+1][j][k>>1][0]+=F[i][j][k][K])%=mod;
            }
    cout<<F[n+1][m][0][0];
    return 0;       
}
